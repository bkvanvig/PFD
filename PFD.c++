
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
// PFD_read
// ------------

void PFD_read (const string& s) {
    istringstream sin(s);
    int i;
    //Task Number
    int task;
    //Number of dependencies
    int num;
    sin >> task >> num;
    while (num > 0){
        cout << "num = " << num << endl;
        sin >> i;
        cout << "i = " << i << endl;
        pq.push(i);
        --num;
    }
    //cout << endl;
    print_pq();
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
void print_pq(void) {
    cout << "pq.size() = "<< pq.size() << endl;
    int p = pq.size();
    for (int i = 0; i < p; ++i)
    {

        cout << pq.top() << " ";
        pq.pop();

    }
    cout << endl;
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
    int tasks = 0;
    int rules = 0;
    getline(r,s);
    istringstream sin(s);
    sin >> tasks >> rules;
    w << tasks << " " << rules << endl;
    while (getline(r,s)){
        PFD_read(s);
    }
    return;
    
}
