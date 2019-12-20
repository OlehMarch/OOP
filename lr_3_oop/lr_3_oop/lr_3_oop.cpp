// lr_3_oop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "map"
#include <conio.h>
 
using namespace std;

int pos = 0;

template <class DataType>
DataType example_function (DataType a)
{
  int x = 5;
  DataType b;
  b = a + x;
  return b;
}

 template <class T>
 class Massiv
 {
   T Array[10];
   int count;
   public:
   void Add(T &);
   void Show();
 };

 template<class T> void Massiv<T>::Add(T &x)
 {
   Array[pos] = x;
   pos++;
   count = pos;
 }
 
 template <class T> void Massiv<T>::Show()
 {
  for (int i = 0;i<count;i++) cout<<Array[i]<<endl;
  cout<<endl;
  pos = 0;
 }

class EvenOddFunctor {
    int even_;
    int odd_;
public:
    EvenOddFunctor() : even_(0), odd_(0) {}
    void operator()(int x) {
        if (x%2 == 0) even_ += x;
        else odd_ += x;
    }
    int even_sum() { return even_; }
    int odd_sum() { return odd_; }
    bool is_cmp() {return even_ > odd_; }
};


void _tmain(int argc, _TCHAR* argv[]) {

	string cmd, id, name;
	map< string, string > human;

	while( cin >> cmd ) {
		if ( cmd == "add" ) {
			cin >> id >> name;
			human[ id ] = name;
			cout << "Added" << endl;
		}
		else if ( cmd == "find" ) {
			cin >> id;
			map< string, string >::const_iterator ifind = human.find( id );
			if ( ifind != human.end() ) {
				cout << "Candidate's name with ID " << ifind->first << " is " << ifind->second << endl;
			}
			else {
				cout << "ID " << id << " not found" << endl;
			}
		}
		else if ( cmd == "del" ) {
			cin >> id;
			human.erase( id );
			cout << "Deleted" << endl;
		}
		else if ( cmd == "view" ) {
			map< string, string >::const_iterator i;
			for( i = human.begin(); i != human.end() ; ++i ) {
				cout << i->first << "\t " << i->second << endl;
			}
		}
		else if ( cmd == "quit" ) {
			return;
		}
		else {
			cerr << "Bad command '" << cmd << "'" << endl;
		}
	}
	
}