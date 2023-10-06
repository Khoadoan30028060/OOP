#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <string>
#include <thread>
#include <stdlib.h>
#include <vector>
#include <fcntl.h>
#include <io.h>
#include <chrono>
#include <fstream>
#include <sstream>
#include <mmsystem.h>



using namespace std;


//screen: goto [x,y]	X là tọa độ ngang Y là tọa độ dọc
void gotoXY(int X, int Y);

void FixConsoleWindow();// cố định kích thước màn hình console

void ResizeConsole(int width, int height); // thay đổi kích thước mành hình console

void SetCursor(bool visible, DWORD size); // ẩn hiện con nháy trỏ

void clrscr(); // xóa màn hình

void TextColor(int X);

int InputKey();

class constantVar {
public:
	static bool isMute;
};

/* mã màu nền trắng - nền kem
chữ đen: 240 - 480
chữ màu tràm: 241 481
chữ xanh lá đậm: 242 - 482
xanh dương nhạt: 243 - 483
màu đỏ: 244 - 484
màu tím: 245 - 485
màu vàng: 246 - 486
màu xám: 247 - 487
màu xám đậm : 248 - 488
màu xanh dương: 249 - 489
màu xanh lá nhạt: 250 - 490
xanh lam: 251 - 491
màu cam: 252 - 492

*/