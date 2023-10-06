#include "CMAP.h"

CMAP::CMAP() {
	Level = CLEVEL();
	player = CPEOPLE();
	for (int i = 0; i <= width; i++) {
		map[0][i] = map[height + 1][i] = char(196); // khung tren va khung duoi
	}
	for (int i = 1; i <= height; i++) {
		map[i][0] = map[i][width] = char(179);
		map[i][width + 1] = ' ';
		for (int j = 1; j < width; j++) {
			if (i % 5 == 0)
				map[i][j] = char(196); // in cac lan duong
			else
				map[i][j] = ' ';
		}
	}
	map[0][0] = char(218);
	map[height + 1][0] = char(192);
	map[0][width] = char(191);
	map[height + 1][width] = char(217);
}

void CMAP::printMap() {
	clrscr();
	gotoXY(0,0);
	for (int i = 0; i <= height + 1; ++i) {
		cout << "  ";
		for (int j = 0; j < width + 1; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}
	int X = 125;
	int Y = 2;
	gotoXY(X, Y++); cout << " ____________________________________________________" << endl;
	gotoXY(X, Y++); cout << "/ _________________________________________________  \\" << endl;
	gotoXY(X, Y++); cout << "\\_/|                   LEVEL "<< Level.getLevel() <<"                     | |" << endl;
	gotoXY(X, Y++); cout << " | |                  MODE: ";
	if (Level.getMode() == 1)
		cout << "Easy                   | |" << endl;
	else if (Level.getMode() == 2)
		cout << "Medium                 | |" << endl;
	else
		cout << "Hard                   | |" << endl;
	gotoXY(X, Y++); cout << " | |===============================================| |" << endl;
	gotoXY(X, Y++); cout << " | |                CONTROL MANUAL                 | |" << endl;
	_setmode(_fileno(stdout), _O_U16TEXT);
	gotoXY(X, Y++); wcout << L" | |        .-----.        ‖        .-----.        | |" << endl;
	gotoXY(X, Y++); wcout << L" | |        |  W  |        ‖        |  ↑  |        | |" << endl;
	gotoXY(X, Y++); wcout << L" | |        '-----'        ‖        '-----'        | |" << endl;
	gotoXY(X, Y++); wcout << L" | |.-----. .-----. .-----.‖.-----. .-----. .-----.| | " << endl;
	gotoXY(X, Y++); wcout << L" | ||  A  | |  S  | |  D  |‖|  ←  | |  ↓  | |  →  || |" << endl;
	gotoXY(X, Y++); wcout << L" | |'-----' '-----' '-----'‖'-----' '-----' '-----'| |" << endl;
	gotoXY(X, Y++); wcout << L" | |===============================================| |" << endl;
	gotoXY(X, Y++); wcout << L" | |                    COMMAND                    | |" << endl;
	gotoXY(X, Y++); wcout << L" | |   .-----------.       ‖     .-------------.   | |" << endl;
	gotoXY(X, Y++); wcout << L" | |   |   Space   |       ‖     |   Setting   |   | |" << endl;
	gotoXY(X, Y++); wcout << L" | |   '-----------'       ‖     '-------------'   | |" << endl;
	gotoXY(X, Y++); wcout << L" | |_______________________________________________| |" << endl;
	gotoXY(X, Y++); wcout << L" \\___________________________________________________/" << endl;
	_setmode(_fileno(stdout), _O_TEXT);
	drawPeople();
}

void CMAP::printFirstScreen() {
	if (constantVar::isMute == false)
		PlaySound(TEXT("background.wav"), NULL, SND_ASYNC);
	int color_background = 480; // nền màu kem 
	int step = 8;
	int X = 37;
	TextColor(color_background);
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 180; j++)
			cout << " ";
	}
	TextColor(color_background + 4);// đỏ
	gotoXY(X, 2); cout << "         ______  ______  ______  ______  ______  __  __       ______  ______  ______  _____          " << endl;
	gotoXY(X, 3); cout << "        /\\  ___\\/\\  == \\/\\  __ \\/\\  ___\\/\\  ___\\/\\ \\_\\ \\     /\\  == \\/\\  __ \\/\\  __ \\/\\  __-.        " << endl;
	TextColor(color_background + 1);// xanh 
	gotoXY(X, 4); cout << "        \\ \\ \\___\\ \\  __<\\ \\ \\/\\ \\ \\___  \\ \\___  \\ \\____ \\    \\ \\ __ <\\ \\ \\/\\ \\ \\  __ \\ \\ \\/\\ \\       " << endl;
	TextColor(color_background + 5); // tím
	gotoXY(X, 5); cout << "         \\ \\_____\\ \\_\\ \\_\\ \\_____\\/\\_____\\/\\_____\\/\\_____\\    \\ \\_\\ \\_\\ \\_____\\ \\_\\ \\_\\ \\____-       " << endl;
	gotoXY(X, 6); cout << "          \\/_____/\\/_/ /_/\\/_____/\\/_____/\\/_____/\\/_____/     \\/_/ /_/\\/_____/\\/_/\\/_/\\/____/       " << endl;
	TextColor(240);

	TextColor(color_background);
	X = 66;
	gotoXY(X, step++); cout << char(218);
	for (int i = 0; i < 40; i++)
		cout << char(196);
	cout << char(191) << endl;
	for (int i = 0; i < 15; i++) {
		gotoXY(X, step++);	cout << char(179) << "                                        " << char(179) << endl;
	}
	gotoXY(X, step++); cout << char(192);
	for (int i = 0; i < 40; i++)
		cout << char(196);
	cout << char(217) << endl;
	step = 26;
	X = 0;

	TextColor(color_background + 4);
	gotoXY(X, step++); cout << "                                " << "                                                           / \\                                               " << "   .   _____*   *        / \\  *     * " << endl;
	gotoXY(X, step++); cout << "   *.        *         *      * " << "            .   ________ _____         ____     __________/ o \\/ \\________      _________   .                 " << " / \\ (._.._)         *  )|(           " << endl;
	TextColor(color_background + 5);
	gotoXY(X, step++); cout << " *'     *        *         `*   " << " ________  / \\ | # # # #|o o o|_______|    |___|               | | # # #  |____|o o o o  | / \\      _____    " << " // \\\\           \\o/    (_|_)    *    ";
	gotoXY(X, step++); cout << "               \\o               " << "| : :: : |// \\\\| # # # #|o o o|  * * *|: ::|. .| []  []  []  []|o| # # #  |. . |o o o o  |// \\\\  _ | O O |   " << " ((|))     .  *   |                    ";
	TextColor(color_background + 6);
	gotoXY(X, step++); cout << "          *     ]?              " << "| : :: : |((|))| # # # #|o o o|* * *  |::  |. .| []  []___]  []|o| # # #  |. . |o o o o  |((|)) / \\| O O |    " << "((|))    /_\\    / \\   *    \\o/        " << endl;
	gotoXY(X, step++); cout << "    o/ *      * |\\              " << "| : :: : |((|))| # # # #|o o o|**  ** |:  :|. .| []  [| 0 |  []|o| # # #  |. . |o o o o  |((|))|# #| O O |    " << " .|     /_|_\\               |         " << endl;
	TextColor(color_background + 2);
	gotoXY(X, step++); cout << "    )                           " << "|___[]___|  |  |___[]___|_[]__|__[]___|_||_|__<|______|/|\\|_;;_|_|___/\\___|_.|_|____[]___|  |  |[]_|_[]__|     " << "         |     *          ( \\    *  " << endl;
	gotoXY(X, step++); cout << "   /|                            " << "                                                      |/ \\|                                                                                        " << endl;
	color_background = 0; // sẽ đổi sau
	TextColor(color_background);
	for (int i = 0; i < 16; i++) {
		gotoXY(X, step++);
		for (int j = 0; j < 179; j++)
			cout << " ";
	}
	TextColor(240);
	gotoXY(X, 34);
	for (int j = 0; j < 179; j++)
		cout << " ";
	for (int i = 0; i < 9; i++) {
		gotoXY(3 + 20 * i, 39); cout << "          ";
		gotoXY(3 + 20 * i, 45); cout << "          ";
	}
	for (int i = 0; i < 6; i++) {
		TextColor(color_background + 15);
		gotoXY(2 + 30 * i, 35); cout << " ____|~\\_";
		gotoXY(2 + 30 * i, 36); cout << "[____|_|-]";
		gotoXY(2 + 30 * i, 37);  cout << " (_)   (_)";
	}
	for (int i = 0; i < 5; i++) {
		TextColor(color_background + 14);
		gotoXY(i + 15 + 35 * i, 41); cout << " o__   ";
		gotoXY(i + 15 + 35 * i, 42); cout << " _>/ _ ";
		gotoXY(i + 15 + 35 * i, 43);  cout << "(_)\\(_)";
	}
	gotoXY(0, 1);
}

