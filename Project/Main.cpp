/*
Project mon ky thuat lap trinh: Quan ly thu vien
Nhom:
Thanh vien:
+ Nguyen Thi Quynh Huong 18211TT5127
+ Le Minh Thanh
*/

//Khai bao thu vien
#include"PhieuMuon.h"
#include"Admin.h"
#include"GiaoVien.h"
#include"SinhVien.h"
//Khai bao nguyen mau ham con

//Ham mau
void color(int nX);

//Menu
void menuChinh();
void menuCon();
void menuTimThongTin();
void menuQuanLySach();
void menuQuanLyBanDoc();
void menuQuanLyPhieuMuon();
void menuThongKe();

//User
void docUserPass(vector <Admin> &Ad);
void xuatUserPass(vector <Admin> Ad);
void login();
bool kiemTraDangNhap(vector <Admin> Ad, string sUser, string sPass);

//Danh sach ban doc
void docDSBanDoc(vector <BanDoc*> &BD);
void xuatDSBanDoc(vector <BanDoc*> BD);
void timBanDoc(vector <BanDoc*> BD, string sMa);
void themDSBanDoc(vector <BanDoc*> &BD);
void ghiDSBanDoc(vector <BanDoc*> BD);
bool kiemTraBanDoc(vector <BanDoc*> BD, string sMa);
int timKiemBanDoc(vector <BanDoc*> BD, string sMa);
int demBanDocSinhVien(vector <BanDoc*> BD);
int demBanDocGiaoVien(vector <BanDoc*> BD);

//Danh sach sach
void themSach(vector <Sach> &S);
void docDSSach(vector <Sach> &S);
void xuatDSSach(vector <Sach> S);
void timThongTinSach(vector <Sach> S, string sMa);
void xoaSach(vector <Sach> &S, string sMa);
void ghiDSSach(vector <Sach> S);
int demSachCon(vector <Sach> S);
int demSachMuon(vector <Sach> S);
int timKiemSach(vector <Sach> S, string sMa);
bool kiemTraTinhTrangSach(vector <Sach> S, string sMa);

//Danh sach phieu muon
void docDSPhieuMuon(vector <PhieuMuon> &PM);
void themPhieuMuon(vector <PhieuMuon> &PM, vector <BanDoc*> BD, vector <Sach> S);
void ghiPhieuMuon(vector <PhieuMuon> PM);
void xuatPhieuMuon(vector <PhieuMuon> PM);
void traSach(vector <PhieuMuon> &PM, vector <Sach> &S, int nSoPM);
void lietKeSachBanDocDangMuon(vector <PhieuMuon> PM, vector <Sach> S, string sMa);

//Cac ham chuc nang
void cn_TimKiemThongTin();
void cn_ThongKe();
void cn_QuanLyPhieuMuon();
void cn_QuanLySach();
void cn_QuanLyBanDoc();

//Khai bao bien
int nSoPM = 0;
int PhieuMuon::nTongPM = 0;
int nChonCN = 0, nTim = 0, nQuanLy = 0, nQuanLySach = 0, nQuanLyBD = 0, nQuanLyPM = 0;
vector <Sach> S;
vector <BanDoc*> BD;
vector <Admin> Ad;
vector <PhieuMuon> PM;
string sMa = "";

//Ham main
void main()
{
	docDSSach(S);
	docDSBanDoc(BD);
	docUserPass(Ad);
	docDSPhieuMuon(PM);
	
	do
	{
		system("cls");
		menuChinh();
		color(9);
		cout << " Ban hay chon chuc nang: ";
		cin >> nChonCN;
		switch (nChonCN)
		{
		case 1:
			xuatDSSach(S);
			break;
		case 2:
			xuatDSBanDoc(BD);
			break;
		case 3:
			cn_TimKiemThongTin();
			break;
		case 4:
			login();
			do
			{
				system("cls");
				color(9);
				menuCon();
				cout << " Chon chuc nang: ";
				cin >> nQuanLy;
				switch (nQuanLy)
				{
				case 1:
					cn_QuanLyPhieuMuon();
					break;
				case 2:
					cn_QuanLySach();
					break;
				case 3:
					cn_QuanLyBanDoc();
					break;
				case 4:
					cn_ThongKe();
					break;
				default:
					color(4);
					cout << " Ban cho thoat Quan Ly!" << endl;
				}
			} while (nQuanLy >= 1 && nQuanLy <= 4);
			break;
		default:
			color(4);
			cout << " Ban chon thoat chuong trinh!" << endl;
		}
		system("PAUSE");
	} while (nChonCN >= 1 && nChonCN <= 4);
	system("PAUSE");
}

