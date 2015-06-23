// --------------------------------
// projects/PFD/TestPFD.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_EXPECTions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "PFD.h"

using namespace std;

// -----------
// TestPFD
// -----------

// ----
// read_first
// ----

TEST(PFDFixture, read_1) {
    string s("1 0\n");
    const pair<int, int> p = PFD_read_first(s);
    ASSERT_EQ(1, p.first);
    ASSERT_EQ(0, p.second);}
TEST(PFDFixture, read_2) {
    string s("1 0\n");
    const pair<int, int> p = PFD_read_first(s);
    ASSERT_EQ(1, p.first);
    ASSERT_EQ(0, p.second);}
TEST(PFDFixture, read_3) {
    string s("1 0\n");
    const pair<int, int> p = PFD_read_first(s);
    ASSERT_EQ(1, p.first);
    ASSERT_EQ(0, p.second);}
TEST(PFDFixture, read_4) {
    string s("1 0\n");
    const pair<int, int> p = PFD_read_first(s);
    ASSERT_EQ(1, p.first);
    ASSERT_EQ(0, p.second);}

// ----
// PFD_print
// ----

TEST(PFDFixture, print_1) {
    ostringstream w;
    int i = 27;
    PFD_print(w, i);
    ASSERT_EQ("27 \n", w.str());}
TEST(PFDFixture, print_2) {
    ostringstream w;
    int i = 27;
    PFD_print(w, i);
    ASSERT_EQ("27 \n", w.str());}
TEST(PFDFixture, print_3) {
    ostringstream w;
    int i = 27;
    PFD_print(w, i);
    ASSERT_EQ("27 \n", w.str());}
TEST(PFDFixture, print_4) {
    ostringstream w;
    int i = 27;
    PFD_print(w, i);
    ASSERT_EQ("27 \n", w.str());}

// -----
// solve
// -----

TEST(PFDFixture, solve_1) {
    istringstream r("1 1\n1 0\n");
    ostringstream w;
    PFD_solve(r, w);
    EXPECT_EQ("1", w.str());}
TEST(PFDFixture, solve_2) {
    istringstream r("5 4\n3 2 1 5\n2 2 5 3\n4 1 3\n5 1 1");
    ostringstream w;
    PFD_solve(r, w);
    EXPECT_EQ("1 5 3 2 4", w.str());}
TEST(PFDFixture, solve_3) {
    istringstream r("4 2\n1 1 4\n2 1 3");
    ostringstream w;
    PFD_solve(r, w);
    EXPECT_EQ("3 2 4 1", w.str());}



/*
% ls -al /usr/include/gtest/
...
gtest.h
...



% locate libgtest.a
/usr/lib/libgtest.a
...



% locate libpthread.a
...
/usr/lib32/libpthread.a



% locate libgtest_main.a
/usr/lib/libgtest_main.a
...



% g++-4.8 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall PFD.c++ TestPFD.c++ -o TestPFD -lgtest -lgtest_main -lpthread



% valgrind TestPFD        >  TestPFD.out 2>&1
% gcov-4.8 -b PFD.c++     >> TestPFD.out
% gcov-4.8 -b TestPFD.c++ >> TestPFD.out



% cat TestPFD.out
==14225== Memcheck, a memory error detector
==14225== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14225== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14225== Command: TestPFD
==14225==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from PFD
[ RUN      ] PFD.read
[       OK ] PFD.read (31 ms)
[ RUN      ] PFD.eval_1
[       OK ] PFD.eval_1 (5 ms)
[ RUN      ] PFD.eval_2
[       OK ] PFD.eval_2 (3 ms)
[ RUN      ] PFD.eval_3
[       OK ] PFD.eval_3 (3 ms)
[ RUN      ] PFD.eval_4
[       OK ] PFD.eval_4 (3 ms)
[ RUN      ] PFD.print
[       OK ] PFD.print (17 ms)
[ RUN      ] PFD.solve
[       OK ] PFD.solve (10 ms)
[----------] 7 tests from PFD (88 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (132 ms total)
[  PASSED  ] 7 tests.
==14225==
==14225== HEAP SUMMARY:
==14225==     in use at exit: 0 bytes in 0 blocks
==14225==   total heap usage: 495 allocs, 495 frees, 70,302 bytes allocated
==14225==
==14225== All heap blocks were freed -- no leaks are possible
==14225==
==14225== For counts of detected and suppressed errors, rerun with: -v
==14225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
File 'PFD.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'PFD.c++.gcov'
...
File 'TestPFD.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestPFD.c++.gcov'
...
*/