// lr_2_oop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Humans.h"
#include "additional_class.h"
using namespace std;
//------------------------------------------------------------------
void _tmain(int argc, _TCHAR* argv[]) {
	Humans *human1 = new Humans;
	Humans *human2 = new Humans;
	HumansAgeIncr HumanIncr;
	Human1 hum1;
	Human2 hum2;
	Humans *human3 = &HumanIncr;
	Humans *human4 = &hum1;
	Humans *human5 = &hum2;
	string name;
	string last_name;
	int age = 0;

	human4->print_all();
	human5->print_all();

	cout<<"Name: ";
	cin>>name;
	cout<<"Last name: ";
	cin>>last_name;
	cout<<"Age: ";
	cin>>age;

	human1->set_name(name);
	human1->set_last_name(last_name);
	human1->set_age(age);

	cout<<"\nHello, "<<human1->get_name()<<" "<<human1->get_last_name()<<"!\nYou are "<<human1->get_age()<<" years old\n\n";

	human1->print_all();

	human3->set_age(age);
	cout<<"Your age, "<<human1->get_name()<<", was increased to "<<human3->get_age()<<"\n\n";

	cout<<"Name: ";
	cin>>name;
	cout<<"Last name: ";
	cin>>last_name;
	cout<<"Age: ";
	cin>>age;

	human2->set_name(name);
	human2->set_last_name(last_name);
	human2->set_age(age);

	cout<<"\nHello, "<<human2->get_name()<<" "<<human2->get_last_name()<<"!\nYou are "<<human2->get_age()<<" years old\n\n";

	switch(compare_ages(human1->get_age(), human2->get_age())) {
		case 1:
			cout<<"Age 1 > age2\n";
			break;
		case 2:
			cout<<"Age 1 < age2\n";
			break;
		case 0:
			cout<<"Age 1 == age2\n";
			break;
	}

	if (human1->get_name() == human2->get_name()) {
		cout<<"\nNames are equal\n\n";
	}
	if (human1->get_name() != human2->get_name()) {
		cout<<"\nNames are not equal\n\n";
	}

	human1->operator ++();
	cout<<"Your age, "<<human1->get_name()<<", was increased to "<<human1->get_age()<<"\n";

	human2->operator ++();
	cout<<"Your age, "<<human2->get_name()<<", was increased to "<<human2->get_age()<<"\n";

	delete human1;
	delete human2;
	
	cout<<"\nPress any key to continue...";
	_getch();
}