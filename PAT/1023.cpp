#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> N1(10, 0);
vector<int> N2(10, 0);
string S, T = "";

int main()
{
    cin >> S;
    for (int i = 0; i < S.length(); i++)
	N1[S[i] - '0']++;
    reverse(S.begin(), S.end());
    int JinWei = 0;
    int a;
    for (int i = 0; i < S.length(); i++)
    {
	a = JinWei + 2 * (S[i] - '0');
	T += (char)(a % 10 + '0');
	JinWei = a / 10;
    }
    if (JinWei != 0)
	T += (char)(JinWei + '0');
    reverse(T.begin(), T.end());
    for (int i = 0; i < T.length(); i++)
	N2[T[i] - '0']++;
    if (N1 == N2)
	cout << "Yes" << "\n" << T;
    else
	cout << "No" << "\n" << T;
    return 0;
}
