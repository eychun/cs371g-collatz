// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

bool collatz_read (istream& r, int& i, int& j) {
    if (!(r >> i))
        return false;
    r >> j;
    return true;}

int cycle_length (int n) {
    assert(n > 0);
    int c = 1;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
	//k + (k >> 1) + 1;
        ++c;}
    assert(c > 0);
    return c;}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
  int maxLen = 0;
  int cycleLen = 0;
  int tmp;

  assert (i != 0);
  assert (j != 0);

  if (i > j) {
    tmp = i;
    i = j;
    j = tmp;
  }
  for (int k = i; k <= j; k++) {
    cycleLen = cycle_length (k);
    maxLen = cycleLen > maxLen ? cycleLen : maxLen;
  }

  return maxLen;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
