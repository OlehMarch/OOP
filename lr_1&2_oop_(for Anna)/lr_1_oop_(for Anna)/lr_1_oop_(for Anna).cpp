// lr_1_oop.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "string"
#include "iostream"
#include <conio.h>
using namespace std;
const int daily_calories = 2350;
//------------------------------------------------------------------
class Food {
protected: 

	string ingredient;
	int kkal;
	int shelf_life;
	string state;

public:

	void set_ingredient(string ingr) {
		ingredient = ingr;
	}

	string get_ingredient() {
		return ingredient;
	}

	virtual void set_state(string st) {
		state = "";
	}

	virtual string get_state() {
		return ingredient;
	}

	void set_kkal(int kk) {
		kkal = kk;
	}

	int get_kkal() {
		return kkal;
	}

	void set_shelf_life(int sl) {
		shelf_life = sl;
	}

	int get_shelf_life() {
		return shelf_life;
	}

	void print_all() {
		cout<<"Ingredient: "<<this->get_ingredient()<<endl;
		cout<<"Kkal: "<<this->get_kkal()<<endl;
		cout<<"Shelf life: "<<this->get_shelf_life()<<endl<<endl;
	}

	friend int kkal_per_day(int kkal);
	friend int kkal_per_day(int kkal1, int kkal2);
	friend bool operator > (Food food1, Food food2);
	friend Food& operator += (Food& food1, Food& food2);

	Food& operator -- () {
		--(this->shelf_life);
		return reinterpret_cast<Food&>(this->shelf_life);
	}

	Food(int value) : kkal(value) {};
	Food(float value) : shelf_life(value) {};
	Food(string value) : ingredient(value) {};

	operator int() { 
		return kkal; 
	}

	operator float() { 
		return shelf_life; 
	}

	operator string() { 
		return ingredient;
	}

	Food() {
		ingredient = "Bread";
		kkal = 30;
		shelf_life = 7;
	}

	Food(string ingr, int kk, int sl) {
		ingredient = ingr;
		kkal = kk;
		shelf_life = sl;
	}

	Food(Food &food);

	~Food() {}

};
//------------------------------------------------------------------
int kkal_per_day(int kkal) {
	return daily_calories - kkal;
}
//------------------------------------------------------------------
int kkal_per_day(int kkal1, int kkal2) {
	return daily_calories - kkal1 - kkal2;
}
//------------------------------------------------------------------
bool operator > (Food food1, Food food2) {
	if (food1.get_kkal() > food2.get_kkal()) {
		return true;
	}
	else {
		return false;
	}
}
//------------------------------------------------------------------
Food& operator += (Food& food1, Food& food2) {
	food1.set_ingredient(food1.get_ingredient() + " with " + food2.get_ingredient());
	return reinterpret_cast<Food&>(food1.get_ingredient());
}
//------------------------------------------------------------------
class constrIsChanged: public Food {
public:
	constrIsChanged() {
		ingredient = "Boiled Egg";
		kkal = 70;
		shelf_life = 10;
	}
};
//------------------------------------------------------------------
class boiledFood: public Food {
public:

	void set_state() {
		state = "Boiled ";
	}

	string get_state() {
		return ingredient = state + ingredient;
	}
	
};
//------------------------------------------------------------------
class slicedFood: public Food {
public:

	void set_state() {
		state = "Sliced ";
	}

	string get_state() {
		return ingredient = state + ingredient;
	}
	
};
//------------------------------------------------------------------
void _tmain(int argc, _TCHAR* argv[]) {

	Food *food1 = new Food;
	Food *food2 = new Food;
	constrIsChanged *food3 = new constrIsChanged;
	boiledFood *food4 = new boiledFood;
	slicedFood *food5 = new slicedFood;
	string ingredient;
	int kkal;
	int shelf_life;

	food3->print_all();
	food4->set_state();
	cout<<food4->get_state()<<endl<<endl;
	food5->set_state();
	cout<<food5->get_state()<<endl<<endl;

	cout<<"Ingredient: ";
	cin>>ingredient;
	cout<<"kkal: ";
	cin>>kkal;
	cout<<"Shelf life: ";
	cin>>shelf_life;
	system("cls");

	food1->set_ingredient(ingredient);
	food1->set_kkal(kkal);
	food1->set_shelf_life(shelf_life);

	food1->print_all();

	*food2 = Food();

	food2->print_all();

	cout<<"Daily calories: "<<daily_calories<<"\nDaily calories left for today: "<<kkal_per_day(food1->get_kkal(), food2->get_kkal());

	if (food1->get_kkal() > food2->get_kkal()) {
		cout<<"\n\nFirst ingredient has more calories than other\n";
	}
	else {
		cout<<"\n\nSecond ingredient has more (or equal amount of) calories\n";
	}

	food1->operator --();
	cout<<"\nShelf life of "<<food1->get_ingredient()<<" was decreased: "<<food1->get_shelf_life()<<endl;
	food2->operator --();
	cout<<"Shelf life of "<<food2->get_ingredient()<<" was decreased: "<<food2->get_shelf_life()<<endl;

	delete food1;
	delete food2;
	
	cout<<"\nPress any key to continue...";
	_getch();
}