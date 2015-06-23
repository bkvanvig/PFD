
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
// PFD_eval
// ------------

/**
 * @param i the number of tasks
 * @param j the number of rules
 * @return an 
 */
int  PFD_eval (int i, int j);

// ------------
// PFD_eval
// ------------
/**
 * prints priority_queue for testing
 * @param ostream w
 */
void print_pq(ostream& w);
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
