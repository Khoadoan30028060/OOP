#include "CONELANE.h"

CONELANE::CONELANE(int speed, int row, bool redlight, bool direction) {
	this->speed = speed;
	this->currentRow = row;
	this->RedLight = redlight;
	this->Direction = direction;
}

vector <COBSTACLE*> CONELANE::getObs() {
	return List;
}

bool CONELANE::pushObs(COBSTACLE* newObs, int LV) {
	if (Direction)  // nếu true thì set lại ví trí bên phải
		newObs->updatePos(RIGHTMAP - 3, newObs->getPos().getY());

	if (newObs->getPos().getX() > RIGHTMAP || newObs->getPos().getX() <= 2)
		return false;

	if (List.size() && abs(List.back()->getPos().getX() - newObs->getPos().getX()) <= newObs->getShape().size() + 20 - (LV - 1) * 2) // 25 là khoảng cách giữa 2 vật thể
		return false; // kiểm tra nếu có danh sách và khoảng cách của vật ở cuối danh sách với  

	List.push_back(newObs);
	return true;
}

void CONELANE::drawObs(CPOSITION pos, vector<string> shape) {
	int X = pos.getX();
	int Y = pos.getY();
	if (X + shape[0].size() == 2 || X >= RIGHTMAP)
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
	else if (X <= LEFTMAP) {
		for (int i = 0; i < shape.size(); i++) {
			gotoXY(3, Y + i);
			for (int j = abs(X) + 3; j < shape[0].size(); j++) {
				cout << shape[i][j];
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

void CONELANE::eraseObs(CPOSITION pos, vector<string> shape) {
	int X = pos.getX();
	int Y = pos.getY();
	if (X + shape[0].size() == 2 || X >= RIGHTMAP)
		return;
	if (!Direction) {
		for (int i = 0; i < shape.size(); i++) {
			gotoXY(X, Y + i);
			for (int j = 0; j < speed; j++)
				cout << " ";
		}
	}
	else {
		for (int i = 0; i < shape.size(); i++) {
			gotoXY(X + shape[0].size() - 1, Y + i);
			for (int j = 0; j < speed; j++) {
				if (X + shape[0].size() - 1 + j == RIGHTMAP)
					continue;
				else if (X + shape[0].size() - 1 + j == LEFTMAP)
					continue;
				else cout << " ";
			}
		}
	}

}

void CONELANE::printAllObs() {	
	if (List.size() == 0)
		return;
	else if (List[0]->getType() == 1 || List[0]->getType() == 3) {
		gotoXY(118, currentRow * 5 + 1); cout << "(";
		gotoXY(120, currentRow * 5 + 1); cout << ")";
		gotoXY(118, currentRow * 5 + 2); cout << "(";
		gotoXY(120, currentRow * 5 + 2); cout << ")";
		if (RedLight) {
			TextColor(244);
			gotoXY(119, currentRow * 5 + 1);
			cout << (char)254;
			TextColor(247);
			gotoXY(119, currentRow * 5 + 2);
			cout << (char)254;
		}
		else {
			TextColor(250);
			gotoXY(119, currentRow * 5 + 2);
			cout << (char)254;
			TextColor(247);
			gotoXY(119, currentRow * 5 + 1);
			cout << (char)254;
		}
	}
	TextColor(240);
	if (Direction)
		gotoXY(RIGHTMAP - 1, currentRow * 5 + 2);
	else
		gotoXY(LEFTMAP - 1, currentRow * 5 + 2);
	for (int i = 0; i < List.size(); i++) {
		drawObs(List[i]->getPos(), List[i]->getShape());
	}
	//std::this_thread::sleep_for(std::chrono::microseconds(100000));
}

void CONELANE::eraseAllObs() {
	if ((RedLight && (rand() % 100 == 0)) || (!RedLight && (rand() % 80 == 0))) {
		changeRedLight();
	}
	if (RedLight == true)
		return;
	int dX = 1;
	if (Direction)
		dX *= -1;
	for (int i = 0; i < List.size(); i++) {
		//std::this_thread::sleep_for(std::chrono::microseconds(100000));
		eraseObs(List[i]->getPos(), List[i]->getShape());
		COBSTACLE* tmp = List[i];
		if (!Direction && tmp->getPos().getX() == RIGHTMAP - 1) {
			List.erase(List.begin() + i);
			delete tmp;
		}
		if (Direction && tmp->getPos().getX() == LEFTMAP - List[i]->getShape()[0].size() + 2) {
			List.erase(List.begin());
			delete tmp;
		}
		tmp->updatePos(tmp->getPos().getX() + dX, tmp->getPos().getY());
	}
}

bool CONELANE::getRedLight() {
	return RedLight;
}

bool CONELANE::getDirection() {
	return Direction;
}

void CONELANE::changeRedLight() {
	RedLight = !RedLight;
}
