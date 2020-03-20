#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int N, M, i;
    cin >> N >> M;
    vector<string> ID(N);
    vector<int> Cgrade(N);
    vector<int> Mgrade(N);
    vector<int> Egrade(N);
    vector<int> Agrade(N);
    for (i = 0; i < N; i++)
    {
	cin >> ID[i] >> Cgrade[i] >> Mgrade[i] >> Egrade[i];
	Agrade[i] = floor((Cgrade[i] + Mgrade[i] + Egrade[i])/3.0 + 0.5);
    }
    vector<string> CheckList(M);
    for (i = 0; i < M; i++)
	cin >> CheckList[i];
    vector<int> Csort = Cgrade;
    vector<int> Msort = Mgrade;
    vector<int> Esort = Egrade;
    vector<int> Asort = Agrade;
    sort(Csort.begin(), Csort.end(), greater<int>());
    sort(Msort.begin(), Msort.end(), greater<int>());
    sort(Esort.begin(), Esort.end(), greater<int>());
    sort(Asort.begin(), Asort.end(), greater<int>());
    string Mark = "ACME";
    vector<int> EachRank(4);
    int idx,j;
    vector<string>::iterator it;
    
    for (i = 0; i < M; i++)
    {
	it = find(ID.begin(), ID.end(), CheckList[i]);
	if (it == ID.end())
	    //not find
	    cout << "N/A" << "\n";
	else
	{
	    idx = it - ID.begin();
	    EachRank[0] = find(Asort.begin(), Asort.end(), Agrade[idx]) - Asort.begin() + 1;
	    EachRank[1] = find(Csort.begin(), Csort.end(), Cgrade[idx]) - Csort.begin() + 1;
	    EachRank[2] = find(Msort.begin(), Msort.end(), Mgrade[idx]) - Msort.begin() + 1;
	    EachRank[3] = find(Esort.begin(), Esort.end(), Egrade[idx]) - Esort.begin() + 1;
	    j = min_element(EachRank.begin(), EachRank.end()) - EachRank.begin();
	    cout << EachRank[j] << " " << Mark[j] << "\n";
	}
    }
    return 0;
}

