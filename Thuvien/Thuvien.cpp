#include<iostream>
#include<time.h>
#include<algorithm>
#include<windows.h>
#include "Data.h"
#include "Themxoahieuchinhdocgia.h" 
#include "Xuatthongtindocgia.h"
#include "Dausach.h"
#include "Ngaythang.h"
#include "Muontra.h"
#include "Ghi_file.h"
#include "Doc_file.h"
#include "Giai_phong_du_lieu.h"
	using namespace std;
// Doc gia
void Nhap_doc_gia(TREE t, DOC_GIA &dg);
void Them_doc_gia(TREE &t, DOC_GIA dg, DS_DOC_GIA &ds_dg);
void Chinh_sua_thong_tin_doc_gia(TREE &t);
void Xoa_node_bat_ki(TREE &t, int mathe, DS_DOC_GIA &ds_dg); // Node o day chinh la doc gia 
void Xuat_thong_tin_doc_gia_theo_ma_the(TREE t);
void Xuat_thong_tin_doc_gia_theo_ho_ten(TREE t, DOC_GIA a[], DS_DOC_GIA ds_dg, int n);
void Liet_ke_danh_sach_sach_dang_muon_cua_1_doc_gia(TREE t, int mathe);
void Xuat_danh_sach_doc_gia_qua_han_theo_thoi_gian_giam_dan(TREE t, DOC_GIA a[], DS_DOC_GIA ds_dg, int n);
// Dau sach
void Them_dau_sach(DS_DAU_SACH &ds_dau_sach);
void Xoa_dau_sach(DS_DAU_SACH &ds_dau_sach);
void Hieu_chinh_dau_sach(DS_DAU_SACH &ds_dau_sach);
void Xuat_thong_tin_1_dau_sach(DAU_SACH *dau_sach);
void Xuat_dms_cua_1_dau_sach(DS_DANH_MUC_SACH ds_dms);
void Xuat_thong_tin_cac_dau_sach(DS_DAU_SACH ds_dau_sach);
// Danh muc sach
void Them_sach(DS_DANH_MUC_SACH &ds_dms, DS_DAU_SACH ds_dau_sach);
void Xoa_sach(DS_DANH_MUC_SACH &ds_dms, DS_DAU_SACH ds_dau_sach);
void Hieu_chinh_sach(DS_DANH_MUC_SACH &ds_dms, DS_DAU_SACH ds_dau_sach);
void Xuat_DS_Theo_Tung_The_Loai(DS_DAU_SACH ds);
void Tim_thong_tin_sach_dua_vao_ten_sach(DS_DAU_SACH ds_dau_sach, DS_DANH_MUC_SACH ds_dms);
// Muon tra
void Muon_sach(TREE &t, DS_DAU_SACH &ds_dau_sach, DS_DANH_MUC_SACH &ds_dms, int mathe);
void Tra_sach(TREE &t, DS_DAU_SACH &ds_dau_sach, DS_DANH_MUC_SACH &ds_dms);