//Dinh nghia ham con

//Cac ham chuc nang
void cn_TimKiemThongTin()
{
	do
	{
		color(9);
		menuTimThongTin();
		cout << " Chon chuc nang: ";
		cin >> nTim;
		switch (nTim)
		{
		case 1:
			color(5);
			timThongTinSach(S, sMa);
			break;
		case 2:
			color(5);
			timBanDoc(BD, sMa);
			break;
		default:
			color(1);
			cout << " Ban chon thoat chuong trinh!" << endl;
		}
		system("PAUSE");
	} while (nTim >= 1 && nTim <= 2);
}
void cn_ThongKe()
{
	do
	{
		color(9);
		menuThongKe();
		cout << " Chon chuc nang: ";
		cin >> nChonCN;
		switch (nChonCN)
		{
		case 1:
			color(10);
			cout << " Tong so sach con lai trong thu vien: " << demSachCon(S) << endl;
			break;
		case 2:
			color(10);
			cout << " Tong so sach da duoc muon: " << demSachMuon(S) << endl;
			break;
		case 3:
			color(9);
			lietKeSachBanDocDangMuon(PM, S, sMa);
			break;
		case 4:
			color(9);
			cout << " So luong ban doc sinh vien: " << demBanDocSinhVien(BD) << endl;
			break;
		case 5:
			color(9);
			cout << " So luong ban doc giao vien: " << demBanDocGiaoVien(BD) << endl;
			break;
		default:
			color(1);
			cout << " Ban chon thoat chuong trinh!" << endl;
		}
		system("PAUSE");
	} while (nChonCN >= 1 && nChonCN <= 5);
}
void cn_QuanLyPhieuMuon()
{
	do
	{
		menuQuanLyPhieuMuon();
		docDSPhieuMuon(PM);
		cout << "PM: " << PM.size();
		cout << " Chon chuc nang: ";
		cin >> nQuanLyPM;
		switch (nQuanLyPM)
		{
		case 1:
			themPhieuMuon(PM, BD, S);
			break;
		case 2:
			color(11);
			traSach(PM, S, nSoPM);
			break;
		case 3:
			color(9);
			xuatPhieuMuon(PM);
			break;
		default:
			color(1);
			cout << " Ban chon thoat chuong trinh!" << endl;
		}
		system("PAUSE");
	} while (nQuanLyPM >= 1 && nQuanLyPM <= 3);
}
void cn_QuanLySach()
{
	do
	{
		color(9);
		menuQuanLySach();
		cout << " Chon chuc nang: ";
		cin >> nQuanLySach;
		switch (nQuanLySach)
		{
		case 1:
			themSach(S);
			break;
		case 2:
			color(9);
			xoaSach(S, sMa);
			break;
		default:
			color(1);
			cout << " Ban chon thoat chuong trinh!" << endl;
		}
		system("PAUSE");
	} while (nQuanLySach >= 1 && nQuanLySach <= 2);
}
void cn_QuanLyBanDoc()
{
	do
	{
		color(9);
		menuQuanLyBanDoc();
		cout << " Chon chuc nang: ";
		cin >> nQuanLyBD;
		switch (nQuanLyBD)
		{
		case 1:
			themDSBanDoc(BD);
			break;
		default:
			color(1);
			cout << " Ban chon thoat chuong trinh!" << endl;
		}
		system("PAUSE");
	} while (nQuanLyBD == 1);
}

