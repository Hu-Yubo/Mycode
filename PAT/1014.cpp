#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K, Q, TotalTime;
vector<int> TimeCost; //Everyone time needs
vector<queue<int>> Queue;
vector<int> QueueSize;
vector<int> QueueTime;
vector<int> FrontTime;
vector<int> WaitTime;
vector<int> FinishTime;

int OutQueue()
{
    int Fastest = min_element(FrontTime.begin(), FrontTime.end()) - FrontTime.begin();
    int t = FrontTime[Fastest];
    for (int i = 0; i < FrontTime.size(); i++)
    {
	FrontTime[i] -= t;
	QueueTime[i] -= t;
    }
    TotalTime += t;
    Queue[Fastest].pop();
    QueueSize[Fastest]--;
    FrontTime[Fastest] = TimeCost[Queue[Fastest].front()];
}   

int InQueue(int i)
{
    int Shortest = min_element(QueueSize.begin(), QueueSize.end()) - QueueSize.begin();
    if (TotalTime >= 540)
	return 0;
    else if (QueueSize[Shortest] >= M)
    {
	OutQueue();
	InQueue(i);
    }
    else
    {
	Queue[Shortest].push(i);
	FrontTime[Shortest] = TimeCost[Queue[Shortest].front()];
	QueueSize[Shortest]++;
	WaitTime[i] = TotalTime + QueueTime[Shortest];
	if (WaitTime[i] >= 540)
	    WaitTime[i] = -1;
	else
	    FinishTime[i] = WaitTime[i] + TimeCost[i];
	QueueTime[Shortest] += TimeCost[i];
    }
    return 0;
}
    
int main()
{
    TotalTime = 0;
    cin >> N >> M >> K >> Q;
    int t, i;
    queue<int> A;
    for (i = 0; i < N; i++)
    {
	Queue.push_back(A);
	QueueSize.push_back(0);
	QueueTime.push_back(0);
	FrontTime.push_back(0);
    }
    for (i = 0; i < K; i++)
    {
	cin >> t;
	TimeCost.push_back(t);
	WaitTime.push_back(-1);
	FinishTime.push_back(-1);
    }
    vector<int> CheckList(Q);
    for (i = 0; i < Q; i++)
    {
	cin >> t;
	CheckList[i] = t - 1;
    }
    for (i = 0; i < K; i++)
	InQueue(i);
    for (i = 0; i < Q; i++)
    {
	if (FinishTime[CheckList[i]] == -1)
	    cout << "Sorry" << "\n";
	else
	{
	    if (FinishTime[CheckList[i]] / 60 + 8 < 10)
		cout << 0;
	    cout << FinishTime[CheckList[i]] / 60 + 8;
	    cout << ":";
	    if (FinishTime[CheckList[i]] % 60 < 10)
		cout << 0;
	    cout << FinishTime[CheckList[i]] % 60 << "\n";
	}
    }
    return 0;
}
