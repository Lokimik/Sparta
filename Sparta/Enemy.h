#pragma once
#include "Ability.h"

class Enemy : public Ability
{
protected:
	size_t m_rage;
	size_t m_bloodlust;
public:
	Enemy(string name, size_t health, size_t damage);
	virtual void SetDamage(size_t damage);
	const size_t GetDamage();
	const size_t GetRage();
	const size_t GetBloodlust();
	virtual void GetDamageAfterAttack(size_t attack);
	virtual void Show();
};

