#include "Console.h"
#include "CGAME.h"
CGAME G;

bool constantVar::isMute = false;

void control() {
	G.controlGame();
}


int main() {
	system("color F7");
	TextColor(240);
	srand(time(NULL));
	ResizeConsole(1320, 800);
	FixConsoleWindow();
	SetCursor(0, 0);
	
    thread t1(control);
	G.menuGame();
	t1.join();

	//vector<string> shape;
	//shape.push_back(" ____|~\\_");
	//shape.push_back("[____|_|-]");
	//shape.push_back(" (_)   (_)");
	//CONELANE a;
	//CPOSITION pos(5, 5);
	//a.drawObs(pos, shape);
	//gotoXY(13, 16);
	//system("pause");
	//pos.setPos(6, 5);
	////std::this_thread::sleep_for(std::chrono::microseconds(100000));
	//a.drawObs(pos, shape);
	//gotoXY(13, 16);
	//system("pause");
	////std::this_thread::sleep_for(std::chrono::microseconds(100000));
	//gotoXY(5, 6); cout << " ";
	//gotoXY(13, 16);
	//system("pause");


	//pos.setPos(7, 5);
	//a.drawObs(pos, shape);
	//gotoXY(13, 16);
	//system("pause");
	//gotoXY(6, 6); cout << " ";
	//gotoXY(13, 16);
	//system("pause");
	//std::this_thread::sleep_for(std::chrono::microseconds(100000));
	//a.drawObs(pos, shape);
	//gotoXY(13, 16);
	//system("pause");
	////std::this_thread::sleep_for(std::chrono::microseconds(100000));
	//gotoXY(5, 6); cout << " ";
	//gotoXY(13, 16);
	//system("pause");
	return 0;
}