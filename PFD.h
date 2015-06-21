
#ifndef PFD_h
#define PFD_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair

using namespace std;

// ------------
// PFD_read
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of ints, i & j, 
 * @return i representing the number of tasks (<=100)
 * @return j representing the number of rules (<=100)
 */
void PFD_read_first (const string& s);

// ------------
// PFD_eval
// ------------

/**
 * @param i the number of tasks
 * @param j the number of rules
 * @return an 
 */
int  PFD_eval (int i, int j);

// -------------
// PFD_print
// -------------

/**
 * print three ints
 * @param w an ostream
 * @param i the beginning of the range, inclusive
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
