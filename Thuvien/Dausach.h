#ifndef Dausach
#define Dausach
#include "Data.h"
#include "Themxoahieuchinhdocgia.h" 
#include "Ngaythang.h"
void Xuat_thong_tin_1_dau_sach(DAU_SACH *dau_sach);
	using namespace std;
// Dau sach
bool Kiem_tra_rong_ds_dau_sach(DS_DAU_SACH ds_dau_sach) // Danh sach dau sach hien tai dang rong (true) hay da co phan tu (false)?
{
	if (ds_dau_sach.so_luong == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Kiem_tra_day_ds_dau_sach(DS_DAU_SACH ds_dau_sach) // Danh sach dau sach day (true) thi khong cho them nua
{
	if (ds_dau_sach.so_luong == MAX_DAU_SACH)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Kiem_tra_ki_tu_ISBN(string isbn) // Chi cho nhap so hoac chu cai
{
	for (int i = 0; i < isbn.length(); i++)
	{
		if ((isbn[i] < 65 || isbn[i] > 90) && (isbn[i] < 48 || isbn[i] > 57 ) && (isbn[i] < 97 || isbn[i] > 122))
		{
			return false;
		}
	}
	return true;
}
bool Kiem_tra_trung_ISBN(DS_DAU_SACH ds_dau_sach, string isbn) 
{
	for (int i = 0; i < ds_dau_sach.so_luong; i++)
	{
		if (ds_dau_sach.list[i]->ISBN == isbn)
		{ 
			return true;
		}
	}
	return false;
}
int Kiem_tra_dau_sach(DS_DAU_SACH ds_dau_sach, string a)
{
	for (int i = 0; i < ds_dau_sach.so_luong; i++)
	{
		// Kiem tra xem dau sach co ton tai khong
		if (ds_dau_sach.list[i]->ISBN == a)
		{
			// Kiem tra xem dau sach do da co sach chua
			if (ds_dau_sach.list[i]->Check == false)
			{
				return i;
			}
		}
	}
	return -1;
}
bool Kiem_tra_ten_sach(DS_DAU_SACH ds_dau_sach, string a)
{
	for (int i = 0; i < ds_dau_sach.so_luong; i++)
	{
		if (ds_dau_sach.list[i]->Ten_sach == a)
		{
			return true;
		}
	}
	return false;
}
void Them_dau_sach(DS_DAU_SACH &ds_dau_sach)
{
	ShowCur(1);
	if (Kiem_tra_day_ds_dau_sach(ds_dau_sach) == true) // Neu danh sach day thi khong cho thep nua
	{
		thong_bao("Danh sach da day.");
		return;
	}
	else
	{
		DAU_SACH *p = new DAU_SACH;
		gotoxy(30,9);
		cout << "Nhap ISBN: ";
		//cin.ignore();
		do
		{
			
			getline(cin, p->ISBN);
			if (Kiem_tra_ki_tu_ISBN(p->ISBN) == false)
			{
				do
				{
					thong_bao("Ma ISBN khong hop le. Xin sua lai.");
					gotoxy(41,9);
					getline(cin, p->ISBN);
				}while (Kiem_tra_ki_tu_ISBN(p->ISBN) == false);
			}
			if (p->ISBN.length() != 4)
			{
				do
				{
					thong_bao("Ma ISBN phai co 4 ki tu. Xin nhap lai.");
					gotoxy(41,9);
					getline(cin, p->ISBN);
				}while (p->ISBN.length() != 4);
			}
			if (Kiem_tra_trung_ISBN(ds_dau_sach, p->ISBN) == true)
			{
				thong_bao("Ma ISBN da ton tai. Xin nhap lai ma khac.");
				gotoxy(41,9);
			}
		}while (Kiem_tra_trung_ISBN(ds_dau_sach, p->ISBN) == true);
		gotoxy(30,11);
		cout << "Nhap ten sach: ";
		getline(cin, p->Ten_sach);
		gotoxy(30,13);
		cout << "Cho biet so trang: ";
		cin >> p->So_trang;
		gotoxy(30,15);
		cout << "Nhap ten tac gia: ";
		cin.ignore();
		getline(cin, p->Tac_gia);
		int namhientai = Lay_nam_he_thong();
		gotoxy(30,17);
		cout << "Nhap nam xuat ban: ";
		do
		{
			cin >> p->Nam_xuat_ban;
			if (p->Nam_xuat_ban > namhientai)
			{
				thong_bao("Nam xuat ban khong the lon hon nam hien tai. Xin kiem tra lai.");
				gotoxy(49,17);
			}
		}while (p->Nam_xuat_ban > namhientai);
		gotoxy(30,19);
		cout << "Nhap the loai: ";
		cin.ignore();
		getline(cin, p->The_loai);
		Chuan_hoa_chu(p->Tac_gia);
		Chuan_hoa_chu(p->Ten_sach);
		Chuan_hoa_chu(p->The_loai);
		ds_dau_sach.list[ds_dau_sach.so_luong] = p;
		ds_dau_sach.so_luong++;
		thong_bao("Them thanh cong.");
	}
}
void Xoa_dau_sach(DS_DAU_SACH &ds_dau_sach)
{
	ShowCur(1);
	gotoxy(30,8); textcolor(12);
	cout << "LUU Y: Neu dau sach hien van con sach thi khong the xoa."; textcolor(15);
	string a;
	gotoxy(30,10);
	cout << "Nhap ma ISBN cua sach: ";
	//cin.ignore();
	getline(cin, a);
	int vitri = Kiem_tra_dau_sach(ds_dau_sach, a);
	if (vitri < 0)
	{
		thong_bao("Dau sach khong ton tai hoac van con sach. Khong xoa duoc.");
		return;
	}
	else
	{
		// 	C1: 
		// B1: Doi vi tri
		for (int i = vitri; i < ds_dau_sach.so_luong-1; i++)
		{
			ds_dau_sach.list[i]->ISBN = ds_dau_sach.list[i+1]->ISBN;
			ds_dau_sach.list[i]->Ten_sach = ds_dau_sach.list[i+1]->Ten_sach;
			ds_dau_sach.list[i]->So_trang = ds_dau_sach.list[i+1]->So_trang;
			ds_dau_sach.list[i]->Tac_gia = ds_dau_sach.list[i+1]->Tac_gia;
			ds_dau_sach.list[i]->Nam_xuat_ban = ds_dau_sach.list[i+1]->Nam_xuat_ban;
			ds_dau_sach.list[i]->The_loai = ds_dau_sach.list[i+1]->The_loai;
		}
		// B2: Giai phong 
		DAU_SACH *tam = ds_dau_sach.list[ds_dau_sach.so_luong-1];
		// Giam so luong
		ds_dau_sach.so_luong--;
		thong_bao("Da xoa xong.");
		
		// 	C2: (Loi, chua fix duoc)
		// Xoa vi tri cuoi mang
		/*if (ds_dau_sach.list[ds_dau_sach.so_luong-1]->ISBN == a)
		{
			delete ds_dau_sach.list[ds_dau_sach.so_luong-1];
			ds_dau_sach.list[ds_dau_sach.so_luong-1-1] = NULL; // Tranh tinh trang con tro bi treo
			ds_dau_sach.so_luong--;
			return;
		}
		delete ds_dau_sach.list[vitri]; // Quan trong 
		for (int i = vitri + 1; i < ds_dau_sach.so_luong-1; i++)
		{
			ds_dau_sach.list[i-1] = ds_dau_sach.list[i]; 
		}
		delete ds_dau_sach.list[ds_dau_sach.so_luong-1-1];
		ds_dau_sach.list[ds_dau_sach.so_luong-1-1] = NULL; // Tranh tinh trang con tro bi treo
		ds_dau_sach.so_luong--;*/
	}
}
void Hieu_chinh_dau_sach(DS_DAU_SACH &ds_dau_sach)
{
	ShowCur(1);
	string a;
	gotoxy(30,9);
	cout << "Nhap ma ISBN cua sach: ";
	//cin.ignore();
	getline(cin, a);
	if (Kiem_tra_trung_ISBN(ds_dau_sach, a) == false)
	{
		thong_bao("Dau sach khong ton tai, khong the hieu chinh.");
		return;
	}	
	for (int i = 0; i < ds_dau_sach.so_luong; i++)
	{
		if (ds_dau_sach.list[i]->ISBN == a) 
		{
			gotoxy(60,11);
			cout << "THONG TIN DAU SACH";
			Xuat_thong_tin_1_dau_sach(ds_dau_sach.list[i]);
			gotoxy(59,19);
			cout << "CHINH SUA THONG TIN";
			/*cout << "Nhap ISBN: ";
			do
			{
				getline(cin, ds_dau_sach.list[i]->ISBN);
				if (Kiem_tra_ki_tu_ISBN(ds_dau_sach.list[i]->ISBN) == false)
				{
					cout << "Ma ISBN khong hop le. Xin sua lai.\n";
					cout << "Sua lai ma ISBN: ";
				}
			}while (Kiem_tra_ki_tu_ISBN(ds_dau_sach.list[i]->ISBN) == false);
			// (Chua lam duoc) Truong hop ma moi sua lai bi trung voi ma co trong danh sach
			/*while (Kiem_tra_trung_ISBN(ds_dau_sach, ds_dau_sach.list[i]->ISBN) == true) 
			{
				cout << "Ma ISBN da ton tai. Xin nhap lai.\n";
				cout << "Nhap lai ma ISBN: ";
				getline(cin, ds_dau_sach.list[i]->ISBN);
			}*/
			gotoxy(30,20);
			cout << "Nhap ten sach: ";
			getline(cin, ds_dau_sach.list[i]->Ten_sach);
			gotoxy(30,21);
			cout << "Cho biet so trang: ";
			cin >> ds_dau_sach.list[i]->So_trang;
			cin.ignore();
			gotoxy(30,22);
			cout << "Nhap ten tac gia: ";
			getline(cin, ds_dau_sach.list[i]->Tac_gia);
			int namhientai = Lay_nam_he_thong();
			gotoxy(30,23);
			cout << "Nhap nam xuat ban: ";
			do
			{
				cin >> ds_dau_sach.list[i]->Nam_xuat_ban;
				if (ds_dau_sach.list[i]->Nam_xuat_ban > namhientai)
				{
					thong_bao("Nam xuat ban khong the lon hon nam hien tai. Xin kiem tra lai.");
					gotoxy(49,23);
				}
			}while (ds_dau_sach.list[i]->Nam_xuat_ban > namhientai);
			gotoxy(30,24);
			cout << "Nhap the loai: ";
			cin.ignore();
			getline(cin, ds_dau_sach.list[i]->The_loai);
			Chuan_hoa_chu(ds_dau_sach.list[i]->Tac_gia);
			Chuan_hoa_chu(ds_dau_sach.list[i]->Ten_sach);
			Chuan_hoa_chu(ds_dau_sach.list[i]->The_loai);
			thong_bao("Hieu chinh thanh cong.");
			return;	
		}
	}
}
void Xuat_thong_tin_1_dau_sach(DAU_SACH *dau_sach)
{
	gotoxy(30, 12);
	cout << "ISBN: " << dau_sach->ISBN;
	gotoxy(30, 13);
	cout << "Ten sach: " << dau_sach->Ten_sach;
	gotoxy(30, 14);
	cout << "So trang: " << dau_sach->So_trang;
	gotoxy(30, 15);
	cout << "Tac gia: " << dau_sach->Tac_gia;
	gotoxy(30, 16);
	cout << "Nam xuat ban: " << dau_sach->Nam_xuat_ban;
	gotoxy(30, 17);
	cout << "The loai: " << dau_sach->The_loai; 
}
void Xuat_thong_tin_1_dau_sach_theo_hang(DAU_SACH *dau_sach, int dong_bat_dau, int dem)
{
	gotoxy(8, dong_bat_dau+dem);
	cout << dau_sach->ISBN;
	gotoxy(16, dong_bat_dau+dem);
	cout << dau_sach->Ten_sach;
	gotoxy(51, dong_bat_dau+dem);
	cout << dau_sach->So_trang;
	gotoxy(62, dong_bat_dau+dem);
	cout << dau_sach->Tac_gia;
	gotoxy(93, dong_bat_dau+dem);
	cout << dau_sach->Nam_xuat_ban;
	gotoxy(104, dong_bat_dau+dem);
	cout << dau_sach->The_loai;
	gotoxy(121, dong_bat_dau+dem);
	cout << dau_sach->So_lan_muon;  
}
void Xuat_dms_cua_1_dau_sach(DS_DANH_MUC_SACH ds_dms)
{
	for (NODE_DANH_MUC_SACH *k = ds_dms.pHead; k != NULL; k = k->pNext)
	{
		cout << "Ma sach: " << k->data.Ma_sach << endl;
		if (k->data.Trang_thai == 0)
		{
			cout << "Trang thai: " << k->data.Trang_thai << " (Cho muon duoc)" << endl;
		}
		else if (k->data.Trang_thai == 1)
		{
			cout << "Trang thai: " << k->data.Trang_thai << " (Da co nguoi muon)" << endl;
		}
		else
		{
			cout << "Trang thai: " << k->data.Trang_thai << " (Sach da thanh ly)" << endl;
		}
		cout << "Vi tri: " << k->data.Vi_tri << endl << endl;	
	}
}
void Xuat_thong_tin_cac_dau_sach(DS_DAU_SACH ds_dau_sach)
{
	khung_xuat_thong_tin_ds(5, 7, 25);
	for (int i = 0; i < ds_dau_sach.so_luong; i++)
	{
//		cout << "\tDAU SACH THU " << i + 1 << endl;
		Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[i], 10, i);
//		cout << "\tDANH MUC SACH TUONG UNG\n";
//		Xuat_dms_cua_1_dau_sach(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach);
//		cout << endl;
	}
	thong_bao("                                     ");
}
// Danh muc sach
NODE_DANH_MUC_SACH* Khoi_tao_node(DANH_MUC_SACH dms)
{
	NODE_DANH_MUC_SACH *p = new NODE_DANH_MUC_SACH;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat.\n";
		return NULL;
	}
	else
	{
		p->pNext = NULL;
		p->data = dms;
		return p;
	}
}
void Them_vao_dau_danh_sach_dms(DS_DANH_MUC_SACH &ds_dms, NODE_DANH_MUC_SACH *p)
{
	if (ds_dms.pHead == NULL)
	{
		ds_dms.pHead = ds_dms.pTail = p;
	}
	else
	{
		p->pNext = ds_dms.pHead;
		ds_dms.pHead = p;
	}
}
void Them_vao_cuoi_danh_sach_dms(DS_DANH_MUC_SACH &ds_dms, NODE_DANH_MUC_SACH *p)
{
	if (ds_dms.pHead == NULL)
	{
		ds_dms.pHead = ds_dms.pTail = p;
	}
	else
	{
		ds_dms.pTail->pNext = p;
		ds_dms.pTail = p;
	}
}
void Xoa_dau_danh_sach_dms(DS_DANH_MUC_SACH &ds_dms)
{
	if (ds_dms.pHead == NULL)
	{
		return;
	}
	else
	{
		NODE_DANH_MUC_SACH *p = ds_dms.pHead;
		ds_dms.pHead = ds_dms.pHead->pNext;
		delete p;
	}
}
void Xoa_cuoi_danh_sach_dms(DS_DANH_MUC_SACH &ds_dms)
{
	if (ds_dms.pHead == NULL)
	{
		return;
	}
	else if (ds_dms.pHead == ds_dms.pTail)
	{
		Xoa_dau_danh_sach_dms(ds_dms);
	}
	else
	{
		for (NODE_DANH_MUC_SACH *k = ds_dms.pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext == ds_dms.pTail)
			{
				delete ds_dms.pTail;
				k->pNext = NULL;
				ds_dms.pTail = k;
				return;
			}
		}
	}
}
void Xoa_1_sach_theo_ma_sach(DS_DANH_MUC_SACH &ds_dms, string a)
{
	if (ds_dms.pHead->data.Ma_sach == a)
	{
		Xoa_dau_danh_sach_dms(ds_dms);
	}
	if (ds_dms.pTail->data.Ma_sach == a)
	{
		Xoa_cuoi_danh_sach_dms(ds_dms);
	}
	NODE_DANH_MUC_SACH *g = new NODE_DANH_MUC_SACH;
	for (NODE_DANH_MUC_SACH *k = ds_dms.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.Ma_sach == a)
		{
			g->pNext = k->pNext;
			delete k;	
		}	
		g = k;
	} 
}
/*bool Kiem_tra_trang_thai_sach(NODE_DANH_MUC_SACH *p)
{
	for (NODE_DANH_MUC_SACH *k = p; k != NULL; k = k->pNext)
	{
		if (k->data.Trang_thai == 1) // Sach da co nguoi muon
		{
			return true;
		}
	}
	return false;
}*/
bool Kiem_tra_trung_ma_sach(DS_DANH_MUC_SACH ds_dms, string masach)
{
	for (NODE_DANH_MUC_SACH *k = ds_dms.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.Ma_sach == masach)
		{
			return true;
		}
	}
	return false;
}
void Them_sach(DS_DANH_MUC_SACH &ds_dms, DS_DAU_SACH ds_dau_sach)
{
	ShowCur(1);
	string a;
	gotoxy(30, 9);
	cout << "Nhap ma ISBN: ";
	//cin.ignore();
	getline(cin, a);
	if (Kiem_tra_trung_ISBN(ds_dau_sach, a) == false)
	{
		thong_bao("Dau sach khong ton tai. Khong the them.");
		return;
	}	
	for (int i = 0; i < ds_dau_sach.so_luong; i++)
	{
		if (ds_dau_sach.list[i]->ISBN == a)
		{
			int stt = ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach.so_luong;
			DANH_MUC_SACH dms;
			// Danh ma tu dong
			// masach = ISBN + stt. VD: AAAA1, AAAA2, AAAA3,...
			string masach = ds_dau_sach.list[i]->ISBN + to_string(stt); // to_string: Chuyen kieu int thanh string. Neu Dev-C++ khong dung duoc: Tools -> Compiler options...-> Settings -> Code Generation -> Language Standard -> Doi thanh ISO C++11 hoac GNU C++11
			// Neu ma trung thi tu dong tang len
			while (Kiem_tra_trung_ma_sach(ds_dms, masach) == true)
			{
				stt++;
				masach = ds_dau_sach.list[i]->ISBN + to_string(stt);
			}
			dms.Ma_sach = masach;
			gotoxy(30, 11);
			cout << "Ma sach: " << dms.Ma_sach;
			dms.Trang_thai = 0;
			gotoxy(30,13);
			cout << "Trang thai: " << dms.Trang_thai << " (Cho muon duoc)";
			gotoxy(30, 15);
			cout << "Nhap vi tri: ";
			getline(cin, dms.Vi_tri);	
			NODE_DANH_MUC_SACH *p = Khoi_tao_node(dms);
			Them_vao_cuoi_danh_sach_dms(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach, p);
			ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach.so_luong++;
			ds_dau_sach.list[i]->Check = true; // <=> Dau sach nay hien tai da co sach => Khong duoc xoa 
			thong_bao("Them thanh cong.");
			return;
		}
	}
}
void Xoa_sach(DS_DANH_MUC_SACH &ds_dms, DS_DAU_SACH ds_dau_sach)
{
	ShowCur(1);
	string isbn;
	gotoxy(30, 9);
	cout << "Nhap ma ISBN: ";
	//cin.ignore();
	getline (cin, isbn);
	if (Kiem_tra_trung_ISBN(ds_dau_sach, isbn) == false)
	{
		thong_bao("Dau sach khong ton tai.");
		return;
	}	
	for (int i = 0; i < ds_dau_sach.so_luong; i++)
	{
		if (ds_dau_sach.list[i]->ISBN == isbn)
		{
			cout << "\tDANH MUC SACH TUONG UNG\n";
			Xuat_dms_cua_1_dau_sach(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach);
			string a;
			cout << "Nhap ma sach: ";
			getline(cin, a);
			if (Kiem_tra_trung_ma_sach(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach, a) == false)
			{
				thong_bao("Sach khong ton tai.");
				return;	
			}		
			else
			{
				Xoa_1_sach_theo_ma_sach(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach, a);
				ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach.so_luong--;
				if (ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach.so_luong == 0)
				{
					ds_dau_sach.list[i]->Check = false; // <=> Dau sach nay hien tai khong con sach. Co the xoa 
				}
				thong_bao("Da xoa xong.");
				return;
			}
		}
	}
}
void Hieu_chinh_sach(DS_DANH_MUC_SACH &ds_dms, DS_DAU_SACH ds_dau_sach)
{
	ShowCur(1);
	string isbn;
	gotoxy(30,9);
	cout << "Nhap ma ISBN: ";
	//cin.ignore();
	getline (cin, isbn);
	if (Kiem_tra_trung_ISBN(ds_dau_sach, isbn) == false)
	{
		thong_bao("Dau sach khong ton tai.");
		return;
	}	
	for (int i = 0; i < ds_dau_sach.so_luong; i++)
	{
		if (ds_dau_sach.list[i]->ISBN == isbn)
		{
			cout << "\tTHONG TIN SACH\n";
			Xuat_thong_tin_1_dau_sach(ds_dau_sach.list[i]);
			cout << "\tDANH MUC SACH TUONG UNG\n";
			Xuat_dms_cua_1_dau_sach(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach);
			string a;
			cout << "Nhap ma sach: ";
			getline(cin, a);
			if (Kiem_tra_trung_ma_sach(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach, a) == false)
			{
				cout << "Sach khong ton tai.\n";
				return;
			}
			for (NODE_DANH_MUC_SACH *k = ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach.pHead; k != NULL; k = k->pNext)
			{
				if (Kiem_tra_trung_ma_sach(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach, a) == true)
				{
					//cout << "Nhap lai ma moi: ";
					//getline(cin, k->data.Ma_sach);
					cout << "Nhap trang thai sach: ";
					do
					{
						cin >> k->data.Trang_thai;
						if (k->data.Trang_thai == 0)
						{
							cout << "=> Cho muon duoc.\n";
							break;
						}
						else if (k->data.Trang_thai == 1)
						{
							cout << "=> Da co nguoi muon.\n";
							break;
						}
						else if (k->data.Trang_thai == 2)
						{
							cout << "=> Sach da thanh ly.\n";
							break;
						}
						else
						{
							cout << "Ma sach khong hop le. Xin nhap lai.\n";
							cout << "Nhap lai ma sach: ";
						}
					}while (k->data.Trang_thai != 0 && k->data.Trang_thai != 1 && k->data.Trang_thai != 2);
					cout << "Nhap vi tri: ";
					cin.ignore();
					getline(cin, k->data.Vi_tri);
					cout << "Hieu chinh thanh cong.\n";
					return;
				}
			}
		}
	}
}

