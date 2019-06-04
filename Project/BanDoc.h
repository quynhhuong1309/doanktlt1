#ifndef BanDoc_h
#define BanDoc_h

#pragma once
#include"Date.h"
class PhieuMuon;
class BanDoc
{
protected:
	string sMaBD, sHoTen, sKhoa;
	Date xNgayDK;
public:
	friend PhieuMuon;
	BanDoc(string sMaBD)
	{
		this->sMaBD = sMaBD;
		this->sHoTen = "";
		this->sKhoa = "";
	}
	BanDoc()
	{
		this->sMaBD = "";
		this->sHoTen = "";
		this->sKhoa = "";
	}
	BanDoc(string sMaBD, string sHoTen, string sKhoa)
		:xNgayDK()
	{
		this->sMaBD = sMaBD;
		this->sHoTen = sHoTen;
		this->sKhoa = sKhoa;
	}
	BanDoc(string sMaBD, string sHoTen, string sKhoa, int nNgay, int nThang, int nNam)
		:xNgayDK(nNgay, nThang, nNam)
	{
		this->sMaBD = sMaBD;
		this->sHoTen = sHoTen;
		this->sKhoa = sKhoa;
	}

	string getMaBD();
	string getHoTen();
	string getKhoa();

	void setMaBD(string sMaBD);
	void setHoTen(string sHoTen);
	void setKhoa(string sKhoa);
	void setBD(string sMaBD, string sHoTen, string sKhoa);

	virtual void outputBanDoc() {};
	virtual void readBanDoc(ifstream &file) {};
	virtual void writeBanDoc(ofstream &file) {};

	void xuatBanDoc();

	virtual ~BanDoc(){}
};
#endif // !BanDoc_h

