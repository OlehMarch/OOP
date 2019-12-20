#include "stdafx.h"
#include "my_hash_map.h"

using namespace std;
//--------------------------------------------------------------------
template<class Ò>
hash_map::hash_map() {
	map = new Map;
	map->isExists = false;
	begin = map;
}
//--------------------------------------------------------------------
template<class Ò>
hash_map::~hash_map() {
	delete map;
	delete begin;
}
//--------------------------------------------------------------------
template<class Ò>
bool hash_map::isExist(int key) {
	while (map) {
		if (key == map->id) {
			return false;
		}
		map = map->next;
	}
	return true;
}
//--------------------------------------------------------------------
template<class Ò>
void hash_map::add() {
	if (map->isExists == false) {
		cout << "Insert ID and Name:\n";
		cin >> map->id >> map->name;
		map->next = NULL;
		map->prev = NULL;
		map->isExists = true;
	}
	else {
		Map* new_map = new Map;
		for (;;) {
			cout << "Insert ID and Name:\n";
			cin >> new_map->id >> new_map->name;
			if (!isExist(new_map->id)) {
				cout << "\nID must be unique!\n\n";
				continue;
			}
			break;
		}
		new_map->isExists = true;
		new_map->next = NULL;
		map = begin;
		while (map->next) {
			map = map->next;
		}
		new_map->prev = map;
		map->next = new_map;
	}
}
//--------------------------------------------------------------------
template<class Ò>
void hash_map::view() {
	if (begin->isExists == false) {
		cout << "Hash map not found\n";
		return;
	}
	map = begin;
	cout << "\nView of hash map:\n";
	while (map) {
		cout << map->id << "\t " << map->name << endl;
		map = map->next;
	}
	return;
}
//--------------------------------------------------------------------
template<class Ò>
void hash_map::find(int key) {
	if (begin->isExists == false) {
		cout << "Hash map not found\n";
		return;
	}
	map = begin;
	bool boolean = false;
	while (map) {
		if (map->id == key) {
			cout << "Candidate's name with ID " << map->id << " is " << map->name << endl;
			boolean = true;
			break;
		}
		map = map->next;
	}
	if (boolean == false) {
		cout << "Not found\n";
	}
	return;
}
//--------------------------------------------------------------------
template<class Ò>
void hash_map::del(int key) {
	if (begin->isExists == false) {
		cout << "Hash map not found\n";
		return;
	}
	map = begin;
	bool boolean = false;
	while (map) {
		if (map->next->id == key) {
			map->next->id = NULL;
			map->next->name = "";
			map->next = map->next->next;
			map = map->next;
			map->prev = map->prev->prev;
			cout << "Deleted!\n";
			boolean = true;
			break;
		}
		map = map->next;
	}
	if (boolean == false) {
		cout << "Not found\n";
	}
	return;
}
//--------------------------------------------------------------------
void human_my() {
	unsigned int id;
	string cmd, name;
	hash_map<T> h_map;
	
	while( cin >> cmd ) {
		if ( cmd == "add" ) {
			h_map.add();
			cout << "Added" << endl;
		}
		else if ( cmd == "find" ) {
			cin >> id;
			h_map.find(id);
		}
		else if ( cmd == "del" ) {
			cin >> id;
			h_map.del(id);
		}
		else if ( cmd == "view" ) {
			h_map.view();
		}
		else if ( cmd == "quit" ) {
			return;
		}
		else {
			cerr << "Bad command '" << cmd << "'" << endl;
		}
	}
}