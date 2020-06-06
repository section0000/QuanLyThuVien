#ifndef Dohoa
#define Dohoa
#include <graphics.h>
//#include <string>
//#include <iostream>
#include<iomanip>
#include <conio.h>
using namespace std;

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//void SetColor(WORD color)
//{
//	HANDLE hConsoleOutput;
//	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
//	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
//	WORD wAttributes = screen_buffer_info.wAttributes;
//	color &= 0x000f;
//	wAttributes &= 0xfff0;
//	wAttributes |= color;
//	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
//}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
void xoa_man_hinh(int x, int y, int rong, int cao)
{
	for(int i=0; i<rong; i++)
	{
		for(int j=0; j<cao; j++)
		{
			gotoxy(x+i, y+j);
			cout<<" ";
		}
	}
}
void khung_vien()
{
	for (int i=0; i<=133; i++)
	{
		gotoxy(0+i, 0);
		cout<<char(219);
		gotoxy(0+i, 40);
		cout<<char(219);
	}
	for(int i=1; i<=40; i++)
	{
		gotoxy(0, 0+i);
		cout<<char(219);
		gotoxy(133, 0+i);
		cout<<char(219);
	}
	gotoxy(60,2);
	cout<<"QUAN LY THU VIEN";
}
void khung_menu()
{
	for (int i=0; i<=37; i++)
	{
		gotoxy(49+i, 4);
		cout<<char(219);
		gotoxy(49+i, 19);
		cout<<char(219);
	}
	for(int i=1; i<=15; i++)
	{
		gotoxy(49, 4+i);
		cout<<char(219);
		gotoxy(86, 4+i);
		cout<<char(219);
	}
}
void huong_dan()
{
	gotoxy(2, 39);
	cout<<"Mui ten len xuong: Dieu khien thanh sang | Enter: Chon | Esc: Thoat";
}
void Normal () {
	SetColor(15);
	SetBGColor(0);
}
void HighLight () {
	SetColor(15);
	SetBGColor(3);
}
void DeMuc(string s)
{
	gotoxy(51, 6); textcolor(14); 
	cout<<s; textcolor(15);
}
void ve_lai_man_hinh()
{
	system("cls");
    khung_vien();
    huong_dan();
}

