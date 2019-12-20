#pragma once

#include "targetver.h"

#include "stdafx.h"
#include "string"
#include "iostream"
#include <conio.h>
#include "Humans.h"
using namespace std;
//------------------------------------------------------------------
class HumansAgeIncr: public Humans {
public:
	int get_age();
};
//------------------------------------------------------------------
class Human1: public Humans {
public:
	int get_age();

	string get_name();

	string get_last_name();

};
//------------------------------------------------------------------
class Human2: public Humans {
public:
	int get_age();

	string get_name();

	string get_last_name();

};