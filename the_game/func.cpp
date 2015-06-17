#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.14159265
#include "func.h"
#include "NPC.h"
#include "imageloader.h"
#include "przeszkoda.h"
#include "scena.h"
#include "enemy.h"
#include <GL/freeglut.h>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

double moveX, moveY;
int strona=0, scena=0, nrEnemy = 0, win=0, pHP, eHP, init=0;
bool trybWalka = false;
vector<NPC>enemy2;
string level, damage, hp;

void SpawnHero()
{
	player.setLVL(1);
	player.setDamage(3, 10);
	player.setAlive(true);
	player.setHP(30);
	player.setNR(0);
	scena = 0;
	level = "Level: ";
	damage = "Damage: min     max";
	hp = "HP: ";
}

void zapiszGre()
{
	fstream plik;
	plik.open("data/save.sv");

	if (plik.is_open())
	{
		plik<<player.getX()<<" "<<player.getY()<<" "<<player.returnHP()<<" "<<player.returnLVL()<<" "<<player.returnDamageMin()<<" "<<player.returnDamageMax()<<endl;
		
		for(int i=0; i<enemy2.size(); i++)
		{
			plik<<enemy2[i].isAlive()<<endl;
		}
	}
	plik.close();
}
void wczytajGre()
{
	fstream plik;
	plik.open("data/save.sv");

	if (plik.is_open())
	{
		double zm1, zm4;
		int zm2, zm3;
		plik>>zm1;
		moveX=-zm1;
		plik>>zm4;
		moveY=-zm4;
		player.setPosition(zm1, zm4);
		plik>>zm2;
		player.setHP(zm2);
		plik>>zm2;
		player.setLVL(zm2);
		plik>>zm2;
		plik>>zm3;
		player.setDamage(zm2, zm3);
		
		
		for(int i=0; i<enemy2.size(); i++)
		{
			bool alive;
			plik>>alive;
			enemy2[i].setAlive(alive);
			usunTo(enemy2[i]);
		}
	}
	win = 0;
	
	plik.close();
}

bool Coords::operator==(const Coords &a)
{
	if ((this->X == a.X) && (this->Y == a.Y))
		return true;
	else
		return false;
}

void idle(void)
{
	glutPostRedisplay();
}
void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void inicjujEnemy2()
{
	enemy2.push_back(black_knight);
	enemy2.push_back(cerber);
	enemy2.push_back(dwarf);
	enemy2.push_back(giant_spider);
	enemy2.push_back(grimlud);
	enemy2.push_back(grund);
	enemy2.push_back(hydra);
	enemy2.push_back(mad_axeman);
	enemy2.push_back(minotaur);
	enemy2.push_back(priestess);
	enemy2.push_back(priest);
	enemy2.push_back(ranger);
	enemy2.push_back(rehgar);
	enemy2.push_back(thraal);
	enemy2.push_back(uruk1);
	enemy2.push_back(uruk2);
	enemy2.push_back(uruk3);
	enemy2.push_back(varus);
}

void sprawdzWalka()
{
	for (int i = 0; i < enemy2.size(); i++)
	{
		if ((player.getPozycja()).X == (enemy2[i].getX() + 0.2237) || (player.getPozycja()).X == (enemy2[i].getX()) || (player.getPozycja()).X == (enemy2[i].getX() - 0.2237))
		{
			if ((player.getPozycja()).Y == (enemy2[i].getY() + 0.2237) || (player.getPozycja()).Y == (enemy2[i].getY()) || (player.getPozycja()).Y == (enemy2[i].getY() - 0.2237))
			{
				if (player.returnLVL() == enemy2[i].returnLVL())
				{
					nrEnemy = enemy2[i].returnNR();
					init = 0;
					scena = 3;
				}
				else
					cout << "Twoj poziom jest zbyt niski, by walczyc z tym przeciwnikiem!" << endl;
			}
		}
	}
}

void sysWalki()
{
	int pMin=player.returnDamageMin();
	int pMax=player.returnDamageMax();
	int eMin=enemy2[nrEnemy].returnDamageMin();
	int eMax=enemy2[nrEnemy].returnDamageMax();

	int pHit=rand() % (pMax-pMin) + pMin;
	int eHit=rand() % (eMax - eMin) + eMin;

	eHP-=pHit;
	pHP-=eHit;

	if(eHP<0)
		eHP=0;
	if(pHP<0)
		pHP=0;

	if(eHP==0)
	{
		win=1;
		enemy2[nrEnemy].setAlive(false);
		player.setLVL(player.returnLVL()+1);
		player.setHP(player.returnHP()+5);
		player.setDamage(player.returnDamageMin()+3, player.returnDamageMax()+3);
		if (nrEnemy == 12)
		{
			scena = 4;
			win = 3;
		}
	}

	if(pHP==0)
	{
		win=2;
	}
	usunTo(enemy2[nrEnemy]);

	
}