void xoa_thong_bao()
{
	for (int i=2; i<120; i++)
	{
		gotoxy(i, 37);
		cout<<" ";
	}
}
void thong_bao(string s)
{
	//ShowCur(0);
	xoa_thong_bao();
	gotoxy(3, 37); textcolor(10); 
	cout<<"THONG BAO: "<<s<<" "; 
	system("pause"); textcolor(15);
	xoa_thong_bao();
}
//void xoa_tuy_chon(int x, int y, int chieu_rong, int chieu_cao)
//{
//	for(int i=0; i<chieu_rong; i++)
//	{
//		for(int j=0; j<chieu_cao; j++)
//		{
//			gotoxy(x+i, y+j);
//			cout<<" ";
//		}
//	}
//}
void khung_xuat_thong_tin_dg(int x, int y, int chieu_cao) // cot bat dau tu 13 - hang bat dau tu 11
{
	gotoxy(x+2,y+1); //15 27 48 64 86 98 108 - 12
	cout <<"Ma the";
	gotoxy(x+14,y+1);
	cout<<"Ho ten";
	gotoxy(x+35,y+1);
	cout<<"Gioi tinh";
	gotoxy(x+51,y+1);//61
	cout<<"Trang thai the";
	gotoxy(x+73,y+1);
	cout<<"Dang muon";
	gotoxy(x+85,y+1);
	cout<<"Da muon";
	gotoxy(x+95,y+1);
	cout<<"So ngay qua han";
	for (int i=0; i<110; i++) { 
		gotoxy(x+1+i,y);
		cout<<"_";
		gotoxy(x+1+i,y+2);
		cout<<"_";	
		gotoxy(x+1+i,y+chieu_cao);
		cout<<"_";	
	}
	for (int i=0; i<chieu_cao; i++) { //cao 24
		gotoxy(x,y+1+i); //13 22 46 58 83 96 106 124
		cout<<"|";
		gotoxy(x+9,y+1+i);
		cout<<"|";
		gotoxy(x+33,y+1+i);
		cout<<"|";
		gotoxy(x+45,y+1+i);
		cout<<"|";
		gotoxy(x+70,y+1+i);
		cout<<"|";
		gotoxy(x+83,y+1+i);
		cout<<"|";
		gotoxy(x+93,y+1+i);
		cout<<"|";
		gotoxy(x+111,y+1+i);
		cout<<"|";
	}
//	int c;
//	do
//	{
//	if(kbhit())
//	{
//		c = getch();
//		if(c==0) c=getch();
//		if(c==27) break;
//	}
//	} while(1);
}
void khung_sach_dang_muon()
{
	gotoxy(20,13);
	cout<<"Ma sach \tNgay muon \tTen sach \t\t\t\t\tTrang thai sach";	
	for (int i=0; i<93; i++) { 
		gotoxy(19+i,12);
		cout<<"_";
		gotoxy(19+i,14);
		cout<<"_";	
		gotoxy(19+i,18);
		cout<<"_";	
	}
	for (int i=0; i<6; i++) { 
		gotoxy(18,13+i); 
		cout<<"|";
		gotoxy(28,13+i); 
		cout<<"|";
		gotoxy(43,13+i); 
		cout<<"|";
		gotoxy(94,13+i); 
		cout<<"|";
		gotoxy(112,13+i);
		cout<<"|";
	}
}
void khung_xuat_thong_tin_ds(int x, int y, int chieu_cao) // cot bat dau tu 10 - hang bat dau tu 9
{
	gotoxy(x+3,y+1);
	cout <<"ISBN";
	gotoxy(x+23,y+1);
	cout<<"Ten sach";
	gotoxy(x+46,y+1);
	cout<<"So trang";
	gotoxy(x+65,y+1);//61
	cout<<"Tac gia";
	gotoxy(x+84,y+1);
	cout<<"Nam xuat ban";
	gotoxy(x+100,y+1);
	cout<<"The loai";
	gotoxy(x+113,y+1);
	cout<<"Luot muon";
	for (int i=0; i<122; i++) { 
		gotoxy(x+1+i,y);
		cout<<"_";
		gotoxy(x+1+i,y+2);
		cout<<"_";	
		gotoxy(x+1+i,y+chieu_cao);
		cout<<"_";	
	}
	for (int i=0; i<chieu_cao; i++) { //cao 24
		gotoxy(x,y+1+i); //13 22 46 58 83 96 106 124
		cout<<"|";
		gotoxy(x+9,y+1+i);
		cout<<"|";
		gotoxy(x+44,y+1+i);
		cout<<"|";
		gotoxy(x+55,y+1+i);
		cout<<"|";
		gotoxy(x+82,y+1+i);
		cout<<"|";
		gotoxy(x+97,y+1+i);
		cout<<"|";
		gotoxy(x+111,y+1+i);
		cout<<"|";
		gotoxy(x+123,y+1+i);
		cout<<"|";
	}
}
void khung_xuat_dms(int x, int y, int chieu_cao)
{
	gotoxy(x+2,y+1);
	cout <<"Ma sach";
	gotoxy(x+27,y+1);
	cout<<"Vi tri";
	gotoxy(x+60,y+1);
	cout<<"Trang thai";
	for (int i=0; i<79; i++) { 
		gotoxy(x+1+i,y);
		cout<<"_";
		gotoxy(x+1+i,y+2);
		cout<<"_";	
		gotoxy(x+1+i,y+chieu_cao);
		cout<<"_";	
	}
	for (int i=0; i<chieu_cao; i++) { 
		gotoxy(x,y+1+i);
		cout<<"|";
		gotoxy(x+10,y+1+i);
		cout<<"|";
		gotoxy(x+50,y+1+i);
		cout<<"|";
		gotoxy(x+80,y+1+i);
		cout<<"|";
	}
}






const int Up = 72;
const int Down = 80;
//menu doc gia
const int so_item_dg = 7;
const int dong_menu_dg =8;
const int cot_menu_dg = 51 ;
char menu_dg [so_item_dg][50] = {"           THEM DOC GIA           ",
			                  	 "         CHINH SUA DOC GIA        ",
			                   	 "            XOA DOC GIA           ",
			                  	 "   SACH DANG MUON CUA 1 DOC GIA   ",
			                 	 "     DANH SACH DOC GIA QUA HAN    ",
				  			 	 "     XUAT DOC GIA THEO HO TEN     ",
						 	  	 "     XUAT DOC GIA THEO MA THE     "};
