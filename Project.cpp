#include<iostream>
#include<string.h>
#include <iomanip>
#include <ctime>
#include<conio.h>
using namespace std;

//Class Customer
class Customer
{
	string name;	   			
	string address;				
	string phone;				
	int days=0;	    			
	float payment_advance;		//THANH TOAN TRUOC
	double bill=0;				
	int booking_id;				
	int room;					//MA PHONG
	int status;
public:
	Customer(){
		days=0;
		payment_advance=0;
		bill=0;
		booking_id=0;
		status=0;
		room=0;
}
	void Enterdata();				//NHAP THONG TIN
	void Displaydata();				//HIEN THI THONG TIN
	friend class Room;
	friend class Hotel;
};
void Customer::Enterdata()		
{
	cout<<"Nhap ten khach hang: ";
	getline(cin, name);
	getline(cin, name);
	cout<<"Nhap dia chi khach hang: ";
	getline(cin,address);
	flag:
	cout<<"Nhap so dien thoai khach hang: ";
	cin>>phone;
	for(int i=0;i<(phone.length());i++)	
  	{									//SO SDT NEN O DANG CHU SO VA GOM 10 CHU SO
		if(!isdigit(phone[i]))
		{
			cout<<"!!So dien thoai phai o dang chu so.\n";
			goto flag;
		}
  	}
  	if(phone.length()!=10)		
  	{
  	  cout<<"!!So dien thoai phai co 10 chu so.\n";
  	  goto flag;
 	 }
}
//

void Customer::Displaydata(){
	cout<<booking_id<<":\t\t";
	cout<<"| "<<left<<setfill(' ')<<setw(30)<<name;
	cout<<"| "<<phone<<"\t\t\t";
	cout<<"| "<<left<<setfill(' ')<<setw(30)<<address;
	cout<<"| "<<room<<"\t\t\t";
	if(status==1){
		cout<<"|\t\t-\t\t|"<<endl;
	}else{
		cout<<"|\tCHECKED OUT.\t\t|"<<endl;
		}
}
    //CLASS ROOM
	//DU LIEU PHONG