void CMAP::printSettings() {
	int color_background = 480; // nền màu kem 
	int step = 8;
	int X = 66;
	for (int i = 0; i < 3; i++) {
		gotoXY(X, step++);	cout << "                                          " << endl;
	}
	gotoXY(X, step++);
	for (int i = 0; i < 42; i++)
		cout << " ";
	TextColor(color_background + 2);
	X = 78;
	gotoXY(X, 9); cout << char(218);
	for (int i = 0; i < 16; i++)
		cout << char(196);
	cout << char(191) << endl;
	gotoXY(X, 9 + 1); cout << char(179) << "    SETTINGS    " << char(179) << endl;
	gotoXY(X, 9 + 2); cout << char(192);
	for (int i = 0; i < 16; i++)
		cout << char(196);
	cout << char(217) << endl;

	step = 12;
	X = 66;
	TextColor(color_background);
	gotoXY(X, step++); cout << char(218);
	for (int i = 0; i < 40; i++)
		cout << char(196);
	cout << char(191) << endl;
	for (int i = 0; i < 11; i++) {
		gotoXY(X, step++);	cout << char(179) << "                                        " << char(179) << endl;
	}
	gotoXY(X, step++); cout << char(192);
	for (int i = 0; i < 40; i++)
		cout << char(196);
	cout << char(217) << endl;
	TextColor(color_background + 3);
	gotoXY(82, 13); cout << "DIFFICULTY" << endl;
	TextColor(color_background + 5);
	gotoXY(82, 21); cout << "SOUNDS :  ";
	TextColor(color_background);
}

