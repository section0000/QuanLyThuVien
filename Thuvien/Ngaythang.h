#ifndef Ngaythang
#define Ngaythang
#include "Data.h"
#include<ctime>
/*bool Nam_nhuan(int nam)
{
    if (nam % 400 == 0)
	{
		return true;
	}     
    if (nam % 4 == 0 && nam % 100 != 0) 
    {
    	return true;
	}
    return false; 	
}*/
void Xuat_ngay_thang(NGAY_THANG date)
{
	cout << date.Ngay << "/" << date.Thang << "/" << date.Nam;
}
void Lay_ngay_gio_he_thong(NGAY_THANG &date) // Muon biet ro hon len google search "Date va time C++"
{
	tm *Today; // Tao 1 struct thoi gian
	time_t ltime; // Tao 1 bien thuoc kieu du lieu time
	time(&ltime); // Tra ve so giay tinh tu epoch (00:00:00 1/1/1970 theo UTC)
	Today = localtime(&ltime); // Dua so giay o tren vao 1 cau truc thoi gian tm
	date.Ngay = Today->tm_mday;
	date.Thang = Today->tm_mon + 1;
	date.Nam = Today->tm_year + 1900;
}
int Lay_nam_he_thong() // Bat dieu kien khong cho nhap nam xuat ban lon hon nam hien tai
{
	tm *Today; 
	time_t ltime; 
	time(&ltime);
	Today = localtime(&ltime);
	return (Today->tm_year + 1900);
}
int Tinh_ngay(NGAY_THANG date) // http://mathforum.org/library/drmath/view/66535.html
{
	if (date.Thang < 3)
	{
		date.Nam--;
		date.Thang = date.Thang + 12;
	}
	return 365*date.Nam + date.Nam/4 - date.Nam/100 + date.Nam/400 + date.Ngay + (153 * date.Thang + 8)/5;
}
int Khoang_cach_giua_2_ngay(NGAY_THANG date1)
{
	NGAY_THANG date2;
	Lay_ngay_gio_he_thong(date2);
	return (Tinh_ngay(date2) - Tinh_ngay(date1));
}
int So_ngay_muon(DS_MUON_TRA ds_mt)
{
	int max = 0;
	int ngay;
	for (NODE_MUON_TRA *k = ds_mt.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.Trang_thai == 0 || k->data.Trang_thai == 2) // Dang muon hoac lam mat sach ma chua den <=> Chua tra sach
		{
			ngay = Khoang_cach_giua_2_ngay(k->data.Ngay_muon);
			if (max < ngay)
			{
				max = ngay;
			}
		}
	}
	return max;
}
int Ngay_qua_han(DS_MUON_TRA ds_mt)
{
	int songaymuon = So_ngay_muon(ds_mt);
	return songaymuon - 7;
}
#endif
