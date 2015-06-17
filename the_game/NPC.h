#ifndef NPC_H
#define NPC_H

class NPC
{
private:
	Coords pozycja;
	int level;
	int minDamage;
	int maxDamage;
	bool alive;
	int hp;
	int nr;
public:
	void DrawHERO(void);
	void DrawNPC(double _x, double _y);
	void setX(double x);
	void setY(double y);
	void setPosition(double _x, double _y);
	double getX();
	double getY();
	Coords getPozycja();
	void setLVL(int x);
	void setDamage(int min, int max);
	void setAlive(bool x);
	void setHP(int _hp);
	void setNR(int _nr);
	bool isAlive();
	int returnNR();
	int returnLVL();
	int returnHP();
	int returnDamageMin();
	int returnDamageMax();
};

extern NPC player;
extern bool ifKolizja;

#endif