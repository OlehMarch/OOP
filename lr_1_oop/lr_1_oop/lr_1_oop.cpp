// lr_1_oop.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Humans.h"
using namespace std;
//------------------------------------------------------------------
void _tmain(int argc, _TCHAR* argv[]) {

	Humans *human1 = new Humans;
	Humans *human2 = new Humans;
	string name;
	string last_name;
	int age;

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