#include "Casee.h"
using namespace std;
void Banner(){   
	            
				ifstream file;
				file.open("Banner.txt", ios_base::in); //import file thì copy đường dẫn rồi đổi \ thành \\ hoặc /
				string line;
				while (getline(file, line)) {
					cout << line << endl;
					Sleep(30); 
				}
				file.close();
}
int dangnhap(int c){
char a[10],b;
string pin="";
	cout<<"------------- Dang Nhap tai khoan cua ban ------------------ !\n";
	cout<<"--------------Nhap tai khoan: ";cin>>a;
	cout<<"--------------Nhap mat khau: ";
	b=_getch();
	while(b!=13){
     pin.push_back(b);
	 cout<<'*';
	 b=_getch();
	}
	if(strcmp(a,"admin")==0 && pin=="123123"){
		return 1;
	}else{
	textcolor(4);
	cout<<"\n\t\tVui Long Dang Nhap Lai !\n";
		c++;
		if(c==3){
			return 0;
		}
	textcolor(10);
	dangnhap(c);
	}
}