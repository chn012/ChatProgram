#pragma once
#include "msg.h"

msg::msg(string  a, string b, string msg)
{
	sender = a;
	recipient = b;
	msg1 = msg;
}

msg::~msg()
{
}

void msg::printMSG()
{
	cout << "Sender: " << sender << "----->Recepient: " << recipient << endl;
	cout << "Message: " << msg1 << endl;
}

string msg::getSender()
{
	return sender;
}

string msg::getRecipient()
{
	return recipient;
}
