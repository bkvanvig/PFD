
#ifndef PFD_h
#define PFD_h

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

using namespace std;

// ------------
// PFD_read
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of ints, t & r 
 * @return t, the number of tasks (<=100)
 * @return r, the number of rules (<=100)
 */
pair<int, int> PFD_read_first (const string& s);

// ------------
// populate_adj
// ------------

/* 
 * read line and add 1's in adj where dependencies exist
 * @param ostream& w, for outputting test matrix
 * @param const string& s, dependency input line
 * @param int t, total number of tasks for this case, 1 <= t <= 100
 */
void populate_adj (ostream& w, const string& s, int t);
// ------------
// PFD_eval
// ------------

/**
 * @param w the output stream
 * @param t the number of tasks
 * 
 */
void PFD_eval (ostream& w, int t);

// ---------
// pop_pq
// ---------

/* 
 * pops 1 element from the priority queue
 * @param ostream& w, for testing output
 * @param int t, total tasks in test
 */
void pop_pq (ostream& w, int t);

// ---------
// scan_succ
// ---------
/*
 * scan rows of successors, add to pq if empty row, then delete regardless
 * @param int t, total number of tasks
 */

void scan_succ(int t);

// -------
// update_succ
// -------
/*
 * add successors of to-be-popped elements before they are written to output
 * successors are found in the corresponding columns of adj matrix
 * @param int t, total tasks in test
 * @param int r, row # to be popped
 */
void update_succ (int t, int r);

// ---------
// full_scan
// ---------
/*
 * scan all rows of adj for blank rows
 * if blank row exists, add to pq and continue scanning
 * @param int t, total number of tasks in case
*/
void full_scan (int t);

// --------
// row_scan
// --------
/*
 * scan row  for dependencies
 * since adj is 0-indexed, search row i-1
 * @param r row number to be searched
 * @param t total number of rows in test case
 * @return 0 if no dependcies
 * @return 1 if >=1 dependencies
 */

int row_scan (int r, int t);

// ------------
// PFD_eval
// ------------
/**
 * prints priority_queue for testing
 * @param ostream w
 */
void print_pq(ostream& w);

// -----------
// print_adj
// -----------

/*
 * prints adjacency matrix for validating test cases
 * @param ostream& w, for writing output matrix
 * @param int t, total number of tasks, for speedier traversal 
 */
void print_adj (ostream& w, int t);

// -------------
// clear_adj
// -------------
void clear_adj (int t);



// -------------
// PFD_print
// -------------

/**
 * print an ints
 * @param w an ostream
 * @param i the int
 */
void PFD_print (ostream& w, int i);

// -------------
// PFD_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void PFD_solve (istream& r, ostream& w);


#endif // PFD_h

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



using namespace std;
//This array is 0 indexed while the input is 1-indexed. to access (2, 1) call adj[1][0]
int adj[100][100] = {0};
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
    //int popped = 0;
    full_scan(t);
    //Change parameter
    //while (popped < t){
        //cout << param << " param" << endl;
        //print_adj(cout, t);
        //assert(succ.empty());
    pop_pq(w, t);
    //}

    //if (popped != t)
            //cout << "popped only" << popped << endl;
        //cout << "final matrix" << endl;
        //print_adj(cout, t);
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
        if (v == 0){
            //cout << "scan_succ pushed " << current << " to pq" << endl;
            pq.push(current);
            used[current-1] = 1;
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
            //cout << "update_succ pushed " << i+1 << " to succ" << endl;
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
    //print_adj(cout, t);
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
            used[i+1] = 1;
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

// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------

#include <iostream> // cin, cout


// ----
// main
// ----

int main () {
    using namespace std;
    PFD_solve(cin, cout);
    return 0;}

/*
% g++-4.8 -pedantic -std=c++11 -Wall PFD.c++ RunPFD.c++ -o RunPFD



% cat RunPFD.in
1 10
100 200
201 210
900 1000

this is a test

% RunPFD < RunPFD.in > RunPFD.out



% cat RunPFD.out




% doxygen -g
// That creates the file Doxyfile.
// Make the following edits to Doxyfile.
// EXTRACT_ALL            = YES
// EXTRACT_PRIVATE        = YES
// EXTRACT_STATIC         = YES



% doxygen Doxyfile
// That creates the directory html/.
*/
