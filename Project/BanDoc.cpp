#include "BanDoc.h"



string BanDoc::getMaBD()
{
	return this->sMaBD;
}
string BanDoc::getHoTen()
{
	return this->sHoTen;
}
string BanDoc::getKhoa()
{
	return this->sKhoa;
}

void BanDoc::setMaBD(string sMaBD)
{
	this->sMaBD = sMaBD;
}
void BanDoc::setHoTen(string sHoTen)
{
	this->sHoTen = sHoTen;
}
void BanDoc::setKhoa(string sKhoa)
{
	this->sKhoa = sKhoa;
}
void BanDoc::setBD(string sMaBD, string sHoTen, string sKhoa)
{
	this->sMaBD = sMaBD;
	this->sHoTen = sHoTen;
	this->sKhoa = sKhoa;
}

void BanDoc::xuatBanDoc()
{
	cout << " Ma ban doc: " << this->sMaBD << endl;
	cout << " Ho ten: " << this->sHoTen << endl;
	cout << " Khoa: " << this->sKhoa << endl;
}
