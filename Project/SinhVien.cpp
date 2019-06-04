#include "SinhVien.h"



void SinhVien::outputBanDoc()
{
	cout << " Loai ban doc: " << this->nLoaiBD << endl;
	BanDoc::xuatBanDoc();
	cout << " Khoa hoc: " << this->sKhoaHoc << endl;
}
void SinhVien::readBanDoc(ifstream &file)
{
	rewind(stdin);
	getline(file, this->sMaBD, ',');

	rewind(stdin);
	getline(file, this->sHoTen, ',');

	rewind(stdin);
	getline(file, this->sKhoa, ',');

	file >> this->xNgayDK.nNgay;
	file.ignore(1);

	file >> this->xNgayDK.nThang;
	file.ignore(1);

	file >> this->xNgayDK.nNam;
	file.ignore(1);

	rewind(stdin);
	getline(file, this->sKhoaHoc, '\n');
}
void SinhVien::writeBanDoc(ofstream &file)
{
	file << this->nLoaiBD << "," << this->sMaBD << "," << this->sHoTen << "," << this->sKhoa << ","
		<< this->xNgayDK.nNgay << "," << this->xNgayDK.nThang << ","
		<< this->xNgayDK.nNam << "," << this->sKhoaHoc << endl;
}
