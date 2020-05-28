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
	if (Kiem_tra_day_ds_dau_sach(ds_dau_sach) == true) // Neu danh sach day thi khong cho thep nua
	{
		return;
	}
	else
	{
		DAU_SACH *p = new DAU_SACH;
		cout << "Nhap ISBN: ";
		cin.ignore();
		do
		{
			getline(cin, p->ISBN);
			if (Kiem_tra_ki_tu_ISBN(p->ISBN) == false)
			{
				do
				{
					cout << "Ma ISBN khong hop le. Xin sua lai.\n";
					cout << "Sua lai ma ISBN: ";
					getline(cin, p->ISBN);
				}while (Kiem_tra_ki_tu_ISBN(p->ISBN) == false);
			}
			if (p->ISBN.length() != 4)
			{
				do
				{
					cout << "Ma ISBN phai co 4 ki tu. Xin nhap lai.\n";
					cout << "Nhap lai ma ISBN: ";
					getline(cin, p->ISBN);
				}while (p->ISBN.length() != 4);
			}
			if (Kiem_tra_trung_ISBN(ds_dau_sach, p->ISBN) == true)
			{
				cout << "Ma ISBN da ton tai. Xin nhap lai ma khac.\n";
				cout << "Nhap lai ma ISBN: ";
			}
		}while (Kiem_tra_trung_ISBN(ds_dau_sach, p->ISBN) == true);
		cout << "Nhap ten sach: ";
		getline(cin, p->Ten_sach);
		cout << "Cho biet so trang: ";
		cin >> p->So_trang;
		cout << "Nhap ten tac gia: ";
		cin.ignore();
		getline(cin, p->Tac_gia);
		int namhientai = Lay_nam_he_thong();
		cout << "Nhap nam xuat ban: ";
		do
		{
			cin >> p->Nam_xuat_ban;
			if (p->Nam_xuat_ban > namhientai)
			{
				cout << "=> Nam xuat ban khong the lon hon nam hien tai. Xin kiem tra lai.\n";
				cout << "Nhap lai nam xuat ban cua sach: ";
			}
		}while (p->Nam_xuat_ban > namhientai);
		cout << "Nhap the loai: ";
		cin.ignore();
		getline(cin, p->The_loai);
		Chuan_hoa_chu(p->Tac_gia);
		Chuan_hoa_chu(p->Ten_sach);
		Chuan_hoa_chu(p->The_loai);
		ds_dau_sach.list[ds_dau_sach.so_luong] = p;
		ds_dau_sach.so_luong++;
	}
}
void Xoa_dau_sach(DS_DAU_SACH &ds_dau_sach)
{
	cout << "LUU Y: Neu dau sach hien van con sach thi khong the xoa.\n";
	string a;
	cout << "Nhap ma ISBN cua sach: ";
	cin.ignore();
	getline(cin, a);
	int vitri = Kiem_tra_dau_sach(ds_dau_sach, a);
	if (vitri < 0)
	{
		cout << "Dau sach khong ton tai hoac van con sach. Khong xoa duoc.\n";
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
		cout << "=> Da xoa.\n";
		
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
	string a;
	cout << "Nhap ma ISBN cua sach: ";
	cin.ignore();
	getline(cin, a);
	if (Kiem_tra_trung_ISBN(ds_dau_sach, a) == false)
	{
		cout << "Dau sach khong ton tai. Khong the hieu chinh.\n";
		return;
	}	
	for (int i = 0; i < ds_dau_sach.so_luong; i++)
	{
		if (ds_dau_sach.list[i]->ISBN == a) 
		{
			cout << "\tTHONG TIN DAU SACH\n";
			Xuat_thong_tin_1_dau_sach(ds_dau_sach.list[i]);
			cout << "\tCHINH SUA\n";
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
			cout << "Nhap ten sach: ";
			getline(cin, ds_dau_sach.list[i]->Ten_sach);
			cout << "Cho biet so trang: ";
			cin >> ds_dau_sach.list[i]->So_trang;
			cin.ignore();
			cout << "Nhap ten tac gia: ";
			getline(cin, ds_dau_sach.list[i]->Tac_gia);
			int namhientai = Lay_nam_he_thong();
			cout << "Nhap nam xuat ban: ";
			do
			{
				cin >> ds_dau_sach.list[i]->Nam_xuat_ban;
				if (ds_dau_sach.list[i]->Nam_xuat_ban > namhientai)
				{
					cout << "=> Nam xuat ban khong the lon hon nam hien tai. Xin kiem tra lai.\n";
					cout << "Nhap lai nam xuat ban cua sach: ";
				}
			}while (ds_dau_sach.list[i]->Nam_xuat_ban > namhientai);
			cout << "Nhap the loai: ";
			cin.ignore();
			getline(cin, ds_dau_sach.list[i]->The_loai);
			Chuan_hoa_chu(ds_dau_sach.list[i]->Tac_gia);
			Chuan_hoa_chu(ds_dau_sach.list[i]->Ten_sach);
			Chuan_hoa_chu(ds_dau_sach.list[i]->The_loai);
			cout << "=> Hieu chinh thanh cong.\n";
			return;	
		}
	}
}
void Xuat_thong_tin_1_dau_sach(DAU_SACH *dau_sach)
{
	cout << "ISBN: " << dau_sach->ISBN << endl;
	cout << "Ten sach: " << dau_sach->Ten_sach << endl;
	cout << "So trang: " << dau_sach->So_trang << endl;
	cout << "Tac gia: " << dau_sach->Tac_gia << endl;
	cout << "Nam xuat ban: " << dau_sach->Nam_xuat_ban << endl;
	cout << "The loai: " << dau_sach->The_loai << endl; 
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
	for (int i = 0; i < ds_dau_sach.so_luong; i++)
	{
		cout << "\tDAU SACH THU " << i + 1 << endl;
		Xuat_thong_tin_1_dau_sach(ds_dau_sach.list[i]);
		cout << "\tDANH MUC SACH TUONG UNG\n";
		Xuat_dms_cua_1_dau_sach(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach);
		cout << endl;
	}
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
	string a;
	cout << "Nhap ma ISBN: ";
	cin.ignore();
	getline(cin, a);
	if (Kiem_tra_trung_ISBN(ds_dau_sach, a) == false)
	{
		cout << "Dau sach khong ton tai. Khong the them.\n";
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
			cout << "Ma sach: " << dms.Ma_sach << endl;
			dms.Trang_thai = 0;
			cout << "Trang thai: " << dms.Trang_thai << " (Cho muon duoc)";
			cout << "\nNhap vi tri: ";
			getline(cin, dms.Vi_tri);	
			NODE_DANH_MUC_SACH *p = Khoi_tao_node(dms);
			Them_vao_cuoi_danh_sach_dms(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach, p);
			ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach.so_luong++;
			ds_dau_sach.list[i]->Check = true; // <=> Dau sach nay hien tai da co sach => Khong duoc xoa 
			cout << "Them thanh cong.\n";
			return;
		}
	}
}
void Xoa_sach(DS_DANH_MUC_SACH &ds_dms, DS_DAU_SACH ds_dau_sach)
{
	string isbn;
	cout << "Nhap ma ISBN: ";
	cin.ignore();
	getline (cin, isbn);
	if (Kiem_tra_trung_ISBN(ds_dau_sach, isbn) == false)
	{
		cout << "Dau sach khong ton tai.\n";
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
				cout << "Sach khong ton tai.\n";
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
				return;
			}
		}
	}
}
void Hieu_chinh_sach(DS_DANH_MUC_SACH &ds_dms, DS_DAU_SACH ds_dau_sach)
{
	string isbn;
	cout << "Nhap ma ISBN: ";
	cin.ignore();
	getline (cin, isbn);
	if (Kiem_tra_trung_ISBN(ds_dau_sach, isbn) == false)
	{
		cout << "Dau sach khong ton tai.\n";
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
        cout<<"Thu vien chua co sach nao."<<endl;
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
	string a;
	cout << "\nNhap ten sach can tim kiem: ";
	cin.ignore();
	getline(cin, a);
	Chuan_hoa_chu(a);
	if (Kiem_tra_ten_sach(ds_dau_sach, a) == false)
	{
		cout << "Dau sach khong ton tai.\n";
		return;
	}
	for (int i = 0; i < ds_dau_sach.so_luong; i++)
	{
		if (ds_dau_sach.list[i]->Ten_sach == a)
		{
			cout << "\n\tTHONG TIN SACH\n";
			Xuat_thong_tin_1_dau_sach(ds_dau_sach.list[i]);
			cout << "\tDANH MUC SACH TUONG UNG\n";
			Xuat_dms_cua_1_dau_sach(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach);
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
	if (ds_dau_sach.so_luong < 10)
	{
		for (int i = 0; i < ds_dau_sach.so_luong; i++)
		{	
			cout << "\n\tDAU SACH THU " << stt++ << endl;
			Xuat_thong_tin_1_dau_sach(ds_dau_sach.list[i]);	
			cout << "So lan muon: " << ds_dau_sach.list[i]->So_lan_muon << endl;
		}
	}
	else
	{
		int vitri = ds_dau_sach.so_luong - 10;
		for (int i = vitri; i < ds_dau_sach.so_luong; i++)
		{
			cout << "\n\tDAU SACH THU " << stt++ << endl;
			Xuat_thong_tin_1_dau_sach(ds_dau_sach.list[i]);	
			cout << "So lan muon: " << ds_dau_sach.list[i]->So_lan_muon << endl;
		}			
	}
}
#endif
