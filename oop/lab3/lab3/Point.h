#pragma once
class Point
{
private:
	double x = 0;
	double y = 0;
public:
	Point() = default;
	Point(double x, double y);

	Point& operator = (const Point& old)
	= default;

	bool operator== (const Point& c1)
	{
		return (c1.x == x &&
			c1.y == y);
	}

	double getX() const;
	double getY() const;

	void setX(double newX);
	void setY(double newY);

	void moveX(double l);
	void moveY(double l);
};

