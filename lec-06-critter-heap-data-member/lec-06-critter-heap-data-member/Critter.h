#pragma once
#ifndef CRITTER_H
#define CRITTER_H
#include <iostream>
#include <string>

using namespace std;

class Critter
{
public:
	Critter(const string& name = "", int age = 0);
	~Critter();                   //destructor prototype   
	Critter(const Critter& c);    //copy constructor prototype
	Critter& operator=(const Critter& c);  //overloaded assignment op
	void Greet() const;

private:
	string* m_pName;
	int m_Age;
};

#endif CRITTER_H