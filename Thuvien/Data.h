#ifndef Data
#define Data
#include<string>

const int MAX_DAU_SACH = 1000;
const int MA_THE_MIN = 1;
const int MA_THE_MAX = 40000;
// Danh muc sach
struct danh_muc_sach
{
	string Ma_sach;
	int Trang_thai; // 0: Cho muon duoc, 1: Da co nguoi muon, 2: Sach da thanh ly
	string Vi_tri;	
};	
typedef struct danh_muc_sach DANH_MUC_SACH;
struct node_danh_muc_sach
{
	DANH_MUC_SACH data;
	struct node_danh_muc_sach *pNext;	
};
typedef struct node_danh_muc_sach NODE_DANH_MUC_SACH;
struct ds_danh_muc_sach
{
	// Khoi tao danh sach
	NODE_DANH_MUC_SACH *pHead = NULL; 
	NODE_DANH_MUC_SACH *pTail = NULL;
	// Khai bao so luong
	int so_luong = 0;	
};
typedef struct ds_danh_muc_sach DS_DANH_MUC_SACH;
// Dau sach
struct dau_sach
{
	string ISBN;
	string Ten_sach;
	int So_trang;
	string Tac_gia;
	int Nam_xuat_ban;
	string The_loai;
	int So_lan_muon = 0;
	// *dms	
	DS_DANH_MUC_SACH ds_danh_muc_sach_cua_dau_sach;
	bool Check; // True: dau sach hien tai van con sach, khong the xoa. False: dau sach hien tai dang rong, co the xoa
};
typedef struct dau_sach DAU_SACH;
struct ds_dau_sach
{
	DAU_SACH *list[MAX_DAU_SACH];
	int so_luong = 0;	
};
typedef struct ds_dau_sach DS_DAU_SACH;
// Muon tra
struct ngay_thang
{
	int Ngay;
	int Thang;
	int Nam;
};
typedef struct ngay_thang NGAY_THANG;
struct muon_tra
{
	string Ma_sach;
	NGAY_THANG Ngay_muon;
	NGAY_THANG Ngay_tra;
	int Trang_thai; // 0: Dang muon, 1: Da tra, 2: Lam mat sach
	// Phan nay them vao, khong co trong yeu cau
	string Ten_sach;
};
typedef struct muon_tra MUON_TRA;
struct node_muon_tra
{
	MUON_TRA data;
	struct node_muon_tra *pNext;
	struct node_muon_tra *pBack;
};
typedef struct node_muon_tra NODE_MUON_TRA;
struct ds_muon_tra
{
	// Khoi tao danh sach
	NODE_MUON_TRA *pHead = NULL;
	NODE_MUON_TRA *pTail = NULL;
	// Khai bao so luong
	int so_luong = 0;	
};
typedef struct ds_muon_tra DS_MUON_TRA;
// The doc gia
struct doc_gia
{
	int Ma_the;
	string Ho;
	string Ten;
	string Phai;
	int Trang_thai_the; // 1: Dang hoat dong, 0: Bi khoa	
	int So_luong_sach_dang_muon;
	int So_ngay_qua_han;
	// Con tro
	DS_MUON_TRA ds_muon_tra_cua_doc_gia;
};
typedef struct doc_gia DOC_GIA;
struct node_doc_gia
{
	DOC_GIA data;
	struct node_doc_gia *pLeft;
	struct node_doc_gia *pRight;	
};
typedef struct node_doc_gia NODE_DOC_GIA;
typedef NODE_DOC_GIA *TREE;
struct ds_doc_gia
{
	int so_luong = 0;	
};
typedef struct ds_doc_gia DS_DOC_GIA;
#endif