class Room
{
	char type;				//LOAI PHONG
	char stype;				//SIZE PHONG
	char ac;				//AC OR NON AC
	int roomNumber;			//MA PHONG
	double rent;			//GIA TIEN THUE HANG NGAY
	int status=0;			//TRANG THAI PHONG
public:
	friend class Hotel;
	void acceptroom(int rno);		//THEM THONG TIN PHONG 
	void displayroom();		//HIEN THI PHONG
	Room()					
	{
		type='\0';
		stype='\0';
		ac='\0';
		roomNumber=0;
		rent=0;
		status=0;
	}
};
void Room::acceptroom(int rno)	
{
	roomNumber=rno;	//ROOM NUMBER
	cout<<"Type AC/Non-AC (A/N) : ";
	cin>>ac;
	while(ac!='A'&& ac!='N')		
	{
		cout<<"Please Re-Enter Type: AC/Non-AC (A/N) : ";
		cin>>ac;
	}
	cout<<"Phong VIP hoac binh thuong (V/N): ";
	cin>>type;
	while(type!='V' && type!='N')
	{
		cout<<"Vui long nhap lai loai phong (V/N) : ";
		cin>>type;
	}
	cout<<"Size phong (B/S): ";
	cin>>stype;
	while(stype!='B'&& stype!='S')
	{
		cout<<"Vui long nhap lai size phong (B/S) : ";
		cin>>stype;
	}
	cout<<"Daily Rent : ";
	cin>>rent;
	while(rent<0 || rent>20000)
	{
		cout<<"Please enter valid rent.";
		cin>>rent;
	}
	status=0;	//TRANG THAI PHONG
	cout<<"\nThem phong thanh cong!"<<endl;
}
void Room::displayroom()
{
	cout<<"| "<<roomNumber<<".\t\t|\t"<<ac<<"\t\t|\t"<<type<<"\t\t|\t"<<stype<<"\t\t|\t"<<rent<<"\t\t|\t";
	if(status==0){
		cout<<"Available.\t|";
	}
	else{
		cout<<"Booked.\t\t|";
		}
	cout<<endl;
}
//class Hotel
class Hotel
{
	Room a[100];			//ARRAY OF ROOMS
	Customer c[100];			//ARRAY OF CUSTOMERS
	int nroom=0, ncust=0;	//SL PHONG VA SL KHACH
public:
	void addRooms();		//THEM PHONG
	void searchroom();		//TIM KIEM PHONG
	void CheckIn();			//DAT CHO 
	void searchcust();		//TIM KIEM KHACH HANG O KHACH SAN
	void availability();	//KIEM TRA 
	void CheckOut();		//CHECKOUT AND BILLING 
	void Summary();			//TOM TAT
};
void Hotel::addRooms()
{
	int rno;
	cout<<"Nhap so luong phong: ";
	cin>>nroom;		
	while(nroom<=0)
	{
		cout<<"!!Vui long nhap lai so luong phong:";
		cin>>nroom;
	}
	for(int i=0;i<nroom;i++)
	{
		cout<<"ROOM "<<(i+1)<<endl;
		flag:
		cout<<endl<<"Nhap ma phong : ";
		cin>>rno;
		if(rno<=0)		
		{
			cout<<endl<<"Ma phong khong hop le! Vui long nhap lai ma so phong : ";
			goto flag;
		}
		for(int i=0; i<nroom;i++)	
		{
			if(a[i].roomNumber==rno)
			{
				cout<<"Khong hop le! So phong lap lai."<<endl;
				goto flag;
			}
		}
		a[i].acceptroom(rno);		
	}
}
void Hotel::availability()		//CHECKING AVAILABILITY OF THE ROOMS
{
	if(nroom==0)
	{
		cout<<"Vui long them phong."<<endl;
		return;
	}
	cout<<"Danh sach tat ca cac phong:"<<endl;
	cout<<"| Ma so phong\t|\tAC/Non-AC\t|\tLoai\t\t|\tSize phong\t\t|\tRent\t\t|\tAvailability  \t|"<<endl;
	for(int i=0;i<nroom;i++)
	{
		a[i].displayroom();	
	}
}
void Hotel::searchroom()	
{
	if(nroom==0)
	{
		cout<<"!!Vui long them phong."<<endl;
		return;
	}
	int flag=0;
	char ac1, type1, stype1;
	cout<<"Nhap thong tin cua phong muon tim kiem\n";
	cout<<"Type AC/Non-AC (A/N) : ";//NHAP THONG TIN CUA PHONG MUON TIM KIEM
	cin>>ac1;
	while(ac1!='A'&& ac1!='N')	
	{
		cout<<"Please Re-Enter Type: AC/Non-AC (A/N) : ";
		cin>>ac1;
	}
	cout<<"Phong VIP hoac binh thuong (V/N): ";
	cin>>type1;
	while(type1!='V' && type1!='N')
	{
		cout<<"Vui long nhap lai loai phong (V/N) : ";
		cin>>type1;
	}
	cout<<"Size phong (B/S): ";
	cin>>stype1;
	while(stype1!='B'&& stype1!='S')
	{
		cout<<"Vui long nhap lai size phong (B/S) : ";
		cin>>stype1;
	}
	for(int i=0;i<nroom;i++)
	{
		if(a[i].ac==ac1 && a[i].type==type1 && a[i].stype==stype1)		
		{
			flag=1;
			cout<<"Tim thay phong!\n"<<endl;
			a[i].displayroom();
		}
	}
	if(flag==0)
	{
		cout<<"Khong co phong nhu vay."<<endl;
	}
}
void Hotel::CheckIn()		
{
	if(nroom==0)
	{
		cout<<"Vui long them phong."<<endl;
		return;
	}
	int i, rno;
	if(ncust<=nroom){	//KIEM TRA SL PHONG TRONG
		c[ncust].booking_id=ncust+1;	//ID CUA KHACH 
		flag:
		int flag1=0;
		cout<<"Nhap ma phong:";		
		cin>>rno;
		for(i=0;i<nroom; i++){
			if(rno==a[i].roomNumber)
			{
				flag1=1;
				break;
			}
		}
		if(flag1==0){
			cout<<"Ma phong khong hop le! Vui long nhap lai.\n";
			goto flag;
		}
		if(a[i].status==0)		//KIEM TRA TINH TRANG PHONG
		{
			char ch2;
			cout<<"Phong kha dung."<<endl;
			a[i].displayroom();
			cout<<"Ban co muon tiep tuc? Press(Y/N)";		
			cin>>ch2;
			if(ch2=='Y')
			{
				c[ncust].Enterdata();		
				cout<<"Nhap so ngay luu tru: ";
				cin>>c[ncust].days;
				c[ncust].bill = c[ncust].days*a[i].rent;		//TINH TIEN
				cout<<"Tong hoa don cua ban se khoang ~"<<(c[ncust].bill)<<"$ ."<<endl<<"Thanh toan truoc toi thieu="<<c[ncust].bill/4<<"\nBan muon thanh toan truoc bao nhieu?";
				cin>>c[ncust].payment_advance;
				while(c[ncust].payment_advance<c[ncust].bill/4||c[ncust].payment_advance>c[ncust].bill)
				{
					cout<<"Vui long nhap lai!!\n";
					cin>>c[ncust].payment_advance;
				}
				cout<<"<--------->\n";
				cout<<"Thank you. Da xac nhan dat cho."<<endl;		//confirmed booking
				cout<<"--------------------------------------------------------------"<<endl;		//printing booking details
				cout<<"Booking Id: "<<c[ncust].booking_id<<"\nTen: "<<c[ncust].name<<"\nMa phong.: "<<rno<<"\nThoi gian: ";
				time_t my_time = time(NULL);
						//IN THOI GIAN HIEN TAI
				cout<<ctime(&my_time);
				a[i].status=1;		//THAY DOI TRANG THAI PHONG->BOOKED
				c[ncust].room=rno;		//MA PHONG
				c[ncust].status=1;
				ncust++;
			}
			else if(ch2=='N')		//NEU MUON DAT PHONG KHAC
			{
				goto flag;
			}
		}
		else		//BOOKED
		{
			cout<<"Phong da dat cho!.Vui long chon phong khac"<<endl;
		}
	}else if(ncust>nroom)		//TAT CA CA PHONG DA DUOC DAT CHO
	{
		cout<<"Xin loi!Khach san da het phong."<<endl;
	}
}
void Hotel::searchcust()
{
	int id, flag=0;
	cout<<"Nhap id booking cua khach hang:";
	cin>>id;
	for(int i=0;i<=ncust;i++)		
	{
		if(c[i].booking_id==id)
		{
			cout<<"\t\t\t Ten"<<setw(20);
			cout<<"\t\t\t Sđt"<<setw(20);
			cout<<"\t\t\t Dia chi"<<setw(20);
			cout<<"\t\t\tMa phong "<<setw(20)<<endl;
			c[i].Displaydata();
			flag=1;
		}
	}
	if(flag==0)		
	{
		cout<<"Khong tim thay khach hang."<<endl;
	}
}
void Hotel::CheckOut()		//THU TUC THANH TOAN
{
	int rno, i, j;
	cout<<"Nhap ma phong: ";
	cin>>rno;
	for(j=0;j<nroom; j++){
		if(rno==a[j].roomNumber)
		{
			break;
		}
	}
	if(a[j].status==0)		
	{
		cout<<"Khong hop le."<<endl;
	}
	for(i=0;i<ncust;i++)	//CHI TIET
	{
		if(c[i].room==rno)
		{
			cout<<"CHECKING OUT."<<endl;
			c[i].Displaydata();		//CUSTOMER DETAILS
			cout<<"Tong hoa don cua ban: "<<c[i].bill<<endl;
			cout<<"Thanh toan truoc: "<<c[i].payment_advance<<"$";
			cout<<endl<<"So tien phai thanh toan= "<<c[i].bill-c[i].payment_advance<<"$";		//PENDING PAYMENTS
			cout<<endl<<"Thank you! Visit Again :)"<<endl;
			a[j].status=0;	//THAY DOI TRANG THAI PHONG
			c[i].status=0;	//CHECKED OUT
			break;
		}
	}
}
void Hotel::Summary()		//IN DANH SACH KHACH HANG
{
	if(nroom==0)
	{
		cout<<"Chua co khach hang nao."<<endl;
		return;
	}
	cout<<"Guest Summary:"<<endl;
	cout<<"Id.\t\t";
	cout<<"|	Name	\t\t";
	cout<<"|	Phone	\t\t";
	cout<<"|	Address	\t\t";
	cout<<"|	Room no	 \t";
	cout<<"|	Status	\t\t|"<<endl;
	for(int i=0;i<ncust;i++)
	{
		c[i].Displaydata();
	}
}
void cls(){

	system("cls");

}
void enter(){
	cout<<"<-- Nhan phim bat ky de tiep tuc !! -->";
	getch();
}
int main()
{
	Hotel Obj;		//TAO DOI TUONG CUA LOP HOTEL
	char ch;
	cout<<endl<<"======================================================================================WELCOME TO========================================================================================";
	do
	{	
		cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t"
				"MENU:\n\t\t\t\t\t\t\t\t\t\t\t"
				"1.OPERATE AS ADMIN\n\t\t\t\t\t\t\t\t\t\t\t"
				"2.OPERATE AS CUSTOMER\n\t\t\t\t\t\t\t\t\t\t\t"
				"3.EXIT\n\t\t\t\t\t\t\t\t\t\t\t"
				"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
		case '1':
			cout<<"Them du lieu cua cac phong trong khach san:"<<endl;
			Obj.addRooms();
			cout<<"Da cap nhat du lieu.Quay lai man hinh chinh"<<endl;
             enter();
			 cls();
			break;
		case '2':
			char ch1;
			do
			{
				//MENU 2 
				cout<<endl<<"*************************************************************************************************************************************************************************************************"<<endl;
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ WELCOME TO ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"
						"Menu:\n\t\t\t\t\t\t\t\t\t\t\t"
						"1.Kiem tra tinh trang phong.\n\t\t\t\t\t\t\t\t\t\t\t"
						"2.Tim kiem phong\n\t\t\t\t\t\t\t\t\t\t\t"
						"3.Check In\n\t\t\t\t\t\t\t\t\t\t\t"
						"4.Tim kiem khach hang\n\t\t\t\t\t\t\t\t\t\t\t"
						"5.Guest Summary\n\t\t\t\t\t\t\t\t\t\t\t"
						"6.Checkout.\n\t\t\t\t\t\t\t\t\t\t\t"
						"7.Go back to Main Menu.\n\t\t\t\t\t\t\t\t\t\t\t"
						"Nhap lua chon:";
				cin>>ch1;
				switch(ch1)
				{
				case '1':
					Obj.availability();
					enter();
					cls();
					break;
				case '2':
					Obj.searchroom();
					enter();
					cls();
					break;
				case '3':
					Obj.CheckIn();
					enter();
					cls();
					break;
				case '4':
					Obj.searchcust();
					enter();
					cls();
					break;
				case '5':
					Obj.Summary();
					enter();
					cls();
					break;
				case '6':
					Obj.CheckOut();
					enter();
					cls();
					break;
				case '7':
					break;
				default:
					cout<<"Lua chon khong hop le."<<endl;
					enter();
					cls();
					break;
				}
			}while(ch1!='7');
			break;
		case '3':
			cout<<"Thank you <3 !!";
			exit(0);
		default:
			cout<<"Lua chon khong hop le."<<endl;
			break;
		}
	}while(ch!='3');
	return 0;
}
