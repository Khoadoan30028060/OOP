#pragma once
#include "Console.h"
#include "CPEOPLE.h"
#include "CLEVEL.h";
#include "CLANE.h"

class CMAP {
private:
	const int width = 115, height = 44; // x = 115, y = 44
	char map[47][117];
	CPEOPLE player;
	CLANE LaneData;
	CLEVEL Level;
public:
	CMAP();

	void printMap();
	void printFirstScreen();
	void printSettings();
	void printLoadGame();

	CPEOPLE getPeople();
	void drawPeople();
	void erasePeople(CPOSITION);
	void updatePosPlayer(int&);

	void initializeNewMap();

	CLANE getLaneData();
	void Collisions();// ham dung do
	void updateLaneData();
	
	bool nextLevel();
	void setLevel(int, int);
	CLEVEL getLevel();

	void resetLevel();
	bool isEnd(); // kết thúc khi bị đụng
	bool isWin();

	void saveGame(string);
	void loadGame(string);

	void drawAmbulance(CPOSITION, vector <string>);
	void eraseAmbulance(CPOSITION, vector <string>);
	void DeadEffect(CPOSITION);
	void winGameEffect();
	~CMAP();
};