// Sap xep
void Sap_Xep_Dau_Sach_Theo_Ten(DS_DAU_SACH &dau_sach)
{
    DAU_SACH *tam = NULL;
    for(int i=0; i<dau_sach.so_luong-1; i++)
    {
        for(int j = i + 1; j <= dau_sach.so_luong-1; j++)
        {
            if(dau_sach.list[i]->Ten_sach > dau_sach.list[j]->Ten_sach)
            {
                tam = dau_sach.list[i];
                dau_sach.list[i] = dau_sach.list[j];
                dau_sach.list[j] = tam;
            }
        }
    }
}
void Xuat_DS_1_The_Loai(DS_DAU_SACH ds, string the_loai)
{
    cout<<"\n\n\t\tThe loai "<<the_loai<<endl;
    int stt = 1;
    for(int i=0; i<ds.so_luong; i++)
    {
        if(ds.list[i]->The_loai == the_loai)
        {
        	cout << "\tDau sach thu " << stt++ << endl;
            /*cout<< ds.list[i]->ISBN<<endl;
            cout<<ds.list[i]->Nam_xuat_ban<<endl;
            cout<<ds.list[i]->So_trang<<endl;
            cout<<ds.list[i]->Tac_gia<<endl;
            cout<<ds.list[i]->Ten_sach<<endl;
            cout<<ds.list[i]->The_loai<<endl;*/
            Xuat_thong_tin_1_dau_sach(ds.list[i]);
        }
    }
}
bool Kiem_Tra_Trung_The_Loai(DS_DAU_SACH ds,string theloai[],int soluong[],int h,int i) // h: So luong the loai hien co
{
	for (int j = 0; j < h; j++) // Duyet danh sach so luong the loai hien co
	{
		if (ds.list[i]->The_loai == theloai[j])
		{
			soluong[j]++; //tang so luong phan tu cua 1 the loai them 1
			return false;
		}
	}
	return true;
}
void Xuat_DS_Theo_Tung_The_Loai(DS_DAU_SACH ds)
{
    if(ds.so_luong == 0)
    {
        thong_bao("Thu vien chua co sach nao.");
        return;
    }
    Sap_Xep_Dau_Sach_Theo_Ten(ds);
    string the_loai[100]; // Tao 1 mang chua toi da 100 the loai 
    int soluong[100]; // So luong sach cua tung the loai
	int h = 0; // So luong the loai hien co    
	the_loai[0] = ds.list[0]->The_loai; // The loai dau tien = the loai cua dau sach dau tien trong danh sach dau sach 
    h=1;  
    for(int i=1; i<ds.so_luong; i++)
    {
        if(Kiem_Tra_Trung_The_Loai(ds, the_loai, soluong, h, i))
        {
            the_loai[h++] = ds.list[i]->The_loai;
        }
    }
    for(int i=0; i<h; i++)
    {
        Xuat_DS_1_The_Loai(ds, the_loai[i]);
    }
}
void Tim_thong_tin_sach_dua_vao_ten_sach(DS_DAU_SACH ds_dau_sach, DS_DANH_MUC_SACH ds_dms)
{
	ShowCur(1);
	string a;
	gotoxy(30,8);
	cout << "Nhap ten sach can tim kiem: ";
	//cin.ignore();
	getline(cin, a);
	Chuan_hoa_chu(a);
	if (Kiem_tra_ten_sach(ds_dau_sach, a) == false)
	{
		thong_bao("Dau sach khong ton tai.");
		return;
	}
	khung_xuat_thong_tin_ds(5, 11, 4);
	for (int i = 0; i < ds_dau_sach.so_luong; i++)
	{
		if (ds_dau_sach.list[i]->Ten_sach == a)
		{
			gotoxy(60,10);
			cout << "THONG TIN SACH";
			Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[i], 14, 0);
			thong_bao("                                     ");
			return;
		}
	}
}
void Sap_xep_dau_sach_tang_dan_theo_so_lan_muon(DS_DAU_SACH &ds_dau_sach)
{
	for (int i = 0; i < ds_dau_sach.so_luong-1; i++)
	{
		for (int j = i + 1; j <= ds_dau_sach.so_luong-1; j++)
		{
			if (ds_dau_sach.list[i]->So_lan_muon > ds_dau_sach.list[j]->So_lan_muon)
			{
				DAU_SACH *t = ds_dau_sach.list[i];
				ds_dau_sach.list[i] = ds_dau_sach.list[j];
				ds_dau_sach.list[j] = t;
			}
		}
	}
}
void Top_10_sach(DS_DAU_SACH ds_dau_sach)
{
	Sap_xep_dau_sach_tang_dan_theo_so_lan_muon(ds_dau_sach);
	int stt = 1;
	int dem=0;
	khung_xuat_thong_tin_ds(5, 7, 13);
	if (ds_dau_sach.so_luong < 10)
	{
		for (int i = ds_dau_sach.so_luong-1; i>=0; i--)
		{	
			//cout << "\n\tDAU SACH THU " << stt++ << endl;
			Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[i], 10, dem);
			dem++;	
			//cout << "So lan muon: " << ds_dau_sach.list[i]->So_lan_muon << endl;
		}
		thong_bao("                                     ");
	}
	else
	{
		int vitri = ds_dau_sach.so_luong - 10;
		for (int i = ds_dau_sach.so_luong-1; i>=vitri; i--)
		{
			//cout << "\n\tDAU SACH THU " << stt++ << endl;
			Xuat_thong_tin_1_dau_sach_theo_hang(ds_dau_sach.list[i], 10, dem);	dem++;
			//cout << "So lan muon: " << ds_dau_sach.list[i]->So_lan_muon << endl;
		}			
		thong_bao("                                     ");
	}
}
#endif
