#include "Menu.h"
using namespace std;
/*---------------------------Nhan_Key_Ban_Phim-----------------------*/
int Menu::NhanKey()
{
    int key;
    key = getch();
    if(key==0) key = getch();
    return key;
}
/*--------------------------Xu_Ly_De_List_Quay_Vong------------------*/
int Menu::XuLyKey(int key,int n)
{
    switch(key)
        {
            case 72:
                    if(n>1) 
                    n--;
                    else n = ListMax;
                    break;
            case 80:
            if(n<ListMax) n++;else n = 1;
            break;
        }
    return n;  
}
/*---------------------------Tao_List_De_In--------------------------*/
void Menu::TaoList()
{
    strcpy(List[1]," [  List 1  ]");
    strcpy(List[2]," [  List 2  ]");
    strcpy(List[3]," [  List 3  ]");
    strcpy(List[4]," [  List 4  ]");
    strcpy(List[5]," [  List 5  ]");
    strcpy(List[6]," [  Exit    ]");
}
/*-----------------------Hien_Thi_List_Hien_Tai----------------------*/
void Menu::HienThi(int n,int row)
{
/*Hien thi Menu tai hang row. List[n] co mau khac voi cac List con lai*/
    int i;
    textcolor(10);
    for(i=1;i<=ListMax;i++)
            {
                gotoxy(row,i);
                printf(List[i]);
            }
    /*Di den hang row, cot n va in List[n] co mau voi cac mau khac*/
        gotoxy(row,n);
        textcolor(12);
        printf(List[n]);
        printf("<=");
}
/*-------------------Xoa_Hien_Thi_List_De_In_List_Tiep_Theo----------*/
void Menu::XoaHienThi(int row)
{
    int i;
    for(i=1;i<=ListMax;i++)
        {
            gotoxy(row-1,i);
            clreol();
        }
}
/*-------------------Ket_Hop_De_Co_Hien_Thi_Thich_Hop----------------*/
void Menu::DeSign()
{   
    int n=1,m=1;
    TaoList();
    while(1)
        {
            XoaHienThi(m);
            HienThi(n,50);
            m = n;
            n = NhanKey();
            if(n==13)
                {
                    switch(m)
                        {
                            case 1: List1();cls();break;
                            case 2: List2();cls();break;
                            case 3: List3();cls(); break;
                            case 4: List4();cls(); break;
                            case 5: List5();cls(); break;      
                            case 6: List6(); break;          
                        }
                }
            n = XuLyKey(n,m);
        }
}
/*--------------------------Chuc_Nang_List_1------------------------*/
void Menu::List1()
{   
    gotoxy(50,10); textcolor(10);
    printf("CHUC NANG CUA LIST 1. NHAN ENTER DE TEP TUC");
    getch();
    gotoxy(50,10); clreol();
}
/*--------------------------Chuc_Nang_List_2------------------------*/
void Menu::List2()
{  
    gotoxy(50,10); textcolor(10);
    printf("CHUC NANG CUA LIST 2. NHAN ENTER DE TEP TUC");
    getch();
    gotoxy(50,10); clreol();
}
/*--------------------------Chuc_Nang_List_3-----------------------*/
void Menu::List3()
{
    gotoxy(50,10); textcolor(10);
    printf("CHUC NANG CUA LIST 3. NHAN ENTER DE TEP TUC");
    getch();
    gotoxy(50,10); clreol();
}
/*--------------------------Chuc_Nang_List_4-------------------------*/
void Menu::List4()
{
    gotoxy(50,10); textcolor(10);
    printf("CHUC NANG CUA LIST 4. NHAN ENTER DE TEP TUC");
    getch();
    gotoxy(50,10); clreol();
}
/*--------------------------Chuc_Nang_List_5-----------------------*/
void Menu::List5()
{
    gotoxy(50,10); textcolor(10);
    printf("CHUC NANG CUA LIST 5. NHAN ENTER DE EXIT");
    getch();
    gotoxy(50,10); clreol();
}
void Menu::List6(){
    exit(0);
}