//Danh sach phieu muon
void docDSPhieuMuon(vector <PhieuMuon> &PM)
{
	ifstream file;
	file.open("PhieuMuon.txt");
	if (file.is_open() == true)
	{
		color(2);
		cout << " Mo file Phieu Muon thanh cong!" << endl;
	}
	else
	{
		color(1);
		cout << " Khong the mo file! " << endl;
	}
	int nN = 0;
	file >> nN;
	file.ignore(1);
	PhieuMuon pm;
	for(int i = 0; i < nN; i++)
	{
		pm.readPM(file);
		PM.push_back(pm);
	}
	//cout << PM.size();
	
	file.close();
}
void themPhieuMuon(vector <PhieuMuon> &PM, vector <BanDoc*> BD, vector <Sach> S)
{
	
	string sMaBD = "";
	string sMaSach = "";
	//PM[0].outputPM();
	Date xNgayMuon, xNgayTra;
	int nA = xNgayMuon.getNgay();
	int nB = xNgayMuon.getThang();
	int nC = xNgayMuon.getNam();
	int nD = xNgayTra.getNgay();
	int nE = xNgayTra.getThang();
	int nF = xNgayTra.getNam();
	color(13);
	cout << "_____________________________THEM PHIEU MUON____________________________" << endl;
	color(7);
	while (true)
	{
		cout << " Nhap ma sach: ";
		rewind(stdin);
		getline(cin, sMaSach);
		if (sMaSach == "")
		{
			cout << " Khong duoc de trong ma sach!" << endl;
		}
		else if (kiemTraTinhTrangSach(S, sMaSach) != true)
		{
			cout << " Sach khong co trong danh sach hoac da co nguoi muon!" << endl;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		cout << " Nhap ma ban doc: ";
		rewind(stdin);
		getline(cin, sMaBD);
		if (sMaBD == "")
		{
			cout << " Khong duoc de trong ma ban doc!" << endl;
		}
		else if (kiemTraBanDoc(BD, sMaBD) != true)
		{
			cout << " Ban doc khong co trong danh sach ban doc!" << endl;
		}
		else
		{
			break;
		}
	}

	PhieuMuon newPM = PhieuMuon(sMaBD, sMaSach);
	PM.push_back(newPM);
	/*ofstream file;
	file.open("PhieuMuon.txt", ios::app);
	file << newPM.getMaPM() << "," << newPM.getMaBanDoc() << "," << newPM.getMaSach() << ","
		<< newPM.getNgayMuon().getNgay() << "," << newPM.getNgayMuon().getThang() << "," << newPM.getNgayMuon().getNam() << ","
		<< newPM.getNgayTra().getNgay() << "," << newPM.getNgayTra().getThang() << "," << newPM.getNgayTra().getNam() << ","
		<< newPM.getTrangThai() << endl;
	file.close();*/
	ghiPhieuMuon(PM);
	
	int nTT = newPM.getMaPM();
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getMaSach() == sMaSach)
		{
			S[i].setTinhTrangSach(nTT);
			break;
		}
	}
	ghiDSSach(S);

	color(2);
	cout << " Them phieu muon thanh cong!" << endl;
}
void ghiPhieuMuon(vector <PhieuMuon> PM)
{
	
	ofstream file;
	file.open("PhieuMuon.txt");
	file << PM.size() << endl;
	
	for (int i = 0; i < PM.size(); i++)
	{
		PM[i].writePM(file);
	}
	file.close();
}
void xuatPhieuMuon(vector <PhieuMuon> PM)
{
	color(8);
	cout << "_________________________DANH SACH PHIEU MUON_________________________" << endl;
	for (int i = 0; i < PM.size(); i++)
	{
		PM[i].outputPM();
		cout << endl;
	}
}
void traSach(vector <PhieuMuon> &PM, vector <Sach> &S, int nSoPM)
{
	cout << " Nhap so phieu muon de tra sach: ";
	cin >> nSoPM;
	for (int i = 0; i < PM.size(); i++)
	{
		if (nSoPM == PM[i].getMaPM() && PM[i].getTrangThai() != 0)
		{
			for (int j = 0; j < S.size(); j++)
			{
				if (PM[i].getMaSach() == S[j].getMaSach())
				{
					S[j].setTinhTrangSach(0);
					PM[i].setTrangThai(0);
					ghiDSSach(S);
					ghiPhieuMuon(PM);
				}
			}
		}
		else
		{
			cout << " Phieu muon nay da duoc tra!" << endl;
		}
	}
	color(2);
	cout << " Tra phieu muon thanh cong!" << endl;
}
void lietKeSachBanDocDangMuon(vector <PhieuMuon> PM, vector <Sach> S, string sMa)
{
	color(4);
B:
	cout << " Nhap ma ban doc can tim: ";
	rewind(stdin);
	getline(cin, sMa);
	for (int i = 0; i < PM.size(); i++)
	{
		if (PM[i].getMaBanDoc() == sMa && PM[i].getTrangThai() != 0)
		{
			for (int j = 0; j < S.size(); j++)
			{
				if (S[j].getMaSach() == PM[i].getMaSach())
				{
					S[j].xuatSach();
				}
			}
		}
		else
		{
			cout << " Ban doc chua muon sach! Nhap lai!" << endl;
			goto B;
		}
	}
}

