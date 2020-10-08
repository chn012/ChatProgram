//Minh Thuc Tran, Zihong Yi, and Christine Nguyen (Team 7)
// CIS22C Project: Message Application "Chat4Free" Friend list

#include <iostream>
#include <string>
#include "bst.h"
#include "linkedlist.h"
#include "msg.h"
#include "hashtable.h"
#include "chat.h"

//comment at each step like at sign in you put "sign in"

bool isSignIn(string username, string password)
{
	//implementation
	return true;
}

int main()
{
	int choice;
	int choice2;
	bool run = true;
	bool exitSignIn = true;
	bool exitFriend = true;
	bool exitAccCreate = true;
	string username;
	string tmp;
	string password;
	string password2;
	string birthday;
	string email;
	string friendUser;
	string friendName = ("");
	string message;
	string goBack = ("go back");
	user* currentUser;
	user* currentFriend;
	user* tempFriend;
	chat* ct = new chat();

mainMenu:
	while (run != false)
	{
		cout << "~~~~~Chat4Free~~~~~" << endl;
		cout << "1) Sign In" << endl;
		cout << "2) Create An Account" << endl;
		cout << "3) Delete An Account" << endl;
		cout << "4) Forget Password?" << endl;
		cout << "5) Quit" << endl << endl;
		cout << "Input: ";
		cin >> choice;
		cout << endl;

		while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 || cin.fail())
		{
			cout << "Not a valid choice \n"
				<< "Please try again \n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Input: ";
			cin >> choice;
			cout << endl;
		}

		switch (choice)
		{
		case 1:
			while (exitSignIn != false)
			{
				string passwordCorrect;
				cout << "Enter your username and password\n";
				cout << "Username: ";
				cin >> username;
				cout << "Password: ";
				cin >> password;
				cout << endl;
				int count = 0;
				int count3 = 0;
				//Check if correct using while loop
				// function isSignIn
				while (true)
				{
					if (!ct->findUsr(username)) {
						cout << "Username is not registered" << endl << endl;
						goto mainMenu;
					}
					if (count >= 5) {
						cout << "You have too many failure attempts" << endl;
						cout << "Going back to main menu" << endl;
						goto mainMenu;
					}
					
					if (ct->getUsr(username)->pswMatch(password))
					{
						cout << "Sign in successful\n\n";
						currentUser = ct->getUsr(username);
						break;
					}
					
					else {
						cout << "Sign in unsuccessful" << endl;

						cout << "You have " << 5 - count++ << "attempts left" << endl;
						cout << "Enter your username and password\n";
						cout << "Username: ";
						cin >> username;
						cout << "Password: ";
						cin >> password;
						cout << endl;
					}
				}

			subMenu:
				cout << "^^^^^Welcome: " << username << "^^^^^\n";
				cout << "1) Friend\n";
				cout << "2) Add A New Friend\n";
				cout << "3) Logout\n\n";
				cout << "Input: ";
				cin >> choice2;
				cout << endl;

				while (choice2 != 1 && choice2 != 2 && choice2 != 3 || cin.fail())
				{
					cout << "Not a valid choice \n"
						<< "Please try again \n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Input: ";
					cin >> choice2;
					cout << endl;
				}

				switch (choice2)
				{
				case 1:
				sub2Menu:
					int choice3;
					while (exitFriend != false)
					{
						cout << "Friend List:" << endl;
						currentUser->printFriendList();
						cout << endl;
						cout << "Please type in the name of your friend or\n"
							<< "\"go back\" to return to the previous menu.\n"
						<< "Input: ";
						cin.ignore(INT_MAX, '\n');
						getline(cin, friendName);
	
						if (friendName == goBack)
						{
							cout << "\nReturning\n\n";
							goto subMenu;
						}
						cout << endl;

						if (ct->findUsr(friendName)) {
							tempFriend = ct->getUsr(friendName);
						}
						else {
							cout << "No username with that name\n\n";
							goto subMenu;
						}
				
						if (currentUser->findFriend(tempFriend))
						{
							currentFriend = tempFriend;
							cout << "*****Friend: " << friendName << "*****\n";
							cout << "1) Text (Chat)\n";
							cout << "2) Review Chat History\n";
							cout << "3) Delete Chat History\n";
							cout << "4) Delete " << friendName << endl;
							cout << "5) Go Back\n\n";
							cout << "Input: ";
							cin >> choice3;
							cout << endl;

							while (choice3 != 1 && choice3 != 2 && choice3 != 3 && choice3 != 4 && choice3 != 5 || cin.fail())
							{
								cout << "Not a valid choice \n"
									<< "Please try again \n";
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Input: ";
								cin >> choice3;
								cout << endl;
							}

							switch (choice3)
							{
							case 1:
								cout << "-----Text(Chat)-----\n";
								cout << endl;
								cout << "Please enter your message:" << endl;
                                    getline(cin,message);
                                    getline(cin,message);
								ct->sendMSG(currentUser, currentFriend, message);
								cout << endl;
								currentUser->printChatHistory(friendName);
								cout << endl;
								goto sub2Menu;
								break;

							case 2:
								cout << "-----Chat History-----\n";
								cout << endl;
								cout << "friendName" << friendName << endl;
								currentUser->printChatHistory(friendName);
								//text code
								goto sub2Menu;
								break;

							case 3:
								cout << "Delete chat history successful\n\n";
								currentUser->deleteChatHistory(friendName);
								break;

							case 4:
								cout << "Delete friend successful\n\n";
								currentUser->deleteFriend(currentFriend);
								goto subMenu;
								break;
							case 5:
								cout << "Going back to friend's menu\n\n";
								goto subMenu;
								break;

							default:{}
							}
						}
						else
						{
							cout << "This user is not your friend yet\n\n";
							goto subMenu;
						}
					}

				case 2:
					cout << "*****Add A New Friend*****\n";
					cout << "Username:";
					cin >> tmp;
					cout << endl;
					if (ct->findUsr(tmp)) {
						if (ct->getUsr(tmp) == currentUser)
						{
							cout << "Cannot add yourself as friend\n\n";
							
						}
						else
						{
							if (currentUser->findFriend(ct->getUsr(tmp)))
							{
								cout << "He/She are already your friend\n\n";
								
							}
							else
							{
								currentUser->addFriend(ct->getUsr(tmp));
								cout << tmp << " has been added to your friendlist!" << endl << endl;
							}

						}
					}
					else {
						cout << "Sorry, no account with username " << tmp << " is found :(" << endl << endl;
					}
					//add friend code
					goto subMenu;
					break;

				case 3:
					cout << "Logging out\n\n";
					goto mainMenu;
					break;

				default: {}
				}
			}

		case 2:
			while (exitAccCreate != false)
			{
				cout << "*****Create An Account*****\n";
				cout << "Account Creation:\n\n";
				// check if username already there
				//check length 15
				cout << "1) Username: ";
				cin >> username;
				while (ct->findUsr(username)) {
					cout << "Name is already taken" << endl;
					cout << "1) Username: ";
					cin >> username;
				}
				//check if right format mm/dd/yyyy
				cout << "2) Birthday: ";
				cin >> birthday;
				//check if email already there
				//check "string @ string . string"
				cout << "3) Email address: ";
				cin >> email;
				// check password length between 6-12
				cout << "4) Password: ";
				cin >> password;
				cout << "5) Confirm password: ";
				cin >> password2;

				if (!password.compare(password2))
				{
					//create new user code
					user* newUsr = new user(username, password, birthday, email);
					ct->addUsr(newUsr);
					cout << "\nCongratulation!" << endl;
					cout << "You can sign in now.\n\n";
					goto mainMenu;
				}
				int count2 = 0;
				//Need a while to go back to main menu
				while (true)
				{
					if (count2 >= 3) {
						cout << "\nYou have too many failure attempts" << endl;
						cout << "Going back to main menu\n\n";
						goto mainMenu;
					}
					else {
						cout << "\nPassword does not match.\n"
							<< "You have " << 3 - count2++ << " attempts left\n"
							<< "Please try again. \n\n";
						cout << "Confirm password: ";
						cin >> password2;
					}

					if (!password.compare(password2))
					{
						//create new user code
						user* newUsr = new user(username, password, birthday, email);
						ct->addUsr(newUsr);
						cout << "\nCongratulation!" << endl;
						cout << "You can sign in now\n\n";
						goto mainMenu;
					}
				}
			}
			break;

		case 3:
			cout << "*****Delete An Account*****\n";
			
			while (exitSignIn != false)
			{
				string passwordCorrect;
				cout << "Enter your username and password\n";
				cout << "Username: ";
				cin >> username;
				cout << "Password: ";
				cin >> password;
				cout << endl;
				int count = 0;
				int count3 = 0;
				//Check if correct using while loop
				// function isSignIn
				while (true)
				{
					if (!ct->findUsr(username)) {
						cout << "Username is not registered" << endl << endl;
						goto mainMenu;
					}
					if (count >= 5) {
						cout << "You have too many failure attempts" << endl;
						cout << "Going back to main menu" << endl;
						goto mainMenu;
					}

					if (ct->getUsr(username)->pswMatch(password))
					{
						cout << "Delete successful\n\n";
						ct->deleteUsr(username);
						goto mainMenu;
					}

					else {
						cout << "Delete unsuccessful" << endl;

						cout << "You have " << 5 - count++ << "attempts left" << endl;
						cout << "Enter your username and password\n";
						cout << "Username: ";
						cin >> username;
						cout << "Password: ";
						cin >> password;
						cout << endl;
					}
				}
			}
			break;

		case 4:
			cout << "*****Forget Password?*****\n";
			cout << "Please input username, email, and birthday\n\n";
			cout << "Username: ";
			cin >> username;
			cout << "Email address: ";
			cin >> email;
			cout << "Birthday: ";
			cin >> birthday;
			cout << endl;

			if (ct->findUsr(username)) {
				currentUser = ct->getUsr(username);
				if (currentUser->getEmail() == email) {
					if (currentUser->getBirthday() == birthday) {
						cout << "Enter your new password:" << endl;
						cin >> password;
						cout << "Confirm your new password:" << endl;
						cin >> password2;

						if (password == password2) {
							currentUser->changePSW(password);
						}
						else {
							cout << "\nPassword does not match" << endl;
						}
					}
					else {
						cout << "Information does not match" << endl;
					}
				}
				else {
					cout << "Information does not match" << endl;
				}
			}
			else {
				cout << "User doesn't exist" << endl;
			}
			// Check if correct
			//forget password code
			cout << endl;
			goto mainMenu;
			break;

		case 5:
			cout << "Exiting Chat4Free" << endl;
			run = false;
			break;

		default:{}
		}
	}
	system("pause");
	return 0;
}
