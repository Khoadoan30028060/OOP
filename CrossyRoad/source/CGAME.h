#pragma once
#include "Console.h"
#include "CMAP.h"

class CGAME {
private:
	bool isLoaded = false,IsRunning = true, IsPausing = true;
	CMAP map = CMAP();
	vector <string> ListFile;
	int index_File = -1;
public:
	CGAME() = default;
	~CGAME() = default;
	void printGame();
	void controlGame();
	void menuGame();
	int establishLoadGame();
	void establishSettings();
	void gameSettings();
	void askPlayerBeforeLoadingGame();
	int loadGameInGameSettings();
	void setListFile();
	void saveListFile();
};

