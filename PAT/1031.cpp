#include <iostream>
#include <string>
using namespace std;

string S;

int main()
{
    cin >> S;
    int n = S.length();
    int n1 = (n+2) / 3 - 1;
    int n2 = (n+2) / 3 + (n+2) % 3;
    int a = 0;
    int b = n - 1;
    string S1(n2-2, ' ');
    for (int i = 0; i < n1; i++)
    {
	cout << S[a] << S1 << S[b] << "\n";
	a++;
	b--;
    }
    cout << S.substr(a, n2);
    return 0;
}
	
	
