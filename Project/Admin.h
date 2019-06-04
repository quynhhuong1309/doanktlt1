#ifndef Admin_h
#define Admin_h

#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Admin
{
	string sUser, sPass;
public:
	Admin()
	{
		this->sUser = "";
		this->sPass = "";
	}
	Admin(string sUser, string sPass)
	{
		this->sUser = sUser;
		this->sPass = sPass;
	}

	string getUser();
	string getpass();
	void setUser(string sUser);
	void setPass(string sPass);
	void setAdmin(string sUser, string sPass);

	void readAdmin(ifstream &fin);
	void writeAdmin(ofstream &fout);

	friend ostream & operator << (ostream &os, Admin &Ad);

	~Admin(void) {};
};
#endif // !Admin_h

