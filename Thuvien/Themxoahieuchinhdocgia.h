#ifndef Mathe
#define Mathe
#include "Data.h"
#include "Xuatthongtindocgia.h"
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
void Nhap_doc_gia(TREE t, DOC_GIA &dg)
{
	dg.Ma_the = Tao_ma_the(t);
	cout << "Ma the: " << dg.Ma_the;
	cout << "\nNhap ho: ";
	getline(cin, dg.Ho);
	cout << "Nhap ten: ";
	getline(cin, dg.Ten);
	cout << "Nhap gioi tinh: ";
	do
	{
		getline(cin, dg.Phai);
		Chuan_hoa_chu(dg.Phai);
		if (dg.Phai != "Nam" && dg.Phai != "Nu")
		{
			cout << "Gioi tinh khong hop le. Xin nhap lai.\n";
			cout << "Nhap lai gioi tinh: ";
		}
	}while (dg.Phai != "Nam" && dg.Phai != "Nu");
	Chuan_hoa_chu(dg.Ho);
	Chuan_hoa_chu(dg.Ten);
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
			cout << "\n\tTHONG TIN DOC GIA\n";
			Xuat_thong_tin_1_doc_gia(t->data);
			cout << "\n\tCHINH SUA THONG TIN\n";
			cin.ignore();
			cout << "\nNhap ho: ";
			getline(cin, t->data.Ho);
			cout << "Nhap ten: ";
			getline(cin, t->data.Ten);
			cout << "Nhap gioi tinh: ";
			do
			{
				getline(cin, t->data.Phai);
				Chuan_hoa_chu(t->data.Phai);
				if (t->data.Phai != "Nam" && t->data.Phai != "Nu")
				{
					cout << "Gioi tinh khong hop le. Xin nhap lai.\n";
					cout << "Nhap lai gioi tinh: ";
				}
			}while (t->data.Phai != "Nam" && t->data.Phai != "Nu");
			cout << "Nhap trang thai the: ";
			do
			{
				cin >> t->data.Trang_thai_the;
				if (t->data.Trang_thai_the != 0 && t->data.Trang_thai_the != 1)
				{
					cout << "Trang thai the khong hop le. Xin nhap lai.\n";
					cout << "Nhap lai trang thai the: ";
				}
			}while (t->data.Trang_thai_the != 0 && t->data.Trang_thai_the != 1);
			Chuan_hoa_chu(t->data.Ho);
			Chuan_hoa_chu(t->data.Ten);
			cout << "=> Sua thanh cong.\n";
			return;
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
void Xoa_node_bat_ki(TREE &t, int mathe, DS_DOC_GIA &ds_dg) // mathe chinh la ma the cua node can xoa
{
    if (t == NULL) // Neu nhu cay rong
    {
        return;
    }
    else // Neu nhu cay da co phan tu
    {
    	if (t->data.So_luong_sach_dang_muon > 0)
    	{
    		cout << "Doc gia hien van chua tra sach. Khong the xoa.\n";
    		return;
		}
        // Neu nhu mathe nho hon ma the cua node goc
        if (mathe < t->data.Ma_the)
        {
            Xoa_node_bat_ki(t->pLeft,mathe, ds_dg); // Duyet sang nhanh trai cua node do
        }
        else if (mathe > t->data.Ma_the)
        {
            Xoa_node_bat_ki(t->pRight,mathe, ds_dg); // Duyet sang nhanh phai cua node do
        }
        else // mathe == t->data.Ma_the <=> Da tim ra node can xoa
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
        }
    }
}
#endif
