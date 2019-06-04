#include "PhieuMuon.h"



string PhieuMuon::getMaBanDoc()
{
	return this->xBanDoc.getMaBD();
}
string PhieuMuon::getMaSach()
{
	return this->xSach.getMaSach();
}
Date PhieuMuon::getNgayMuon()
{
	return this->xNgayMuon;
}
Date PhieuMuon::getNgayTra()
{
	return this->xNgayTra;
}
int PhieuMuon::getMaPM()
{
	return this->nMaPM;
}
int PhieuMuon::getTrangThai()
{
	return this->nTrangThai;
}
void PhieuMuon::setTrangThai(int a)
{
	this->nTrangThai = a;
}

Date &PhieuMuon::tinhNgayTra()
{
	switch (xNgayMuon.nThang)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		{
			xNgayTra.nNgay = xNgayMuon.nNgay + 7;
			if (xNgayTra.nNgay > 31)
			{
				xNgayTra.nNgay = xNgayTra.nNgay - 31;
				xNgayTra.nThang++;
			}
			if (xNgayTra.nThang > 12)
			{
				xNgayTra.nThang = 1;
				xNgayTra.nNam++;
			}
			break;
		}
		case 4: case 6: case 9: case 11:
		{
			xNgayTra.nNgay = xNgayMuon.nNgay + 7;
			if (xNgayTra.nNgay > 30)
			{
				xNgayTra.nNgay = xNgayTra.nNgay - 30;
				xNgayTra.nThang++;
			}
			break;
		default:
		{
			if ((xNgayMuon.nNam % 400 == 0) || ((xNgayMuon.nNam % 4 == 0) && (xNgayMuon.nNam % 100 != 0)))
			{
				xNgayTra.nNgay = xNgayMuon.nNgay + 7;
				if (xNgayTra.nNgay > 28)
				{
					xNgayTra.nNgay = xNgayTra.nNgay - 28;
					xNgayTra.nThang++;
				}
			}
		}
		}
	}
	return xNgayTra;
}
void PhieuMuon::outputPM()
{
	cout << setw(20) << " Ma phieu muon: " << this->getMaPM() << setw(20) << endl;
	cout << setw(20) << " Ma ban doc: " << this->getMaBanDoc() << setw(20) << endl;
	cout << setw(20) << " Ma sach: " << this->getMaSach() << setw(20) << endl;
	cout << setw(20) << " Ngay muon: " << this->getNgayMuon().nNgay << "/" << this->getNgayMuon().nThang << "/" << this->getNgayMuon().nNam << setw(20) << endl;
	cout << setw(20) << " Ngay tra: " << this->getNgayTra().nNgay << "/" << this->getNgayTra().nThang << "/" << this->getNgayTra().nNam << setw(20) << endl;
	cout << setw(20) << " Tinh trang: " << this->getTrangThai() << endl;
}
void PhieuMuon::readPM(ifstream &file)
{
	file >> this->nMaPM;
	file.ignore(1);

	rewind(stdin);
	getline(file, this->xBanDoc.sMaBD, ',');

	rewind(stdin);
	getline(file, this->xSach.sMaSach, ',');

	file >> this->xNgayMuon.nNgay;
	file.ignore(1);

	file >> this->xNgayMuon.nThang; 
	file.ignore(1);

	file >> this->xNgayMuon.nNam;
	file.ignore(1);

	file >> this->xNgayTra.nNgay;
	file.ignore(1);

	file >> this->xNgayTra.nThang;
	file.ignore(1);

	file >> this->xNgayTra.nNam;
	file.ignore(1);

	file >> this->nTrangThai;
	file.ignore(1);
}
void PhieuMuon::writePM(ofstream &file)
{
	file << this->getMaPM() << "," << this->getMaBanDoc() << "," << this->getMaSach() << ","
		<< this->getNgayMuon().getNgay() << "," << this->getNgayMuon().getThang() << "," << this->getNgayMuon().getNam() << ","
		<< this->getNgayTra().getNgay() << "," << this->getNgayTra().getThang() << "," << this->getNgayTra().getNam() << "," 
		<< this->getTrangThai() << endl;
}