void Khoi_tao_cay(TREE &t)
{
	t = NULL; // Cay rong
}
// Test 
void Menu(DS_DOC_GIA &ds_dg, TREE &t, DS_DAU_SACH ds_dau_sach, DS_DANH_MUC_SACH ds_dms)
{
	int luachon;
	while(true)
	{
		system("cls");
		cout << "\t\tQUAN LY THU VIEN\n";
		cout << "\t\tDOC GIA\n";
		cout << "\t1.Them doc gia.\n";
		cout << "\t2.Chinh sua thong tin doc gia.\n";		
		cout << "\t3.Xoa doc gia.\n";			
		cout << "\t4.Xuat thong tin doc gia theo ma the.\n";
		cout << "\t5.Xuat thong tin doc gia theo ho ten.\n";
		cout << "\t6.Danh sach sach dang muon cua 1 doc gia.\n";
		cout << "\t7.So luong doc gia.\n";
		cout << "\t8.Danh sach doc gia qua han.\n";
		cout << "\t\tDAU SACH VA DANH MUC SACH\n";
		cout << "\t9.Them 1 dau sach.\n";
		cout << "\t10.Xuat thong tin dau sach.\n";
		cout << "\t11.Xoa 1 dau sach.\n";
		cout << "\t12.Hieu chinh 1 dau sach.\n";
		cout << "\t13.Them sach vao 1 dau sach.\n";
		cout << "\t14.Xoa sach thuoc 1 dau sach.\n";
		cout << "\t15.Hieu chinh thong tin sach thuoc 1 dau sach.\n";
		cout << "\t16.Xuat danh sach dau sach theo the loai.\n";
		cout << "\t17.Tra cuu thong tin sach dua vao ten sach.\n";
		cout << "\t18.10 dau sach co luot muon nhieu nhat.\n";
		cout << "\t\tMUON TRA\n";
		cout << "\t19.Muon sach.\n";
		cout << "\t\tTRA SACH\n";
		cout << "\t20.Tra sach.\n";
		cout << "\t21.Luu du lieu.\n";
		cout << "\t22.Xoa toan bo du lieu.\n";
		cout << "\t0.Ket thuc.\n";
		cout << "========================\n";
		cout << "Nhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			cout << "\n==========NHAP THONG TIN DOC GIA==========\n\n";
			DOC_GIA dg;
			cin.ignore();
			Nhap_doc_gia(t,dg);
			Them_doc_gia(t,dg,ds_dg);
		}
		else if (luachon == 2)
		{
			cout << "\n==========HIEU CHINH THONG TIN DOC GIA==========\n\n";
			int n;
			cout << "Nhap ma the doc gia: ";
			cin >> n;
			if (Kiem_tra_trung_ma_the(t, n) == false)
			{
				cout << "Doc gia khong co trong thu vien.\n";
				system("pause");
			}
			else
			{
				Chinh_sua_thong_tin_doc_gia(t, n);
				system("pause");
			}
		}
		else if (luachon == 3)
		{
			cout << "\n==========XOA THONG TIN DOC GIA==========\n\n";
			int mathe;
			cout << "Nhap ma the cua doc gia: ";
			cin >> mathe;
			if (Kiem_tra_trung_ma_the(t, mathe) == false)
			{
				cout << "Doc gia khong co trong thu vien.\n";
				system("pause");
			}
			else
			{
				Xoa_node_bat_ki(t,mathe, ds_dg);
				system("pause");
			}
		}
		else if (luachon == 4)
		{
			cout << "\n==========THONG TIN DOC GIA==========\n\n";
			Xuat_thong_tin_doc_gia_theo_ma_the(t);
			system("pause");			
		}		
		else if (luachon == 5)
		{
			DOC_GIA a[ds_dg.so_luong];
			int n = 0;
			cout << "\n==========THONG TIN DOC GIA==========\n\n";
			Xuat_thong_tin_doc_gia_theo_ho_ten(t, a, ds_dg, n);	
			system("pause");
		}
		else if (luachon == 6)
		{
			int mathe;
			cout << "\nNhap ma the doc gia: ";
			cin >> mathe;
			if (Kiem_tra_trung_ma_the(t, mathe) == false)
			{
				cout << "Doc gia khong co trong thu vien.\n";
				system("pause");
			}
			else
			{
				Liet_ke_danh_sach_sach_dang_muon_cua_1_doc_gia(t, mathe);
				system("pause");
			}
		}
		else if (luachon == 7)
		{
			cout << "\n=> So luong doc gia: " << ds_dg.so_luong << endl;
			system("pause");
		}
		else if (luachon == 8)
		{
			cout << "\n==========DANH SACH DOC GIA QUA HAN==========\n\n";
			Xuat_danh_sach_doc_gia_qua_han_theo_thoi_gian_giam_dan(t, ds_dg);	
			system("pause");
		}
		else if (luachon == 9)
		{
			cout << "\n==========NHAP THONG TIN DAU SACH==========\n\n";
			Them_dau_sach(ds_dau_sach);
		}
		else if (luachon == 10)
		{
			cout << "\n==========DANH SACH DAU SACH==========\n\n";			
			if (Kiem_tra_rong_ds_dau_sach(ds_dau_sach) == true)
			{
				cout << "Danh sach dau sach hien tai dang trong.\n";
				system("pause");
			}
			else
			{
				Xuat_thong_tin_cac_dau_sach(ds_dau_sach);
				system("pause");	
			}
		}
		else if (luachon == 11)
		{
			cout << "\n==========XOA 1 DAU SACH==========\n\n";
			if (Kiem_tra_rong_ds_dau_sach(ds_dau_sach) == true)
			{
				cout << "Danh sach dau sach dang rong. Khong the xoa.\n";
				system("pause");
			}
			else
			{
				Xoa_dau_sach(ds_dau_sach);
				system("pause");
			}
		}
		else if (luachon == 12)
		{
			cout << "\n==========HIEU CHINH THONG TIN DAU SACH==========\n\n";
			Hieu_chinh_dau_sach(ds_dau_sach);
			system("pause");
		}
		else if (luachon == 13)
		{
			cout << "\n==========THEM SACH VAO DAU SACH==========\n\n";
			Them_sach(ds_dms, ds_dau_sach);
			system("pause");
		}
		else if (luachon == 14)
		{
			cout << "\n==========XOA SACH THUOC 1 DAU SACH==========\n";
			Xoa_sach(ds_dms, ds_dau_sach);
			system("pause");
		}
		else if (luachon == 15)
		{
			cout << "\n==========HIEU CHINH THONG TIN SACH THUOC 1 DAU SACH==========\n";
			Hieu_chinh_sach(ds_dms, ds_dau_sach);
			system("pause");
		}
		else if (luachon == 16)
		{
			cout << "\n==========DANH SACH DAU SACH DUA THEO THE LOAI==========\n";
			Xuat_DS_Theo_Tung_The_Loai(ds_dau_sach);
			system("pause");
		}
		else if (luachon == 17)
		{
			cout << "\n==========TRA CUU THONG TIN SACH==========\n";
			Tim_thong_tin_sach_dua_vao_ten_sach(ds_dau_sach, ds_dms);
			system("pause");				
		}
		else if (luachon == 18)
		{
			cout << "\n==========TOP 10 SACH==========\n";
			Top_10_sach(ds_dau_sach);
			system("pause");
		}
		else if (luachon == 19)
		{
			cout << "\n==========MUON SACH==========\n";
			int a;
			cout << "Nhap ma the doc gia: ";
			cin >> a;
			if (Kiem_tra_trung_ma_the(t, a) == false)
			{
				cout << "Doc gia khong ton tai.\n";
				system("pause");
			}
			else
			{
				Muon_sach(t, ds_dau_sach, ds_dms, a);
				system("pause");
			}
		}
		else if (luachon == 20)
		{
			Tra_sach(t, ds_dau_sach, ds_dms);
			system("pause");
		}
		else if (luachon == 21)
		{
			Ghi_file_ds_doc_gia(t, ds_dg);
			Ghi_file_ds_dau_sach(ds_dau_sach);
		}
		else if (luachon == 22)
		{
			Giai_phong_ds_dg(t, ds_dg);
			Giai_phong_ds_dau_sach(ds_dau_sach);
		}
		else
		{
			break;
		}
	}
}

int main()
{
	srand((int) time(0));
	TREE t;
	Khoi_tao_cay(t);
	DS_DOC_GIA ds_dg;
	DS_DAU_SACH ds_dau_sach;
	DS_DANH_MUC_SACH ds_dms;
	// Test
	cout << "Dang tai du lieu...";
	Load_file_doc_gia(t, ds_dg);
	Load_file_dau_sach(ds_dau_sach);
	Sleep(1200);
	cout << "\nTai du lieu thanh cong.";
	Sleep(1200);
	Menu(ds_dg,t, ds_dau_sach, ds_dms);
	system("pause");
	return 0;
}
