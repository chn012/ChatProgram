#pragma once
#include "chat.h"

chat::chat()
{}

void chat::addUsr(user * a)
{
	data->add(a->getUsrName(), a);
}

void chat::deleteUsr(string name)
{
	data->remove(name);
}

void chat::sendMSG(user* sender, user* recipient, string text)
{
	msg* message = new msg(sender->getUsrName(), recipient->getUsrName(), text);
	sender->sendMSG(sender->getUsrName(), message);
	recipient->receiveMSG(recipient->getUsrName(), message);

}

bool chat::findUsr(string usrname)
{


	return data->hasKey(usrname);
}

user * chat::getUsr(string name)
{
	try
	{
		if (!findUsr(name))
		{
			throw "Username doesn't exist";
		}
		return data->get(name);
	}
	catch (const char* err)
	{
		cout << err << endl;
	}

}
