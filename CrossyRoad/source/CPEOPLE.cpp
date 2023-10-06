#include "CPEOPLE.h"

CPEOPLE::CPEOPLE() {
	isAlive = true;
	pos.setPos(54, 42); // vị trí người chơi khi mới bắt đầu 
	shape.push_back("  o  ");
	shape.push_back(" /|\\ ");
	shape.push_back(" / \\ ");
}

CPEOPLE::CPEOPLE(CPOSITION pos) {
	isAlive = true;
	this->pos = pos;
	shape.push_back("  o  ");
	shape.push_back(" /|\\ ");
	shape.push_back(" / \\ ");
}

vector <string> CPEOPLE::getShape() {
	return shape;
}

bool CPEOPLE::getState() {
	return isAlive;
}

CPOSITION CPEOPLE::getPos() {
	return pos;
}

void CPEOPLE::Left() {
	if (pos.getX() - 3 <= LeftMap)
		return;
	pos.setPos(pos.getX() - 3, pos.getY());
}

void CPEOPLE::Right() {
	if (pos.getX() + 3 >= RightMap)
		return;
	pos.setPos(pos.getX() + 3, pos.getY());
}

void CPEOPLE::Up() {
	if (pos.getY() <= 5)
		return;
	pos.setPos(pos.getX(), pos.getY() - 5);
}

void CPEOPLE::Down() {
	if (pos.getY() + 5 > 42)
		return;
	pos.setPos(pos.getX(), pos.getY() + 5);
}

void CPEOPLE::checkDead(CPOSITION pos, vector<string> shape) {
	if (this->pos.getX() == pos.getX() + shape[0].size())//Đụng từ bên phải qua trái
		isAlive = false;
	if (this->pos.getX() + 3 == pos.getX()) //Đụng từ bên trái qua phải
		isAlive = false;
	for (int j = 0; j < shape[0].size(); j++) {//Đụng từ dưới đi lên hay trên đi xuống
		if (this->pos.getX() == pos.getX() + j)
			isAlive = false;
	}
}

CPEOPLE::~CPEOPLE() {


}