//Danh sach sach
void themSach(vector <Sach> &S)
{
	string sMaSach, sTuaDe, sTacGia, sNhaXB;
	int nTriGia, nNamPhatHanh, nSoTrang, nTinhTrangSach;
	cout << "_______________________________THEM SACH_______________________________" << endl;
C:
	cout << " Nhap ma sach: ";
	rewind(stdin);
	getline(cin, sMaSach);
	if (timKiemSach(S, sMaSach) != -1)
	{
		cout << " Sach da co trong danh sach!" << endl;
		goto C;
	}
	cout << " Nhap tua de: ";
	rewind(stdin);
	getline(cin, sTuaDe);

	cout << " Nhap tac gia: ";
	rewind(stdin);
	getline(cin, sTacGia);

	cout << " Nhap nha xuat ban: ";
	rewind(stdin);
	getline(cin, sNhaXB);

	cout << " Nhap tri gia: ";
	cin >> nTriGia;

	cout << " Nhap nam phat hanh: ";
	cin >> nNamPhatHanh;

	cout << " Nhap so trang: ";
	cin >> nSoTrang;

	nTinhTrangSach = 0;

	Sach newB = Sach(sMaSach, sTuaDe, sTacGia, sNhaXB, nTriGia, nNamPhatHanh, nSoTrang, nTinhTrangSach);
	S.push_back(newB);
	int demS = S.size();
	demS++;
	ghiDSSach(S);
	color(10);
	cout << " Them sach thanh cong!" << endl;
}
void docDSSach(vector <Sach> &S)
{
	ifstream file;
	file.open("Sach.txt");
	if (file.is_open() == true)
	{
		color(2);
		cout << " Mo file Sach thanh cong!" << endl;
	}
	else
	{
		color(1);
		cout << " Khong the mo file! " << endl;
	}
	int nN = 0;
	file >> nN;
	file.ignore(1);
	Sach docS;
	for (int i = 0; i < nN; i++)
	{
		docS.readSach(file);
		S.push_back(docS);
	}
	file.close();
}
void xuatDSSach(vector <Sach> S)
{
	cout << "________________________DANH SACH SACH___________________________" << endl;
	for (int i = 0; i < S.size(); i++)
	{
		S[i].xuatSach();
		cout << endl;
	}
}
void timThongTinSach(vector <Sach> S, string sMa)
{
	color(5);
	cout << " Nhap ma sach can tim: ";
	rewind(stdin);
	getline(cin, sMa);
	int nFlag = 0;
	for (int i = 0; i < BD.size(); i++)
	{
		if (S[i].getMaSach() == sMa)
		{
			nFlag = 1;
			S[i].xuatSach();
		}
	}
	if (nFlag != 1)
	{
		cout << " Ma sach khong ton tai!" << endl;
	}
}
void xoaSach(vector <Sach> &S, string sMa)
{
	int nFlag = 0;
	cout << " Nhap ma sach can xoa: ";
	rewind(stdin);
	getline(cin, sMa);
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getMaSach() == sMa && S[i].getTinhTrangSach() == 0)
		{
			nFlag = 1;
			S.erase(S.begin() + i);
			int sB = S.size();
			sB--;
			ghiDSSach(S);
			cout << " Xoa sach thanh cong!" << endl;
		}
	}
	if (nFlag != 1)
	{
		color(2);
		cout << " Khong the xoa sach!" << endl;
	}
}
void ghiDSSach(vector <Sach> S)
{
	ofstream file;
	file.open("Sach.txt");
	file << S.size() << endl;
	for (int i = 0; i < S.size(); i++)
	{
		S[i].writeSach(file);
	}
	file.close();
}
int demSachCon(vector <Sach> S)
{
	int nDem = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrangSach() == 0)
		{
			nDem++;
		}
	}
	return nDem;
}
int demSachMuon(vector <Sach> S)
{
	int nDem = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrangSach() != 0)
		{
			nDem++;
		}
	}
	return nDem;
}
int timKiemSach(vector <Sach> S, string sMa)
{
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getMaSach() == sMa)
		{
			return i;
		}
	}
	return -1;
}
bool kiemTraTinhTrangSach(vector <Sach> S, string sMa)
{
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getMaSach() == sMa && S[i].getTinhTrangSach() == 0)
		{
			return true;
		}
	}
	return false;
}

