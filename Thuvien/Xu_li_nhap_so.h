#ifndef Xu_li_nhap_so
#define Xu_li_nhap_so
#include<limits>
#include<ctype.h>  // De lay ham isdigit()
#include<sstream>  // De convert string sang int

void Nhap_so(int &n)
{
	string user_string_num = "";
	
    int is_num = 0;
    int decimal_count = 0; // Kiem tra xem so duoc nhap co phai la so thap phan khong
    int user_converted_num;

    bool is_num_bool = false; // Kiem tra xem co phai la so nguyen khong (Dung de thoat khoi vong lap)
    bool contains_spaces = false; // Kiem tra xem so duoc nhap co chua khoang trang khong. VD: 4   4
    bool retype = false; // Muc dich la de khi nhap du lieu khong hop le no hien len thong bao yeu cau nhap lai 

    do
    {
    	// cout << "Nhap so: " // Test chuong trinh thoi
		if (retype == true)
		{
			ShowCur(1);
			xoa_man_hinh(30, 9, 90, 1);
			gotoxy(30, 9);
			cout << "Nhap ma the doc gia: ";
			gotoxy(51, 9);
			//cout << "Nhap lai: ";
		}
        do
        {
        	getline(cin, user_string_num);
        	if (user_string_num == "") // Kiem tra truong hop bo trong du lieu
        	{
//        		cout << "=> Khong duoc bo trong du lieu.\n";
//        		cout << "Nhap lai: ";
				thong_bao("Khong duoc bo trong du lieu."); 
				ShowCur(1);
				xoa_man_hinh(30, 9, 90, 1);
				gotoxy(30, 9);
				cout << "Nhap ma the doc gia: ";
				gotoxy(51, 9);
				//cout << "Nhap lai: ";
			}
		}while (user_string_num == "");
		for (int i = 0; i < user_string_num.size(); i++)
		{
			if (isspace(user_string_num[i]) == true)
			{
				contains_spaces = true;
			}
		}
        if (user_string_num[0] == '-') // Kiem tra xem co phai so am khong
        {
        	is_num++;
		}
        if (user_string_num[0] == '0' && isdigit(user_string_num[1])) // Neu user nhap so co so 0 o dau => So khong hop le
        {
        	is_num = 0;
		}
        else 
        {
            for (int i = 0; i < user_string_num.size(); i++)
            {
            	// Kiem tra tung ki tu xem co phai la so khong
                if (isdigit(user_string_num[i]))
                {
                	is_num++;
				}
				// Kiem tra xem co phai so thap phan khong (Do ta can int nen neu nhap float <=> Khong hop le)
                if (user_string_num[i] == '.')
                {
                	decimal_count++;
				}
            }
        }
        if (decimal_count == 1)
        {
        	is_num = 0;
		}   
		// Neu input dung la 1 so nguyen hop le
        if (is_num == user_string_num.size() && contains_spaces == false) 
        {
        	// Convert user_string_num tu string sang int bang phuong thuc str_stream_object
            stringstream str_stream_object(user_string_num);
            // Khi nay str_stream_object da chua noi dung cua user_string_num, ta can phai dua no vao user_converted_num
            str_stream_object >> user_converted_num;
            is_num_bool = true; // Dung de ra khoi vong lap
            // Hien thi thong bao convert thanh cong (Co the bo qua phan nay)
//            cout << endl
//                 << user_string_num << "(user_string_num) "
//                 << "la mot so!"  << endl
//                 << user_converted_num << "(user_converted_num) "
//                 << "la mot so!"  << endl
//                 << endl;
        }
        else
        {
        	// Thong bao loi
        	thong_bao("Ma so khong hop le.");
        	xoa_man_hinh(30, 9, 90, 1);
			gotoxy(30, 9);
			cout << "Nhap ma the doc gia: ";
			gotoxy(51, 9);
//            cout << endl
//                 << "So khong duoc phep chua khoang trang.\n"
//                 << "So khong duoc phep chua chu cai.\n"
//                 << "So khong duoc phep chua cac bieu tuong.\n"
//                 << "So khong the la so thap phan.\n" 
//                 << endl;
          	// 	 Clear va ingore:
            // "When an input error is made, the stream "breaks," cin returns false, and the program stops. It's very important 
			// to guard against such errors as we did in the program. But what if we want to recover from the error,
			// rather than have the program stop? There are two steps to recovering from an error:
			// 1. Clear the error with cin.clear().
			// 2. Remove the incorrect characters from the stream. One way to do this is with cin.ignore()" 
            cin.clear(); // Hieu nom na la reset lai trang thai cua stream tu bad -> good
            // Ham ignore co 2 tham so: 1 la cho biet can bo qua bao nhieu ki tu, 2 la xac dinh ki tu cuoi cung can bo qua (Giong nhu diem dau va diem cuoi)
        //cin.ignore(numeric_limits<streamsize>::max(), '\n'); // numeric_limits<streamsize>::max(): Gia tri lon nhat cua mot stream (max)
            													 // Noi cach khac: y nghia cua no trong ham ignore nay la 
            													 // 	khong gioi han so luong ki tu bo qua
  
			// Reset lai cac gia tri 
            is_num_bool     = false;
            is_num          = 0;
            decimal_count   = 0;
            contains_spaces = false;
            retype	 		= true;
        }
    }while (is_num_bool == false);
    n = user_converted_num;
}
#endif
