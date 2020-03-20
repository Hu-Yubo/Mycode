#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
int c;
vector<string> C1;
vector<string> C2;
vector<int> C3;

void InsertSort()
{
    int i;
    string ID;
    string NAME;
    int STORE;
    for (i = 0; i < N; i++)
    {
	cin >> ID >> NAME >> STORE;
	if (C1.empty())
	{
	    C1.push_back(ID);
	    C2.push_back(NAME);
	    C3.push_back(STORE);
	}
	else
	{
	    if (c == 1)
	    {
		vector<string>::iterator it1 = C1.begin();
		vector<string>::iterator it2 = C2.begin();
		vector<int>::iterator it3 = C3.begin();
		while (ID > *it1)
		{
		    it1++;
		    if (it1 == C1.end())
			break;
		}
		int a = it1 - C1.begin();
		C1.insert(it1, ID);
		C2.insert(it2 + a, NAME);
		C3.insert(it3 + a, STORE);
	    }
	    else if (c == 2)
	    {
		vector<string>::iterator it1 = C1.begin();
		vector<string>::iterator it2 = C2.begin();
		vector<int>::iterator it3 = C3.begin();
		int a;
		while (NAME >= *it2)
		{
		    if (NAME == *it2)
		    {
			a = it2 - C2.begin();
			if (ID > *(it1 + a))
			    it2++;
			else
			    break;
		    }
		    else
			it2++;
		    if (it2 == C2.end())
			break;
		}
		    a = it2 - C2.begin();
		C1.insert(it1 + a, ID);
		C2.insert(it2, NAME);
		C3.insert(it3 + a, STORE);
	    }
	    else if (c == 3)
	    {
		vector<string>::iterator it1 = C1.begin();
		vector<string>::iterator it2 = C2.begin();
		vector<int>::iterator it3 = C3.begin();
		int a;
		while (STORE >= *it3)
		{
		    if (STORE == *it3)
		    {
			a = it3 - C3.begin();
			if (ID > *(it1 + a))
			    it3++;
			else
			    break;
		    }
		    else
			it3++;
		    if (it3 == C3.end())
			break;
		}
		    a = it3 - C3.begin();
		C1.insert(it1 + a, ID);
		C2.insert(it2 + a, NAME);
		C3.insert(it3, STORE);
	    }
	}
    }
}



int main()
{
    cin >> N >> c;
    InsertSort();
    for (int i = 0; i < C1.size(); i++)
    {
	cout << C1[i] << " " << C2[i] << " " << C3[i] << "\n";
    }
}
