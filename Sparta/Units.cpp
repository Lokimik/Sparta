#include "Weapons.h"
#include "Units.h"

Units::Units(string name, Weapons * weapons, size_t health, size_t damage) : m_weapon(weapons), Ability(name, health, damage) {}

void Units::SetDamage(size_t damage) 
{
	m_damage = damage + GetMorality() + m_weapon->GetDamageOfWeapons();
}

const size_t Units::GetDamage()
{
	return m_damage;
}

const size_t Units::GetMorality()
{
	return m_morality;
}

const size_t Units::GetArmor()
{
	return m_armor;
}

void Units::GetDamageAfterAttack(size_t attack) 
{
	if (m_health > attack)
	{
		m_health -= attack;
	}
	else
	{
		m_health = 0;
	}
}

void Units::Show() 
{
	cout << endl << "Name: " << GetName() << endl;
	cout << "Type: Unity" << endl;
	cout << "Damage: " << GetDamage() << endl;
	cout << "Health: " << GetHealth() << endl;
}

 
