#include "Admin.h"



string Admin::getUser()
{
	return this->sUser;
}
string Admin::getpass()
{
	return this->sPass;
}
void Admin::setUser(string sUser)
{
	this->sUser = sUser;
}
void Admin::setPass(string sPass)
{
	this->sPass = sPass;
}
void Admin::setAdmin(string sUser, string sPass)
{
	this->sUser = sUser;
	this->sPass = sPass;
}

void Admin::readAdmin(ifstream &fin)
{
	rewind(stdin);
	getline(fin, this->sUser, ',');

	rewind(stdin);
	getline(fin, this->sPass, '\n');
}
void Admin::writeAdmin(ofstream &fout)
{
	fout << this->sUser << "," << this->sPass << endl;
}

ostream & operator << (ostream &os, Admin &Ad)
{
	os << " User: " << Ad.getUser() << endl;
	os << " Pass: " << Ad.getpass() << endl;
	return os;
}
