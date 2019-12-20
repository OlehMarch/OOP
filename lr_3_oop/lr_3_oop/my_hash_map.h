#pragma once

#include "targetver.h"

#include "iostream"
#include "string"

using namespace std;

template<class Ò>
class hash_map {
private:
	struct Map {
		int id;
		string name;
		Map* next;
		Map* prev;
		bool isExists;
	};
	Map* map;
	Map* begin;
	
public:
	hash_map(void);
	~hash_map(void);
	void add(void);
	void del(int);
	void find(int);
	void view(void);
	bool isExist(int);

	friend void human_my(void);
};