void CMAP::printLoadGame() {
	int color_background = 480; // nền màu kem 
	int step = 8;
	int X = 66;
	for (int i = 0; i < 3; i++) {
		gotoXY(X, step++);	cout << "                                          " << endl;
	}
	gotoXY(X, step++);
	for (int i = 0; i < 42; i++)
		cout << " ";
	TextColor(color_background + 2);
	X = 78;
	gotoXY(X, 9); cout << char(218);
	for (int i = 0; i < 16; i++)
		cout << char(196);
	cout << char(191) << endl;
	gotoXY(X, 9 + 1); cout << char(179) << "    LOAD GAME   " << char(179) << endl;
	gotoXY(X, 9 + 2); cout << char(192);
	for (int i = 0; i < 16; i++)
		cout << char(196);
	cout << char(217) << endl;

	TextColor(color_background);
	step = 12;
	X = 66;
	gotoXY(X, step++); cout << char(218);
	for (int i = 0; i < 40; i++)
		cout << char(196);
	cout << char(191) << endl;
	for (int i = 0; i < 11; i++) {
		gotoXY(X, step++);	cout << char(179) << "                                        " << char(179) << endl;
	}
	gotoXY(X, step++); cout << char(192);
	for (int i = 0; i < 40; i++)
		cout << char(196);
	cout << char(217) << endl;
	TextColor(color_background + 3);
	gotoXY(82, 13); cout << "LIST FILE" << endl;
	TextColor(color_background);
	gotoXY(66, 24); cout << "Enter ESC to quit!!!" << endl;
}

CPEOPLE CMAP::getPeople() {
	return player;
}