int MenuDongDG(char td [so_item_dg][50]){
	DeMuc("             DOC GIA              ");
	khung_menu();
	
  Normal();
  //system("cls");   
  int chon =0;
  int i; 
  for ( i=0; i< so_item_dg ; i++)
  { gotoxy(cot_menu_dg, dong_menu_dg +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot_menu_dg,dong_menu_dg+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		              	Normal();
              	gotoxy(cot_menu_dg,dong_menu_dg+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot_menu_dg,dong_menu_dg+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item_dg)
  			  {
  		        Normal();
              	gotoxy(cot_menu_dg,dong_menu_dg+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot_menu_dg,dong_menu_dg+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon+1;
  	case 27: return 0;
	  
  }  // end switch
  } while (1);
}
//menu dau sach
const int so_item_ds = 7;
const int dong_menu_ds =8;
const int cot_menu_ds = 51 ;
char menu_ds [so_item_ds][50] = {"           THEM DAU SACH          ",
			                  	 "        CHINH SUA DAU SACH        ",
			                   	 "           XOA DAU SACH           ",
			                  	 "      XUAT THONG TIN DAU SACH     ",
								 "             TIM SACH             ",
								 "    XUAT DAU SACH THEO THE LOAI   ",
								 " 10 DAU SACH DUOC MUON NHIEU NHAT "};
int MenuDongDS(char td [so_item_ds][50]){
	DeMuc("             DAU SACH             ");
	khung_menu();
	
  Normal();
  //system("cls");   
  int chon =0;
  int i; 
  for ( i=0; i< so_item_ds ; i++)
  { gotoxy(cot_menu_ds, dong_menu_ds +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot_menu_ds,dong_menu_ds+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		              	Normal();
              	gotoxy(cot_menu_ds,dong_menu_ds+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot_menu_ds,dong_menu_ds+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item_ds)
  			  {
  		        Normal();
              	gotoxy(cot_menu_ds,dong_menu_ds+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot_menu_ds,dong_menu_ds+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon+1;
  	case 27: return 0;
	  
  }  // end switch
  } while (1);
}
//menu danh muc sach
const int so_item_dms = 3;
const int dong_menu_dms =8;
const int cot_menu_dms = 51 ;
char menu_dms [so_item_dms][50] = {"     THEM SACH VAO 1 DAU SACH     ",
				  			 	   "     XOA SACH THUOC 1 DAU SACH    ",
						 	  	   "  CHINH SUA SACH THUOC 1 DAU SACH "};
int MenuDongDMS(char td [so_item_dms][50]){
	DeMuc("          DANH MUC SACH           ");
	khung_menu();
	
  Normal();
  //system("cls");   
  int chon =0;
  int i; 
  for ( i=0; i< so_item_dms ; i++)
  { gotoxy(cot_menu_dms, dong_menu_dms +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot_menu_dms,dong_menu_dms+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		              	Normal();
              	gotoxy(cot_menu_dms,dong_menu_dms+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot_menu_dms,dong_menu_dms+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item_dms)
  			  {
  		        Normal();
              	gotoxy(cot_menu_dms,dong_menu_dms+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot_menu_dms,dong_menu_dms+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon+1;
  	case 27: return 0;
	  
  }  // end switch
  } while (1);
}
//menu muon tra
const int so_item_mt =4;
const int dong_menu_mt =8;
const int cot_menu_mt = 51 ;
char menu_mt [so_item_mt][50] = {"             MUON SACH            ",
				  			     "             TRA SACH             ",
				  			     "           LAM MAT SACH           ",
				  			     "             DEN SACH             "};
int MenuDongMT(char td [so_item_mt][50]){
	DeMuc("          MUON TRA SACH          ");
	khung_menu();
	
  Normal();
  //system("cls");   
  int chon =0;
  int i; 
  for ( i=0; i< so_item_mt ; i++)
  { gotoxy(cot_menu_mt, dong_menu_mt +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot_menu_mt,dong_menu_mt+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		              	Normal();
              	gotoxy(cot_menu_mt,dong_menu_mt+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot_menu_mt,dong_menu_mt+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item_mt)
  			  {
  		        Normal();
              	gotoxy(cot_menu_mt,dong_menu_mt+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot_menu_mt,dong_menu_mt+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon+1;
  	case 27: return 0;
	  
  }  // end switch
  } while (1);
}

//menu thoat
const int so_item_thoat = 2;
const int dong_menu_thoat =25;
const int cot_menu_thoat = 63 ;
char menu_thoat [so_item_thoat][50] = {"   CO    ",
				  			           "  KHONG  "};
int MenuDongTHOAT(char td [so_item_thoat][50]){
	//DeMuc("          MUON TRA SACH          ");
	//khung_menu();
gotoxy(54,23);
cout<<"LUU DU LIEU TRUOC KHI THOAT?";
  Normal();
  //system("cls");   
  int chon =0;
  int i; 
  for ( i=0; i< so_item_thoat ; i++)
  { gotoxy(cot_menu_thoat, dong_menu_thoat +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot_menu_thoat,dong_menu_thoat+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		              	Normal();
              	gotoxy(cot_menu_thoat,dong_menu_thoat+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot_menu_thoat,dong_menu_thoat+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item_thoat)
  			  {
  		        Normal();
              	gotoxy(cot_menu_thoat,dong_menu_thoat+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot_menu_thoat,dong_menu_thoat+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon+1;
  	case 27: return 0;
	  
  }  // end switch
  } while (1);
}




#endif
