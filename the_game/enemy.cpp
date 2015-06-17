#include <iostream>
#define PI 3.14159265
#include "func.h"
#include "NPC.h"
#include "imageloader.h"
#include "przeszkoda.h"
#include "scena.h"
#include "enemy.h"
#include <GL/freeglut.h>
#include <vector>
using namespace std;

GLuint _textureId;
Image * image;

NPC black_knight, cerber, dwarf, giant_spider, grimlud, grund, hydra, mad_axeman, minotaur, priestess, priest, ranger, rehgar, thraal, uruk1, uruk2, uruk3, varus;

void NPC::DrawNPC(double _x, double _y)
{
	glTranslated(_x, _y, 0);
	glBindTexture(GL_TEXTURE_2D, _textureId); //Mówimy OpenGl jaka tekstura
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
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

void rysujEnemy()
{
	image = loadBMP("data/icons/black_knight.bmp");
	glPushMatrix();
	if(black_knight.isAlive()==true)
		black_knight.DrawNPC(5.8162, -4.474);
	glPopMatrix();

	image = loadBMP("data/icons/cerber.bmp");
	glPushMatrix();
	if(cerber.isAlive()==true)
		cerber.DrawNPC(-6.0399, -1.3422);
	glPopMatrix();

	image = loadBMP("data/icons/dwarf.bmp");
	glPushMatrix();
	if(dwarf.isAlive()==true)
		dwarf.DrawNPC(-1.1185, -2.0133);
	glPopMatrix();

	image = loadBMP("data/icons/giant_spider.bmp");
	glPushMatrix();
	if(giant_spider.isAlive()==true)
		giant_spider.DrawNPC(2.237, -4.0266);
	glPopMatrix();

	image = loadBMP("data/icons/grimlud.bmp");
	glPushMatrix();
	if(grimlud.isAlive()==true)
		grimlud.DrawNPC(3.3555, -3.8029);
	glPopMatrix();

	image = loadBMP("data/icons/grund.bmp");
	glPushMatrix();
	if(grund.isAlive()==true)
		grund.DrawNPC(4.0266, -5.3688);
	glPopMatrix();

	image = loadBMP("data/icons/hydra.bmp");
	glPushMatrix();
	if(hydra.isAlive()==true)
		hydra.DrawNPC(-3.3555, -5.8162);
	glPopMatrix();

	image = loadBMP("data/icons/mad_axeman.bmp");
	glPushMatrix();
	if(mad_axeman.isAlive()==true)
		mad_axeman.DrawNPC(-4.0266, -3.8029);
	glPopMatrix();

	image = loadBMP("data/icons/minotaur.bmp");
	glPushMatrix();
	if(minotaur.isAlive()==true)
		minotaur.DrawNPC(0.4474, -5.5925);
	glPopMatrix();

	image = loadBMP("data/icons/priestess.bmp");
	glPushMatrix();
	if(priestess.isAlive()==true)
		priestess.DrawNPC(3.5792, 0.6711);
	glPopMatrix();

	image = loadBMP("data/icons/priest.bmp");
	glPushMatrix();
	if(priest.isAlive()==true)
		priest.DrawNPC(4.474, 0.6711);
	glPopMatrix();

	image = loadBMP("data/icons/ranger.bmp");
	glPushMatrix();
	if(ranger.isAlive()==true)
		ranger.DrawNPC(-4.9214, -1.7896);
	glPopMatrix();

	image = loadBMP("data/icons/rehgar.bmp");
	glPushMatrix();
	if(rehgar.isAlive()==true)
		rehgar.DrawNPC(-4.474, 2.4607);
	glPopMatrix();

	image = loadBMP("data/icons/thraal.bmp");
	glPushMatrix();
	if(thraal.isAlive()==true)
		thraal.DrawNPC(-2.0133, -6.0399);
	glPopMatrix();

	image = loadBMP("data/icons/uruk_1.bmp");
	glPushMatrix();
	if(uruk1.isAlive()==true)
		uruk1.DrawNPC(4.474, -3.1318);
	glPopMatrix();

	image = loadBMP("data/icons/uruk_2.bmp");
	glPushMatrix();
	if(uruk2.isAlive()==true)
		uruk2.DrawNPC(2.237, -2.237);
	glPopMatrix();

	image = loadBMP("data/icons/uruk_3.bmp");
	glPushMatrix();
	if(uruk3.isAlive()==true)
		uruk3.DrawNPC(-2.6844, -2.4607);
	glPopMatrix();

	image = loadBMP("data/icons/varus.bmp");
	glPushMatrix();
	if(varus.isAlive()==true)
		varus.DrawNPC(-4.474, 0.6711);
	glPopMatrix();
}

void inicjujEnemy()
{
	black_knight.setAlive(true);
	black_knight.setX(5.8162);
	black_knight.setY(-4.474);
	black_knight.setLVL(6);
	black_knight.setHP(100);
	black_knight.setDamage(7, 15);
	black_knight.setNR(0);

	cerber.setAlive(true);
	cerber.setX(-6.0399);
	cerber.setY(-1.3422);
	cerber.setLVL(11);
	cerber.setHP(140);
	cerber.setDamage(12, 20);
	cerber.setNR(1);

	dwarf.setAlive(true);
	dwarf.setX(-1.1185);
	dwarf.setY(-2.0133);
	dwarf.setLVL(1);
	dwarf.setHP(25);
	dwarf.setDamage(2, 5);
	dwarf.setNR(2);

	giant_spider.setAlive(true);
	giant_spider.setX(2.237);
	giant_spider.setY(-4.0266);
	giant_spider.setLVL(12);
	giant_spider.setHP(145);
	giant_spider.setDamage(17, 22);
	giant_spider.setNR(3);

	grimlud.setAlive(true);
	grimlud.setX(3.3555);
	grimlud.setY(-3.8029);
	grimlud.setLVL(8);
	grimlud.setHP(110);
	grimlud.setDamage(10, 17);
	grimlud.setNR(4);

	grund.setAlive(true);
	grund.setX(4.0266);
	grund.setY(-5.3688);
	grund.setLVL(13);
	grund.setHP(150);
	grund.setDamage(19, 24);
	grund.setNR(5);

	hydra.setAlive(true);
	hydra.setX(-3.3555);
	hydra.setY(-5.8162);
	hydra.setLVL(16);
	hydra.setHP(240);
	hydra.setDamage(10, 20);
	hydra.setNR(6);

	mad_axeman.setAlive(true);
	mad_axeman.setX(-4.0266);
	mad_axeman.setY(-3.8029);
	mad_axeman.setLVL(2);
	mad_axeman.setHP(35);
	mad_axeman.setDamage(5, 8);
	mad_axeman.setNR(7);

	minotaur.setAlive(true);
	minotaur.setX(0.4474);
	minotaur.setY(-5.5925);
	minotaur.setLVL(14);
	minotaur.setHP(155);
	minotaur.setDamage(20, 26);
	minotaur.setNR(8);

	priestess.setAlive(true);
	priestess.setX(3.5792);
	priestess.setY(0.6711);
	priestess.setLVL(4);
	priestess.setHP(50);
	priestess.setDamage(8, 13);
	priestess.setNR(9);

	priest.setAlive(true);
	priest.setX(4.474);
	priest.setY(0.6711);
	priest.setLVL(5);
	priest.setHP(55);
	priest.setDamage(9, 13);
	priest.setNR(10);

	ranger.setAlive(true);
	ranger.setX(-4.9214);
	ranger.setY(-1.7896);
	ranger.setLVL(10);
	ranger.setHP(115);
	ranger.setDamage(14, 20);
	ranger.setNR(11);

	rehgar.setAlive(true);
	rehgar.setX(-4.474);
	rehgar.setY(2.4607);
	rehgar.setLVL(18);
	rehgar.setHP(420);
	rehgar.setDamage(5, 19);
	rehgar.setNR(12);

	thraal.setAlive(true);
	thraal.setX(-2.0133);
	thraal.setY(-6.0399);
	thraal.setLVL(15);
	thraal.setHP(160);
	thraal.setDamage(22, 27);
	thraal.setNR(13);

	uruk1.setAlive(true);
	uruk1.setX(4.474);
	uruk1.setY(-3.1318);
	uruk1.setLVL(7);
	uruk1.setHP(100);
	uruk1.setDamage(9, 16);
	uruk1.setNR(14);

	uruk2.setAlive(true);
	uruk2.setX(2.237);
	uruk2.setY(-2.237);
	uruk2.setLVL(3);
	uruk2.setHP(40);
	uruk2.setDamage(8, 11);
	uruk2.setNR(15);

	uruk3.setAlive(true);
	uruk3.setX(-2.6844);
	uruk3.setY(-2.4607);
	uruk3.setLVL(9);
	uruk3.setHP(100);
	uruk3.setDamage(16, 21);
	uruk3.setNR(16);

	varus.setAlive(true);
	varus.setX(-4.474);
	varus.setY(0.6711);
	varus.setLVL(17);
	varus.setHP(300);
	varus.setDamage(12, 22);
	varus.setNR(17);
}