void CMAP::drawPeople() {
	int X = player.getPos().getX();
	int Y = player.getPos().getY();
	if (Y >= height || X + 3 <= 0) // vị trí ở ngoài map
		return;
	for (int i = 0; i < 3; i++) {
		gotoXY(X, Y + i);
		cout << player.getShape()[i];
	}
}

void CMAP::erasePeople(CPOSITION pos) {
	int X = pos.getX();
	int Y = pos.getY();
	if (Y >= height || X + 3 <= 0) // vị trí ở ngoài map
		return;
	for (int i = 0; i < 3; i++) {
		gotoXY(X, Y + i);
		cout << "     ";
		
	}
}

void CMAP::updatePosPlayer(int &key) {
	switch (key){
		case 119: {
			player.Up();
			break;
		}
		case 115: {
			player.Down();
			break;
		}
		case 97: {
			player.Left();
			break;
		}
		case 100: {
			player.Right();
			break;
		}
		default: return;
	}
}

void CMAP::initializeNewMap() {
	player.~CPEOPLE();
	new (&player) CPEOPLE();
	LaneData.~CLANE();
	new (&LaneData) CLANE();
	for (int i = 0; i < 7; i++) {
		bool direction = rand() % 2;
		LaneData.pushLane(new CONELANE(1, i + 1, false,direction));
		COBSTACLE* newObs = Level.chooseTypeObs(CPOSITION(3, (i + 1) * 5 + 2), direction,(rand() % 4 + 1));
		LaneData.pushObs(newObs, i, Level.getLevel());
	}
}

CLANE CMAP::getLaneData() {
	return LaneData;
}


void CMAP::Collisions() {
	int curLanePos = (this->getPeople().getPos().getY() - 2) / 5 - 1;// Lấy số thứ tự của cái hàng hiện tại 
	if (curLanePos == -1 || curLanePos == 7) // Nếu mà con người đang ở hàng đầu hoặc cuối thì ko làm gì
		return;
	vector <COBSTACLE*> ListObs = getLaneData().getLanePos(curLanePos)->getObs();// Lấy list obs của cái hàng hiện tại ra
	for (int i = 0; i < ListObs.size(); i++) {
		COBSTACLE* obs = ListObs[i];
		player.checkDead(obs->getPos(), obs->getShape());
		if (player.getState() == false) {
			obs->sound();
			std::this_thread::sleep_for(std::chrono::microseconds(1000000));
			return;
		}
	}
}

void CMAP::updateLaneData() {
	int type = rand() % 4 + 1; // random loại vật cản
	int numOfObsInOneLane = Level.getLevel() * 2;
	if (type == 3) { // xe hơi to nên giới hạn lại
		if (Level.getLevel() == 3) numOfObsInOneLane = 3;
		else numOfObsInOneLane -= 1;
	}
	vector<CONELANE*> list = LaneData.getListLane();
	for (int i = 0; i < list.size(); i++) {
		vector<COBSTACLE*> tmp = list[i]->getObs();
		if (tmp[0]->getType() == type) {
			if (tmp.size() <= numOfObsInOneLane) {
				COBSTACLE* newObs = Level.chooseTypeObs(CPOSITION(3, tmp[0]->getPos().getY()),list[i]->getDirection(), type);
				LaneData.pushObs(newObs, i, Level.getLevel());
			}
		}
	}
}

bool CMAP::nextLevel() {
	return Level.nextLevel();
}

void CMAP::setLevel(int LV, int mode) {
	Level.setLevel(LV, mode);
}

CLEVEL CMAP::getLevel() {
	return Level;
}

void CMAP::resetLevel() {
	Level.~CLEVEL();
	new (&Level) CLEVEL();
}

bool CMAP::isEnd() {
	return player.getState();
}

bool CMAP::isWin() {
	if (player.getPos().getY() == 2) {
		// âm thanh chúc mừng
		/*if (constantVar::isMute == false)
			PlaySound(TEXT("level win.wav"), NULL, SND_ASYNC);*/
		return true;
	}
	return false;
}

