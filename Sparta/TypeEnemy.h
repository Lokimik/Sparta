#pragma once
#include "Enemy.h"

class Slave
	: public Enemy
{
public:
	Slave() : Enemy("Slave", 5, 1)
	{
		m_rage = rand() % 2 + 1;
		m_bloodlust = 0;
		SetDamage(GetDamage());
	}
};

class Barbarian 
	: public Enemy
{
public:
	Barbarian() : Enemy("Barbarian", 20, 8)
	{
		m_rage = rand() % 2 + 1;
		m_bloodlust = 2;
		SetDamage(GetDamage());
	}
};

class Persians
	: public Enemy
{
public:
	Persians() : Enemy("Persians", 60, 45)
	{
		m_rage = rand() % 5 + 1;
		m_bloodlust = 4;
		SetDamage(GetDamage());
	}
};

class Dragon
	: public Enemy
{
public:
	Dragon() : Enemy("Dragon", 1500, 500)
	{
		m_rage = rand() % 20 + 1;
		m_bloodlust = rand() % 40 + 5;
		SetDamage(GetDamage());
	}
};

class Demigod 
	: public Enemy
{
public:
	Demigod() : Enemy("Demigod", 1700, 150)
	{
		m_rage = rand() % 10 + 5;
		m_bloodlust = rand() % 10 + 5;
		SetDamage(GetDamage());
	}
};