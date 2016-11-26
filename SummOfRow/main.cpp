#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  cout << "Hello World!" << endl;

  int e = pow(10, -4);

  //------------------------

  long double an = 0;
  int n = 1;
  long double nfact = 1;

  for (int i = n; i > 0; --i) {
    nfact *= i;
  }
  cout << "nfact :" << nfact << endl;
  an = 2 * pow(nfact, 2);
  cout << "an = 2(n!)^2 : " << an << endl;
  nfact = 1;
  for (int i = 2*n; i > 0; --i) {
    nfact *= i;
  }
  cout << "(2n)! : " << nfact << endl;
  n = 3 * nfact;

  nfact = 1;
  long double size = pow(2, sizeof(long double) * sizeof(long double));
  for (long double i = n;  (nfact < size) ? (i > 0) : (nfact <= size); --i) {
    nfact *= i;
  }

  an = an / nfact;

  cout << "an = 2(n!)^2 / (3((2n)!)! == " << an << endl;

  return 0;
}
