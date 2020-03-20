#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int Hash[100001];
    int a[100001];
    int n;
    int i;
    for (i = 0; i < N; i++)
    {
	cin >> n;
	a[i] = n;
	Hash[n]++;
    }
    for (i = 0; i < N; i++)
	if (Hash[a[i]] == 1)
	    break;
    if (i == N)
	cout << "None";
    else
	cout << a[i];
}
