#include <math.h>
#include "BULLET.h"


BULLET::BULLET(int dir, int speed) : BUTTON(
	L"BULLET",10,200,450,5
)
{
	this->dir = dir;
	this->speed = speed;
}
void BULLET::move(const RECT& boundary)
{
	this->moveHorizontal(cos(this->dir) * this->speed);
	this->moveVertical(sin(this->dir) * this->speed);

	if (!(this->intersect(boundary)))// ������ ��� ���
	{
		setVisible(false);
		setAutoLocation(boundary);
		setAutoSpeed();
		setVisible(true);
	}
}
void BULLET::setSpeed(const int &speed)
{
	this->speed = speed;
}
void BULLET::upSpeed()
{
	this->speed++;
}
void BULLET::setAutoSpeed()
{
	int speed = rand() % 4+1;
	this->setSpeed(speed);
}

void BULLET::setAutoLocation(const RECT& area)
{
	int rnd = rand() % 4;
	int dir = 0;
	this->setAutoSpeed();

	switch (rnd)
	{
	case 0:// ���� ����
		dir = 270;
		this->setLocation(area.left, area.top + (rand()%(area.bottom-area.top)+1) );
		break;
	case 1:// ���� ����
		dir = 180;
		this->setLocation(area.left + (rand() % (area.right - area.left) + 1), area.top);
		break;
	case 2:// ������ ����
		dir = 90;
		this->setLocation(area.right, area.top + (rand() % (area.bottom - area.top) + 1));
		break;
	case 3:// �Ʒ��� ����
		dir = 360;
		this->setLocation(area.left + (rand() % (area.right - area.left) + 1),area.bottom );
		break;
	default:
		break;
	}
	setDir((360 + (dir-20) - (rand() % 140)) % 360);
}

void BULLET::setDir(const int& dir)
{
	this->dir = dir;
}
bool BULLET::intersect(const RECT& target)
{
	RECT temp = target;
	temp.left += 5;
	temp.top += 5;
	return IntersectRect(&temp, &this->rect, &temp);
}
