#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "Boss.h"



class Enemy
{
public:
    Enemy(int damage = 10);
    virtual ~Enemy();
    void virtual Attack() const;

protected:
    int* m_pDamage;
};

Enemy::Enemy(int damage)
{
    m_pDamage = new int(damage);
}

Enemy::~Enemy()
{
    cout << "In Enemy destructor, deleting m_pDamage.\n";
    delete m_pDamage;
    m_pDamage = 0;
}


#endif 
