#ifndef Sach_h
#define Sach_h

#pragma once
#include"Date.h"
class PhieuMuon;

class Sach
{
private:
	string sMaSach, sTuaDe, sTacGia, sNhaXB;
	int nTriGia, nNamPhatHanh, nSoTrang, nTinhTrangSach;
public:
	friend PhieuMuon;
	Sach(string sMaSach)
	{
		this->sMaSach = sMaSach;
		this->sTuaDe = "";
		this->sTacGia = "";
		this->sNhaXB = "";
		this->nTriGia = 0;
		this->nNamPhatHanh = 0;
		this->nSoTrang = 0;
		this->nTinhTrangSach = 0;
	}
	Sach()
	{
		this->sMaSach = "";
		this->sTuaDe = "";
		this->sTacGia = "";
		this->sNhaXB = "";
		this->nTriGia = 0;
		this->nNamPhatHanh = 0;
		this->nSoTrang = 0;
		this->nTinhTrangSach = 0;
	}
	Sach(string sMaSach, string sTuaDe, string sTacGia, string sNhaXB, int nTriGia, int nNamPhatHanh, int nSoTrang, int nTinhTrangSach)
	{
		this->sMaSach = sMaSach;
		this->sTuaDe = sTuaDe;
		this->sTacGia = sTacGia;
		this->sNhaXB = sNhaXB;
		this->nTriGia = nTriGia;
		this->nNamPhatHanh = nNamPhatHanh;
		this->nSoTrang = nSoTrang;
		this->nTinhTrangSach = nTinhTrangSach;
	}
	string getMaSach();
	string getTuaDe();
	string getTacGia();
	string getNhaXB();
	int getTriGia();
	int getNamPhatHanh();
	int getSoTrang();
	int getTinhTrangSach();
	void setMaSach(string sMaSach);
	void setTuaDe(string sTuaDe);
	void setTacGia(string sTacGia);
	void setNhaXB(string sNhaXB);
	void setTriGia(int nTriGia);
	void setNamPhatHanh(int nNamPhatHanh);
	void setSoTrang(int nSoTrang);
	void setTinhTrangSach(int nTinhTrangSach);
	void setSach(string sMaSach, string sTuaDe, string sTacGia, string sNhaXB, int nTriGia, int nNamPhatHanh, int nSoTrang, int nTinhTrangSach);

	void readSach(ifstream &file);
	void writeSach(ofstream &file);
	void xuatSach();

	~Sach(){}
};
#endif // !Sach_h

