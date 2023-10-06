#pragma once
#include "COBSTACLE.h"
class CDUCK: public COBSTACLE {
public:
	CDUCK();
	CDUCK(CPOSITION, bool);
	vector <string> getShape();
	int getType();
	void sound();
	~CDUCK();
};

/*
   _
__(.)>
\___)

  _
<(.)__
 (___/

*/