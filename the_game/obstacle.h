#ifndef OBSTACLE_H
#define OBSTACLE_H

class CObstacle public: Coords
{
protected:
	double x, y;
public:
	void DrawNPC(void);
	void setX(double X);
	void setY(double Y);
	double getX();
	double getY();
};



#endif