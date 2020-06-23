#ifndef Mathe
#define Mathe
#include "Data.h"
#include "Xuatthongtindocgia.h"
#include "Dohoa.h"
#include "Xu_li_nhap_so.h"
	using namespace std;
bool Kiem_tra_trung_ma_the(TREE t, int x)
{
	if (t == NULL)
	{
		return false; // Cay rong => Khong trung
	}
	else
	{
		 // Neu phan tu can tim kiem ma nho hon node goc thi duyet sang trai de tim
		if (x < t->data.Ma_the)
		{
			Kiem_tra_trung_ma_the(t->pLeft, x);
		}
		// Tuong tu o tren, duyet sang ben phai
		else if (x > t->data.Ma_the)
		{
			Kiem_tra_trung_ma_the(t->pRight, x);
		}
		else // ds_dg.t->data.Ma_the == x
		{
			return true; // Trung
		}
	}
}
int Tao_ma_the(TREE t)
{
	int n;
	do
	{
		n = rand()%(MA_THE_MAX - MA_THE_MIN + 1) + MA_THE_MIN; 
	}while (Kiem_tra_trung_ma_the(t, n) == true);
	return n;
}
void Chuan_hoa_chu(string &a)
{
	while (a[0] == ' ') // Xoa khoang trang dau 
	{
		a.erase(a.begin() + 0);
	}
	while (a[a.length()-1] == ' ') // Xoa khoang trang cuoi
	{
		a.erase(a.begin()+ a.length()-1);
	}
	// Xoa khoang trang giua
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i+1] == ' ')
		{
			a.erase(a.begin() + i);
			i--;
		}
	}
	// Viet hoa ki tu dau cua moi chu 
	if (a[0] >= 97 && a[0] <= 122)
	{
		a[0] = a[0] - 32;
	}
	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] == ' ') // Kiem tra tu tiep theo
		{
			i++;
			if (a[i] >= 97 && a[i] <= 122)
			{
				a[i] = a[i] - 32;
			}
		}
		else
		{
			if (a[i] >= 65 && a[i] <= 90)
			{
				a[i] = a[i] + 32;
			}
		}
	}
}
bool Kiem_tra_nhap_ho_ten(string hoten) // Chi cho nhap chu cai, khoang trang, va mot so ki tu dac biet nhu "., -, &" (VD: Robert M. Pirsig, Randy Pausch & Jeffrey Zaslow, Antoine de Saint-ExupÃ©ry,...)
{
	for (int i = 0; i < hoten.length(); i++)
	{
		if ((hoten[i] < 65 || hoten[i] > 90) && (hoten[i] < 97 && hoten[i > 122]) && (hoten[i] != 32) && (hoten[i] != 38) &&
			(hoten[i] != 45) && (hoten[i] != 46))
		{
			return false;
		}
	}
	return true;
}
void Nhap_va_kiem_tra_bo_trong_du_lieu(string &s, int x, int y) // x,y la noi con tro quay lai de nhap
{
Nhapdulieu:
	getline(cin, s);
	int dem = 0;
	if (s == "")
	{
		do
		{
			thong_bao("Khong duoc bo trong du lieu.");
			xoa_man_hinh(x, y, 70, 1);
			gotoxy(x, y);
			getline(cin, s);
		}while (s == "");
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			dem++;
		}
	}
	if (dem == s.length())
	{
		thong_bao("Ten khong hop le. Xin nhap lai.");
		xoa_man_hinh(x, y, 70, 1);
		gotoxy(x,y);
		goto Nhapdulieu;
	}
}
void Nhap_doc_gia(TREE t, DOC_GIA &dg)
{	
	huong_dan_nhap_doc_gia();
	gotoxy(30, 10);
	cout << "Ma the: "<<endl;
	dg.Ma_the = Tao_ma_the(t);
	gotoxy(30, 12);
	cout << "Nhap ho: "; 
	gotoxy(30, 14);
	cout << "Nhap ten: ";
	gotoxy(30, 16);
	cout << "Nhap gioi tinh: ";
	while (true)
	{
		if (kbhit())
		{
			char key = getch();
			if (key == 13)
			{
				ShowCur(1);
				do
				{
					gotoxy(30,10);
					cout << "Ma the: " << dg.Ma_the;
					gotoxy(39, 12);
					Nhap_va_kiem_tra_bo_trong_du_lieu(dg.Ho, 39, 12);
					if (Kiem_tra_nhap_ho_ten(dg.Ho) == false)
					{
						thong_bao("Ten khong hop le, xin nhap lai.");
						xoa_man_hinh(39, 12, 80, 1);
						gotoxy(39, 12);	
					}	
				}while (Kiem_tra_nhap_ho_ten(dg.Ho) == false);
				do
				{
					gotoxy(40, 14);
					Nhap_va_kiem_tra_bo_trong_du_lieu(dg.Ten, 40, 14);
					if (Kiem_tra_nhap_ho_ten(dg.Ten) == false)
					{
						thong_bao("Ten khong hop le, xin nhap lai.");
						xoa_man_hinh(40, 14, 80, 1);	
						gotoxy(40, 14);			
					}	
				}while (Kiem_tra_nhap_ho_ten(dg.Ten) == false);	
				do
				{
					gotoxy(46, 16);
					getline(cin, dg.Phai);
					Chuan_hoa_chu(dg.Phai);
					if (dg.Phai != "Nam" && dg.Phai != "Nu")
					{
						thong_bao("Gioi tinh khong hop le, xin nhap lai.");
						xoa_man_hinh(46, 16, 80, 1);
					}
				}while (dg.Phai != "Nam" && dg.Phai != "Nu");
				Chuan_hoa_chu(dg.Ho);
				Chuan_hoa_chu(dg.Ten);	
				thong_bao("Them thanh cong.");
				return;
			}
			else if (key == 27)
			{
				return;
			}
		}
	}
}
// Them
void Them_doc_gia(TREE &t, DOC_GIA dg, DS_DOC_GIA &ds_dg)
{
	if (t == NULL) // Neu cay dang rong
	{
		NODE_DOC_GIA *p = new NODE_DOC_GIA; // Khoi tao 1 node de them vao cay
		p->pLeft = NULL;
		p->pRight = NULL;
		p->data = dg; // Them du lieu vao node
		p->data.So_luong_sach_dang_muon = 0;
		p->data.So_ngay_qua_han = 0;
		p->data.Trang_thai_the = 1;
		t = p; // Node p chinh la node goc
		ds_dg.so_luong++;
	}
	else // Neu cay da co ton tai phan tu
	{
		if (t->data.Ma_the > dg.Ma_the) 
		{
			Them_doc_gia(t->pLeft, dg, ds_dg); // Them phan tu vao nhanh ben trai
		}
		else if (t->data.Ma_the < dg.Ma_the)
		{
			Them_doc_gia(t->pRight, dg, ds_dg); // // Them phan tu vao nhanh ben phai
		}
	}
}
// Hieu chinh
void Chinh_sua_thong_tin_doc_gia(TREE &t, int mathe)
{
	if (t != NULL)
	{
		Chinh_sua_thong_tin_doc_gia(t->pLeft, mathe);
		if (t->data.Ma_the == mathe)
		{
			huong_dan_chinh_sua_doc_gia();
			gotoxy(60,11);
			cout << "THONG TIN DOC GIA";
			Xuat_thong_tin_1_doc_gia(t->data);
			gotoxy(59,20);
			cout << "CHINH SUA THONG TIN";
			ShowCur(0);
			gotoxy(30,21);
			cout << "Nhap ho: ";
			gotoxy(30,22);
			cout << "Nhap ten: ";
			gotoxy(30,23);
			cout << "Nhap gioi tinh: ";
			gotoxy(30,25);
			cout << "Nhap trang thai the(0/1): ";
			while (true)
			{
				if (kbhit())
				{
					char key = getch();
					if (key == 13)
					{
						ShowCur(1);
						do
						{
							gotoxy(39, 21);
							Nhap_va_kiem_tra_bo_trong_du_lieu(t->data.Ho, 39, 21);
							if (Kiem_tra_nhap_ho_ten(t->data.Ho) == false)
							{
								thong_bao("Ten khong hop le, xin nhap lai.");
								xoa_man_hinh(39, 21, 80, 1);	
								gotoxy(39, 21);
							}			
						}while (Kiem_tra_nhap_ho_ten(t->data.Ho) == false);	
						do
						{
							gotoxy(40, 22);
							Nhap_va_kiem_tra_bo_trong_du_lieu(t->data.Ten, 40, 22);
							if (Kiem_tra_nhap_ho_ten(t->data.Ten) == false)
							{
								thong_bao("Ten khong hop le, xin nhap lai.");
								xoa_man_hinh(40, 22, 80, 1);	
								gotoxy(40, 22);
							}	
						}while (Kiem_tra_nhap_ho_ten(t->data.Ten) == false);		
						do		
						{
							gotoxy(46, 23);
							getline(cin, t->data.Phai);
							Chuan_hoa_chu(t->data.Phai);
							if (t->data.Phai != "Nam" && t->data.Phai != "Nu")
							{
								thong_bao("Gioi tinh khong hop le, xin nhap lai.");
								xoa_man_hinh(46, 23, 80, 1);
							}
						}while (t->data.Phai != "Nam" && t->data.Phai != "Nu");	
						do
						{
							gotoxy(56, 25);
							Nhap_so(t->data.Trang_thai_the, 56, 25);
							if (t->data.Trang_thai_the != 0 && t->data.Trang_thai_the != 1)
							{					
								thong_bao("Trang thai the khong hop le, xin nhap lai.");
								xoa_man_hinh(56, 25, 70, 1);
							}
						}while (t->data.Trang_thai_the != 0 && t->data.Trang_thai_the != 1);
						Chuan_hoa_chu(t->data.Ho);
						Chuan_hoa_chu(t->data.Ten); // cin.ignore();
						thong_bao("Hieu chinh thanh cong.");	
						return;
					}
					else if (key == 27)
					{
						break;
					}
				}
			}
		}
		Chinh_sua_thong_tin_doc_gia(t->pRight, mathe);
	}
}
// Xoa
void Tim_node_the_mang(TREE &X, TREE &Y) 
{

    if (Y->pRight != NULL)
    {
        Tim_node_the_mang(X,Y->pRight); 
    }
    else 
    {
        X->data = Y->data; 
        X = Y; 
        Y = Y->pLeft; 
    }    
}
void Xoa_node_bat_ki(TREE &t, int mathe, DS_DOC_GIA &ds_dg, DS_DAU_SACH ds_dau_sach) // mathe chinh la ma the cua node can xoa
{
    if (t == NULL) // Neu nhu cay rong
    {
        return;
    }
    else // Neu nhu cay da co phan tu
    {
        // Neu nhu mathe nho hon ma the cua node goc
        if (mathe < t->data.Ma_the)
        {
            Xoa_node_bat_ki(t->pLeft,mathe, ds_dg, ds_dau_sach); // Duyet sang nhanh trai cua node do
        }
        else if (mathe > t->data.Ma_the)
        {
            Xoa_node_bat_ki(t->pRight,mathe, ds_dg, ds_dau_sach); // Duyet sang nhanh phai cua node do
        }
        else // mathe == t->data.Ma_the <=> Da tim ra node can xoa
        {
        	gotoxy(60,11);
			cout << "THONG TIN DOC GIA";
        	Xuat_thong_tin_1_doc_gia(t->data);
        	gotoxy(20,22);
			cout<<"Ma sach \tNgay muon \tTen sach \t\t\t\t\tTrang thai sach";	
			for (int i=0; i<93; i++) 
			{ 
				gotoxy(19+i,21);
				cout<<"_";
				gotoxy(19+i,23);
				cout<<"_";	
				gotoxy(19+i,27);
				cout<<"_";	
			}
			for (int i=0; i<6; i++) 
			{ 
				gotoxy(18,22+i); 
				cout<<"|";
				gotoxy(28,22+i); 
				cout<<"|";
				gotoxy(43,22+i); 
				cout<<"|";
				gotoxy(94,22+i); 
				cout<<"|";
				gotoxy(112,22+i);
				cout<<"|";
			}
			gotoxy(40,20);
			cout << "DANH SACH SACH DANG MUON CUA DOC GIA: " << t->data.Ho << " " << t->data.Ten << endl;
			int dem=0;
			for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2)
				{
					string tensachtam;
					tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
					dem++;
					gotoxy(20,23+dem);
					cout<< k->data.Ma_sach<<"\t"<< k->data.Ngay_muon.Ngay << "/" << k->data.Ngay_muon.Thang << "/" << k->data.Ngay_muon.Nam<<"\t"<< tensachtam;
					if (k->data.Trang_thai == 0)
					{
						gotoxy(96,23+dem);
						cout << k->data.Trang_thai << " (Dang muon)";	
					}
					else if (k->data.Trang_thai == 2)
					{
						gotoxy(96,23+dem);
						cout << k->data.Trang_thai << " (Da lam mat)";	
					}
				}
			}
        	if (t->data.So_luong_sach_dang_muon > 0) 
    		{

    			thong_bao("Doc gia hien van chua tra sach. Khong the xoa.");
    			return;
			}
			huong_dan_xoa_doc_gia_2();
			gotoxy(60, 30);
			textcolor(11);
			ShowCur(1);
			cout << "XAC NHAN XOA?";
			while (true)
			{
				if (kbhit())
				{
					char key = getch();
					if (key == 13)
					{
						// Danh cho xoa node co 1 con va node la
            			NODE_DOC_GIA *X = t; // Node the mang, la node ma ti nua se xoa
            			// Neu nhu nhanh trai = NULL <=> Day la cay con trai
            			if (t->pLeft == NULL)
            			{
                			// Duyet sang phai cua node can xoa de cap nhat moi lien ket giua cha cua node can xoa voi node con cua node can xoa
                			t = t->pRight;
            			}
            			else if (t->pRight == NULL)
            			{
                			// Duyet sang trai cua node can xoa de cap nhat moi lien ket giua cha cua node can xoa voi node con cua node can xoa
                			t = t->pLeft;
            			}
            			// Danh cho node co 2 con
            			else 
            			{
							// Tim node phai ngoai cung cua cay con trai(cay con trai cua node can xoa)
                			Tim_node_the_mang(X,t->pLeft);
            			}
            			delete X;
            			ds_dg.so_luong--;
            			thong_bao("Xoa thanh cong.");
            			Normal();
						return;	
					}
					else if (key == 27)
					{
						return;
					}
				}
			}
        }
    }
}
#endif
