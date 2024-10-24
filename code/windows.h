#include<iostream>
#include<conio.h>
#include<Windows.h>
#pragma once
using namespace std;

void gotoxy(int x, int y){
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1}; 
	hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition (hConsoleOutput, Cursor_an_Pos);
}