void CMAP::winGameEffect() {
	// them nhac thang
	if (constantVar::isMute == false)
		PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC);
	string winGame;
	int i = 1;
	system("cls");
	ifstream fi("Ending1.txt");
	string temp;
	int Y = 0;
	int color_background = 240;
	while (!fi.eof()) {
		TextColor(color_background);
		getline(fi, temp, '\n');
		gotoXY(0, Y++);
		for (int j = 0; j < temp.size(); j++) {
			TextColor(color_background);
			if (i >= 1 && i <= 4) TextColor(color_background + 6);
			if (i >= 5 && i <= 10) {
				TextColor(color_background + 4);
				if ((j >= 0 && j <= 8) || (j >= 36 && j <= 41) || (j >= 97 && j <= 102) || (j >= +103 && j <= 111) || (j >= 36 + 103 && j <= 41 + 103) || (j >= 97 + 103 && j <= 102 + 103)) TextColor(color_background + 13);
				if ((j >= 11 && j <= 22) || (j >= 45 && j <= 60) || (j >= 77 && j <= 87) || (j >= 11 + 103 && j <= 22 + 103) || (j >= 45 + 103 && j <= 60 + 103) || (j >= 77 + 103 && j <= 87 + 103)) TextColor(color_background + 4);
				if ((j >= 22 && j <= 28) || (j >= 42 && j <= 44) || (j >= 22 + 103 && j <= 28 + 103) || (j >= 42 + 103 && j <= 44 + 103)) TextColor(color_background + 5);
				if ((j >= 61 && j <= 72) || (j >= 61 + 103 && j <= 72 + 103)) TextColor(color_background + 10);
			}
			//int text = 44;
			if ((i >= 3 && i <= 5 && j >= 56 && j <= 60)) TextColor(color_background + 4);
			//if ((i >= 13 && i <= 18) || (i >= 33 && i <= 38)) TextColor(color_background + 8);
			if ((i >= 19 && i <= 32)) TextColor(color_background + 9);
			if ((i >= 5 && i <= 10 && ((j >= 8 && j <= 12) || (j >= 88 && j <= 92) || (j >= 8 + 103 && j <= 12 + 103))) || (i >= 25 && i <= 30 && ((j >= 69 + 40 && j <= 73 + 40) || (j >= 32 + 40 && j <= 36 + 40)))) {
				TextColor(color_background + 10);
				if (j == 10 || j == 90 || j == 71 + 40 || j == 34 + 40) TextColor(color_background + 4);
			}
			if ((i >= 19 && i <= 23) && (j >= 22 && j <= 80)) TextColor(color_background + 6);
			if (i > 38) TextColor(color_background + 10);
			cout << temp[j];
		}
		i++;
		cout << endl;
	}
	fi.close();
	vector<string> youWin;
	youWin.push_back(" __  __   ______   __  __       __     __   __   __   __    ");
	youWin.push_back("/\\ \\_\\ \\ /\\  __ \\ /\\ \\/\\ \\     /\\ \\  _ \\ \\ /\\ \\ /\\ \"-.\\ \\  ");
	youWin.push_back("\\ \\\\____ \\\\ \\\ \\/\\ \\\\ \\ \\_\\ \\    \\ \\ \\/ \".\\ \\\\ \\ \\\\ \\ \\ -. \\ ");
	youWin.push_back(" \\/\\_____\\\\ \\_____\\\\ \\_____\\    \\ \\__/\".~\\_\\\\ \\_\\\\ \\_\\\\\"\\_\\\ ");
	youWin.push_back("  \\/_____/ \\/_____/ \\/_____/     \\/_/   \\/_/ \\/_/ \\/_/ \\/_/");
	for (int k = 0; k < 20000; k++) {
		TextColor(color_background + rand() % 6 + 1);
		for (int i = 0; i < 5; i++) {
			gotoXY(62, i + 18);
			cout << youWin[i];
		}
	}


}

