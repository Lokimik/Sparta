#include "Weapons.h"

Weapons::Weapons(string name, size_t damage) : m_name(name), m_damage_of_weap(damage) {}

const size_t Weapons::GetDamageOfWeapons() 
{
	return m_damage_of_weap;
}