void Napisz(float x, float y, string str)
{
	int len, i;
	glRasterPos2f(x, y);
	char * cstr = new char[str.length() + 1];
	strcpy_s(cstr, str.length() + 1, str.c_str());
	len = (int)strlen(cstr);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, cstr[i]);
	}
}

void processNormalKeys(unsigned char key, int xx, int yy) 
{
	switch (key)
	{
	case 27:
	{
			   exit(0);
			   break;
	}
	case 32:
	{
			   if (scena == 0)
				   scena = 1;
			   else if (scena == 1)
				   scena = 2;
			   else if (scena == 3)
			   {
				   if (win == 0)
					   sysWalki();
				   else if (win == 1)
				   {
					   scena = 2;
					   init = 0;
					   win = 0;
				   }
				   else if (win == 2)
					   exit(0);
			   }
			   else if (scena == 4)
				   exit(0);
			   break;
	}
	case 102:
	{
				sprawdzWalka();
				break;
	}
	case 's':
	{
		zapiszGre();
		break;
	}
	case 'w':
	{
		wczytajGre();
		if(scena == 3)
		{
			scena = 2;
			wczytajGre();
		}
		break;
	}
	}
}
void SpecialKeysFunc(int key, int x, int y)
{
	if (scena == 2)
	{
		switch (key)
		{
		case GLUT_KEY_UP:
		{
							if (ifKolizja == false)
							{
								moveY -= 0.2237;
								player.setY(0.2237);
								cout << "x " << player.getX() << " y " << player.getY() << endl;
							}
							strona = 8;
							break;
		}

		case GLUT_KEY_DOWN:
		{
							  if (ifKolizja == false)
							  {
								  moveY += 0.2237;
								  player.setY(-0.2237);
								  cout << "x " << player.getX() << " y " << player.getY() << endl;
							  }
							  strona = 2;
							  break;
		}

		case GLUT_KEY_RIGHT:
		{
							   if (ifKolizja == false)
							   {
								   moveX -= 0.2237;
								   player.setX(0.2237);
								   cout << "x " << player.getX() << " y " << player.getY() << endl;
							   }
							   strona = 6;
							   break;
		}

		case GLUT_KEY_LEFT:
		{
							  if (ifKolizja == false)
							  {
								  moveX += 0.2237;
								  player.setX(-0.2237);
								  cout << "x " << player.getX() << " y " << player.getY() << endl;
							  }
							  strona = 4;
							  break;
		}
		}
	}
}


void cofka()
{
	if (ifKolizja == true)
	{
		if (strona == 8)
		{
			moveY += 0.2237;
			player.setY(-0.2237);
		}
		else if (strona == 2)
		{
			moveY -= 0.2237;
			player.setY(0.2237);
		}
		else if (strona == 6)
		{
			moveX += 0.2237;
			player.setX(-0.2237);
		}
		else if (strona == 4)
		{
			moveX -= 0.2237;
			player.setX(0.2237);
		}
	}
}
string convert(int i)
{
	stringstream ss;
	string str;
	ss << i;
	ss >> str;
	return str;
}


void display(void)
{	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	kolizja();
	cofka();
	glPushMatrix();
	
	if (scena==0)
		drawMenu();
	else if (scena==1)
		drawIntro();
	else if (scena == 2)
	{
		int i = player.returnLVL();
		Napisz(-1.95, -1.19, level);
		Napisz(-1.40, -1.19, convert(i));
		int j = player.returnHP();
		Napisz(-1.95, -1.32, hp);
		Napisz(-1.40, -1.32, convert(j));
		int k = player.returnDamageMin();
		Napisz(-1.95, -1.45, damage);
		Napisz(-1.40, -1.45, convert(k));
		int l = player.returnDamageMax();
		Napisz(-1.12, -1.45, convert(l));
		drawMap(moveX, moveY);
		
	}
	else if (scena == 3)
	{
		if(init==0)
		{
			pHP = player.returnHP();
			eHP = enemy2[nrEnemy].returnHP();
			init=1;
		}
		Napisz(-1.2, 1.1, hp);
		Napisz(-1.2, 1, convert(pHP));
		Napisz(1.2, 1.1, hp);
		Napisz(1.2, 1, convert(eHP));
		string W="Wygrales! Nacisnij spacje, aby kontynuowac.";
		string P="Zginales! Rozpocznij od poczatku lub wczytaj rozgrywke.";
		if(win==1)
			Napisz(-0.3, 0, W);
		else if(win==2)
			Napisz(-0.4, 0, P);
		drawBattle(nrEnemy);
	}
	else if (scena == 4)
	{
		drawEnding();
	}

	glPopMatrix();
	glutSwapBuffers();
}