//Danh sach ban doc
void docDSBanDoc(vector <BanDoc*> &BD)
{
	ifstream file;
	file.open("BanDoc.txt");
	if (file.is_open() == true)
	{
		color(2);
		cout << " Mo file Ban Doc thanh cong!" << endl;
	}
	else
	{
		color(1);
		cout << " Khong the mo file! " << endl;
	}
	int nLoaiBD = 0, nN = 0;
	file >> nN;
	file.ignore(1);
	BanDoc *p;
	for (int i = 0; i < nN; i++)
	{
		file >> nLoaiBD;
		file.ignore(1);
		if (nLoaiBD == 1)
		{
			p = new GiaoVien;
			p->readBanDoc(file);
			BD.push_back(p);
		}
		else
		{
			p = new SinhVien;
			p->readBanDoc(file);
			BD.push_back(p);
		}
	}
	file.close();
}
void xuatDSBanDoc(vector <BanDoc*> BD)
{
	color(11);
	cout << "___________________________DANH SACH BAN DOC___________________________" << endl;
	for (int i = 0; i < BD.size(); i++)
	{
		color(15);
		BD[i]->outputBanDoc();
		cout << "_______________________________________________________________________" << endl;
	}
}
void timBanDoc(vector <BanDoc*> BD, string sMa)
{
	color(4);
	cout << " Nhap ma ban doc can tim: ";
	rewind(stdin);
	getline(cin, sMa);
	for (int i = 0; i < BD.size(); i++)
	{
		if (BD[i]->getMaBD() == sMa)
		{
			BD[i]->outputBanDoc();
		}
	}
}
void themDSBanDoc(vector <BanDoc*> &BD)
{
	int nLoaiBD = 0;
	string sMaBD, sHoTen, sKhoa, sDiaChi, sSoDT, sKhoaHoc;
	Date D;
	int nNgay = D.getNgay();
	int nThang = D.getThang();
	int nNam = D.getNam();
	do
	{
		system("cls");
		color(13);
		cout << " \t\t\t______________________________THEM BAN DOC_________________________________" << endl;
		cout << " \t\t\t\t\t0. Them ban doc sinh vien." << endl;
		cout << " \t\t\t\t\t1. Them ban doc giao vien." << endl;
		cout << " \t\t\t\t\t2. Thoat!" << endl;
		cout << " \t\t\tChon chuc nang: ";
		cin >> nLoaiBD;
		if (nLoaiBD == 1)
		{
			nLoaiBD = 1;
		D:
			cout << " Nhap ma ban doc: ";
			rewind(stdin);
			getline(cin, sMaBD);

			if (timKiemBanDoc(BD, sMaBD) != -1)
			{
				cout << " Ban doc da co trong danh sach!" << endl;
				goto D;
			}

			cout << " Nhap ho ten ban doc: ";
			rewind(stdin);
			getline(cin, sHoTen);

			cout << " Nhap ten khoa: ";
			rewind(stdin);
			getline(cin, sKhoa);

			cout << " Nhap dia chi: ";
			rewind(stdin);
			getline(cin, sDiaChi);

			cout << " Nhap so dien thoai: ";
			rewind(stdin);
			getline(cin, sSoDT);

			BanDoc *GV = new GiaoVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, sDiaChi, sSoDT);
			BD.push_back(GV);
			int q = BD.size();
			q++;
			ghiDSBanDoc(BD);
			color(10);
			cout << " Them ban doc thanh cong! " << endl;
			break;
		}
		else if(nLoaiBD == 0)
		{
			nLoaiBD = 0;
		E:
			cout << " Nhap ma ban doc: ";
			rewind(stdin);
			getline(cin, sMaBD);

			if (timKiemBanDoc(BD, sMaBD) != -1)
			{
				cout << " Ban doc da co trong danh sach!" << endl;
				goto E;
			}
			cout << " Nhap ho ten ban doc: ";
			rewind(stdin);
			getline(cin, sHoTen);

			cout << " Nhap ten khoa: ";
			rewind(stdin);
			getline(cin, sKhoa);

			cout << " Nhap khoa hoc: ";
			rewind(stdin);
			getline(cin, sKhoaHoc);

			BanDoc *SV = new SinhVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, sKhoaHoc);
			BD.push_back(SV);
			int q = BD.size();
			q++;
			ghiDSBanDoc(BD);
			color(10);
			cout << " Them ban doc thanh cong! " << endl;
			break;
		}
		else if (nLoaiBD == 2)
		{
			color(1);
			cout << " Ban chon thoat chuong trinh!" << endl;
			break;
		}
		else
		{
			color(1);
			cout << " Chon sai chuc nang! Vui long chon lai." << endl;
		}
	} while (nLoaiBD >= 0 && nLoaiBD <= 2);
}
int timKiemBanDoc(vector <BanDoc*> BD, string sMa)
{
	for (int i = 0; i < BD.size(); i++)
	{
		if (BD[i]->getMaBD() == sMa)
		{
			return i;
		}
	}
	return -1;
}
void ghiDSBanDoc(vector <BanDoc*> BD)
{
	ofstream file;
	file.open("BanDoc.txt");
	file << BD.size() << endl;
	for (int i = 0; i < BD.size(); i++)
	{
		BD[i]->writeBanDoc(file);
	}
	file.close();
}
bool kiemTraBanDoc(vector <BanDoc*> BD, string sMa)
{
	for (int i = 0; i < BD.size(); i++)
	{
		if (BD[i]->getMaBD() == sMa)
		{
			return true;
		}
	}
	return false;
}
int demBanDocSinhVien(vector <BanDoc*> BD)
{
	int nDem = 0;
	int nLoai = 0;
	string sMaBD = "";
	ifstream File;
	File.open("BanDoc.txt");
	int nN = 0;
	File >> nN;
	File.ignore(1);
	for(int i = 0; i < nN; i++)
	{
		File >> nLoai;
		File.ignore(1, ',');
		if (nLoai == 1)
		{
			getline(File, sMaBD, '\n');
		}
		else if (nLoai == 0)
		{
			nDem++;
			getline(File, sMaBD, '\n');
		}
	}
	return nDem;
}
int demBanDocGiaoVien(vector <BanDoc*> BD)
{
	int nDem = 0;
	int nLoai = 0;
	string sMaBD = "";
	string sHoTen = "";
	string sKhoa = "";
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	string sDC = "";
	string sSDT = "";
	int nKhoaHoc = 0;
	ifstream File;
	File.open("BanDoc.txt");
	int nN = 0;
	File >> nN;
	File.ignore(1);
	for (int i = 0; i < nN; i++)
	{
		File >> nLoai;
		File.ignore(1, ',');
		if (nLoai == 1)
		{
			nDem++;
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			getline(File, sDC, ',');
			getline(File, sSDT, '\n');
		}
		else if (nLoai == 0)
		{
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			File >> nKhoaHoc;
			File.ignore(1, '\n');
		}
	}
	File.close();
	return nDem;
}
//User
void docUserPass(vector <Admin> &Ad)
{
	ifstream fin;
	fin.open("Admin.txt");
	if (fin.is_open() == true)
	{
		color(2);
		cout << " Mo file Admin thanh cong!" << endl;
	}
	else
	{
		color(1);
		cout << " Khong the mo file!" << endl;
	}
	Admin q;
	while (!fin.eof()) //end of file
	{
		q.readAdmin(fin);
		Ad.push_back(q);
	}
	fin.close();
}
void xuatUserPass(vector <Admin> Ad)
{
	cout << "__________________________DANH SACH ADMIN_______________________________" << endl;
	for (int i = 0; i < Ad.size(); i++)
	{
		cout << Ad[i];
		cout << endl;
	}
}
void login()
{
	string sUser = "", sPass = "";
	cout << "__________________________DANG NHAP__________________________" << endl;
A:
	color(7);
	cout << " Nhap N de thoat! " << endl;
	color(9);
	cout << " Nhap User: ";
	rewind(stdin);
	getline(cin, sUser);

	cout << " Nhap mat khau: ";
	rewind(stdin);
	getline(cin, sPass);
	if (sUser == "N" || sPass == "N")
	{
		return;
	}
	if (kiemTraDangNhap(Ad, sUser, sPass) == true)
	{
		cout << " Dang nhap thanh cong!" << endl;
	}
	else
	{
		cout << " Dang nhap khong thanh cong!" << endl;
		goto A;
	}
}
bool kiemTraDangNhap(vector <Admin> Ad, string sUser, string sPass)
{
	for (int i = 0; i < Ad.size(); i++)
	{
		if (Ad[i].getUser() == sUser && Ad[i].getpass() == sPass)
		{
			return true;
		}
	}
	return false;
}