void CMAP::saveGame(string FileName) {
	FileName += ".txt";
	fstream fs(FileName, ios::out);
	// vi tri cua nguoi choi
	fs << player.getPos().getX() << " " << player.getPos().getY() << endl;
	// xuất thông tin của level trước 
	fs << Level.getLevel() << " " << Level.getMode() << endl;
	// LaneData
	vector<CONELANE*> LaneTemp = LaneData.getListLane();
	// xuất thông tin của 7 CONELANE	
	for (int i = 0; i < 7; i++) {
		fs << LaneTemp[i]->getDirection() << " " << LaneTemp[i]->getRedLight() << endl; // hướng đi cây đèn giao thông ở mỗi hàng
	}
	for (int i = 0; i < 7; i++) {
		vector<COBSTACLE*> ListObs = LaneTemp[i]->getObs(); //CONELANE
		for (int j = 0; j < ListObs.size(); j++) {
			fs << ListObs[j]->getPos().getX() << " ";
			fs << ListObs[j]->getPos().getY() << " ";
			fs << ListObs[j]->getType() << " ";
		}
		fs << endl;
	}
	fs.close();
}

void CMAP::loadGame(string FileName) {
	FileName += ".txt";
	fstream fs(FileName, ios::in);
	// player;
	int X, Y;
	fs >> X;
	fs >> Y;
	player.~CPEOPLE();
	new(&player) CPEOPLE(CPOSITION(X, Y));
	//Level
	int level, mode;
	fs >> level >> mode;
	Level.~CLEVEL();
	new(&Level) CLEVEL(level, mode);
	// LaneData
	LaneData.~CLANE();
	new (&LaneData) CLANE();
	int redLight,direction;
	int arr[7];
	for (int i = 0; i < 7; i++) {
		fs >> direction;
		arr[i] = direction;
		fs >> redLight;
		LaneData.pushLane(new CONELANE(1, i + 1,redLight, direction));
	}
	string data;
	int type;
	getline(fs, data);
	for (int i = 0; i < 7; i++) {
		getline(fs, data);
		stringstream ss(data);
		while (!ss.eof()) {
			ss >> X;
			ss >> Y;
			ss >> type;
			COBSTACLE* newObs = Level.chooseTypeObs(CPOSITION(X, Y), arr[i], type);
			LaneData.pushObs(newObs, i, Level.getLevel());
		}
	}
	fs.close();
}

void CMAP::drawAmbulance(CPOSITION pos, vector <string> shape) {
	int X = pos.getX();
	int Y = pos.getY();
	
	if (X == LEFTMAP - 1 || X > RIGHTMAP)
		return;
	if (X + shape[0].size() >= RIGHTMAP) {
		for (int i = 0; i < shape.size(); i++) {
			gotoXY(X, Y + i);
			for (int j = 0; j < shape[0].size(); j++) {
				if (X + j < RIGHTMAP)
					cout << shape[i][j];
				else continue;
			}
		}
	}
	else {
		for (int i = 0; i < shape.size(); i++) {
			gotoXY(X, Y + i);
			cout << shape[i];
		}
	}
}

void CMAP::eraseAmbulance(CPOSITION pos, vector <string> shape) {
	int X = pos.getX();
	int Y = pos.getY();
	if (X == LEFTMAP - 1 || X > RIGHTMAP)
		return;
	for (int i = 0; i < shape.size(); i++) {
		gotoXY(X, Y + i);
		cout << " ";
	}
}

