#include "CGAME.h"

void CGAME::printGame() {
	vector <string> win;
	win.push_back("\\ o /");
	win.push_back("  |  ");
	win.push_back(" / \\ ");
	CPOSITION pos;
	if (!isLoaded)
		map.initializeNewMap();
	isLoaded = false;
	map.printMap();
	while (true) {
		gotoXY(125, 1); cout << "Player's name:                      ";
		if (index_File == -1) {
			gotoXY(140, 1); cout << "NO NAME";
		}
		else {
			gotoXY(140, 1); cout << ListFile[index_File];
		}

		map.erasePeople(pos);
		CLANE List = map.getLaneData();
		CPEOPLE player = map.getPeople();
		map.drawPeople();
		List.printAllLane();
		std::this_thread::sleep_for(std::chrono::microseconds(map.getLevel().getTime())); // 1000 microseconds = 1 ms = 0.01 s
		List.eraseAllLane();
		map.erasePeople(player.getPos());
		map.Collisions();
		map.updateLaneData();
		pos = CPOSITION(player.getPos().getX(), 2);
		if (IsPausing) {
			map.drawPeople();
			List.printAllLane();
			return;
		}
		if (!map.isEnd()) {
			map.drawPeople();
			List.printAllLane();
			map.DeadEffect(player.getPos());
			return;
		}	
		if (map.isWin()) {
			IsPausing = true;
			List.printAllLane();
			if (constantVar::isMute == false)
				PlaySound(TEXT("level win.wav"), NULL, SND_ASYNC);
			for (int i = 0; i < 5000; i++) {
				map.drawAmbulance(pos, win);
				map.drawPeople();
			}
			if (map.getLevel().getLevel() == 3) {
				map.winGameEffect();
				std::this_thread::sleep_for(0.8s);
			}
			break;
		}
	}
}

void CGAME::controlGame() {
	int key;
	while (IsRunning) {
		while (!IsPausing && map.isEnd() && !map.isWin()) {
			if (!_kbhit()) {
				key = _getch();
				if (key == 32) {
					IsPausing = true; // dùng để ngưng luồng xài pif (constantVar::isMute == false)
					continue;
				}
				else if (key == 'a' || key == 's' || key == 'w' || key == 'd') {
					if (constantVar::isMute == false)
						PlaySound(TEXT("move2.wav"), NULL, SND_ASYNC);
					IsPausing = false;
					map.updatePosPlayer(key);
				}
				else if (key == 224) {
					key = _getch();
				}
			}
		}
	}
	
}

int CGAME::establishLoadGame() {
	int  color_background = 480; // màu kem
	int key, pos = 0;
	map.printLoadGame();
	setListFile();
	while (true) {
		switch (InputKey()) {
		case 'w': {
			pos--;
			if (ListFile.size() != 0)
				pos = (pos + ListFile.size()) % ListFile.size();
			break;
		}
		case 's': {
			pos++;
			if (ListFile.size() != 0)
				pos = pos % ListFile.size();
			break;
		}
		case 13: {
			if (ListFile.size() != 0) {
				map.loadGame(ListFile[pos]);
				index_File = pos;
			}
			return 1;
		}
		case 27: {
			int step = 12;
			gotoXY(66, step++);
			for (int i = 0; i < 42; i++)
				cout << " ";
			for (int i = 0; i < 11; i++) {
				gotoXY(66, step++);	cout << "                                          " << endl;
			}
			gotoXY(66, step++);
			for (int i = 0; i < 42; i++)
				cout << " ";
			return 0;
		}
		default: break;
		}
		if (ListFile.size() != 0) {
			gotoXY(62 + (41 - ListFile[pos].size()) / 2, 14 + pos);
			TextColor(color_background + 5); cout << "> " << ListFile[pos] << ".txt <" << endl;
			TextColor(color_background);
			for (int i = 0; i < ListFile.size(); i++) {
				if (i == pos) {
					continue;
				}
				gotoXY(62 + (41 - ListFile[i].size()) / 2, 14 + i);
				cout << "  " << ListFile[i] << ".txt  " << endl;
			}
		}
	}
	return 0;
}

