#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> PostOrder;
vector<int> InOrder;
vector<vector<int>> LevelOrder(30);

int Travel(int L, int R, int Root, int Depth)
{
    if (L > R)
	return 0;
    LevelOrder[Depth].push_back(PostOrder[Root]);
    int RootIdx = find(InOrder.begin(), InOrder.end(), PostOrder[Root]) - InOrder.begin();
    Travel(L, RootIdx - 1, Root - (R - RootIdx) - 1, Depth + 1);
    Travel(RootIdx + 1, R, Root - 1,  Depth + 1);
    return 0;
}
    
int main()
{
    cin >> N;
    int i, t;
    for (i = 0; i < N; i++)
    {
	cin >> t;
	PostOrder.push_back(t);
    }
    for (i = 0; i < N; i++)
    {
	cin >> t;
	InOrder.push_back(t);
    }
    Travel(0, N - 1, N - 1,  0);
    i = 0;
    while (LevelOrder[i].size())
    {
	for (int j = 0; j < LevelOrder[i].size(); j++)
	{
	    if (i == 0)
		cout << LevelOrder[i][j];
	    else
		cout << " " << LevelOrder[i][j];
	}
	i++;
    }
}