void CMAP::DeadEffect(CPOSITION posPlayer) {
	vector<string> shapeAmbulance;
	shapeAmbulance.push_back(".-------.___   ");
	shapeAmbulance.push_back("|   +   |[ ]\\_ ");
	shapeAmbulance.push_back("|       |- '  )");
	shapeAmbulance.push_back("'-(o)------(o)-");
	shapeAmbulance[0][0] = char(218);
	shapeAmbulance[0][8] = char(191);
	shapeAmbulance[3][0] = char(192);
	shapeAmbulance[3][1] = char(196);
	shapeAmbulance[1][0] = shapeAmbulance[2][0] = char(179);
	shapeAmbulance[1][8] = shapeAmbulance[2][8] = char(179);
	for (int i = 1; i < 8; i++)
		shapeAmbulance[0][i] = char(196);
	for (int i = 5; i < 11; i++)
		shapeAmbulance[3][i] = char(196);
	for (int i = 1; i < 8; i++)
		shapeAmbulance[2][i] = '=';
	int X = 4, Y = posPlayer.getY() - 1;
	int color[2] = { 79, 31 };
	CPOSITION posAmbulance(X,Y);
	drawAmbulance(posAmbulance, shapeAmbulance);
	if (constantVar::isMute == false)
		PlaySound(TEXT("ambulance.wav"), NULL, SND_ASYNC);
	while (posAmbulance.getX() <= 108) {
		eraseAmbulance(posAmbulance, shapeAmbulance);
		posAmbulance.setPos(X++, Y);
		drawAmbulance(posAmbulance, shapeAmbulance);
		TextColor(color[((X - 4) / 2) % 2]);
		gotoXY(X + 2, Y + 1);
		cout << " + ";
		TextColor(240);
		std::this_thread::sleep_for(std::chrono::microseconds(20000));
	}
	for (int i = 0; i < shapeAmbulance.size(); i++) {
		gotoXY(X - 1, Y + i); cout << " ";
		gotoXY(X, Y + i);
		for (int j = 0; j < shapeAmbulance[0].size(); j++)
			if (X + j == 117)
				cout << char(179);
			else cout << " ";
	}
	if (constantVar::isMute == false)
		PlaySound(TEXT("lose.wav"), NULL, SND_ASYNC);
	for (int i = 0; i < 120; i++) {
		Y = 15;
		TextColor(480 + rand() % 10 + 1);
		_setmode(_fileno(stdout), _O_U16TEXT);
		gotoXY(3, Y++); wcout << L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████" << endl;
		gotoXY(3, Y++); wcout << L"█░░░░░░░░██░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░██░░░░░░████░░░░░░█████████░░░░░░░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░░░░░░░██" << endl;
		gotoXY(3, Y++); wcout << L"█░░▄▀▄▀░░██░░▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀░░████░░▄▀░░█████████░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░██" << endl;
		gotoXY(3, Y++); wcout << L"█░░░░▄▀░░██░░▄▀░░░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░██░░▄▀░░████░░▄▀░░█████████░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░░░░░█░░▄▀░░░░░░░░░░██" << endl;
		gotoXY(3, Y++); wcout << L"███░░▄▀▄▀░░▄▀▄▀░░███░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░████░░▄▀░░█████████░░▄▀░░██░░▄▀░░█░░▄▀░░█████████░░▄▀░░██████████" << endl;
		gotoXY(3, Y++); wcout << L"███░░░░▄▀▄▀▄▀░░░░███░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░████░░▄▀░░█████████░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░░░░░█░░▄▀░░░░░░░░░░██" << endl;
		gotoXY(3, Y++); wcout << L"█████░░░░▄▀░░░░█████░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░████░░▄▀░░█████████░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░██" << endl;
		gotoXY(3, Y++); wcout << L"███████░░▄▀░░███████░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░████░░▄▀░░█████████░░▄▀░░██░░▄▀░░█░░░░░░░░░░▄▀░░█░░▄▀░░░░░░░░░░██" << endl;
		gotoXY(3, Y++); wcout << L"███████░░▄▀░░███████░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░████░░▄▀░░█████████░░▄▀░░██░░▄▀░░█████████░░▄▀░░█░░▄▀░░██████████" << endl;
		gotoXY(3, Y++); wcout << L"███████░░▄▀░░███████░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░████░░▄▀░░░░░░░░░░█░░▄▀░░░░░░▄▀░░█░░░░░░░░░░▄▀░░█░░▄▀░░░░░░░░░░██" << endl;
		gotoXY(3, Y++); wcout << L"███████░░▄▀░░███████░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░████░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░██" << endl;
		gotoXY(3, Y++); wcout << L"███████░░░░░░███████░░░░░░░░░░░░░░█░░░░░░░░░░░░░░████░░░░░░░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░░░░░░░██" << endl;
		gotoXY(3, Y++); wcout << L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████" << endl;
		_setmode(_fileno(stdout), _O_TEXT);
	}
}

CMAP::~CMAP() {

}
