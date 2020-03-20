#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Pay;
vector<int> Chain;
vector<int> Sum;
vector<int> RightIndex;
int INF = 1000000;

void Output()
{
    int min = *min_element(Sum.begin(), Sum.end());
    vector<int>::iterator it = find(Sum.begin(), Sum.end(), min);
    while(it != Sum.end())
    {
	cout << it - Sum.begin() + 1 << "-" << RightIndex[it - Sum.begin()] + 1 << "\n";
	*it = INF;
	it = find(Sum.begin(), Sum.end(), min);
    }
}



int main()
{
    cin >> N >> Pay;
    int i;
    for (i = 0; i < N; i++)
    {
	int a;
	cin >> a;
	Chain.push_back(a);
	Sum.push_back(0);
	RightIndex.push_back(0);
    }
    int flag = 0;
    i = -1;
    while (Sum[0] < Pay)
    {
	i++;
	if (i == N)
	{
	    flag = 1;
	    Sum[0] = INF;
	    break;
	}
	Sum[0] += Chain[i];
    }
    RightIndex[0] = i;
    for (i = 1; i < N; i++)
    {
	if (flag)
	{
	    Sum[i] = INF;
	    continue;
	}
	int j = RightIndex[i-1];
	Sum[i] = Sum[i-1] - Chain[i-1];
	while (Sum[i] < Pay)
	{
	    j++;
	    if (j == N)
	    {
		flag = 1;
		Sum[i] = INF;
		break;
	    }
	    Sum[i] += Chain[j];
	}
	RightIndex[i] = j;
    }
    Output();
    return 0;
}
