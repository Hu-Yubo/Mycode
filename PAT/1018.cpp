#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Max, N, Sp, M;
int infty = 1000000;
vector<vector<int>> Path;
vector<vector<int>> ShortestPath;
vector<int> Distance;
vector<int> Amount;
vector<int> Require;
vector<int> Mark;

int Adjust(int Sp)
{    
    int Relaxed = 0;
    while (Relaxed != Sp)
    {
	for (int i = 1; i < N; i++)
	{
	    if (Distance[i] > Distance[Relaxed] + Path[Relaxed][i] && Mark[i] == 0)
	    {
		Distance[i] = Distance[Relaxed] + Path[Relaxed][i];
		ShortestPath[i] = ShortestPath[Relaxed];
		ShortestPath[i].push_back(i);
		Require[i] = Require[Relaxed] + Amount[i];
	    }
	    else if(Distance[i] == Distance[Relaxed] + Path[Relaxed][i] && Mark[i] == 0)
	    {
		if (Require[Relaxed] + Amount[i] <= Require[i])
		{
		    ShortestPath[i] = ShortestPath[Relaxed];
		    ShortestPath[i].push_back(i);
		    Require[i] = Require[Relaxed] + Amount[i];
		}
	    }
	}
	Distance[Relaxed] = infty;
	Relaxed = min_element(Distance.begin(), Distance.end()) - Distance.begin();
	Mark[Relaxed] = 1;
    }
    return 0;
}


int main()
{
    cin >> Max >> N >> Sp >> M;
    N++;
    int i, t;
    int Perfect = Max/2;
    for (i = 0; i < N; i++)
    {
	Path.push_back(vector<int>(N, infty));
	ShortestPath.push_back(vector<int>(1, 0));
	if (i == 0)
	{
	    Amount.push_back(0);
	    Require.push_back(0);
	    Mark.push_back(1);
	    Distance.push_back(0);
	}
	else
	{
	    cin >> t;
	    Amount.push_back(Perfect - t);
	    Require.push_back(infty);
	    Mark.push_back(0);
	    Distance.push_back(infty);
	}
    }
    int a, b;
    for (i = 0; i < M; i++)
    {
	cin >> a >> b >> t;
	Path[a][b] = t;
	Path[b][a] = t;
    }
    Adjust(Sp);
    if (Require[Sp] >= 0)
    {
	cout << Require[Sp] << " ";
	for (i = 0; i < ShortestPath[Sp].size(); i++)
	{
	    if (i == 0)
		cout << ShortestPath[Sp][i];
	    else
		cout << "->" << ShortestPath[Sp][i];
	}
	cout << " " << 0;
    }
    else
    {
	cout << 0 << " ";
	for (i = 0; i < ShortestPath[Sp].size(); i++)
	{
	    if (i == 0)
		cout << ShortestPath[Sp][i];
	    else
		cout << "->" << ShortestPath[Sp][i];
	}
	cout << " " << -Require[Sp];
    }
    return 0;
}
