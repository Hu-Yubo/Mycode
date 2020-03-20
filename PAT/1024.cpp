#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;
int K;

int Plus()
{
    int a;
    int InAdd = 0;
    string R = "";
    for (int i = 0; i < S.length(); i++)
    {
	a = (S[i] - '0') + (T[i] - '0') + InAdd;
	InAdd = a / 10;
	R += (char)(a % 10 + '0');
    }
    if (InAdd != 0)
	R += (char)(InAdd + '0');
    S = R;
    T = R;
    reverse(S.begin(), S.end());
    return 0;
}	

int main()
{
    cin >> S >> K;
    int times = 0;
    T = S;
    reverse(T.begin(), T.end());
    while(S != T && times < K)
    {
	times++;
	Plus();
    }
    cout << S << "\n" << times;
}
