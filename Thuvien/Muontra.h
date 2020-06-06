#ifndef Muontra
#define Muontra
NODE_MUON_TRA* Khoi_tao_node_mt(MUON_TRA mt)
{
	NODE_MUON_TRA *p = new NODE_MUON_TRA;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat.\n";
		return NULL;
	}
	p->data = mt;
	p->pNext = NULL;
	p->pBack = NULL;
	return p;
}
void Them_vao_dau_danh_sach_mt(DS_MUON_TRA &ds_mt, NODE_MUON_TRA *p)
{
	if (ds_mt.pHead == NULL)
	{
		ds_mt.pHead = ds_mt.pTail = p;
	}
	else
	{
		ds_mt.pHead->pBack = p;
		p->pNext = ds_mt.pHead;
		ds_mt.pHead = p;
	}
}
void Them_vao_cuoi_danh_sach_mt(DS_MUON_TRA &ds_mt, NODE_MUON_TRA *p)
{
	if (ds_mt.pHead == NULL)
	{
		ds_mt.pHead = ds_mt.pTail = p;
	}
	else
	{
		ds_mt.pTail->pNext = p;
		p->pBack = ds_mt.pTail;
		ds_mt.pTail = p;
	}
}
void Giai_phong_danh_sach_mt(DS_MUON_TRA &ds_mt)
{
	NODE_MUON_TRA *k = NULL;
	while (ds_mt.pHead != NULL)
	{
		k = ds_mt.pHead;
		ds_mt.pHead = ds_mt.pHead->pNext;
		delete k;
	}
}
bool Mat_sach(DS_MUON_TRA ds_mt)
{
	for (NODE_MUON_TRA *k = ds_mt.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.Trang_thai == 2)
		{
			return true;
		}
	}
	return false;
}
string Tra_ve_ten_sach(DS_DAU_SACH ds_dau_sach, string masach)
{
	string tam;
	tam.insert(tam.begin() + 0, masach.begin() + 0, masach.begin() + 4);
	for (int i = 0; i < ds_dau_sach.so_luong; i++)
	{
		if (ds_dau_sach.list[i]->ISBN == tam)
		{
			tam = ds_dau_sach.list[i]->Ten_sach;
			break;
		}
	}
	return tam;
}
void Muon_sach(TREE &t, DS_DAU_SACH &ds_dau_sach, DS_DANH_MUC_SACH &ds_dms, int mathe)
{
	if (t != NULL) // Duyet cay
	{
		Muon_sach(t->pLeft, ds_dau_sach, ds_dms, mathe); 
		if (t->data.Ma_the == mathe)
		{
			//Xuat_thong_tin_1_doc_gia(t->data);
			Xuat_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->data.ds_muon_tra_cua_doc_gia, t);
			if (t->data.So_luong_sach_dang_muon == 0)
			{
				gotoxy(30, 20);
				cout << "Doc gia hien van chua muon sach nao.";
			}
			// Kiem tra so luong sach dang muon cua doc gia
			/*int soluong = 0;
			for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2) // Dang muon hoac lam mat sach ma chua den <=> Chua tra sach
				{
					soluong++;
					if (soluong == 3)
					{
						cout << "Doc gia chi duoc muon toi da 3 cuon sach.\n";
						return;
					}
				}
			}*/
			if (t->data.So_luong_sach_dang_muon == 3) // Dang muon hoac lam mat sach ma chua den <=> Chua tra sach
			{
				gotoxy(30, 20);
				cout << "Doc gia chi duoc muon toi da 3 cuon sach.";
				thong_bao("                                     ");
				return;
			}
			// Kiem tra trang thai the cua doc gia
			if (t->data.Trang_thai_the == 0)
			{
				gotoxy(30, 20);
				cout << "The cua doc gia hien dang bi khoa nen khong the muon sach.";
				thong_bao("                                     ");
				return;
			}
			// Kiem tra xem doc gia co lam mat sach khong
			if (Mat_sach(t->data.ds_muon_tra_cua_doc_gia) == true)
			{
				gotoxy(30, 20);
				cout << "Doc gia khong duoc muon sach vi da lam mat sach.";
				thong_bao("                                     ");
				return;
			}
			// Kiem tra xem doc gia co giu sach qua han khong
			if (So_ngay_muon(t->data.ds_muon_tra_cua_doc_gia) > 7)
			{
				gotoxy(30, 20);
				cout << "Doc gia khong duoc muon sach vi da giu sach qua han 7 ngay.";
				thong_bao("                                     ");
				return;
			}
			thong_bao("                                     ");
			xoa_man_hinh(20, 10, 95, 25);
//			gotoxy(30, 9);
//			cout << "CAC DAU SACH HIEN CO TRONG THU VIEN";
			if (Kiem_tra_rong_ds_dau_sach(ds_dau_sach) == true)
			{
				thong_bao("Thu vien tam thoi chua co sach.");
				return;
			}
			Xuat_DS_Theo_Tung_The_Loai(ds_dau_sach);	
			string tensach;	
			gotoxy(30, 36);
			cout << "Nhap ten dau sach can muon: ";
			//cin.ignore();
			Nhap_va_kiem_tra_bo_trong_du_lieu(tensach, 58, 36);
			Chuan_hoa_chu(tensach);
			if (Kiem_tra_ten_sach(ds_dau_sach, tensach) == false)
			{
				thong_bao("Dau sach khong co trong thu vien.");
				return;
			}	
			// Neu dang muon sach thuoc dau sach nay thi khong duoc muon nua
			for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
			{
				string tensachtam;
				tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
				if (tensachtam == tensach && k->data.Trang_thai == 0)
				{
					thong_bao("Doc gia hien dang muon sach nay roi.");
					return;
				}
			}
			for (int i = 0; i < ds_dau_sach.so_luong; i++) // Duyet dach sach de tim ra dau sach muon muon
			{
				if (ds_dau_sach.list[i]->Ten_sach == tensach)
				{
					xoa_man_hinh(5, 7, 128, 30);
					gotoxy(30, 10);
					cout<<"Ten sach: " << ds_dau_sach.list[i]->Ten_sach;
					gotoxy(60, 12);
					cout << "DANH MUC SACH";
					khung_xuat_dms(27, 13, 20);
					Xuat_dms_cua_1_dau_sach(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach, 16);
					string masach;
				Nhapmasach:			
					gotoxy(30, 35);
					cout << "Nhap ma sach can muon: ";	
					Nhap_va_kiem_tra_bo_trong_du_lieu(masach, 53, 35);					
					if (Kiem_tra_trung_ma_sach(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach, masach) == false)
					{		
						thong_bao("Ma sach khong ton tai.");
						goto Nhapmasach; // Quay ve nhap lai ma sach
					}
					// Duyet ds danh muc sach cua dau sach do de tim ra sach co ma muon muon
					for (NODE_DANH_MUC_SACH *g = ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach.pHead; g != NULL; g = g->pNext)
					{
						if (g->data.Ma_sach == masach)
						{
							if (g->data.Trang_thai == 1)
							{
								thong_bao("Sach da co nguoi muon. Xin chon sach khac.");
								goto Nhapmasach;
							}
							else if (g->data.Trang_thai == 2)
							{
								thong_bao("Sach da thanh ly. Xin chon sach khac.");
								goto Nhapmasach;
							}
							else if (g->data.Trang_thai == 0) // Duoc phep muon
							{
								g->data.Trang_thai = 1; // Thay doi trang thai sach la da co nguoi muon
								MUON_TRA mt; // Tao 1 bien cho de lam
								// mt.Ten_sach = tensach;
								mt.Ngay_tra.Nam = 0;
								mt.Ngay_tra.Thang = 0;
								mt.Ngay_tra.Ngay = 0;
								mt.Ma_sach = masach;
								mt.Trang_thai = 0;
								NGAY_THANG ngaymuon;
								Lay_ngay_gio_he_thong(ngaymuon); // Lay ngay hien tai lam ngay muon
								mt.Ngay_muon = ngaymuon;
								/*// Test truong hop muon qua 7 ngay
								cout << "\tNHAP NGAY MUON\n";
								cout << "Nhap ngay: ";
								cin >> ngaymuon.Ngay;
								cout << "Nhap thang: ";
								cin >> ngaymuon.Thang;
								cout << "Nhap nam: ";
								cin >> ngaymuon.Nam;
								mt.Ngay_muon = ngaymuon;*/
								NODE_MUON_TRA *p = Khoi_tao_node_mt(mt);
								Them_vao_cuoi_danh_sach_mt(t->data.ds_muon_tra_cua_doc_gia, p);
								t->data.So_luong_sach_dang_muon++;
								t->data.ds_muon_tra_cua_doc_gia.so_luong++; // De cho biet tong so sach da muon, biet them thong tin la chinh chu co hay khong cung khong anh huong
								ds_dau_sach.list[i]->So_lan_muon++;
								thong_bao("Muon thanh cong.");
								return;	
							}
						}
					}
				}
			}
		}
		Muon_sach(t->pRight, ds_dau_sach, ds_dms, mathe);
	}
}
void Xu_li_tra_sach(TREE &t, DS_DAU_SACH &ds_dau_sach, DS_DANH_MUC_SACH &ds_dms, int mathe)
{
	if (t != NULL) // Duyet cay
	{
		Xu_li_tra_sach(t->pLeft, ds_dau_sach, ds_dms, mathe);
		if (t->data.Ma_the == mathe)
		{
			Xuat_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->data.ds_muon_tra_cua_doc_gia, t);
			if (t->data.So_luong_sach_dang_muon == 0)
			{
				gotoxy(30, 20);
				cout << "Doc gia hien van chua muon sach nao.";
				thong_bao("                                  ");
				return;
			}
//			cout << "\tTHONG TIN DOC GIA\n";
//			Xuat_thong_tin_1_doc_gia(t->data);
//			Xuat_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->data.ds_muon_tra_cua_doc_gia, t);
//			if (t->data.So_luong_sach_dang_muon == 0)
//			{
//				cout << "Doc gia hien van chua muon sach nao.\n";
//				return;
//			}
			NGAY_THANG ngaytra;	// Dung de luu ngay tra
			string tensach;
			gotoxy(30, 20);	
			cout << "Nhap ten sach can tra: ";
			//cin.ignore();
			do
			{
				Nhap_va_kiem_tra_bo_trong_du_lieu(tensach, 53, 20);
				Chuan_hoa_chu(tensach);			
				if (Kiem_tra_ten_sach(ds_dau_sach, tensach) == false)
				{
				thong_bao("Sai ten sach. Xin nhap lai.");
				gotoxy(53, 20);
				}				
			}while (Kiem_tra_ten_sach(ds_dau_sach, tensach) == false);
			// Duyet danh sach de tim ra dau sach co ten giong voi sach can tra
			for (int i = 0; i < ds_dau_sach.so_luong; i++) 
			{
				if (ds_dau_sach.list[i]->Ten_sach == tensach)
				{
					string tam; // Bien dung de luu lai ma sach cua sach duoc tra
					 // Duyet ds muon tra cua doc gia de tim ra sach co ten do va tien hanh chinh sua thong tin
					for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
					{
						string tensachtam;
						tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
						if (tensachtam == tensach)
						{
							if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2) // 0 la dang muon, 2 la lam mat sach. Lam mat sach thi khi den sach <=> Tra sach 
							{
								k->data.Trang_thai = 1; // Sua trang thai muon tra lai la 1 (Da tra)
								Lay_ngay_gio_he_thong(ngaytra);
								k->data.Ngay_tra = ngaytra; // Lay ngay hien tai lam ngay tra. Khong ro la nen cho nhap ngay hay lay luon ngay hien tai?
								tam = k->data.Ma_sach; 
								t->data.So_luong_sach_dang_muon--;
								break;
							}
						}
					}
					// Sua phan muon tra xong tien hanh sua thong tin danh muc sach do lai
					for (NODE_DANH_MUC_SACH *g = ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach.pHead; g != NULL; g = g->pNext)
					{
						if (g->data.Ma_sach == tam)
						{
							g->data.Trang_thai = 0; // Cho muon duoc
							
						}
					}
				}
			}
			gotoxy(30, 22);
			cout << "Ngay tra: ";
			Xuat_ngay_thang(ngaytra);
			thong_bao("Xac nhan da tra.");
			return;
		}
		Xu_li_tra_sach(t->pRight, ds_dau_sach, ds_dms, mathe);
	}
}
void Xu_li_lam_mat_sach(TREE &t, DS_DAU_SACH &ds_dau_sach, DS_DANH_MUC_SACH &ds_dms, int mathe)
{
	if (t != NULL)
	{
		Xu_li_lam_mat_sach(t->pLeft, ds_dau_sach, ds_dms, mathe);
		if (t->data.Ma_the == mathe)
		{
			if (t->data.Ma_the == mathe)
			{
				Xuat_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->data.ds_muon_tra_cua_doc_gia, t);
				if (t->data.So_luong_sach_dang_muon == 0)
				{
					gotoxy(30, 20);
					cout << "Doc gia hien van chua muon sach nao.";
					thong_bao("                                  ");	
					return;
				}	
				string tensach;	
				gotoxy(30, 20);
				cout << "Nhap ten sach da lam mat: ";
				//cin.ignore();
				do
				{
					Nhap_va_kiem_tra_bo_trong_du_lieu(tensach, 56, 20);
					Chuan_hoa_chu(tensach);			
					if (Kiem_tra_ten_sach(ds_dau_sach, tensach) == false)
					{
					thong_bao("Sai ten sach. Xin nhap lai.");
					gotoxy(56, 20);
					}				
				}while (Kiem_tra_ten_sach(ds_dau_sach, tensach) == false);
				// Duyet danh sach de tim ra dau sach co ten giong voi sach bi lam mat
				for (int i = 0; i < ds_dau_sach.so_luong; i++)
				{
					if (ds_dau_sach.list[i]->Ten_sach == tensach)
					{
						// Duyet ds muon tra cua doc gia de tim ra sach co ten do va tien hanh chinh sua thong tin
						for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
						{
							string tensachtam;
							tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
							if (tensachtam == tensach)
							{
								if (k->data.Trang_thai == 0)
								{
									k->data.Trang_thai = 2; // Sua trang thai muon tra cua doc gia doi voi sach do tu 0 (Dang muon) sang 2 (Lam mat) <=> Chua tra sach
									return;
								}
							}
						}
					}
				}	
			}
		}
		Xu_li_lam_mat_sach(t->pRight, ds_dau_sach, ds_dms, mathe);
	}
}	
void Tra_sach(TREE &t, DS_DAU_SACH &ds_dau_sach, DS_DANH_MUC_SACH &ds_dms)
{
	int luachon;
	while(true)
	{
		system("cls");
		cout << "\t\tTRA SACH\n";
		cout << "\t1.Tra sach.\n";
		cout << "\t2.Lam mat sach.\n";
		cout << "\t3.Den sach.\n";
		cout << "\t0.Ket thuc.\n";
		cout << "=============================\n";
		cout << "Nhap lua chon: ";
		do
		{
			cin >> luachon;
			if (luachon < 0 || luachon > 3)
			{
				cout << "Lua chon khong hop le. Xin nhap lai.\n";
				cout << "Nhap lai lua chon: ";
			}
		}while (luachon < 0 || luachon > 3);
		if (luachon == 1)
		{		
			int a;
			cout << "\nNhap ma the doc gia: ";
			cin >> a;
			if (Kiem_tra_trung_ma_the(t, a) == false)
			{
				cout << "Doc gia khong co trong thu vien.\n";
				system("pause");
			}
			else
			{
				Xu_li_tra_sach(t, ds_dau_sach, ds_dms, a);			
				system("pause");	
			}
		}
		else if (luachon == 2)
		{
			int a;
			cout << "\nNhap ma the doc gia: ";
			cin >> a;
			if (Kiem_tra_trung_ma_the(t, a) == false)
			{
				cout << "Doc gia khong co trong thu vien.\n";
				system("pause");
			}
			else
			{
				Xu_li_lam_mat_sach(t, ds_dau_sach, ds_dms, a);	
				cout << "Xac nhan lam mat.\n";		
				system("pause");	
			}			
		}
		else if (luachon == 3)
		{
			int a;
			cout << "\nNhap ma the doc gia: ";
			cin >> a;
			if (Kiem_tra_trung_ma_the(t, a) == false)
			{
				cout << "Doc gia khong co trong thu vien.\n";
				system("pause");
			}
			else
			{
				Xu_li_tra_sach(t, ds_dau_sach, ds_dms, a);		
				system("pause");	
			}			
		}
		else
		{
			break;
		}
	}	
}
#endif
