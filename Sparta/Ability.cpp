#include "Ability.h"

Ability::Ability(string name, size_t health, size_t damage) : m_name(name), m_health(health), m_damage(damage){}

void Ability::SetHealth(size_t health)
{
	m_health = health;
}

void Ability::SetDamage(size_t damage) 
{
	m_damage = damage;
}

void Ability::SetLuck(int luck) 
{
	m_luck = luck;
}

const size_t Ability::GetHealth() 
{
	return m_health;
}

const int Ability::GetLuck() 
{
	return m_damage;
}

const string Ability::GetName()
{
	return m_name;
}
