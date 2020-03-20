#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int number(string S, int RADIX)
{
    int n = S.length() - 1;
    int N = 0;
    for (int i = 0; i <= n; i++)
    {
	if ('0' <= S[i] && S[i] <= '9')
	    N = N + (S[i] - '0') * pow(RADIX, n - i);
	else
	    N = N + (S[i] - 'a' + 10) * pow(RADIX, n - i);
    }
    return N;
}

int main()
{
    string N1, N2, temp;
    int tag, radix1;
    cin >> N1 >> N2 >> tag >> radix1;
    if (tag == 2)
    {
	N1 = temp;
	N1 = N2;
	N2 = temp;
    }
    int n1 = number(N1, radix1);
    int radix2 = 1;
    int mark = 0;
    int n2 = number(N2, radix2);
    while (n2 < n1)
    {
	radix2++;
	n2 = number(N2, radix2);
	if (n2 == n1)
	{
	    mark = 1;
	    break;
	}
    }
    if (mark == 1)
	cout << radix2;
    else
	cout << "Impossible";
	
}
