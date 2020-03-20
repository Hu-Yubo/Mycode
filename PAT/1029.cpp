#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long int> V1;

int main()
{
    cin >> N;
    int i, t;
    for (i = 0; i < N; i++)
    {
	cin >> t;
	V1.push_back(t);
    }
    cin >> N;
    for (i = 0; i < N; i++)
    {
	cin >> t;
	if (find(V1.begin(), V1.end(), t) == V1.end())
	    V1.push_back(t);
    }
    sort(V1.begin(), V1.end());
    cout << V1[(V1.size()-1)/2];
}
