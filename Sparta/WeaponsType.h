#pragma once
#include "Weapons.h"

class Spear 
	: public Weapons
{
public:
	Spear() :Weapons("Spear", 15) {}
};

class Sword 
	: public Weapons
{
public:
	Sword() :Weapons("Sword", 10) {}
};

class Pilum
	: public Weapons
{
public:
	Pilum() : Weapons("Pilum", 7) {}
};

class Axe
	: public Weapons
{
public:
	Axe() : Weapons("Axe", 5) {}
};

class Hands
	: public Weapons
{
public:
	Hands() : Weapons("Hands", 3) {}
};