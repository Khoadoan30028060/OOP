#include "COBSTACLE.h"

COBSTACLE::COBSTACLE() {
	direction = false;
}

COBSTACLE::COBSTACLE(CPOSITION start, bool direction) : pos(start) {
	this->direction = direction;
} // tạo vật cản mới bắt đầu hàng thứ bất kì

CPOSITION COBSTACLE::getPos() {
	return pos;
}



void COBSTACLE::updatePos(int dx, int dy) {
	pos.setPos(dx, dy);
}
