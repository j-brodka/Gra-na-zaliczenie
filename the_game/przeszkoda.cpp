#include <iostream>
#define PI 3.14159265
#include "func.h"
#include "NPC.h"
#include <GL/freeglut.h>
#include "imageloader.h"
#include <vector>
#include "przeszkoda.h"
#include "scena.h"
#include "enemy.h"
using namespace std;

bool ifKolizja=false;
NPC player;
vector<Coords>koord;
vector<Coords>enemy;

void kolSpawn()
{
	Coords srodek;
	srodek.X = 0;
	srodek.Y = 0;
	koord.push_back(srodek);
	for (int i = 0; i < 3; i++)
	{
		srodek.Y -= 0.2237;
		koord.push_back(srodek);
	}
}

void kolLawa()
{
	Coords first, second, third;
	first.X = -5.3688;
	first.Y = 1.7896;
	second.X = -4.6977;
	second.Y = 0.6711;
	third.X = -4.474;
	third.Y = 1.5659;
	koord.push_back(third);
	third.Y += 0.2237;
	koord.push_back(third);
	for (int i = 0; i < 8; i++)
	{
		first.X += 0.2237;
		first.Y = 1.7896;
		for (int i = 0; i < 5; i++)
		{
			first.Y += 0.2237;
			koord.push_back(first);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		second.X += 0.2237;
		second.Y = 0.6711;
		for (int i = 0; i < 3; i++)
		{
			second.Y += 0.2237;
			koord.push_back(second);
		}
	}
	
}

void kolLas1()		//Centralny
{
	Coords first, second, third, fourth, fifth, sixth, seventh, eight, last;
	first.X = -4.0266;
	first.Y = -2.9081;
	second.X = -0.2237;
	second.Y = -4.2503;
	third.X = -3.8029;
	third.Y = -4.474;
	fourth.X = -4.744;
	fourth.Y = -3.1318;
	fifth.X = -0.8948;
	fifth.Y = -2.9081;
	sixth.X = -0.8948;
	sixth.Y = -2.6844;
	seventh.X = -1.1185;
	seventh.Y = -2.6844;
	eight.X = -0.2237;
	eight.Y = -0.6711;
	last.X = -4.474;
	last.Y = -3.1318;
	koord.push_back(third);
	for (int i = 0; i < 21; i++)
	{
		first.X += 0.2237;
		first.Y = -2.9081;
		for (int i = 0; i < 5; i++)
		{
			first.Y -= 0.2237;
			koord.push_back(first);
		}
	}
	for (int i = 0; i < 18; i++)
	{
		second.X -= 0.2237;
		koord.push_back(second);
	}
	for (int i = 0; i < 4; i++)
	{
		third.X += 0.2237;
		third.Y = -4.2503;
		for (int i = 0; i < 2; i++)
		{
			third.Y -= 0.2237;
			koord.push_back(third);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		fourth.X += 0.2237;
		fourth.Y = -3.1318;
		for (int i = 0; i < 5; i++)
		{
			fourth.Y -= 0.2237;
			koord.push_back(fourth);
		}
	}
	for (int i = 0; i < 7; i++)
	{
		fifth.X += 0.2237;
		koord.push_back(fifth);
	}
	for (int i = 0; i < 9; i++)
	{
		sixth.X += 0.2237;
		koord.push_back(sixth);
	}
	for (int i = 0; i < 10; i++)
	{
		seventh.X += 0.2237;
		seventh.Y = -2.6844;
		for (int i = 0; i < 6; i++)
		{
			seventh.Y += 0.2237;
			koord.push_back(seventh);
		}
	}
	for (int i = 0; i < 6; i++)
	{
		eight.X += 0.2237;
		eight.Y = -0.6711;
		for (int i = 0; i < 2; i++)
		{
			eight.Y -= 0.2237;
			koord.push_back(eight);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		last.X += 0.2237;
		last.Y = -3.1318;
		for (int i = 0; i < 5; i++)
		{
			last.Y -= 0.2237;
			koord.push_back(last);
		}
	}
}

void kolLas2()		//zachodni
{
	Coords first, second, third, fourth, fifth, sixth, seventh;
	first.X = -2.6844;
	first.Y = -2.9081;
	second.X = -2.237;
	second.Y = -1.5659;
	third.X = -4.2503;
	third.Y = -1.3422;
	fourth.X = -5.3688;
	fourth.Y = -0.8948;
	fifth.X = -6.2636;
	fifth.Y = -0.8948;
	sixth.X = -5.3688;
	sixth.Y = -1.1185;
	seventh.X = -4.474;
	seventh.Y = -0.8948;
	koord.push_back(first);
	koord.push_back(fourth);
	for (int i = 0; i < 6; i++)
	{
		first.Y += 0.2237;
		koord.push_back(first);
	}
	for (int i = 0; i < 9; i++)
	{
		second.X -= 0.2237;
		second.Y = -1.5659;
		for (int i = 0; i < 3; i++)
		{
			second.Y += 0.2237;
			koord.push_back(second);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		third.X -= 0.2237;
		third.Y = -1.3422;
		for (int i = 0; i < 2; i++)
		{
			third.Y += 0.2237;
			koord.push_back(third);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		fourth.X -= 0.2237;
		koord.push_back(fourth);
	}
	for (int i = 0; i < 2; i++)
	{
		fifth.X += 0.2237;
		fifth.Y = -0.8948;
		for (int i = 0; i < 2; i++)
		{
			fifth.Y -= 0.2237;
			koord.push_back(fifth);
		}
	}
	for (int i = 0; i < 1; i++)
	{
		sixth.X += 0.2237;
		sixth.Y = -1.1185;
		for (int i = 0; i < 6; i++)
		{
			sixth.Y -= 0.2237;
			koord.push_back(sixth);
		}
	}
	for (int i = 0; i < 8; i++)
	{
		seventh.Y += 0.2237;
		koord.push_back(seventh);
	}
}

void kolLas3()			//wschodni
{
	Coords first, second, third, fourth, fifth, sixth, seventh;
	first.X = 1.3422;
	first.Y = -2.237;
	second.X = 2.6844;
	second.Y = -3.1318;
	third.X = 2.9081;
	third.Y = -2.4607;
	fourth.X = 3.1318;
	fourth.Y = -1.7896;
	fifth.X = 3.5792;
	fifth.Y = -1.7896;
	sixth.X = 4.0266;
	sixth.Y = -1.1185;
	seventh.X = 4.9214;
	seventh.Y = -1.7896;
	koord.push_back(first);
	koord.push_back(fourth);
	for (int i = 0; i < 7; i++)
	{
		first.X += 0.2237;
		koord.push_back(first);
	}
	for (int i = 0; i < 5; i++)
	{
		second.X += 0.2237;
		second.Y = -3.1318;
		for (int i = 0; i < 3; i++)
		{
			second.Y += 0.2237;
			koord.push_back(second);
		}
	}
	for (int i = 0; i < 9; i++)
	{
		third.X += 0.2237;
		third.Y = -2.4607;
		for (int i = 0; i < 3; i++)
		{
			third.Y += 0.2237;
			koord.push_back(third);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		fifth.X += 0.2237;
		fifth.Y = -1.7896;
		for (int i = 0; i < 3; i++)
		{
			fifth.Y += 0.2237;
			koord.push_back(fifth);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		sixth.Y += 0.2237;
		koord.push_back(sixth);
	}
	for (int i = 0; i < 4; i++)
	{
		seventh.X += 0.2237;
		seventh.Y = -1.7896;
		for (int i = 0; i < 5; i++)
		{
			seventh.Y -= 0.2237;
			koord.push_back(seventh);
		}
	}
}

void kolSwamp()
{
	Coords first, second;
	first.X = 3.5792;
	first.Y = -0.2237;
	second.X = 4.2503;
	second.Y = 1.1185;
	for (int i = 0; i < 2; i++)
	{
		first.X += 0.2237;
		first.Y = -0.2237;
		for (int i = 0; i < 5; i++)
		{
			first.Y += 0.2237;
			koord.push_back(first);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		second.Y -= 0.2237;
		koord.push_back(second);
	}
}

void kolKatedra()
{
	Coords first;
	first.X = 5.3688;
	first.Y = -2.9081;
	for (int i = 0; i < 2; i++)
	{
		first.X += 0.2237;
		first.Y = -2.9081;
		for (int i = 0; i < 7; i++)
		{
			first.Y -= 0.2237;
			koord.push_back(first);
		}
	}
}

void kolLas4()			//po³udniowy
{
	Coords first, second, third, fourth, fifth, sixth, seventh, eighth, nineth, tenth, eleventh, next, next1, prelast, last;
	first.X = 4.474;
	first.Y = -2.237;
	second.X = 4.0266;
	second.Y = -3.3555;
	third.X = 4.474;
	third.Y = -4.6977;
	fourth.X = 2.4607;
	fourth.Y = -5.3688;
	fifth.X = 0.8948;
	fifth.Y = -5.1451;
	sixth.X = 1.3422;
	sixth.Y = -4.9214;
	seventh.X = 2.0133;
	seventh.Y = -5.1451;
	eighth.X = 1.3422;
	eighth.Y = -5.5925;
	nineth.X = -0.2237;
	nineth.Y = -5.5925;
	tenth.X = -2.0133;
	tenth.Y = -5.3688;
	eleventh.X = -2.6844;
	eleventh.Y = 5.1451;
	next.X = 2.237;
	next.Y = -4.2503;
	next1.X = 2.9081;
	next1.Y = -4.474;
	prelast.X = -0.6711;
	prelast.Y = -5.8162;
	last.X = -0.6711;
	last.Y = -6.0399;
	for (int i = 0; i < 5; i++)
	{
		first.Y -= 0.2237;
		koord.push_back(first);
	}
	for (int i = 0; i < 3; i++)
	{
		second.X += 0.2237;
		second.Y = -3.3555;
		for (int i = 0; i < 6; i++)
		{
			second.Y -= 0.2237;
			koord.push_back(second);
		}
	}
	for (int i = 0; i < 9; i++)
	{
		third.X -= 0.2237;
		third.Y = -4.6977;
		for (int i = 0; i < 2; i++)
		{
			third.Y -= 0.2237;
			koord.push_back(third);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		fourth.X -= 0.2237;
		fourth.Y = -5.3688;
		for (int i = 0; i < 5; i++)
		{
			fourth.Y += 0.2237;
			koord.push_back(fourth);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		fifth.X -= 0.2237;
		fifth.Y = -5.1451;
		for (int i = 0; i < 2; i++)
		{
			fifth.Y += 0.2237;
			koord.push_back(fifth);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		sixth.X -= 0.2237;
		koord.push_back(sixth);
	}
	for (int i = 0; i < 3; i++)
	{
		seventh.X -= 0.2237;
		seventh.Y = -5.1451;
		for (int i = 0; i < 2; i++)
		{
			seventh.Y -= 0.2237;
			koord.push_back(seventh);
		}
	}
	for (int i = 0; i < 11; i++)
	{
		eighth.X -= 0.2237;
		koord.push_back(eighth);
	}
	for (int i = 0; i < 8; i++)
	{
		nineth.X -= 0.2237;
		nineth.Y = -5.5925;
		for (int i = 0; i < 3; i++)
		{
			nineth.Y += 0.2237;
			koord.push_back(nineth);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		tenth.X -= 0.2237;
		koord.push_back(tenth);
	}
	for (int i = 0; i < 3; i++)
	{
		eleventh.X -= 0.2237;
		eleventh.Y = -5.1451;
		for (int i = 0; i < 4; i++)
		{
			eleventh.Y -= 0.2237;
			koord.push_back(eleventh);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		next.X += 0.2237;
		koord.push_back(next);
	}
	for (int i = 0; i < 2; i++)
	{
		prelast.X -= 0.2237;
		koord.push_back(prelast);
	}
	for (int i = 0; i < 6; i++)
	{
		last.X -= 0.2237;
		koord.push_back(last);
	}
	for (int i = 0; i < 2; i++)
	{
		next1.X += 0.2237;
		next1.Y = -4.474;
		for (int i = 0; i < 4; i++)
		{
			next1.Y += 0.2237;
			koord.push_back(next1);
		}
	}
}

void kolizjaEnemy()
{
	enemy.push_back(black_knight.getPozycja());
	enemy.push_back(cerber.getPozycja());
	enemy.push_back(dwarf.getPozycja());
	enemy.push_back(giant_spider.getPozycja());
	enemy.push_back(hydra.getPozycja());
	enemy.push_back(grimlud.getPozycja());
	enemy.push_back(grund.getPozycja());
	enemy.push_back(mad_axeman.getPozycja());
	enemy.push_back(minotaur.getPozycja());
	enemy.push_back(priestess.getPozycja());
	enemy.push_back(priest.getPozycja());
	enemy.push_back(ranger.getPozycja());
	enemy.push_back(rehgar.getPozycja());
	enemy.push_back(thraal.getPozycja());
	enemy.push_back(uruk1.getPozycja());
	enemy.push_back(uruk2.getPozycja());
	enemy.push_back(uruk3.getPozycja());
	enemy.push_back(varus.getPozycja());
}

void stworzKolizja()
{
	kolSpawn();
	kolLawa();
	kolKatedra();
	kolSwamp();
	kolLas1();
	kolLas2();
	kolLas3();
	kolLas4();

	kolizjaEnemy();

	for (int i = 0; i < koord.size(); i++)
	{
		for (int j = 0; j < enemy.size(); j++)
		{
			if (koord[i] == enemy[j])
			{
				koord.erase(koord.begin() + i);
				i = 0;
			}
		}
	}
}

void kolizja()
{
	for (int i = 0; i < koord.size(); i++)
	{
		if (player.getPozycja() == koord[i])
		{
			ifKolizja = false;
			i = koord.size();
		}
		else
			ifKolizja = true;
	}
}

void usunTo(NPC enemy)
{
	if(enemy.isAlive()==false)
		koord.push_back(enemy.getPozycja());
}

