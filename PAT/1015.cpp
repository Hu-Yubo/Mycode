#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

string S;
vector<int> X;
int R;
int a, b, l;

int IsPrime(int a)
{
    int flag = 1;
    if (a == 1)
	return 0;
    for (int i = 2; i < sqrt(a) + 1; i++)
    {
	if (a % i == 0)
	{
	    flag--;
	    break;
	}
    }
    return flag;
}
    
void Calculate()
{
    int i;
    l = S.length();
    for (i = 0; i < l; i++ )
    {
	a = a + (S[i] - '0') * pow(10, l-1-i);
    }
    int t = a;
    while (1)
    {
	if (t == 0)
	    break;
	X.push_back(t % R);
	t = t / R;
    }
    l = X.size();
    for (i = 0; i < l; i++)
	b = b + X[i] * pow(R, l-i-1);
}

int main()
{
    while (1)
    {
	cin >> S;
	if (S[0] == '-')
	    break;
	cin >> R;
	a = 0;
	b = 0;
	X.clear();
	Calculate();
	if(a == 1 || b == 1)
	    cout << "No" << "\n";
	else if (IsPrime(a) && IsPrime(b))
	    cout << "Yes" << "\n";
	else
	    cout << "No" << "\n";
    }
}

	
	
