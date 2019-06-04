#ifndef SinhVien_h
#define SinhVien_h

#pragma once
#include "BanDoc.h"
class SinhVien :
	public BanDoc
{
private:
	string sKhoaHoc;
	int nLoaiBD;
public:
	SinhVien()
		:BanDoc()
	{
		this->nLoaiBD = 0;
		this->sKhoaHoc = "";
	}
	SinhVien(string sMaBD, string sHoTen, string sKhoa, string sKhoaHoc)
		:BanDoc(sMaBD, sHoTen, sKhoa)
	{
		this->nLoaiBD = 0;
		this->sKhoaHoc = sKhoaHoc;
	}
	SinhVien(string sMaBD, string sHoTen, string sKhoa, int nNgay, int nThang, int nNam, string sKhoaHoc)
		:BanDoc(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam)
	{
		this->nLoaiBD = 0;
		this->sKhoaHoc = sKhoaHoc;
	}

	void outputBanDoc();
	void readBanDoc(ifstream &file);
	void writeBanDoc(ofstream &file);

	~SinhVien(void) {};
};
#endif // !SinhVien_h

