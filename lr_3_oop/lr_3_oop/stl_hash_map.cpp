#include "stdafx.h"
#include "stl_hash_map.h"

using namespace std;

void human_stl() {
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