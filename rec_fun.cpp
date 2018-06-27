#include <iostream>
#include "rec_fun.h"
using namespace std;

// 1. Triangle Pattern
void triangle(ostream &outs, unsigned int m, unsigned int n) {
    //Was going to use for loops to print upper/lower, but was not efficient
    if (m <= n) {
        string asterik = string(m, '*');
        cout << asterik << endl;
        triangle(cout, m + 1, n);
        //Prints out 5, then decrements
        cout << asterik << endl;
    }
}

// 2. Section Numbers
//#include <strclass.h> kept using this and it did not work, it said this was same as <string>
// or had its own header file.
void numbers(ostream &outs, const string &prefix, unsigned int levels) {
    if (levels == 0) {
        cout << prefix << endl;
        return;
    }

    for (int i = 1; i < 10; i++) {
        string dot = (levels == 1 ? " " : "."); //Case Handling: True print " " after, False print "." after
        string section = (prefix + to_string(i)) + dot; //String combining
        numbers(outs, section, levels - 1);
    }
}

// 3. A Teddy Bear Picnic
bool bears(int n) {
    //Stopping case 1: N is 42
    if (n == 42) {
        return true;
    }
        //Stopping case 2: N is less than 42
    else if (n < 42) {
        return false;
    } else {
        //divisible by 5
        if (n % 5 == 0) {
            if (bears(n - 42)) {
                return true;
            }
        }
        //divisible by 2
        if (n % 2 == 0) {
            if (bears(n / 2)) {
                return true;
            }
        }
        //divisible by 3 or 4
        if ((n % 3 == 0) || (n % 4 == 0)) {
            int sec_last = (n % 100) / 10;
            int last = n % 10;
            int mult = sec_last * last;
            if (bears(n - mult)) {
                return true;
            }
        }
            //false if it final n != 42 or it is less than 42
        else {
            return false;
        }
    }
}


// 4. A Fractal Pattern
void pattern(ostream &outs, unsigned int n, unsigned int i) {
    unsigned int k;
    //Stopping case
    if (n == 1) {
        for (k = 0; k < i; k++) {
            outs << " ";
        }
        outs << "* ";
        outs << endl;
        return;
    }

    pattern(outs, n / 2, i);

    for (k = 0; k < i; k++) {
        outs << " ";
    }
    for (k = 0; k < n; k++) {
        outs << "* ";
    }
    outs << endl;

    pattern(outs, n / 2, i + n);
}




