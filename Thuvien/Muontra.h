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
void Xoa_dau_danh_sach_mt(DS_MUON_TRA &ds_mt)
{
	if (ds_mt.pHead == NULL)
	{
		return;
	}
	else
	{
		NODE_MUON_TRA *p = ds_mt.pHead;
		ds_mt.pHead = ds_mt.pHead->pNext;
		delete p;
	}
}
void Xoa_cuoi_danh_sach_mt(DS_MUON_TRA &ds_mt)
{
	if (ds_mt.pHead == NULL)
	{
		return;
	}
	else if (ds_mt.pHead == ds_mt.pTail)
	{
		Xoa_dau_danh_sach_mt(ds_mt);
	}
	else
	{
		NODE_MUON_TRA *p = ds_mt.pTail;
		ds_mt.pTail = ds_mt.pTail->pBack;
		delete p;
	}
}
void Xoa_1_node_muon_tra_theo_ma_sach(DS_MUON_TRA &ds_mt, string masach)
{
	if (ds_mt.pHead->data.Ma_sach == masach)
	{
		Xoa_dau_danh_sach_mt(ds_mt);
	}
	if (ds_mt.pTail->data.Ma_sach == masach)
	{
		Xoa_cuoi_danh_sach_mt(ds_mt);
	}
	for (NODE_MUON_TRA *k = ds_mt.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.Ma_sach == masach)
		{
			NODE_MUON_TRA *g = k->pBack;
			g->pNext = k->pNext;
			delete k;
		}
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
	ShowCur(0);
	if (t != NULL) // Duyet cay
	{
		Muon_sach(t->pLeft, ds_dau_sach, ds_dms, mathe); 
		if (t->data.Ma_the == mathe)
		{
			Xuat_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->data.ds_muon_tra_cua_doc_gia, t);
			if (t->data.So_luong_sach_dang_muon == 0)
			{
				gotoxy(30, 20);
				cout << "Doc gia hien van chua muon sach nao.";
			}
			// Kiem tra so luong sach dang muon cua doc gia
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
			if (Kiem_tra_rong_ds_dau_sach(ds_dau_sach) == true)
			{
				thong_bao("Thu vien tam thoi chua co sach.");
				return;
			}
			huong_dan_muon_sach();
			Xuat_DS_Theo_Tung_The_Loai(ds_dau_sach);
			string tensach;	
			huong_dan_muon_sach_2();
			ShowCur(0);
			gotoxy(30, 36);
			cout << "Nhap ten dau sach can muon: ";
			while (true)
			{
				if (kbhit())
				{
					char key = getch();
					if (key == 13)
					{
						ShowCur(1);
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
								if(ds_dau_sach.list[i]->Check == false) //kiem tra dms cua dau sach co rong hay khong
								{
									thong_bao("Dau sach hien khong co sach nao.");
									return;
								}
								huong_dan_muon_sach_3();
								gotoxy(30, 35); 
								cout << "Nhap ma sach can muon: ";
								gotoxy(31, 36);
								cout << "(Go exit de thoat)";
								ShowCur(0);
								while (true)
								{
									if (kbhit())
									{
										char key2 = getch();
										if (key2 == 13)
										{
											gotoxy(31, 36);
											cout << "(Go exit de thoat)";			
											ShowCur(1);
											string masach; 
										Nhapmasach:	
											gotoxy(53, 35);
											Nhap_va_kiem_tra_bo_trong_du_lieu(masach, 53, 35);	
											if (masach == "Exit" || masach == "exit")
											{
												return;
											}					
											if (Kiem_tra_trung_ma_sach(ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach, masach) == false)
											{		
												thong_bao("Ma sach khong ton tai.");
												xoa_man_hinh(53, 35, 80, 1);
												gotoxy(53,35);
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
														xoa_man_hinh(53, 35, 80, 1);
														goto Nhapmasach;
													}
													else if (g->data.Trang_thai == 2)
													{
														thong_bao("Sach da thanh ly. Xin chon sach khac.");
														xoa_man_hinh(53, 35, 80, 1);
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
														/*// Test truong hop muon qua 7 ngay
														cout << "\tNHAP NGAY MUON\n";
														cout << "Nhap ngay: ";
														cin >> ngaymuon.Ngay;
														cout << "Nhap thang: ";
														cin >> ngaymuon.Thang;
														cout << "Nhap nam: ";
														cin >> ngaymuon.Nam;
														mt.Ngay_muon = ngaymuon;*/
														Lay_ngay_gio_he_thong(ngaymuon); // Lay ngay hien tai lam ngay muon
														mt.Ngay_muon = ngaymuon;
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
										else if (key2 == 27)
										{
											return;
										}
									}	
								}	

							}
						}
					}
					else if (key == 27)
					{
						return;
					}
				}
			}
		}
		Muon_sach(t->pRight, ds_dau_sach, ds_dms, mathe);
	}
}
//void Xu_li_tra_sach(TREE &t, DS_DAU_SACH &ds_dau_sach, DS_DANH_MUC_SACH &ds_dms, int mathe)
//{
//	if (t != NULL) // Duyet cay
//	{
//		Xu_li_tra_sach(t->pLeft, ds_dau_sach, ds_dms, mathe);
//		if (t->data.Ma_the == mathe)
//		{
//			Xuat_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->data.ds_muon_tra_cua_doc_gia, t);
//			if (t->data.So_luong_sach_dang_muon == 0)
//			{
//				gotoxy(30, 20);
//				cout << "Doc gia hien van chua muon sach nao.";
//				thong_bao("                                  ");
//				return;
//			}
//			ShowCur(0);
//			huong_dan_muon_sach_2();
//			gotoxy(30, 20);
//			cout << "Nhap ten sach can tra: ";
//			gotoxy(31, 22);
//			cout << "(Go exit de thoat)";
//			while (true)
//			{
//				if (kbhit())
//				{
//					char key = getch();
//					if (key == 13)
//					{
//						gotoxy(31,22);
//						cout << "(Go exit de thoat)";					
//						gotoxy(53, 20);
//						ShowCur(1);
//						NGAY_THANG ngaytra;	// Dung de luu ngay tra
//						string tensach;
//						do
//						{
//							Nhap_va_kiem_tra_bo_trong_du_lieu(tensach, 53, 20);
//							Chuan_hoa_chu(tensach);	
//							if (tensach == "Exit" || tensach == "exit")
//							{
//								return;
//							}							
//							if (Kiem_tra_ten_sach(ds_dau_sach, tensach) == false)
//							{
//								thong_bao("Sai ten sach. Xin nhap lai.");
//								xoa_man_hinh(53, 20, 80, 1);
//								gotoxy(53, 20);
//							}				
//						}while (Kiem_tra_ten_sach(ds_dau_sach, tensach) == false);
//						// Duyet danh sach de tim ra dau sach co ten giong voi sach can tra
//						for (int i = 0; i < ds_dau_sach.so_luong; i++) 
//						{
//							if (ds_dau_sach.list[i]->Ten_sach == tensach)
//							{
//								string tam; // Bien dung de luu lai ma sach cua sach duoc tra
//								 // Duyet ds muon tra cua doc gia de tim ra sach co ten do va tien hanh chinh sua thong tin
//								for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
//								{
//									string tensachtam;
//									tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
//									if (tensachtam == tensach)
//									{
//										if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2) // 0 la dang muon, 2 la lam mat sach. Lam mat sach thi khi den sach <=> Tra sach 
//										{
//											k->data.Trang_thai = 1; // Sua trang thai muon tra lai la 1 (Da tra)
//											Lay_ngay_gio_he_thong(ngaytra);
//											k->data.Ngay_tra = ngaytra; // Lay ngay hien tai lam ngay tra. Khong ro la nen cho nhap ngay hay lay luon ngay hien tai?
//											tam = k->data.Ma_sach; 
//											t->data.So_luong_sach_dang_muon--;
//											// Nen xoa hay khong? Xoa: du lieu duoc giai phong => Du da hon ve bo nho. Khong xoa: co the lay lai du lieu va lam them phan "Lich su muon sach"
//											Xoa_1_node_muon_tra_theo_ma_sach(t->data.ds_muon_tra_cua_doc_gia, tam);
//											break;
//										}
//									}
//								}
//								// Sua phan muon tra xong tien hanh sua thong tin danh muc sach do lai
//								for (NODE_DANH_MUC_SACH *g = ds_dau_sach.list[i]->ds_danh_muc_sach_cua_dau_sach.pHead; g != NULL; g = g->pNext)
//								{
//									if (g->data.Ma_sach == tam)
//									{
//										g->data.Trang_thai = 0; // Cho muon duoc									
//									}
//								}
//							}
//						}
//						gotoxy(30, 22);
//						cout << "Ngay tra: ";
//						Xuat_ngay_thang(ngaytra);
//						thong_bao("Xac nhan da tra.");
//						return;
//					}
//					else if (key == 27)
//					{
//						return;
//					}
//				}
//			}
//		}
//		Xu_li_tra_sach(t->pRight, ds_dau_sach, ds_dms, mathe);
//	}
//}
void Xu_li_tra_sach(TREE &t, DS_DAU_SACH &ds_dau_sach, DS_DANH_MUC_SACH &ds_dms, int mathe)
{
	ShowCur(0);
	huong_dan_tra_sach();
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
			int dem = 0;
			int chon = 0;
			for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2)
				{
					if (dem == 0) SetColor(27);
					string tensachtam;
					tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
					dem++;
					gotoxy(20,14+dem);
					cout<< k->data.Ma_sach<<"\t"<< k->data.Ngay_muon.Ngay << "/" << k->data.Ngay_muon.Thang << "/" << k->data.Ngay_muon.Nam<<"\t"<< tensachtam;
					if (k->data.Trang_thai == 0)
					{
						gotoxy(96,14+dem);
						cout << k->data.Trang_thai << " (Dang muon)";	
					}
					else if (k->data.Trang_thai == 2)
					{
						gotoxy(96,14+dem);
						cout << k->data.Trang_thai << " (Da lam mat)";	
					}
					Normal();
				}
			}
			do {
			int kytu;
			int flag = 1;
			kytu = getch();
  			if (kytu==0) kytu = getch();
  			switch (kytu) {
    		case Up :if (chon+1 > 1)
  			{
  		        Normal();
              	Xuat_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->data.ds_muon_tra_cua_doc_gia, t);
              	chon--;
              	dem = 0;
              	flag = 0;
              	for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2)
					{
						if (flag == chon)
						{
							SetColor(27);
							string tensachtam;
							tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
							dem++;
							gotoxy(20,14+dem);
							cout<< k->data.Ma_sach<<"\t"<< k->data.Ngay_muon.Ngay << "/" << k->data.Ngay_muon.Thang << "/" << k->data.Ngay_muon.Nam<<"\t"<< tensachtam;
							if (k->data.Trang_thai == 0)
							{
								gotoxy(96,14+dem);
								cout << k->data.Trang_thai << " (Dang muon)";	
							}
							else if (k->data.Trang_thai == 2)
							{
								gotoxy(96,14+dem);
								cout << k->data.Trang_thai << " (Da lam mat)";	
							}
							Normal();
							break;
						} 
			 			flag++;
			 			dem++;
					}
  			  	}
  			}
  			break;
  			case Down :if (chon+1 <t->data.So_luong_sach_dang_muon)
  			{
  		        Normal();
              	Xuat_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->data.ds_muon_tra_cua_doc_gia, t);
              	chon++;
              	dem = 0;
              	flag = 0;
              	for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2)
					{
						if (flag == chon)
						{
							SetColor(27);
							string tensachtam;
							tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
							dem++;
							gotoxy(20,14+dem);
							cout<< k->data.Ma_sach<<"\t"<< k->data.Ngay_muon.Ngay << "/" << k->data.Ngay_muon.Thang << "/" << k->data.Ngay_muon.Nam<<"\t"<< tensachtam;
							if (k->data.Trang_thai == 0)
							{
								gotoxy(96,14+dem);
								cout << k->data.Trang_thai << " (Dang muon)";	
							}
							else if (k->data.Trang_thai == 2)
							{
								gotoxy(96,14+dem);
								cout << k->data.Trang_thai << " (Da lam mat)";	
							}
							Normal();
							break;
						} 
			 			flag++;
			 			dem++;
					}
  			  	}	
  			}
  			break;
  			case 13 : 
  			{
  				if (t->data.So_luong_sach_dang_muon == 0)
				{
					gotoxy(30, 20);
					cout << "Doc gia hien van chua muon sach nao.";
					thong_bao("                                  ");
					return;
				}
  				flag = 0;
  				NGAY_THANG ngaytra;	// Dung de luu ngay tra
				string tensach;
				for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2)
					{
						if (flag == chon)
						{
							tensach = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
							break;
						} 
			 			flag++;
					}
  				}
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
									// Nen xoa hay khong? Xoa: du lieu duoc giai phong => Du da hon ve bo nho. Khong xoa: co the lay lai du lieu va lam them phan "Lich su muon sach"
									Xoa_1_node_muon_tra_theo_ma_sach(t->data.ds_muon_tra_cua_doc_gia, tam);
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
				chon = 0;
				xoa_man_hinh(18 ,12, 95, 15);
				khung_sach_dang_muon();
				dem = 0;
				for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2)
					{
						if (dem == 0) SetColor(27);
						string tensachtam;
						tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
						dem++;
						gotoxy(20,14+dem);
						cout<< k->data.Ma_sach<<"\t"<< k->data.Ngay_muon.Ngay << "/" << k->data.Ngay_muon.Thang << "/" << k->data.Ngay_muon.Nam<<"\t"<< tensachtam;
						if (k->data.Trang_thai == 0)
						{
							gotoxy(96,14+dem);
							cout << k->data.Trang_thai << " (Dang muon)";	
						}
						else if (k->data.Trang_thai == 2)
						{
							gotoxy(96,14+dem);
							cout << k->data.Trang_thai << " (Da lam mat)";	
						}
						Normal();
					}
				}
			}
			break;
  			case 27: return ; 
  			}  // end switch
  		} while (1);
  		
		}
		Xu_li_tra_sach(t->pRight, ds_dau_sach, ds_dms, mathe);
	}
}
void Xu_li_lam_mat_sach(TREE &t, DS_DAU_SACH &ds_dau_sach, DS_DANH_MUC_SACH &ds_dms, int mathe)
{
	ShowCur(0);
	huong_dan_tra_sach();
	if (t != NULL)
	{
		Xu_li_lam_mat_sach(t->pLeft, ds_dau_sach, ds_dms, mathe);
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
			int dem = 0;
			int chon = 0;
			for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2)
				{
					if (dem == 0) SetColor(27);
					string tensachtam;
					tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
					dem++;
					gotoxy(20,14+dem);
					cout<< k->data.Ma_sach<<"\t"<< k->data.Ngay_muon.Ngay << "/" << k->data.Ngay_muon.Thang << "/" << k->data.Ngay_muon.Nam<<"\t"<< tensachtam;
					if (k->data.Trang_thai == 0)
					{
						gotoxy(96,14+dem);
						cout << k->data.Trang_thai << " (Dang muon)";	
					}
					else if (k->data.Trang_thai == 2)
					{
						gotoxy(96,14+dem);
						cout << k->data.Trang_thai << " (Da lam mat)";	
					}
					Normal();
				}
			}
			do {
			int kytu;
			int flag = 1;
			kytu = getch();
  			if (kytu==0) kytu = getch();
  			switch (kytu) {
    		case Up :if (chon+1 > 1)
  			{
  		        Normal();
              	Xuat_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->data.ds_muon_tra_cua_doc_gia, t);
              	chon--;
              	dem = 0;
              	flag = 0;
              	for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2)
					{
						if (flag == chon)
						{
							SetColor(27);
							string tensachtam;
							tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
							dem++;
							gotoxy(20,14+dem);
							cout<< k->data.Ma_sach<<"\t"<< k->data.Ngay_muon.Ngay << "/" << k->data.Ngay_muon.Thang << "/" << k->data.Ngay_muon.Nam<<"\t"<< tensachtam;
							if (k->data.Trang_thai == 0)
							{
								gotoxy(96,14+dem);
								cout << k->data.Trang_thai << " (Dang muon)";	
							}
							else if (k->data.Trang_thai == 2)
							{
								gotoxy(96,14+dem);
								cout << k->data.Trang_thai << " (Da lam mat)";	
							}
							Normal();
							break;
						} 
			 			flag++;
			 			dem++;
					}
  			  	}
  			}
  			break;
  			case Down :if (chon+1 <t->data.So_luong_sach_dang_muon)
  			{
  		        Normal();
              	Xuat_danh_sach_sach_dang_muon_cua_1_doc_gia(ds_dau_sach, t->data.ds_muon_tra_cua_doc_gia, t);
              	chon++;
              	dem = 0;
              	flag = 0;
              	for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2)
					{
						if (flag == chon)
						{
							SetColor(27);
							string tensachtam;
							tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
							dem++;
							gotoxy(20,14+dem);
							cout<< k->data.Ma_sach<<"\t"<< k->data.Ngay_muon.Ngay << "/" << k->data.Ngay_muon.Thang << "/" << k->data.Ngay_muon.Nam<<"\t"<< tensachtam;
							if (k->data.Trang_thai == 0)
							{
								gotoxy(96,14+dem);
								cout << k->data.Trang_thai << " (Dang muon)";	
							}
							else if (k->data.Trang_thai == 2)
							{
								gotoxy(96,14+dem);
								cout << k->data.Trang_thai << " (Da lam mat)";	
							}
							Normal();
							break;
						} 
			 			flag++;
			 			dem++;
					}
  			  	}	
  			}
  			break;
  			case 13 : 
  			{
  				if (t->data.So_luong_sach_dang_muon == 0)
				{
					gotoxy(30, 20);
					cout << "Doc gia hien van chua muon sach nao.";
					thong_bao("                                  ");
					return;
				}
  				flag = 0;
  				NGAY_THANG ngaytra;	// Dung de luu ngay tra
				string tensach;
				for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2)
					{
						if (flag == chon)
						{
							tensach = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
							break;
						} 
			 			flag++;
					}
  				}
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
											thong_bao("Xac nhan lam mat.");
										}
										else
										{
											thong_bao("Sach da bi lam mat.");
										}
									}
								}
							}
						}
				chon = 0;
				xoa_man_hinh(18 ,12, 95, 15);
				khung_sach_dang_muon();
				dem = 0;
				for (NODE_MUON_TRA *k = t->data.ds_muon_tra_cua_doc_gia.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2)
					{
						if (dem == 0) SetColor(27);
						string tensachtam;
						tensachtam = Tra_ve_ten_sach(ds_dau_sach, k->data.Ma_sach);
						dem++;
						gotoxy(20,14+dem);
						cout<< k->data.Ma_sach<<"\t"<< k->data.Ngay_muon.Ngay << "/" << k->data.Ngay_muon.Thang << "/" << k->data.Ngay_muon.Nam<<"\t"<< tensachtam;
						if (k->data.Trang_thai == 0)
						{
							gotoxy(96,14+dem);
							cout << k->data.Trang_thai << " (Dang muon)";	
						}
						else if (k->data.Trang_thai == 2)
						{
							gotoxy(96,14+dem);
							cout << k->data.Trang_thai << " (Da lam mat)";	
						}
						Normal();
					}
				}
			}
			break;
  			case 27: return ; 
  			}  // end switch
  		} while (1);
		
		}	
		Xu_li_lam_mat_sach(t->pRight, ds_dau_sach, ds_dms, mathe);
	}
}	

#endif