void CGAME::establishSettings() {
	int color_background = 480;
	int temp = -1;
	int key, pos = 0;
	map.printSettings();
	string sound[2] = { "ON","OFF" };
	string option[5] = { "EASY", "MEDIUM", "HARD", "ON", "QUIT" };
	if (constantVar::isMute == true)
		option[3] = sound[1];
	while (true) {
		switch (InputKey()) {
		case 'w': {
			/*if (constantVar::isMute == false)
				PlaySound(TEXT("move2.wav"), NULL, SND_ASYNC);*/
			pos--;
			pos = (pos + 5) % 5;
			break;
		}
		case 's': {
			/*if (constantVar::isMute == false)
				PlaySound(TEXT("move2.wav"), NULL, SND_ASYNC);*/
			pos++;
			pos = pos % 5;
			break;
		}
		case 13: {
			/*if (constantVar::isMute == false)
				PlaySound(TEXT("move2.wav"), NULL, SND_ASYNC);*/
			if (pos == 3) {
				if (constantVar::isMute == true) {
					option[3] = sound[0];
					PlaySound(TEXT("background.wav"), NULL, SND_ASYNC);
					constantVar::isMute = false;
				}
				else {
					option[3] = sound[1];
					PlaySound(NULL, 0, 0);
					constantVar::isMute = true;
				}
			}
			else if (pos == 4) {
				int step = 12;
				gotoXY(66, step++);
				for (int i = 0; i < 42; i++)
					cout << " ";
				for (int i = 0; i < 11; i++) {
					gotoXY(66, step++);	cout << "                                          " << endl;
				}
				gotoXY(66, step++);
				for (int i = 0; i < 42; i++)
					cout << " ";
				return;
			}
			else {
				temp = pos;
				map.setLevel(1, pos + 1);
			}
		}
		default: break;
		}

		if (pos == 3) {
			gotoXY(72 + (41 - option[pos].size()) / 2, 15 + 2 * pos);
			TextColor(color_background + 1); cout << "> " << option[pos] << " < " << endl;
		}
		else {
			if (pos != temp) {
				gotoXY(64 + (41 - option[pos].size()) / 2, 15 + 2 * pos);
				TextColor(color_background + 1); cout << "> " << option[pos] << " < " << endl;
			}
			else if (pos == temp) {
				gotoXY(64 + (41 - option[pos].size()) / 2, 15 + 2 * pos);
				TextColor(color_background + 4); cout << "> " << option[pos] << " < " << endl;
			}
		}
		TextColor(color_background);
		for (int i = 0; i < 5; i++) {
			if (i == pos)
				continue;
			else if (temp == i)
				continue;
			else if (i == 3 && pos != 3) {
				gotoXY(72 + (41 - option[i].size()) / 2, 15 + 2 * i);
				cout << "  " << option[i] << "  " << endl;
			}
			else if (i != 3) {
				gotoXY(64 + (41 - option[i].size()) / 2, 15 + 2 * i);
				cout << "  " << option[i] << "  " << endl;
			}
		}
	}
}

