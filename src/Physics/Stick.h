#pragma once

#include "../Graphics.h"

class Point;
class Stick
{
private:
	Point& p0;
	Point& p1;
	float length;

	bool isActive = true;
	bool isSelected = false;

	//Uint32 color = 0xFF0048E3;
	Uint32 color = 0xFFFFFFFF;
	Uint32 colorWhenSelected = 0xFF0048E3;

public:
	Stick(Point& p0, Point& p1, float lenght);
	~Stick() = default;

	void SetIsSelected(bool value);

	void Update();
	void Draw(const Graphics* renderer) const;
	void Break();
};