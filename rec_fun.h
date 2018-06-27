// Provided by:   ____________(John Chen)__________
// Email Address: ____________(johnchen062094@gmail.com)________
// FILE: rec_fun.h
// Attempt at creating a header file based on previous header file examples.
//
//  Triangle Pattern
//  void triangle(ostream& outs, unsigned int m, unsigned int n)
//  Precondition: The unsigned int of m, must be less than or equal to n (m <= n).
//  Postcondition: The function has printed a pattern of 2*(n-m+1) lines
//  to the output stream outs. The first line contains m asterisks, the next
//  line contains m+1 asterisks, and so on up to a line with n asterisks. Then
//  the pattern is repeated backwards, going n back down to m.
//
//  Section Numbers
//  void numbers(ostream& outs, const string& prefix, unsigned int levels)
//  Precondition: The unsigned int levels must be greater than or equal to 0.
//  Postcondition: The levels argument determines how many levels the section numbers have
//  and should print each level from 1 through 9 always.
//
//  A Teddy Bear Picnic
//  Postcondition: The goal of the game is to end up with EXACTLY 42 bears, in which when the bool
//  function is called, it should print "True", it is possible to get 42, or "False" which means
//  the int n, is not able to get to 42, based on the given rules.
//
//  A Fractal Pattern
//  Poscondition: The sequence should print a pattern of asterisks and blanks based on the algorithm that
//  you found.

#ifndef CSC212_PROJ_THREE_REC_FUN_H
#define CSC212_PROJ_THREE_REC_FUN_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

        //Triangle Pattern
        void triangle(ostream &outs, unsigned int m, unsigned int n);

        //Section numbers
        void numbers(ostream &outs, const string &prefix, unsigned int levels);

        //A Teddy Bear Picnic
        bool bears(int n);

        //A Fractal Pattern
        void pattern(ostream &outs, unsigned int n, unsigned int i);

#endif //CSC212_PROJ_THREE_REC_FUN_H
