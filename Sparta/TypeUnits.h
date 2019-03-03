#pragma once
#include "Units.h"
#include "WeaponsType.h"

class Hoplite 
	: public Units
{
public:
	Hoplite() : Units("Hoplite", m_weapon, 50, 30)
	{
		m_weapon = new Spear;
		m_morality = rand() % 80 + 1;
		SetDamage(GetDamage());
	}
};

class Hypaspists
	: public Units
{
public:
	Hypaspists() : Units("Hypaspists", m_weapon, 25, 15)
	{
		m_weapon = new Sword;
		m_morality = rand() % 60 + 1;
		SetDamage(GetDamage());
	}
};

class Agriana
	: public Units
{
public:
	Agriana() : Units("Agriana", m_weapon, 20, 10)
	{
		m_weapon = new Pilum;
		m_morality = rand() % 40 + 1;
		SetDamage(GetDamage());
	}
};

class Peltasts
	: public Units
{
public:
	Peltasts() : Units("Peltasts", m_weapon, 15, 8)
	{
		m_weapon = new Axe;
		m_morality = rand() % 20 + 1;
		SetDamage(GetDamage());
	}
};

class Libertini
	: public Units
{
public:
	Libertini() : Units("Libertini", m_weapon, 10, 4)
	{
		m_weapon = new Hands;
		m_morality = rand() % 10 + 1;
		SetDamage(GetDamage());
	}
};