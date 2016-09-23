#include <iostream>
#include <cmath>
#include "nod.h"

using namespace std;

int nod(int A, int B) {
  // checkers
  int a = abs(A);
  int b = abs(B);
  if (a == 0 && b == 0){
    return 0;
  } else if ( a == 0) {
    return b;
  } else if (b == 0 ){
    return a;
  }

  // algorithm
  int t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

void test_nod(int a, int b, int expectation) {
  cout << "Nod of " << a << " and " << b << " : " << nod(a, b) << ". Expectation was " << expectation << endl;
  nod(a, b) == expectation ? cout << "True" : cout << "False";
  cout << endl;
}