void CGAME::menuGame() {
	int color_background = 480;
	setListFile();
	
	int color[4] = { color_background + 2,color_background + 9,color_background + 1,color_background + 5 };
	string option[4] = { "    NEW GAME    ","    LOAD GAME   ","    SETTINGS    ","      QUIT      " };
	int key, pos = 0;
	bool changeInput = true;
	map.printFirstScreen();

	while (true) {
		if (changeInput) {
			key = InputKey();
		}
		
		switch (key) {
			case 'w': {
				/*if (constantVar::isMute == false)
					PlaySound(TEXT("move2.wav"), NULL, SND_ASYNC);*/
				pos--;
				pos = (pos + 4) % 4;
				break;
			}
			case 's': {
				/*if (constantVar::isMute == false)
					PlaySound(TEXT("move2.wav"), NULL, SND_ASYNC);*/
				pos++;
				pos = pos % 4;
				break;
			}
			case 13: {
				/*if (constantVar::isMute == false)
					PlaySound(TEXT("move2.wav"), NULL, SND_ASYNC);*/
				switch (pos) {
					case 0: {
						changeInput = true;
						IsPausing = false;
						clrscr();
						TextColor(240);
						for (int i = 0; i < 130; i++) {
							for (int j = 0; j < 180; j++)
								cout << " ";
						}
						do {
							printGame();																															/*chung em iu thay cho em 10 diem nha*/
							gameSettings();
							if (map.isWin()) {
								bool check = map.nextLevel();
								if (!check) {
									map.resetLevel();
									break;
								}
								isLoaded = false;
							}
						} while (!IsPausing && IsRunning && map.isEnd());
						/*if (constantVar::isMute == false) 
							PlaySound(TEXT("background.wav"), NULL, SND_ASYNC);*/
						clrscr();
						map.resetLevel();
						map.printFirstScreen();
						index_File = -1;
						break;
					}
					case 1: {
						changeInput = true;
						int type = establishLoadGame(); 
						if (type == 1) {
							changeInput = false;
							key = 13;
							pos = 0;
							isLoaded = true;
						}
						break; 
					}
					case 2: {
						changeInput = true;
						establishSettings();
						break;
					}
					case 3: IsRunning = false; clrscr();   return;
				}
				TextColor(color_background);
				int step = 8;
				gotoXY(66, step++); cout << char(218);
				for (int i = 0; i < 40; i++)
					cout << char(196);
				cout << char(191) << endl;
				for (int i = 0; i < 15; i++) {
					gotoXY(66, step++);	cout << char(179) << "                                        " << char(179) << endl;
				}
				gotoXY(66, step++); cout << char(192);
				for (int i = 0; i < 40; i++)
					cout << char(196);
				cout << char(217) << endl;
			}
			default: break;
		}

		int step = 9;
		int X = 78;
		TextColor(color[pos]);
		gotoXY(X, step + 4 * pos); cout << char(218);
		for (int i = 0; i < 16; i++)
			cout << char(196);
		cout << char(191) << endl;
		gotoXY(X, step + 4*pos + 1); cout << char(179) << option[pos] << char(179) << endl;
		gotoXY(X, step + 4 * pos + 2); cout << char(192);
		for (int i = 0; i < 16; i++)
			cout << char(196);
		cout << char(217) << endl;
		TextColor(color_background);

		for (int i = 0; i < 4; i++) {
			if (i == pos)
				continue;
			gotoXY(X, step + 4 * i); cout << char(218);
			for (int i = 0; i < 16; i++)
				cout << char(196);
			cout << char(191) << endl;
			gotoXY(X, step + 4 * i + 1); cout << char(179) << option[i] << char(179) << endl;
			gotoXY(X, step + 4 * i + 2); cout << char(192);
			for (int i = 0; i < 16; i++)
				cout << char(196);
			cout << char(217) << endl;
		}
	}
}