//Menu
void menuChinh()
{
	system("cls");
	color(13);
	cout << " \t\t\t______________________________MENU_________________________________" << endl;
	cout << " \t\t\t\t\t1. Hien thi thong tin sach." << endl;
	cout << " \t\t\t\t\t2. Hien thi thong tin ban doc." << endl;
	cout << " \t\t\t\t\t3. Tim kiem thong tin sach va ban doc." << endl;
	cout << " \t\t\t\t\t4. Quan Ly." << endl;
	cout << " \t\t\t\t\t5. Thoat!" << endl;
}
void menuCon()
{
	system("cls");
	color(10);
	cout << " \t\t\t______________________________QUAN LY_________________________________" << endl;
	cout << " \t\t\t\t\t1. Quan ly phieu muon." << endl;
	cout << " \t\t\t\t\t2. Quan ly sach." << endl;
	cout << " \t\t\t\t\t3. Quan ly ban doc." << endl;
	cout << " \t\t\t\t\t4. Thong ke." << endl;
	cout << " \t\t\t\t\t5. Thoat!" << endl;
}
void menuTimThongTin()
{
	system("cls");
	color(14);
	cout << " \t\t\t______________________________TIM THONG TIN_________________________________" << endl;
	cout << " \t\t\t\t\t1. Tim sach theo ma sach." << endl;
	cout << " \t\t\t\t\t2. Tim ban doc theo ma ban doc." << endl;
	cout << " \t\t\t\t\t3. Thoat!" << endl;
}
void menuQuanLySach()
{
	system("cls");
	color(6);
	cout << " \t\t\t______________________________QUAN LY SACH_________________________________" << endl;
	cout << " \t\t\t\t\t1. Them sach." << endl;
	cout << " \t\t\t\t\t2. Xoa sach." << endl;
	cout << " \t\t\t\t\t3. Thoat!" << endl;
}
void menuQuanLyBanDoc()
{
	system("cls");
	color(5);
	cout << " \t\t\t______________________________QUAN LY BAN DOC_________________________________" << endl;
	cout << " \t\t\t\t\t1. Them ban doc." << endl;
	cout << " \t\t\t\t\t2. Thoat!" << endl;
}
void menuQuanLyPhieuMuon()
{
	system("cls");
	color(4);
	cout << " \t\t\t______________________________QUAN LY PHIEU MUON_________________________________" << endl;
	cout << " \t\t\t\t\t1. Tao phieu muon moi." << endl;
	cout << " \t\t\t\t\t2. Tra sach." << endl;
	cout << " \t\t\t\t\t3. In danh sach phieu muon." << endl;
	cout << " \t\t\t\t\t4. Thoat!" << endl;
}
void menuThongKe()
{
	system("cls");
	color(3);
	cout << " \t\t\t______________________________THONG KE_________________________________" << endl;
	cout << " \t\t\t\t\t1. Tong so sach con lai trong thu vien." << endl;
	cout << " \t\t\t\t\t2. Tong so sach da duoc muon." << endl;
	cout << " \t\t\t\t\t3. Liet ke sach ma mot ban doc dang muon." << endl;
	cout << " \t\t\t\t\t4. So luong ban doc sinh vien." << endl;
	cout << " \t\t\t\t\t5. So luong ban doc giao vien." << endl;
	cout << " \t\t\t\t\t6. Thoat!" << endl;
}

//Ham mau
void color(int nX)
{
	HANDLE hc;
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, nX);
}