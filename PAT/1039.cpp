#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int Ns, Nk, n;
    cin >> Ns >> Nk;
    vector<vector<string>> Course(Nk);
    int c, Nc;
    string name;
    for (int i = 0; i < Nk; i++)
    {
	cin >> c >> Nc;
	for (int j = 0; j < Nc; j++)
	{
	    cin >> name;
	    Course[c-1].push_back(name);
	}
    }
    vector<int> HisCourse;
    for (int i = 0; i < Ns; i++)
    {
	HisCourse.clear();
	cin >> name;
	for (int j = 0; j < Nk; j++)
	    if (find(Course[j].begin(), Course[j].end(), name) != Course[j].end())
		HisCourse.push_back(j+1);
	sort(HisCourse.begin(), HisCourse.end());
	cout << name << " " << HisCourse.size();
	for (int j = 0; j < HisCourse.size(); j++)
	    cout << " " << HisCourse[j];
	cout << "\n";
    }
    return 0;
}
	
