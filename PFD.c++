
// --------
// includes
// --------

#include <cassert>    // assert
#include <functional> // greater
#include <iostream>   // endl, istream, ostream
#include <queue>      // priority_queue
#include <sstream>    // istringstream
#include <string>     // getline, string
#include <utility>    // make_pair, pair
#include <vector>     // vector

#include "PFD.h"

using namespace std;
//This array is 0 indexed while the input is 1-indexed. to access (2, 1) call adj[1][0]
int adj[100][100];
//priority queue of candidates to output
priority_queue<int, vector<int>, greater<int> > pq;
//priority queue of successors
priority_queue<int, vector<int>, greater<int> > succ;

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
    int v;
    int task;
    int num;
    sin >> task >> num;
    for (int i = 0; i < num; ++i)
    {
        /* code */
        sin >> v;
        adj[task-1][v-1] = 1;
    }
}

// ------------
// PFD_eval
// ------------

void PFD_eval (ostream& w, int t) {
    // <your code>
    full_scan(t);
    pop_pq(w, t);
    w << endl;
}
// ---------
// scan_succ
// ---------
void scan_succ(int t){
    int current = 0;
    while (!succ.empty()){
        current = succ.top();
        int v = row_scan(current, t);
        if (v == 0){
            pq.push(current);
        }  
        succ.pop();
    }
}

// ---------
// pop_pq
// ---------
void pop_pq (ostream& w, int t){
    while (!pq.empty()){

        w << pq.top() << " ";
        update_succ(t, pq.top());
        pq.pop();
        scan_succ(t);
    }
}
// -------
// update_succ
// -------
void update_succ (int t, int r){
    for (int i = 0; i < t; ++i)
    {
        if (adj[i][r-1]==1){
            succ.push(i+1);
            adj[i][r-1] = 0;
        }
    }
}

// --------
// row_scan
// --------
int row_scan (int r, int t){
    for (int i = 0; i < t; ++i)
    {
        if (adj[r-1][i]==1)
            return 1;
    }
    return 0;
}

// ----------
// full_scan
// ----------
void full_scan (int t){
    int write = 0;
    for (int i = 0; i < t; ++i)
    {
        for (int j = 0; j < t; ++j)
        {
            if (adj[i][j]==1){
                write = 1;
            }
        }
        if (write == 0){
            pq.push(i+1);
        }
        write = 0;
    }
    return;
}


// -------------
// print_adj
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
// clear_adj
// -------------
void clear_adj (int t) {
    for (int i = 0; i < t; ++i){
        for (int j = 0; j < t; ++j)
        {
            /* code */
            adj[i][j] = 0;
        }
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
    for (int i = 0; i < rules; ++i)
    {
        getline(r,s);
        populate_adj(w, s, tasks);
    }
    PFD_eval(w, tasks);
}
