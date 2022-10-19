#include"Dohoa1.h"
using namespace std;
void ccolor(int clr){

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, clr);

//the above code displays colorful background. if you want colorful then you can remove the above comment but not the code, only comment//
}
void clreol( ) {
	COORD coord;
	DWORD written;
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	coord.X = info.dwCursorPosition.X;
	coord.Y = info.dwCursorPosition.Y;
	FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
  	info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
	gotoxy (info.dwCursorPosition.X , info.dwCursorPosition.Y );
}
void gotoxy(int x,int y)
{   
    static HANDLE mau=NULL;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD tinh = {x,y} ;
	SetConsoleCursorPosition(mau,tinh ) ;
}
void cls(){

	system("cls");

}
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void pwellcome(){
	ccolor(26);
    textcolor(12);
	char welcome[50]="WELCOME";
	char welcome2[50]=" TO";
	char welcome3[50]="HOTEL ";
	char welcome4[50]="   MANAGEMENT SYSTEM";
	cout<<"\n\n\n\n\n\t\t\t";
	for(int wlc=0; wlc<strlen(welcome);wlc++){

		cout<<welcome[wlc];
		Sleep(100);
	}
	ccolor(26);
	cout<<"\n\n\t\t\t\t ";
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){

		cout<<welcome2[wlc2];
		Sleep(100);
	}
	ccolor(26);
	cout<<"\n\n\t\t\t\t\t ";
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){

			cout<<welcome3[wlc3];
		}
		else{

			cout<<welcome3[wlc3];
		}

		Sleep(100);
	}
	ccolor(26);
	cout<<"\n\n\n\t\t\t\t ";
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){

			cout<<welcome4[wlc3];
		}
		else{

			cout<<welcome4[wlc3];
		}
		Sleep(100);
	}
	ccolor(26);

}
void loadingbar(void){
	  textcolor(10);
	for (int i=15;i<=100;i+=5){

		cls();
		cout<<"\n\n\n\n\n\n\n\t\t\t\t";
		cout<<i<<"% Loading...\n\n\t\t";

		cout<<"";

		for (int j=0; j<i;j+=2){

			ccolor(160+j);
			cout<<" ";
			ccolor(26);

		}
		Sleep(100);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(100);
		}

	}

}
