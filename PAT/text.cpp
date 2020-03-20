#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string S1 = "Adffwcacaz";
    string S2 = "B";
    vector<int> A(3);
    A[0] = 0;
    A[1] = 1;
    A[2] = 2;
    vector<int>::iterator it = A.begin() + 1;
    cout << *it;
    return 0;
}
