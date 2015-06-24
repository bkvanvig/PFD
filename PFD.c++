
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
int adj[100][100]= {0};
//vector<vector<int> > adj(100, vector <int> (0));
priority_queue<int, vector<int>, greater<int> > pq;
priority_queue<int, vector<int>, greater<int> > succ;
int used [100] = {0};

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
    //cout << task << " " << num << endl;
    for (int i = 0; i < num; ++i)
    {
        /* code */
        sin >> v;
        adj[task-1][v-1] = 1;
        //cout << task << " = " << v << endl;
    }
    //print_adj(cout, t);
}

// ------------
// PFD_eval
// ------------

void PFD_eval (ostream& w, int t) {
    // <your code>
    
    full_scan(t);
    //Change parameter
   // while (param > 0){
        //cout << param << " param" << endl;
        //print_adj(cout, t);
        
        assert(succ.empty());
        int popped = pop_pq(w, t);
       
        if (popped != t)
            cout << "popped only" << popped << endl;
        

    //}
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
        //cout << "row_scan = " << v << " with row " << current << endl;
        if (v == 0 && used[current-1] == 0){
            //cout << "scan_succ pushed " << current << " to pq" << endl;
            pq.push(current);
        }  
        succ.pop();
    }
}

// ---------
// pop_pq
// ---------
int pop_pq (ostream& w, int t){
    int popped = 0;
    while (!pq.empty()){
        w << pq.top() << " ";
        update_succ(t, pq.top());
        used[pq.top()-1] = 1;
        pq.pop();
        scan_succ(t);
        ++popped;
    }
    return popped;
}
// -------
// update_succ
// -------
void update_succ (int t, int r){
    for (int i = 0; i < t; ++i)
    {
        if (adj[i][r-1]==1){
            //cout << "pushed " << i+1 << " to succ" << endl;
            succ.push(i+1);
            adj[i][r-1] = 0;
        }
    }
    //scan_succ(t);
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
// // --------
// // col_scan
// // --------
// int col_scan (int c, int t){
//     for (int i = 0; i < t; ++i)
//     {
//         if (adj[i][c-1]==1)
//             return 1;
//     }
//     return 0;
// }
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
            //cout << "full_scan pushed " << i+1 << endl; 
            pq.push(i+1);
        }
        
    }
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
    //print_adj(w, tasks);
    for (int i = 0; i < rules; ++i)
    {
        getline(r,s);
        populate_adj(w, s, tasks);
    }
    PFD_eval(w, tasks);
    //w << 1;
    //print_adj(w, tasks);
}
