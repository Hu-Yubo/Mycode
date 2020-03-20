#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N, M, K;
stack<int> S;

int DFS(vector<vector<int>> Path, vector<int>& Mark, int START, int NowMark)
{
    int END;
    for (END = 0; END < N; END++)
    {
	if (Path[START][END] == 1 && Mark[END] == -1 )
	{
	    Mark[END] = NowMark;
	    S.push(END);
	    DFS(Path, Mark, S.top(), NowMark);
	    return 0;
	}
    }
    if (END == N)
    {
	S.pop();
	if (S.empty())
	{
	    return 0;	    
	}
	else
	    DFS(Path, Mark, S.top(), NowMark);
    }
}

int main()
{
    int i;
    cin >> N >> M >> K;
    vector<vector<int>> Path(N, vector<int>(N, 0));
    int c1, c2;
    for (i = 0; i < M; i++)
    {
	cin >> c1 >> c2;
	Path[c1-1][c2-1] = 1;
	Path[c2-1][c1-1] = 1;
    }
    vector<int> Checklist(K);
    for (i = 0; i < K; i++)
    {
	cin >> c1;
	Checklist[i] = c1 - 1;
    }
    int Origin, NowMark, j;
    vector<int>::iterator it;
    for (i = 0; i < K; i++)
    {
	vector<int> Mark(N, -1);
	Origin = Checklist[i];
	NowMark = 0;
	Mark[Origin] = NowMark;
	for(j = 0; j < N; j++)
	{
	    if (Path[Origin][j] == 1 && Mark[j] == -1)
	    {
		S.push(j);
		NowMark++;
		Mark[j] = NowMark;
		DFS(Path, Mark, j, NowMark);
	    }
	}
	it = find(Mark.begin(), Mark.end(), -1);
	while (it != Mark.end())
	{
	    j = it - Mark.begin();
	    S.push(j);
	    NowMark++;
	    Mark[j] = NowMark;
	    DFS(Path, Mark, j, NowMark);
	    it = find(Mark.begin(), Mark.end(), -1);
	}
	cout << NowMark - 1 << "\n";
    }
    return 0;
}
