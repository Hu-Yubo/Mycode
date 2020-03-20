#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int K, N;
vector<int> ArriveTime;
vector<int> ProcessTime;
int WaitTime = 0;
vector<int> Windows;
vector<int> WindowsTime;
int OpenTime = 28800;//seconds
int Closetime = 32400;
int NowTime = 0;

int Seconds(string S)
{
    return ((S[0]-'0')*36000+(S[1]-'0')*3600+(S[3]-'0')*600+(S[4]-'0')*60+(S[6]-'0')*10+(S[7]-'0'));
}

int Insert(string S,int t)
{
    int at = Seconds(S) - OpenTime;
    if (at > Closetime)
	return 0;
    if (ArriveTime.empty())
    {
	ArriveTime.push_back(at);
	ProcessTime.push_back(t);
	return 0;
    }
    vector<int>::iterator it = ArriveTime.begin();
    while(*it < at && it != ArriveTime.end())
    {
	it++;
    }
    ProcessTime.insert(ProcessTime.begin()+(it-ArriveTime.begin()), t);
    ArriveTime.insert(it, at);
    return 0;
}

int OutQueue()
{
    int Fastest = min_element(WindowsTime.begin(), WindowsTime.end()) - WindowsTime.begin();
    int t = WindowsTime[Fastest];
    NowTime += t;
    for (int i = 0; i < K; i++)
	WindowsTime[i] -= t;
    Windows[Fastest] = -1;
    return 0;
}    

int InQueue(int i)
{
    int Free = find(Windows.begin(), Windows.end(), -1) - Windows.begin();
    if (Free == K) //FULL
    {
	OutQueue();
	InQueue(i);
    }
    else
    {
	if (ArriveTime[i] > NowTime)
	{
	    for (int j = 0; j < K; j++)
		WindowsTime[j] -= ArriveTime[i] - NowTime;
	    NowTime = ArriveTime[i];
	}
	Windows[Free] = i;
	WindowsTime[Free] = ProcessTime[i];
	WaitTime += NowTime - ArriveTime[i];
    }
    return 0;
}
    
int main()
{
    cin >> N >> K;
    string S;
    int t;
    int i;
    for (i = 0; i < N; i++)
    {
	cin >> S >> t;
	if (t > 60)
	    t = 60;
	Insert(S, t*60);
    }
    N = ArriveTime.size();
    if (N == 0)
    {
	cout << "0.0";
	return 0;
    }
    Windows = vector<int>(K, -1);
    WindowsTime = Windows;
    for (i = 0; i < N; i++)
	InQueue(i);
    cout << setiosflags(ios::fixed) << setprecision(1) << (double(WaitTime)/60.0/double(N));
    return 0;
}
