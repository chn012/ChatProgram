#pragma once
#include "user.h"
#include "hashtable.h"

class chat {

private:
	hashtable<string, user*>* data = new hashtable<string, user*>();


public:
	chat();
	void addUsr(user* a);
	void deleteUsr(string name);
	void sendMSG(user* sender, user* recipient, string msg);
	bool findUsr(string usrname);
	user* getUsr(string name);

};
