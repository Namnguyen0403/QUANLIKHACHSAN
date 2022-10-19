#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<iostream>
#include<conio.h>
#include "Dohoa1.h"
#include<stdio.h>
#include <ctype.h>
#define ListMax 6
class Menu
{
    private:
    typedef char str[20];
    str List[ListMax];
    public:
    int NhanKey();
    int XuLyKey(int key,int n);
    void TaoList();
    void HienThi(int n,int row);
    void XoaHienThi(int row);
    void DeSign();
    /*Phan cai dat chuc nang cho tung List*/
    void List1();
    void List2();
    void List3();
    void List4();
    void List5();
    void List6();
};