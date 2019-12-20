#include "stdafx.h"
#include "Humans.h"
using namespace std;

void Humans::set_age(int human_age) {
	age = human_age;
}

int Humans::get_age() {
	return age;
}

void Humans::set_name(string human_name) {
	name = human_name;
}

string Humans::get_name() {
	return name;
}

void Humans::set_last_name(string human_last_name) {
	last_name = human_last_name;
}

string Humans::get_last_name() {
	return last_name;
}

void Humans::print_all() {
	cout<<"Name: "<<this->get_name()<<endl;
	cout<<"Last name: "<<this->get_last_name()<<endl;
	cout<<"Age: "<<this->get_age()<<endl<<endl;
}

Humans& Humans::operator ++ () {
	++(this->age);
	return reinterpret_cast<Humans&>(this->age);
}



Humans::operator int() { 
	return age; 
}

Humans::operator char*() {
	char* value = new char[name.length() + 1]; 
	strcpy(value, name.c_str());
	return value;
}

Humans::operator string() { 
	return name;
}

Humans::Humans() {
	age = 0;
	name = "Name";
	last_name = "Last name";
}

Humans::Humans(string human_name, string human_last_name, int human_age) {
	age = human_age;
	name = human_name;
	last_name = human_last_name;
}

Humans::~Humans() {}

bool operator == (string first_name, string second_name) {
	if (first_name.length() == second_name.length()) {
		for (int i = 0; i < first_name.length(); ++i) {
			if (first_name[i] != second_name[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

bool operator != (string first_name, string second_name) {
	if (first_name.length() == second_name.length()) {
		for (int i = 0; i < first_name.length(); ++i) {
			if (first_name[i] != second_name[i]) {
				return true;
			}
		}
		return false;
	}
	else {
		return true;
	}
}

int compare_ages(int age1, int age2) {
	if (age1 > age2) {
		return 1;
	}
	else if (age1 < age2) {
		return 2;
	}
	else {
		return 0;
	}
}