#include "Sach.h"



string Sach::getMaSach()
{
	return this->sMaSach;
}
string Sach::getTuaDe()
{
	return this->sTuaDe;
}
string Sach::getTacGia()
{
	return this->sTacGia;
}
string Sach::getNhaXB()
{
	return this->sNhaXB;
}
int Sach::getTriGia()
{
	return this->nTriGia;
}
int Sach::getNamPhatHanh()
{
	return this->nNamPhatHanh;
}
int Sach::getSoTrang()
{
	return this->nSoTrang;
}
int Sach::getTinhTrangSach()
{
	return this->nTinhTrangSach;
}
void Sach::setMaSach(string sMaSach)
{
	this->sMaSach = sMaSach;
}
void Sach::setTuaDe(string sTuaDe)
{
	this->sTuaDe = sTuaDe;
}
void Sach::setTacGia(string sTacGia)
{
	this->sTacGia = sTacGia;
}
void Sach::setNhaXB(string sNhaXB)
{
	this->sNhaXB = sNhaXB;
}
void Sach::setTriGia(int nTriGia)
{
	this->nTriGia = nTriGia;
}
void Sach::setNamPhatHanh(int nNamPhatHanh)
{
	this->nNamPhatHanh = nNamPhatHanh;
}
void Sach::setSoTrang(int nSoTrang)
{
	this->nSoTrang = nSoTrang;
}
void Sach::setTinhTrangSach(int nTinhTrangSach)
{
	this->nTinhTrangSach = nTinhTrangSach;
}
void Sach::setSach(string sMaSach, string sTuaDe, string sTacGia, string sNhaXB, int nTriGia, int nNamPhatHanh, int nSoTrang, int nTinhTrangSach)
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

void Sach::readSach(ifstream &file)
{
	rewind(stdin);
	getline(file, this->sMaSach, ',');

	rewind(stdin);
	getline(file, this->sTuaDe, ',');

	rewind(stdin);
	getline(file, this->sTacGia, ',');

	rewind(stdin);
	getline(file, this->sNhaXB, ',');

	file >> this->nTriGia;
	file.ignore(1);

	file >> this->nNamPhatHanh;
	file.ignore(1);

	file >> this->nSoTrang;
	file.ignore(1);

	file >> this->nTinhTrangSach;
	file.ignore(1);
}
void Sach::writeSach(ofstream &file)
{
	file << this->sMaSach << "," << this->sTuaDe << "," << this->sTacGia << "," << this->sNhaXB << ","
		<< this->nTriGia << "," << this->nNamPhatHanh << ","
		<< this->nSoTrang << "," << this->nTinhTrangSach << endl;
}
void Sach::xuatSach()
{
	cout << " Ma sach: " << this->sMaSach << endl;
	cout << " Tua de: " << this->sTuaDe << endl;
	cout << " Tac gia: " << this->sTacGia << endl;
	cout << " Nha xuat ban: " << this->sNhaXB << endl;
	cout << " Tri gia: " << this->nTriGia << endl;
	cout << " Nam phat hanh: " << this->nNamPhatHanh << endl;
	cout << " So trang: " << this->nSoTrang << endl;
	cout << " Tinh trang sach: " << this->nTinhTrangSach << endl;
}