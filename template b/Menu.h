#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
#include <string>
#ifndef MENU_H
#define MENU_H
using namespace std;
#include"Cset.h"
class Menu
{
public:
	Menu();
	~Menu() {}
	int choose_group();//choose whitch group
	void main_Menu();
private:
	Cset<long> long_group;
	Cset<char> charA_group;
	Cset<char> charB_group;
	Cset<string> string_group;



};

#endif
