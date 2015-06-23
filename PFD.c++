
// --------
// includes
// --------

#include <cassert>  // assert
#include <functional> //greater
#include <iostream> // endl, istream, ostream
#include <queue>   //priority_queue
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <vector>   //vector

#include "PFD.h"

using namespace std;


vector<vector<int> > adj(100, vector <int> (0));
priority_queue<int, vector<int>, greater<int> > pq;

// ------------
// PFD_read_first
// ------------

pair<int, int> PFD_read_first (const string& s){
    istringstream sin(s);
    int t;
    int r;
    sin >> t >> r;
    return make_pair(t, r);
}

// ------------
// PFD_read
// ------------

void PFD_read (const string& s) {
    istringstream sin(s);
    int i;
    int task;
    int num;
    sin >> task >> num;
    while (num > 0){
        sin >> i;
        pq.push(i);
        --num;
    }
    //cout << endl;
    //print_pq();
    return;}

// ------------
// PFD_eval
// ------------

int PFD_eval (int i, int j) {
    // <your code>
    return 1;
    }

// -------------
// print_pq
// -------------
void print_pq(ostream& w) {
    int p = pq.size();
    for (int i = 0; i < p; ++i)
    {
        w << pq.top() << " ";
        pq.pop();
    }
    w << endl;
}

// -------------
// PFD_print
// -------------

void PFD_print (ostream& w, int i) {
    w << i << " " << endl;}

// -------------
// PFD_solve
// -------------

void PFD_solve (istream& r, ostream& w) {
    string s;
    w << 1;
    // int firstln = 0;
    // int tasks = 0;
    // int rules = 0;
    // getline(r,s);
    // const pair <int, int> p = PFD_read_first(s);
    // tasks = p.first;
    // rules = p.second;
    // for (int i = 0; i < rules; ++i)
    // {
    //     getline(r,s);
    // }
    return;
    
}
