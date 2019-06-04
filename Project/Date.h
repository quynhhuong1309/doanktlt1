#ifndef Date_h
#define Date_h

#include<iostream>
using namespace std;
#include<string>
#include<iomanip>
#include<vector>
#include<Windows.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include<ctime>
#include<time.h>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

class BanDoc;
class Sach;
class GiaoVien;
class SinhVien;
class PhieuMuon;

class Date
{
private:
	int nNgay, nThang, nNam;
public:
	friend BanDoc;
	friend Sach;
	friend GiaoVien;
	friend SinhVien;
	friend PhieuMuon;
	Date(int nNgay, int nThang, int nNam)
	{
		this->nNgay = nNgay;
		this->nThang = nThang;
		this->nNam = nNam;
	}
	Date()
	{
		time_t rawtime;
		struct tm *info;
		char buffer[80];
		time(&rawtime);
		info = localtime(&rawtime);
		this->nNgay = (info->tm_mday);
		this->nThang = (info->tm_mon + 1);
		this->nNam = (info->tm_year + 1900);
	}
	int getNgay();
	int getThang();
	int getNam();
	void setNgay(int nNgay);
	void setThang(int nThang);
	void setNam(int nNam);
	void setDate(int nNgay, int nThang, int nNam);
	~Date(){}
};
#endif // !Date_h

