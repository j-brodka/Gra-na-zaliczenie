#include <iostream>
#define PI 3.14159265
#include "func.h"
#include "NPC.h"
#include <GL/freeglut.h>
#include "imageloader.h"
#include "przeszkoda.h"
#include "scena.h"
#include "enemy.h"
#include <vector>

Image * imageHERO = loadBMP("data/hero.bmp");
GLuint _textureIdHERO;

void NPC::DrawHERO(void)
{
	glBindTexture(GL_TEXTURE_2D, _textureIdHERO); //Mówimy OpenGl jaka tekstura
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, //zawsze GL_TEXTURE_2D
		0, //0 teraz
		GL_RGB, //Format OpenGL u¿yty dla obrazu
		imageHERO->width, imageHERO->height, //Szerokoœæ i wysokoœæ
		0, //Ramka obrazu
		GL_RGB, //GL_RGB, pixele s¹ w tym formacie
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, pixele s¹ takimi zmiennymi
		imageHERO->pixels);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1f, 0.1f, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1f, 0.1f, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0);

	glEnd();
}

void NPC::setX(double x)
{
	pozycja.X += x;
}
void NPC::setY(double y)
{
	pozycja.Y += y;
}
double NPC::getX()
{
	return pozycja.X;
}
double NPC::getY()
{
	return pozycja.Y;
}
Coords NPC::getPozycja()
{
	return pozycja;
}
void NPC::setLVL(int x)
{
	level = x;
}
void NPC::setDamage(int min, int max)
{
	minDamage = min;
	maxDamage = max;
}
bool NPC::isAlive()
{
	return alive;
}
void NPC::setAlive(bool x)
{
	alive = x;
}
void NPC::setHP(int _hp)
{
	hp = _hp;
}
void NPC::setNR(int _nr)
{
	nr = _nr;
}
int NPC::returnNR()
{
	return nr;
}
int NPC::returnLVL()
{
	return level;
}
int NPC::returnHP()
{
	return hp;
}
int NPC::returnDamageMin()
{
	return minDamage;
}
int NPC::returnDamageMax()
{
	return maxDamage;
}
void NPC::setPosition(double _x, double _y)
{
	pozycja.X=_x;
	pozycja.Y=_y;
}