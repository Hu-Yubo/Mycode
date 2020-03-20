#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<vector<int>> Tree;
vector<int> Mark;
vector<int> Depth;
vector<int> Length;
stack<int> S;
int flag, N;
int NowMark;
int DFS(int root)
{
    int i;
    for (i = 0; i < N; i++)
    {
	if (Tree[root][i] == 1 && Mark[i] == 0)
	{
	    Mark[i] = NowMark;
	    S.push(i);
	    Depth[i] = Depth[root] + 1;
	    DFS(S.top());
	    return 0;
	}
    }
    if (i == N)
    {
	S.pop();
	if (S.empty())
	    return 0;
	else
	    DFS(S.top());
    }
}

int main()
{
    cin >> N;
    int i;
    for (i = 0; i < N; i++)
    {
	Tree.push_back(vector<int> (N, 0));
	Mark.push_back(0);
	Depth.push_back(-1);
	Length.push_back(0);
    }
    int a, b;
    for (i =0; i < N-1; i++)
    {
	cin >> a >> b;
	Tree[a-1][b-1] = 1;
	Tree[b-1][a-1] = 1;
    }
    flag = 0;
    for (i = 0; i < N; i++)
    {
	if (flag == 0)
	{
	    Mark = vector<int>(N, 0);
	    NowMark = 1;
	    Mark[i] = NowMark;
	    Depth[i] = 0;
	    S.push(i);
	    DFS(i);
	    vector<int>::iterator it = find(Mark.begin(), Mark.end(), 0);
	    while (it != Mark.end())
	    {
		flag = 1;
		int j = it - Mark.begin();
		S.push(j);
		NowMark++;
		Mark[j] = NowMark;
		DFS(j);
		it = find(Mark.begin(), Mark.end(), 0);
	    }
	    Length[i] = *max_element(Depth.begin(), Depth.end());
	}
    }
    if (flag)
	printf("Error: %d components", NowMark);
    else
    {
	int idx = max_element(Length.begin(), Length.end()) - Length.begin();
	int max = Length[idx];
	cout << idx + 1;
	Length[idx]--;
	vector<int>::iterator it = find(Length.begin(), Length.end(), max);
	while(it != Length.end())
	{
	    cout << "\n" << it - Length.begin() + 1;
	    Length[it - Length.begin()]--;
	    it = find(Length.begin(), Length.end(), max);
	}
    }
}
	
	
