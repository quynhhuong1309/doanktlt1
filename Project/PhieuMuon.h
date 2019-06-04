#ifndef PhieuMuon_h
#define PhieuMuon_h

#pragma once
#include"Sach.h"
#include"BanDoc.h"
class PhieuMuon
{
private:
	BanDoc xBanDoc;
	Sach xSach;
	Date xNgayMuon, xNgayTra;
	static int nTongPM;
	int nMaPM;
	int nTrangThai;
public:
	friend Date;
	friend Sach;
	friend BanDoc;
	PhieuMuon()
	{
		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTrangThai = 1;
		this->xNgayTra = tinhNgayTra();
	}
	PhieuMuon(string sMaBD, string sMaSach)
		:xBanDoc(sMaBD), xSach(sMaSach)
	{
		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTrangThai = 1;
		this->xNgayTra = tinhNgayTra();
	}
	PhieuMuon(int nMaPM, string sMaBD, string sMaSach, int a, int b, int c, int d, int e, int f)
		:xBanDoc(sMaBD), xSach(sMaSach), xNgayMuon(a, b, c), xNgayTra(d, e, f)
	{
		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTrangThai = 1;
		this->xNgayTra = tinhNgayTra();
	}

	string getMaBanDoc();
	string getMaSach();
	Date getNgayMuon();
	Date getNgayTra();
	int getMaPM();
	int getTrangThai();
	void setTrangThai(int a);

	static int getTongPM()
	{
		return nTongPM;
	}

	Date &tinhNgayTra();
	void outputPM();
	void readPM(ifstream &file);
	void writePM(ofstream &file);
	~PhieuMuon(void) {};
};
#endif // !PhieuMuon_h

