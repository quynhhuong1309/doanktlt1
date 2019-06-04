#include "GiaoVien.h"



void GiaoVien::outputBanDoc()
{
	cout << " Loai ban doc: " << this->nLoaiBD << endl;
	BanDoc::xuatBanDoc();
	cout << " Dia chi: " << this->sDiaChi << endl;
	cout << " So dien thoai: " << this->sSoDT << endl;
}
void GiaoVien::readBanDoc(ifstream &file)
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
	getline(file, this->sDiaChi, ',');

	rewind(stdin);
	getline(file, this->sSoDT, '\n');
}
void GiaoVien::writeBanDoc(ofstream &file)
{
	file << this->nLoaiBD << "," << this->sMaBD << "," << this->sHoTen << "," << this->sKhoa << ","
		<< this->xNgayDK.nNgay << "," << this->xNgayDK.nThang << "," << this->xNgayDK.nNam << "," << this->sDiaChi << "," << this->sSoDT << endl;
}