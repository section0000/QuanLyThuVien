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
void xoa_man_hinh()
  {
  	for(int i=2; i<=130; i++)
  	{
		for(int j=4; j<=36; j++)
		{
			gotoxy(i,j); cout<<" ";	
		}	
	}
  }
void khung_vien()
{
	for (int i=0; i<=133; i++)
	{
		gotoxy(0+i, 0);
		cout<<char(219);
	}
	for(int i=1; i<=40; i++)
	{
		gotoxy(0, 0+i);
		cout<<char(219);
	}
	for(int i=1; i<=40; i++)
	{
		gotoxy(133, 0+i);
		cout<<char(219);
	}
	for(int i=0; i<=133; i++)
	{
		gotoxy(0+i, 40);
		cout<<char(219);
	}
	gotoxy(60,2);
	cout<<"QUAN LY THU VIEN";
}
//void khung_menu()
//{
//	for (int i=0; i<=30; i++)
//	{
//		gotoxy(52+i, 4);
//		cout<<char(219);
//	}
//	for(int i=1; i<=12; i++)
//	{
//		gotoxy(52, 4+i);
//		cout<<char(219);
//	}
//	for(int i=1; i<=12; i++)
//	{
//		gotoxy(82, 4+i);
//		cout<<char(219);
//	}
//	for(int i=0; i<=30; i++)
//	{
//		gotoxy(52+i, 16);
//		cout<<char(219);
//	}
//}
void khung_menu()
{
	for (int i=0; i<=37; i++)
	{
		gotoxy(49+i, 4);
		cout<<char(219);
	}
	for(int i=1; i<=15; i++)
	{
		gotoxy(49, 4+i);
		cout<<char(219);
	}
	for(int i=1; i<=15; i++)
	{
		gotoxy(86, 4+i);
		cout<<char(219);
	}
	for(int i=0; i<=37; i++)
	{
		gotoxy(49+i, 19);
		cout<<char(219);
	}
}
void huong_dan()
{
	gotoxy(2, 39);
	cout<<"Mui ten len xuong: Dieu khien thanh sang | Enter: Chon - | Esc: Thoat";
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
const int so_item_ds = 6;
const int dong_menu_ds =8;
const int cot_menu_ds = 51 ;
char menu_ds [so_item_ds][50] = {"           THEM DAU SACH          ",
			                  	 "        CHINH SUA DAU SACH        ",
			                   	 "           XOA DAU SACH           ",
			                  	 "      XUAT THONG TIN DAU SACH     ",
								 "             TIM SACH             ",
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
const int so_item_dms = 4;
const int dong_menu_dms =8;
const int cot_menu_dms = 51 ;
char menu_dms [so_item_dms][50] = {"     THEM SACH VAO 1 DAU SACH     ",
				  			 	   "     XOA SACH THUOC 1 DAU SACH    ",
						 	  	   "  CHINH SUA SACH THUOC 1 DAU SACH ",
								   "    XUAT DANH SACH THEO THE LOAI  "};
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
const int so_item_mt = 2;
const int dong_menu_mt =8;
const int cot_menu_mt = 51 ;
char menu_mt [so_item_mt][50] = {"             MUON SACH            ",
				  			     "             TRA SACH             "};
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



#endif
