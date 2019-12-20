#include "stdafx.h"
#include "additional_class.h"
using namespace std;
//------------------------------------------------------------------
int HumansAgeIncr::get_age() {
	int temp = Humans::get_age();
	Humans::set_age(++temp);
	return temp;
}
//------------------------------------------------------------------
int Human1::get_age() {
	return 17;
}

string Human1::get_name() {
	return "Name1";
}

string Human1::get_last_name() {
	return "Last name1";
}
//------------------------------------------------------------------
int Human2::get_age() {
	return 18;
}

string Human2::get_name() {
	return "Name2";
}

string Human2::get_last_name() {
	return "Last name2";
}