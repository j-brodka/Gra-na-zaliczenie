#ifndef FUNC_H
#define FUNC_H

using namespace std;

class Coords
{
public:
	double X;
	double Y;
	bool operator==(const Coords &a);
};

void idle(void);
void resize(int width, int height);
void processNormalKeys(unsigned char key, int xx, int yy);
void mouseMovement(int x, int y);
void onMouseButton(int button, int state, int x, int y);
void display(void);
void SpecialKeysFunc(int key, int x, int y);

void kolizja();
void okienko(int x);
void inicjujEnemy2();

void SpawnHero();
extern int scena;
void Napisz(float x, float y, string str);

#endif