void CGAME::gameSettings() {
	int key;
	bool changeInput = true;
	CLANE List = map.getLaneData();
	setListFile();
	if (!IsPausing || (map.isWin() && map.getLevel().getLevel() == 3))
		return;
	int step = 12;
	gotoXY(53, step++); cout << char(218);
	for (int i = 0; i < 40; i++)
		cout << char(196);
	cout << char(191) << endl;
	for (int i = 0; i < 12; i++) {
		gotoXY(53, step++);	cout << char(179) << "                                        " << char(179) << endl;
	}
	string sound[2] = { "ON","OFF" };
	string option[5] = { "CONTINUE", "SAVE GAME", " LOAD GAME ", "ON", "QUIT" };
	if (constantVar::isMute == true)
		option[3] = sound[1];
	gotoXY(69, 21); cout << "SOUNDS :  ";
	for (int i = 0; i < 5; i++) {
		if (i == 3) {
			gotoXY(59 + (41 - option[i].size()) / 2, 15 + 2 * i);
			if (constantVar::isMute == true) {
				option[i] = sound[1];
			}
			cout << "  " << option[i] << "  " << endl;
		}
		else {
			gotoXY(51 + (41 - option[i].size()) / 2, 15 + 2 * i);
			cout << "  " << option[i] << "  " << endl;
		}
	}
	gotoXY(53, step++); cout << char(192);
	for (int i = 0; i < 40; i++)
		cout << char(196);
	cout << char(217) << endl;
	int pos = 0;
	while (true) {
		if (changeInput) {
			key = InputKey();
		}
		switch (key) {
		case 'w': {
			/*if (constantVar::isMute == false)
				PlaySound(TEXT("move2.wav"), NULL, SND_ASYNC);*/
			pos--;
			pos = (pos + 5) % 5;
			break;
		}
		case 's': {
			/*if (constantVar::isMute == false)
				PlaySound(TEXT("move2.wav"), NULL, SND_ASYNC);*/
			pos++;
			pos = pos % 5;
			break;
		}
		case 13: {
			/*if (constantVar::isMute == false)
				PlaySound(TEXT("move2.wav"), NULL, SND_ASYNC);*/
			switch (pos) {
			case 0: {
				IsPausing = false;
				isLoaded = true;
				return;
			}
			case 1: {
				int step = 13;
				for (int i = 0; i < 11; i++) {
					gotoXY(54, step++);	cout << "                                        " << endl;
				}
				if (index_File == -1) {
					gotoXY(58, 13); cout << "Enter filename saving game data " << endl;
					string filename;
					do {
						gotoXY(58, 15); cout << "FileName:                  ";
						SetCursor(1, 0);
						gotoXY(68, 15); getline(cin, filename);
						if (std::count(ListFile.begin(), ListFile.end(), filename) > 0)
							gotoXY(58, 16); cout << "File name existed!!!";
						SetCursor(0, 0);
					} while (std::count(ListFile.begin(), ListFile.end(), filename) > 0);

					if (ListFile.size() == 9)
						ListFile.erase(ListFile.begin());
					ListFile.push_back(filename);
					map.saveGame(filename);
				}
				else {
					gotoXY(58, 13); cout << "Player's name: " << ListFile[index_File];
					gotoXY(58, 15); cout << "System saved the currrent state";
					map.saveGame(ListFile[index_File]);
					std::this_thread::sleep_for(1s);
				}
				saveListFile();
				isLoaded = true;
				changeInput = false;
				key = 13;
				pos = 0;
				break;
			}
			case 2: {
				askPlayerBeforeLoadingGame();
				int type = loadGameInGameSettings();
				isLoaded = true;
				int step = 12;
				gotoXY(53, step++); cout << char(218);
				for (int i = 0; i < 40; i++)
					cout << char(196);
				cout << char(191) << endl;
				for (int i = 0; i < 15; i++) {
					gotoXY(53, step++);	cout << char(179) << "                                        " << char(179) << endl;
				}
				gotoXY(53, step++); cout << char(192);
				for (int i = 0; i < 40; i++)
					cout << char(196);
				cout << char(217) << endl;
				if (type == 1) {
					changeInput = false;
					key = 13;
					pos = 0;
				}
				break;
			}
			case 3: {
				if (constantVar::isMute == true) {
					option[3] = sound[0];
					constantVar::isMute = false;
				}
				else {
					constantVar::isMute = true;
					option[3] = sound[1];
				}
				break;
			}
			case 4: IsPausing = true; std::this_thread::sleep_for(0.5s); return;
			}
			break;
		}
		default: break;
		}
		gotoXY(69, 21); cout << "SOUNDS :";
		if (pos == 3) {
			gotoXY(59 + (41 - option[pos].size()) / 2, 15 + 2 * pos);
		}
		else {
			gotoXY(51 + (41 - option[pos].size()) / 2, 15 + 2 * pos);
		}
		TextColor(245); cout << "> " << option[pos] << " < " << endl;
		TextColor(240);
		for (int i = 0; i < 5; i++) {
			if (i == pos)
				continue;
			else if (i == 3 && pos != 3) {
				gotoXY(59 + (41 - option[i].size()) / 2, 15 + 2 * i);
				cout << "  " << option[i] << "  " << endl;
			}
			else if (i != 3) {
				gotoXY(51 + (41 - option[i].size()) / 2, 15 + 2 * i);
				cout << "  " << option[i] << "  " << endl;
			}
		}
	}
}

