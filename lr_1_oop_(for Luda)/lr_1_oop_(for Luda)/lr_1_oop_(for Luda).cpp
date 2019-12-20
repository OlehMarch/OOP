// lr_1_oop.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "string"
#include "iostream"
#include <conio.h>
using namespace std;
//------------------------------------------------------------------
class Abonent;
//------------------------------------------------------------------
class Tel {
private: 

	int num_tel;
	string tel_type;

public:

	friend Abonent;

	void set_num(int num) {
		num_tel = num;
	}

	int get_num() {
		return num_tel;
	}

	void set_tel_type(string tel) {
		tel_type = tel;
	}

	string get_tel_type() {
		return tel_type;
	}

	void print_all() {
		cout<<"Telephone: "<<this->get_num()<<endl;
		cout<<"Type of telephone: "<<this->get_tel_type()<<endl;
	}

	friend bool operator == (string &first_name, string &second_name);
	friend bool operator != (string &first_name, string &second_name);

	Tel& operator+(int num) {
		Tel *tel = new Tel;
		char* code = "056";
		cout<<"Phone number with operator code: "<<code<<num;
		return *tel;
	}

	operator int() { 
		if ((tel_type == "home") || (tel_type == "Home")|| (tel_type == "hom") || (tel_type == "Hom")) {
			return 110157155;
		}
		if ((tel_type == "mobile") || (tel_type == "Mobile") || (tel_type == "mob") || (tel_type == "Mob")) {
			return 115157142;
		}
		return 0;
	}

	operator string() {
		string temp;
		char* str;
		itoa(num_tel, str, 10);
		for (int i = 0; i < sizeof(num_tel) - 1; i++) {
			temp[0] = str[0];
		}
		return temp;
	}

	Tel() {
		num_tel = 123456;
		tel_type = "Home phone";
	}

	Tel(int num, string tel_t) {
		num_tel = num;
		tel_type = tel_t;
	}

	Tel(Tel &tel);

	~Tel() {}

};
//------------------------------------------------------------------
class Abonent {
private: 

	string abonent;

public:

	void set_abonent(string abon) {
		abonent = abon;
	}

	string get_abonent() {
		return abonent;
	}

	void print_all(Tel &tel) {
		cout<<"Telephone: "<<tel.get_num()<<endl;
		cout<<"Type of telephone: "<<tel.get_tel_type()<<endl;
		cout<<"Name: "<<this->get_abonent()<<endl;
	}

	Abonent(char* value) : abonent(value) {};

	operator char*() {
		char* value = new char[abonent.length() + 1]; 
		strcpy(value, abonent.c_str());
		return value;
	}

	Abonent() {
		abonent = "Name";
	}

	Abonent(Tel &tel, int num, string tel_t, string abon) {
		tel.num_tel = num;
		tel.tel_type = tel_t;
		this->abonent = abon;
	}

	Abonent(Abonent &abon);

	~Abonent() {}

};
//------------------------------------------------------------------
bool operator == (string first, int value) {
	if (value == 1) {
		char* second = "hom";
		char* value = new char[first.length() + 1]; 
		strcpy(value, first.c_str());
		if (strstr(value, second)) return true;
		return false;
	}
	if (value == 0) {
		char* second = "mob";
		char* value = new char[first.length() + 1]; 
		strcpy(value, first.c_str());
		if (strstr(value, second)) return true;
		return false;
	}
}
//------------------------------------------------------------------
bool operator != (string first, int value) {
	if (value != 1) {
		char* second = "mob";
		char* value = new char[first.length() + 1]; 
		strcpy(value, first.c_str());
		if (strstr(value, second)) return true;
		return false;
	}
	if (value != 0) {
		char* second = "hom";
		char* value = new char[first.length() + 1]; 
		strcpy(value, first.c_str());
		if (strstr(value, second)) return true;
		return false;
	}
}
//------------------------------------------------------------------
void _tmain(int argc, _TCHAR* argv[]) {

	Tel *tel = new Tel;
	Abonent *abonent = new Abonent;
	int num = 0;
	string type, name;

	Abonent(*tel, 123456, "Home", "Name");
	abonent->print_all(*tel);

	cout<<"\nName: ";
	cin>>name;
	cout<<"Telephone: ";
	cin>>num;
	cout<<"Type of phone: ";
	cin>>type;

	abonent->set_abonent(name);
	tel->set_num(num);
	tel->set_tel_type(type);
	
	cout<<endl;
	abonent->print_all(*tel);

	if ((tel->get_tel_type() == 1)) {
		cout<<"\nThis is number of home phone\n\n";
	}
	if ((tel->get_tel_type() != 0)) {
		cout<<"\nThis is number of mobile phone\n\n";
	}

	tel->operator +(tel->get_num());

	delete abonent;
	delete tel;
	
	cout<<"\n\nPress any key to continue...";
	_getch();
}