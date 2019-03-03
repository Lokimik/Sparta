#pragma once
#include "Ability.h"
#include "Weapons.h"

class Units : public Ability
{
protected:
	size_t m_morality;
	size_t m_armor = 0;
	Weapons* m_weapon;
public:
	Units(string name, Weapons* weapons, size_t health, size_t damage);
	virtual void SetDamage(size_t damage);
	const size_t GetDamage();
	const size_t GetMorality();
	const size_t GetArmor();
	virtual void GetDamageAfterAttack(size_t attack);
	virtual void Show();
};

