#pragma once
#include "COBSTACLE.h"
#include "CBIKE.h"
#include "CBUTTERFLY.h"
#include "CCAR.h"
#include "CDUCK.h"

class CLEVEL {
private:
	int Level, Time, Mode; // time dùng để điều chỉnh tốc độ di chuyển của obs
	const int maxLevel = 3;
	void Initialize();
public:
	CLEVEL();
	CLEVEL(int, int);
	CLEVEL& operator= (const CLEVEL&);
	int getLevel();
	int getMode();
	bool setLevel(int, int);
	bool nextLevel();
	int getTime();
	COBSTACLE* chooseTypeObs(CPOSITION, bool ,int);
	~CLEVEL();
};

