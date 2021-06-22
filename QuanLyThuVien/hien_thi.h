#pragma once
#include<iostream>
#include<conio.h>//getch()
#include<stdint.h>
#include<string.h>//char
#include<string>//string
#include<iomanip>// for setw va setfill
#include"hang_so.h"// thu vien chua cac hang so
#include"mylib.h"// thu vien chua cac ham xu li do hoa

using namespace std;
extern int nPassenger;
// co toi da 5 phan tu toi da 50 ki tu
int xKeyDisplay[7] = { 1,20,45,63,83,95, 107 };// toa do X cac diem nut

char ThucDon[MaxItem][70] = {
					   "1. Quan ly Doc Gia                      ",
					   "2. In danh sach doc gia                 ",
					   "3. Nhap dau sach va danh ma sach tu dong",
					   "4. In danh sach dau sach                ",
					   "5. Tim thong tin sach                   ",
					   "6. Muon sach                            ",
					   "7. Tra sach                             ",
					   "8. Danh sach doc gia muon sach qua han  ",
					   "9. Top 10 sach muon nhieu nhat          ",
					   "0. Thoat Chuong Trinh                   "
};

// dong tuy chon
void NormalLine()
{
	SetColor(15);// yellow
	SetBGColor(0);// black
}
// dong dang chon
void HighlightLine()
{
	SetColor(15);// yellow 
	SetBGColor(1);// dark blue        
}
/*============== CENTER MENU =============*/
void DrawTable()
{
	gotoxy(X_TitlePage - 7, Y_TitlePage + 1);
	cout << "CHUC NANG CHINH";
	/*      "HOC VIEN CONG NGHE BUU CHINH VIEN THONG CO SO THANH PHO HO CHI MINH"*/
	//ve thanh ngang ben tren va duoi
	for (int i = xKeyDisplay[3] - 12; i < 122; i++)
	{

		//ve thanh ngang ben tren so 1
		gotoxy(i, Y_Display - 2);
		cout << char(176);

		// ve thanh ngang ben tren so 2
		gotoxy(i, Y_Display + 1);
		cout << char(176);

		//ve thanh ngang ben duoi
		//gotoxy(i, Y_Display + 19);
		//cout << char(176);

		gotoxy(i, Y_Display + 19 + 3);
		cout << char(176);
	}

	for (int j = Y_Display; j < Y_Display + 25; j++)
	{
		gotoxy(xKeyDisplay[3] - 12, j - 2);
		cout << char(176);

		gotoxy(122, j - 2);
		cout << char(176);
	}
}
int menu_dong(char ThucDon[MaxItem][70])
{
	// xuat menu
	ShowCur(false);// an con tro nhap nhay di
	NormalLine();
	system("cls");
	DrawTable();
	for (int i = 0; i < MaxItem; i++)
	{

		gotoxy(X_CenterMenu, Y_CenterMenu + i * 2);
		cout << ThucDon[i];
	}
	// to mau cho dong duoc chon
	int pointer = 0; // vi tri hien tai cua thanh sang
//	HighlightLine();
	gotoxy(X_CenterMenu, Y_CenterMenu + pointer * 2);
	HighlightLine();
	cout << ThucDon[pointer];
	// dieu khien chuc nang
	char signal;
	while (true)
	{
		signal = _getch();// kiem tra xem co nhap gi tu ban phim khong
		if (signal == -32)
		{
			signal = _getch();
		}
		// dieu huong
		switch (signal)
		{
		case KEY_UP:
			if (pointer + 1 > 1)
			{
				// tro ve mau cu
				NormalLine();
				gotoxy(X_CenterMenu, Y_CenterMenu + pointer * 2);
				cout << ThucDon[pointer];
				pointer--;// cap nhat lai vi tri 
				// vi tri thanh sang
				HighlightLine();
				gotoxy(X_CenterMenu, Y_CenterMenu + pointer * 2);
				cout << ThucDon[pointer];
			}
			break;
		case KEY_DOWN:
			if (pointer + 1 < MaxItem)
			{
				NormalLine();
				gotoxy(X_CenterMenu, Y_CenterMenu + pointer * 2);
				cout << ThucDon[pointer];
				pointer++;
				HighlightLine();
				gotoxy(X_CenterMenu, Y_CenterMenu + pointer * 2);
				cout << ThucDon[pointer];
			}
			break;
		case ENTER:// lua lai ket qua de thuc hien lenh tuong ung voi CenterMenu
			return pointer + 1;
		}
	}
}
/* ========== END CENTER MENU =========== */

void introduce()
{
	ShowCur(false);
	string temp;
	ifstream file("introduce.txt", ios::in);
	SetColor(ColorCode_Blue);
	if (file.good())
	{
		while (file.eof() == false)
		{
			getline(file, temp);
			//Sleep(80);
			cout << temp << endl;
		}
	}
	else
	{
		cout << " \n Liet ket file that bai " << endl;
	}

	ShowCur(false);
	gotoxy(50, 34);
	SetBGColor(ColorCode_Black);
	SetColor(ColorCode_Red);
	cout << "Please ! Press ENTER to continue !!!! ";
	SetBGColor(ColorCode_Black);

	string content[] = { "Dau Truong Quan          | N18DCCN162",
						 "Nguyen Ngoc Phuong Trinh | N18DCCN231" };
	
	int x = 100;
	int y = 4;
	int length = 40;
	for (int i = 0; i < 2; i++)
	{

		gotoxy(x - 2, y - 1);
		cout << char(176) << setw(length) << setfill(char(176)) << char(176) << char(176);

		gotoxy(x - 2, y);
		cout << char(176) << content[i] << setw(length - content[i].length() + 1) << setfill(' ') << char(176);
		y += 2;
	}
	gotoxy(x - 2, y - 1);
	cout << char(176) << setw(length) << setfill(char(176)) << char(176) << char(176);
	gotoxy(98, 2);
	cout << "Thanh vien";
	while (!_kbhit()) {
		gotoxy(45, 32);
		SetColor(1 + rand() % 15);
		Sleep(100);
		cout << "HOC VIEN CONG NGHE BUU CHINH VIEN THONG CO SO TP HO CHI MINH";
	}

	cin.ignore();
	return;
}
