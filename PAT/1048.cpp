#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int a, b;
    vector<int> Coins(N);
    vector<int> Result(2, M+1);
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
	cin >> a;
	b = M - a;
	Coins[i] = a;
	if (find(Coins.begin(), Coins.end(), b) == Coins.end() || find(Coins.begin(), Coins.end(), b) == Coins.begin()+i)
	    continue;
	else
	{
	    if (min(a, b) < Result[0])
	    {
		flag = 1;
		Result[0] = min(a, b);
		Result[1] = max(a, b);
	    }
	}
    }
    if (!flag)
	cout << "No solution";
    else
	cout << Result[0] << " " << Result[1];
    return 0;
}
