#ifndef GiaoVien_h
#define GiaoVien_h

#pragma once
#include "BanDoc.h"
class GiaoVien :
	public BanDoc
{
private:
	string sDiaChi, sSoDT;
	int nLoaiBD;
public:
	GiaoVien()
		:BanDoc()
	{
		this->nLoaiBD = 1;
		this->sDiaChi = "";
		this->sSoDT = "";
	}
	GiaoVien(string sMaBD, string sHoTen, string sKhoa, string sDiaChi, string sSoDT)
		:BanDoc(sMaBD, sHoTen, sKhoa)
	{
		this->nLoaiBD = 1;
		this->sDiaChi = sDiaChi;
		this->sSoDT = sSoDT;
	}
	GiaoVien(string sMaBD, string sHoTen, string sKhoa, int nNgay, int nThang, int nNam, string sDiaChi, string sSoDT)
		:BanDoc(sMaBD, sHoTen, sKhoa,nNgay, nThang, nNam)	
	{
		this->nLoaiBD = 1;
		this->sDiaChi = sDiaChi;
		this->sSoDT = sSoDT;
	}
	void outputBanDoc();
	void readBanDoc(ifstream &file);
	void writeBanDoc(ofstream &file);

	~GiaoVien(void) {};
};
#endif // !GiaoVien_h