void CGAME::askPlayerBeforeLoadingGame() {
	int step = 13;
	for (int i = 0; i < 11; i++) {
		gotoXY(54, step++);	cout << "                                        " << endl;
	}
	gotoXY(56, 13); cout << "Do you want to save this game data: " << endl;
	string option[2] = { "YES", "NO" };
	int pos = 0;
	while (true) {
		switch (InputKey()) {
			case 'w': {
				/*if (constantVar::isMute == false)
					PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);*/
				pos--;
				pos = (pos + 2) % 2;
				break;
			}
			case 's': {
				/*if (constantVar::isMute == false)
					PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);*/
				pos++;
				pos = pos % 2;
				break;
			}
			case 13: {
				/*if (constantVar::isMute == false)
					PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);*/
				if (pos != 0)
					return;
				else {
					gotoXY(58, 15); cout << "Enter filename saving game data " << endl;
					gotoXY(58, 17); cout << "                                " << endl;
					string filename;
					gotoXY(58, 17); cout << "FileName: ";
					getline(cin, filename);
					if (ListFile.size() == 9)
						ListFile.erase(ListFile.begin());
					ListFile.push_back(filename);
					map.saveGame(filename);
					saveListFile();
					return;
				}
			}
			default: break;
		}
		gotoXY(56, 13); cout << "Do you want to save this game data: " << endl;
		gotoXY(51 + (41 - option[pos].size()) / 2, 15 + 2 * pos);
		TextColor(241); cout << "> " << option[pos] << " < " << endl;
		TextColor(240);
		for (int i = 0; i < 2; i++) {
			if (i == pos)
				continue;
			gotoXY(51 + (41 - option[i].size()) / 2, 15 + 2 * i);
			cout << "  " << option[i] << "  " << endl;
		}
	}
	return;
}

int CGAME::loadGameInGameSettings() {
	int step = 13, pos = 0;
	for (int i = 0; i < 11; i++) {
		gotoXY(54, step++);	cout << "                                        " << endl;
	}
	gotoXY(53, 25); cout << "Enter ESC to quit!!!" << endl;
	gotoXY(69, 13); cout << "LIST FILE" << endl;
	while (true) {
		switch (InputKey()) {
			case 'w': {
				/*if (constantVar::isMute == false)
					PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);*/
				pos--;
				if (ListFile.size() != 0)
					pos = (pos + ListFile.size()) % ListFile.size();
				break;
			}
			case 's': {
				/*if (constantVar::isMute == false)
					PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);*/
				pos++;
				if (ListFile.size() != 0)
					pos = pos % ListFile.size();
				break;
			}
			case 13: {
				/*if (constantVar::isMute == false)
					PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);*/
				if (ListFile.size() != 0) {
					map.loadGame(ListFile[pos]);
					index_File = pos;
				}
				return 1;
			}
			case 27: {
				/*if (constantVar::isMute == false)
					PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);*/
				int step = 12;
				gotoXY(53, step++);
				for (int i = 0; i < 42; i++)
					cout << " ";
				for (int i = 0; i < 11; i++) {
					gotoXY(53, step++);	cout << "                                          " << endl;
				}
				gotoXY(53, step++);
				for (int i = 0; i < 42; i++)
					cout << " ";
				return 0;
			}
			default: break;
		}
		if (ListFile.size() != 0) {
			gotoXY(49 + (41 - ListFile[pos].size()) / 2, 14 + pos);
			TextColor(245); cout << "> " << ListFile[pos] << ".txt <" << endl;
			TextColor(240);
			for (int i = 0; i < ListFile.size(); i++) {
				if (i == pos) {
					continue;
				}
				gotoXY(49 + (41 - ListFile[i].size()) / 2, 14 + i);
				cout << "  " << ListFile[i] << ".txt  " << endl;
			}
		}
	}
	return 0;
}

void CGAME::setListFile() {
	ListFile.clear();
	fstream fs("ListFile.txt", ios::in);
	string filename;
	while (!fs.eof()) {
		getline(fs, filename);
		if (filename != "")
			ListFile.push_back(filename);
	}
	fs.close();
}

void CGAME::saveListFile() {
	fstream fs("ListFile.txt", ios::out);
	int num = ListFile.size();
	if (num >= 9)
		num = 9;
	for (int i = 0; i < num; i++)
		fs << ListFile[i] << endl;
	fs.close();
}