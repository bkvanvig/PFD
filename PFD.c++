
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

int adj[100][100]= {0};
//vector<vector<int> > adj(100, vector <int> (0));
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
// populate_adj
// ------------

void populate_adj (ostream& w, const string& s, int t) {
    istringstream sin(s);
    int i;
    int task;
    int num;
    sin >> task >> num;
    //cout << task << " " << num << endl;
    while (num > 0){
        sin >> i;
        adj[task-1][i-1] = 1;
        //cout << task << " " << i << endl;
        --num;
    }
    //print_adj(w, t);
}

// ------------
// PFD_eval
// ------------

void PFD_eval (ostream& w, int t) {
    // <your code>

    return;
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
// print_pq
// -------------
void print_adj (ostream& w, int t) {
    for (int i = 0; i < t; ++i){
        for (int j = 0; j < t; ++j)
        {
            /* code */
            w << adj[i][j] << " ";
        }
        w << endl;
    }

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
    int tasks = 0;
    int rules = 0;
    getline(r,s);
    const pair <int, int> p = PFD_read_first(s);
    tasks = p.first;
    rules = p.second;
    //print_adj(w, tasks);
    for (int i = 0; i < rules; ++i)
    {
        getline(r,s);
        populate_adj(w, s, tasks);
    }
    PFD_eval(w, tasks);
    w << 1;
    //print_adj(w, tasks);
}
