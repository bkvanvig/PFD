
// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "PFD.h"

using namespace std;

// ------------
// PFD_read
// ------------

void PFD_read_first (const string& s, int num) {
    
    return;}

// ------------
// PFD_eval
// ------------

int PFD_eval (int i, int j) {
    // <your code>
    return 1;
    }


// -------------
// PFD_print
// -------------

void PFD_print (ostream& w, int i) {
    w << i << " ";}

// -------------
// PFD_solve
// -------------

void PFD_solve (istream& r, ostream& w) {
    string s;
    istringstream sin(s);
    int i;
    getline(r,s);
    int num = 5;
    while (num >0){
        sin >> i;
        PFD_print(w, i);
        --num;
    }
    cout << endl;
    
}
