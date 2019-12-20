#pragma once

#include "targetver.h"

#include "stdafx.h"
#include "string"
#include "iostream"
#include <conio.h>
using namespace std;

class Humans {
private: 

	int age;
	string name;
	string last_name;

public:

	friend int compare_ages(int age1, int age2);

	void set_age(int human_age);

	virtual int get_age();

	void set_name(string human_name);

	virtual string get_name();

	void set_last_name(string human_last_name);

	virtual string get_last_name();

	void print_all();

	friend bool operator == (string &first_name, string &second_name);
	friend bool operator != (string &first_name, string &second_name);
	
	Humans& operator ++ ();

	Humans(int value) : age(value) {};
	Humans(char* value) : name(value) {};
	Humans(string value) : name(value) {};

	operator int();

	operator char*();

	operator string();

	Humans();

	Humans(string human_name, string human_last_name, int human_age);

	Humans(Humans &human);

	~Humans();

};
bool operator == (string first_name, string second_name);
bool operator != (string first_name, string second_name);
int compare_ages(int age1, int age2);