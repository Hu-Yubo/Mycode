#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a;
string S = "#";

int main()
{
    string S1;
    for (int i = 0; i < 3; i++)
    {
	S1 = "";
	int b;
	cin >> a;
	while (1)
	{
	    if (a == 0)
		break;
	    b = a % 13;
	    if (b >= 10)
		S1 += (char)(b - 10 + 'A');
	    else
		S1 += (char)(b + '0');
	    a = a / 13;
	}
	int l = 2 -  S1.length();
	for(int j = 0; j < l; j++)
	    S1 += '0';
	reverse(S1.begin(), S1.end());
	S += S1;
    }
    cout << S;
}
