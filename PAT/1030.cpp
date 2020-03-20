#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, S, D;
int INFTY = 10000000;
vector<vector<int>> Path;
vector<vector<int>> Cost;
vector<vector<int>> ShortestPath;
vector<int> Mark;
vector<int> Distance;
vector<int> TotalCost;

int main()
{
    cin >> N >> M >> S >> D;
    int i;
    for (i = 0; i < N; i++)
    {
	Path.push_back(vector<int> (N, INFTY));
	Cost.push_back(vector<int> (N, INFTY));
	Mark.push_back(0);
	Distance.push_back(INFTY);
	TotalCost.push_back(INFTY);
	ShortestPath.push_back(vector<int> (1, S));
    }
    int c1, c2;
    for (i = 0; i < M; i++)
    {
	cin >> c1 >> c2;
	scanf("%d", &Path[c1][c2]);
	Path[c2][c1] = Path[c1][c2];
	scanf("%d", &Cost[c1][c2]);
	Cost[c2][c1] = Cost[c1][c2];
    }
    Mark[S] = 1;
    Distance[S] = 0;
    TotalCost[S] = 0;
    int Rlx = S;
    while(Mark[D] != 1)
    {
	for (i = 0; i < N; i++)
	{
	    if (Mark[i] == 0 && Distance[i] > Distance[Rlx] + Path[Rlx][i])
	    {
		Distance[i] = Distance[Rlx] + Path[Rlx][i];
		TotalCost[i] = TotalCost[Rlx] + Cost[Rlx][i];
		ShortestPath[i] = ShortestPath[Rlx];
		ShortestPath[i].push_back(i);
	    }
	    else if (Mark[i] == 0 && Distance[i] == Distance[Rlx] + Path[Rlx][i])
	    {
		if (TotalCost[i] > TotalCost[Rlx] + Cost[Rlx][i])
		{
		    TotalCost[i] = TotalCost[Rlx] + Cost[Rlx][i];
		    ShortestPath[i] = ShortestPath[Rlx];
		    ShortestPath[i].push_back(i);
		}
	    }
	}
	Distance[Rlx] = INFTY;
	Rlx = min_element(Distance.begin(), Distance.end()) - Distance.begin();
	Mark[Rlx] = 1;
    }
    for (i = 0; i < ShortestPath[D].size(); i++)
    {
	if (i == 0)
	    cout << ShortestPath[D][i];
	else
	    cout << " " << ShortestPath[D][i];
    }
    cout << " " << Distance[D] << " " << TotalCost[D];
}
    
