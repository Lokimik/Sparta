#include "Enemy.h"

Enemy::Enemy(string name, size_t health, size_t damage) : Ability(name, health, damage) {}

void Enemy::SetDamage(size_t damage) 
{
	int attack = damage + GetRage() + GetBloodlust();
	Ability::SetDamage(attack);
}

const size_t  Enemy::GetDamage() 
{
	return m_damage;
}

const size_t  Enemy::GetRage() 
{
	return m_rage;
}

const size_t  Enemy::GetBloodlust() 
{
	return m_bloodlust;
}

void  Enemy::GetDamageAfterAttack(size_t attack) 
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

void  Enemy::Show() 
{
	cout << endl << "Name: " << GetName() << endl;
	cout << "Type: Enemy" << endl;
	cout << "Damage: " << GetDamage() << endl;
	cout << "Health: " << GetHealth() << endl;
}