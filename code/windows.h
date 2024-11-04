#include<iostream>
#include<conio.h>
#include<Windows.h>
#pragma once
using namespace std;

//Di chuyển tọa độ
void gotoxy(int x, int y){
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1}; 
	hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition (hConsoleOutput, Cursor_an_Pos);
}

void textcolor (int x){
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (mau,x);
}

// Xóa màn hình giúp đỡ lag
void XoaManHinh(){
	HANDLE hout;
	COORD Position;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition (hout, Position);
}
void setConsoleFullScreen() {
    #ifdef _WIN32
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);
    #endif
}