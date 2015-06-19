
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

pair<int, int> PFD_read_first (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// PFD_eval
// ------------

int PFD_eval (int i, int j) {
    // <your code>
    }


// -------------
// PFD_print
// -------------

void PFD_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// PFD_solve
// -------------

void PFD_solve (istream& r, ostream& w) {
    string s;
    if (getline(r,s)) {
        const pair<int, int> p = PFD_read_first(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = PFD_eval(i, j);
    }
    while (getline(r, s)) {
        
        PFD_print(w, i, j, v);}}
