#include "Casee.cpp"
#include "Dohoa1.cpp"
#include "Menu.cpp"
int main()
{
	system("title HOTEL MANAGEMENT SYSTEM");
	system("mode con: cols=88 lines=30");
	textcolor(11);
	Banner();
	textcolor(10);
	if (dangnhap(0) == 1)
	{   
		loadingbar();
		cls();
		pwellcome();
		Sleep(300);
		cls();
		Menu ob;
		ob.DeSign();
		cls();
	}
	else
	{
		cout << "   Ban da dang nhap qua so lan !\n";
		textcolor(10);
		cout << "	Nhan Phim Bat Ki De Thoat Chuong Trinh";
		getch();
		exit(0);
	}
}
