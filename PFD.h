
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
 * pop all elements in the priority queue
 * @param ostream& w, for testing output
 * @param int t, total tasks in test
 * @return number of remaining tasks to be evaluated
 */
int pop_pq (ostream& w, int t);

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
