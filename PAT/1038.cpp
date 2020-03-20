#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
    int flag = 0;
    if (a.length() < b.length())
    {
	for (int i = 0; i < a.length(); i++)
	    if (a[i] != b[i])
	    {
		flag = 1;
		break;
	    }
	if (flag)
	    return a < b;
	else
	    return compare(b.substr(a.length()), a);
    }
    else
    {
	if (a == b)
	    return true;
	for (int i = 0; i < b.length(); i++)
	    if (a[i] != b[i])
	    {
		flag = 1;
		break;
	    }
	if (flag)
	    return a < b;
	else
	    return compare(a.substr(b.length()), a);
    }
}

int main()
{
    int N;
    cin >> N;
    string s;
    vector<string> V;
    for (int i = 0; i < N; i++)
    {
	cin >> s;
	V.push_back(s);
    }
    sort(V.begin(), V.end(), compare);
    string Merge = "";
    for (int i = 0; i < N; i++)
	Merge += V[i];
    if (Merge == string(Merge.length(),'0'))
	cout << 0;
    else
    {
	int i;
	for (i = 0; i < Merge.length(); i++)
	{
	    if (Merge[i] != '0')
	    {
		break;
	    }
	}
	cout << Merge.substr(i);
    }
    return 0;
}
