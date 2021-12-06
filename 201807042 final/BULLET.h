#pragma once

#include "BUTTON.h"

class BULLET : public BUTTON{
protected:
	int dir;
	int speed;
public:
	BULLET(int dir, int speed);
	void move(const RECT& target);
	void setSpeed(const int& speed);
	void setDir(const int & dir);
	void upSpeed();
	void setAutoSpeed();
	void setAutoLocation(const RECT& area);
	bool intersect(const RECT& target);
};

