#include <iostream>
#define PI 3.14159265
#include "func.h"
#include "NPC.h"
#include <GL/freeglut.h>
#include <string>
#include <cstring>
#include "imageloader.h"
#include "przeszkoda.h"
#include "scena.h"
#include "enemy.h"
#include <vector>
using namespace std;

Image * imageMAP = loadBMP("data/mapa.bmp");
GLuint _textureIdMAP;
Image * imageMENU = loadBMP("data/menu.bmp");
GLuint _textureIdMENU;
Image * imageINTRO = loadBMP("data/intro.bmp");
GLuint _textureIdINTRO;
Image * imageTABELA = loadBMP("data/tabela.bmp");
GLuint _textureIdTABELA;
Image * imageEND = loadBMP("data/ending.bmp");
GLuint _textureIdEND;


GLuint _textureIdBATTLE;
Image * imageBATTLE;


void drawMenu()
{
	glEnable(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, _textureIdMENU);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageMENU->width, imageMENU->height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageMENU->pixels);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-2, -2, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-2, 2, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2, 2, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2, -2, 0);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void drawIntro()
{
	glEnable(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, _textureIdINTRO);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageINTRO->width, imageINTRO->height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageINTRO->pixels);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-2, -2, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-2, 2, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2, 2, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2, -2, 0);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void drawTable()
{

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, _textureIdTABELA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageTABELA->width, imageTABELA->height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageTABELA->pixels);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.25f, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.25f, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.25f, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.25f, 0);

	glEnd();

}

void drawMap(double moveX, double moveY)
{
	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	player.DrawHERO();
	glTranslated(-1.51, -1.29, 0);
	drawTable();
	glPopMatrix();

	glPushMatrix();
	glTranslated(moveX, moveY, 0);

	glPushMatrix();
	rysujEnemy();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, _textureIdMAP);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageMAP->width, imageMAP->height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageMAP->pixels);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-10.5, -9, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-10.5, 9, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(10.5, 9, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(10.5, -9, 0);

	glEnd();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void drawEnding()
{
	glEnable(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, _textureIdEND);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageEND->width, imageEND->height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageEND->pixels);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-2, -2, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-2, 2, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2, 2, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2, -2, 0);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void drawBattle(int nrEnemy)
{
	if (nrEnemy==0)
		imageBATTLE = loadBMP("data/battle/black_knight.bmp");
	
	else if (nrEnemy==1)
		imageBATTLE = loadBMP("data/battle/cerber.bmp");
	
	else if (nrEnemy == 2)
		imageBATTLE = loadBMP("data/battle/dwarf.bmp");
	
	else if (nrEnemy == 3)
		imageBATTLE = loadBMP("data/battle/giant_spider.bmp");
	
	else if (nrEnemy == 4)
		imageBATTLE = loadBMP("data/battle/grimlud.bmp");
	
	else if (nrEnemy == 5)
		imageBATTLE = loadBMP("data/battle/grund.bmp");
	
	else if (nrEnemy == 6)
		imageBATTLE = loadBMP("data/battle/hydra.bmp");
	
	else if (nrEnemy == 7)
		imageBATTLE = loadBMP("data/battle/mad_axeman.bmp");

	else if (nrEnemy == 8)
		imageBATTLE = loadBMP("data/battle/minotaur.bmp");
	
	else if (nrEnemy == 9)
		imageBATTLE = loadBMP("data/battle/priesstes.bmp");
	
	else if (nrEnemy == 10)
		imageBATTLE = loadBMP("data/battle/priest.bmp");
	
	else if (nrEnemy == 11)
		imageBATTLE = loadBMP("data/battle/ranger.bmp");
	
	else if (nrEnemy == 12)
		imageBATTLE = loadBMP("data/battle/rehgar.bmp");
	
	else if (nrEnemy == 13)
		imageBATTLE = loadBMP("data/battle/thraal.bmp");
	
	else if (nrEnemy == 14)
		imageBATTLE = loadBMP("data/battle/uruk1.bmp");
	
	else if (nrEnemy == 15)
		imageBATTLE = loadBMP("data/battle/uruk2.bmp");
	
	else if (nrEnemy == 16)
		imageBATTLE = loadBMP("data/battle/uruk3.bmp");
	
	else if (nrEnemy == 17)
		imageBATTLE = loadBMP("data/battle/varus.bmp");
	
	string X="Atak: spacja";
	Napisz(-0.2f, -1, X);

	glEnable(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, _textureIdBATTLE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageBATTLE->width, imageBATTLE->height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageBATTLE->pixels);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-2, -2, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-2, 2, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2, 2, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2, -2, 0);

	glEnd();

	glDisable(GL_TEXTURE_2D);

	
}