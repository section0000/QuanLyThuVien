#ifndef Xuatthongtin
#define Xuatthongtin
#include "Ngaythang.h"
string Tra_ve_ten_sach(DS_DAU_SACH ds_dau_sach, string masach); 

void Tinh_ngay_qua_han_cua_cac_doc_gia(TREE &t)
{
	if (t != NULL)
	{
		t->data.So_ngay_qua_han = Ngay_qua_han(t->data.ds_muon_tra_cua_doc_gia);
		Tinh_ngay_qua_han_cua_cac_doc_gia(t->pLeft);
		Tinh_ngay_qua_han_cua_cac_doc_gia(t->pRight);
	}
}
void Xuat_thong_tin_1_doc_gia(DOC_GIA dg)
{
	gotoxy(30,12);
	cout << "Ma the: " << dg.Ma_the;
	gotoxy(30,13);
	cout << "Ho ten: " << dg.Ho << " " << dg.Ten;
	gotoxy(30,14);
	cout << "Gioi tinh: " << dg.Phai;
	if (dg.Trang_thai_the == 0)
	{
		gotoxy(30,15);
		cout << "Trang thai the: " << dg.Trang_thai_the << " (Bi khoa)";
	}
	else
	{
		gotoxy(30,15);
		cout << "Trang thai the: " << dg.Trang_thai_the << " (Dang hoat dong)";
	}
	gotoxy(30,16);
	cout << "So luong sach dang muon: " << dg.So_luong_sach_dang_muon;
	dg.So_ngay_qua_han = Ngay_qua_han(dg.ds_muon_tra_cua_doc_gia);
	if (dg.So_ngay_qua_han < 0)
	{
		dg.So_ngay_qua_han = 0;
	}
	gotoxy(30,17);
	cout << "So ngay qua han: " << dg.So_ngay_qua_han;
	gotoxy(30,18);
	cout << "Tong so sach da muon: " << dg.ds_muon_tra_cua_doc_gia.so_luong << endl << endl;
}
void Xuat_thong_tin_1_doc_gia_theo_hang(DOC_GIA dg, int dong)
{
	gotoxy(30,14+dong);
	cout<<dg.Ma_the<<"\t"<<dg.Ten<<"\t"<<dg.Phai;
	if (dg.Trang_thai_the == 0)
	{
		gotoxy(45,14+dong);
		cout << "Trang thai the: " << dg.Trang_thai_the << " (Bi khoa)";
	}
	else
	{
		gotoxy(45,14+dong);
		cout << "Trang thai the: " << dg.Trang_thai_the << " (Dang hoat dong)";
	}
	gotoxy(59,14+dong);
	cout<<dg.So_luong_sach_dang_muon;
	gotoxy(65,14+dong);
	cout<<dg.ds_muon_tra_cua_doc_gia.so_luong;
	gotoxy(70,14+dong);
	cout<<dg.So_ngay_qua_han;
}
void Xuat_thong_tin_doc_gia_theo_ma_the(TREE t) // Xuat theo the ma the tang dan
{
    if (t != NULL)
    {
	    Xuat_thong_tin_doc_gia_theo_ma_the(t->pLeft);
	    Xuat_thong_tin_1_doc_gia(t->data);
        Xuat_thong_tin_doc_gia_theo_ma_the(t->pRight);
    }   
}
void Chuyen_doc_gia_sang_mang(TREE t, DOC_GIA a[], int &n)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		Chuyen_doc_gia_sang_mang(t->pLeft, a, n);
		a[n++] = t->data;
		Chuyen_doc_gia_sang_mang(t->pRight, a, n);
	}
}
string Noi_ho_ten(string ten, string ho)
{
	string tam;  
	tam = ten; 
	for (int i = 0; i < ho.length(); i++)
	{
		tam.push_back(ho[i]); // Them ho vao sau ten. VD: Ten la "Phuc", Ho (+ chu lot) la "Pham Hoang" thi khi them vao se la Phuc Pham Hoang
	}
	return tam;
}
void Sap_xep_doc_gia_theo_ho_ten(TREE t, DOC_GIA a[], int &n)
{
	Chuyen_doc_gia_sang_mang(t, a, n);
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j <= n-1; j++)
		{
			if (Noi_ho_ten(a[i].Ten, a[i].Ho) > Noi_ho_ten(a[j].Ten, a[j].Ho))
			{
				DOC_GIA t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}
void Xuat_thong_tin_doc_gia_theo_ho_ten(TREE t, DOC_GIA a[], DS_DOC_GIA ds_dg, int n)
{
	Sap_xep_doc_gia_theo_ho_ten(t, a, n);
	for (int i = 0; i < ds_dg.so_luong; i++) // do n = ds_dg.so_luong;
	{
		cout << "\tDOC GIA THU " << i + 1 << endl;
		Xuat_thong_tin_1_doc_gia(a[i]);
	}
}
void Xuat_danh_sach_sach_dang_muon_cua_1_doc_gia(DS_DAU_SACH ds_dau_sach, DS_MUON_TRA ds_mt, TREE t)
{
	int c;
	gotoxy(30,12);
	cout << "DANH SACH SACH DANG MUON CUA DOC GIA: " << t->data.Ho << " " << t->data.Ten << endl;
	gotoxy(30,14);
	cout<<"Ma sach \tNgay muon \tTen sach \t\t\t\tTrang thai sach";
	int dem=0;
	for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2)
		{
			string tensachtam;
			tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
			dem++;
			gotoxy(30,14+dem);
	cout<< k->data.Ma_sach<<"\t"<< k->data.Ngay_muon.Ngay << "/" << k->data.Ngay_muon.Thang << "/" << k->data.Ngay_muon.Nam<<"\t"<< tensachtam;
			if (k->data.Trang_thai == 0)
			{
				gotoxy(96,14+dem);
				cout << "Trang thai sach: " << k->data.Trang_thai << " (Dang muon)";	
			}
			else if (k->data.Trang_thai == 2)
			{
				gotoxy(96,14+dem);
				cout << "Trang thai sach: " << k->data.Trang_thai << " (Da lam mat)";	
			}
		}
	}
	do
	{
	if(kbhit())
	{
		c = getch();
		if(c==0) c=getch();
		if(c==27) break;
	}
	} while(1);	
}
void Liet_ke_danh_sach_sach_dang_muon_cua_1_doc_gia(DS_DAU_SACH ds_dau_sach, TREE t, int mathe)
{
	if (t != NULL)
	{
		Liet_ke_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->pLeft, mathe);
		if (t->data.Ma_the == mathe)
		{
			if (t->data.ds_muon_tra_cua_doc_gia.so_luong == 0)
			{
				gotoxy(30,12);
				cout << "Doc gia van chua muon sach nao.";
				return;
			}
			Xuat_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->data.ds_muon_tra_cua_doc_gia, t);
		}
		Liet_ke_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->pRight, mathe);
	}
}
void Chuyen_doc_gia_qua_han_sang_mang(TREE t, DOC_GIA a[], int &n)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		Chuyen_doc_gia_qua_han_sang_mang(t->pLeft, a, n);
		if (t->data.So_ngay_qua_han > 0)
		{
			a[n++] = t->data;
		}
		Chuyen_doc_gia_qua_han_sang_mang(t->pRight, a, n);
	}
}
void Sap_xep_doc_gia_qua_han_theo_thoi_gian_giam_dan(TREE t, DOC_GIA a[], int &n)
{
	Chuyen_doc_gia_qua_han_sang_mang(t, a, n);
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j <= n-1; j++)
		{
			if (a[i].So_ngay_qua_han < a[j].So_ngay_qua_han)
			{
				DOC_GIA t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}
void Xuat_danh_sach_doc_gia_qua_han_theo_thoi_gian_giam_dan(TREE t, DS_DOC_GIA ds_dg)
{
	int c;
	Tinh_ngay_qua_han_cua_cac_doc_gia(t);
	int n = 0;
	DOC_GIA *a = new DOC_GIA[ds_dg.so_luong];
	Sap_xep_doc_gia_qua_han_theo_thoi_gian_giam_dan(t, a, n);
	gotoxy(30,12);
	cout <<"Ma the \tHo ten \tGioi tinh \tTrang thai the \tDang muon \tDa muon \tSo ngay qua han";
	for (int i = 0; i < n; i++)
	{
		Xuat_thong_tin_1_doc_gia_theo_hang(a[i], i);
	}
	delete []a;
	do
	{
	if(kbhit())
	{
		c = getch();
		if(c==0) c=getch();
		if(c==27) break;
	}
	} while(1);	
}
#endif
