#pragma once
#include "Ability.h"

class Weapons 
{
	size_t m_damage_of_weap;
	string m_name;
public:
	Weapons(string name, size_t damage);
	const size_t GetDamageOfWeapons();
};

