/*
Student Name: Muhammet Çavuş
Student Number: 2018400306
Project Number: 1
Compile Status: [SUCCESS/FAIL] success
Running Status: [SUCCESS/FAIL] success
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/

#include "Restaurant.h"

using namespace std;

void Restaurant::execute(const vector<string>& operations) {
    for (const string& op : operations){
        cout << "Operation: " << op << "\t";
        
		/* YOU NEED TO IMPLEMENT THIS PART */
		if(op=="N") {
		    for(int i=0; i<tables.size(); i++) {
		        if(!tables[i].isOccupied()) {
                    tables[i].occupy();
                    break;
		        }
		    }
		} else if(op=="S") {
            for(int i=tables.size()-1; i>=0; i--) {
                if(!tables[i].isOccupied()) {
                    tables[i].occupy();
                    break;
                }
            }
        } else {
            tables[stoi(op) -1].empty();
		}
        cout << "State: " << *this << endl;
    }
}

Restaurant::Restaurant(unsigned int N)
	: tables{N}
{
    cout << "-Starting- \tState: " << *this << endl;
}

ostream &operator<<(ostream &out, Restaurant &restaurant) {
    for (Table table : restaurant.tables) {
        out << table.isOccupied();
    }
	return out;
}

