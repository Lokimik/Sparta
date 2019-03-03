#pragma once
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Ability {
	protected:
	string m_name;
	size_t m_health;
	size_t m_damage;
	int m_luck=0;
public:
	Ability(string name, size_t health, size_t damage);
	void SetHealth(size_t health);
	virtual void SetDamage(size_t damage);
	void SetLuck(int luck);
	const size_t GetHealth();
	const int GetLuck();
	const string GetName();
	virtual void GetDamageAfterAttack(size_t attack) = 0;
	virtual void Show() = 0;
};