#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int INF = 1000;
int _INF = -1000;

int main()
{
    int N;
    vector<string> NAME;
    string name;
    char sex;
    vector<string> ID;
    string id;
    vector<int> MGrade;
    vector<int> FGrade;
    int grade;
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
	cin >> name >> sex >> id >> grade;
	NAME.push_back(name);
	ID.push_back(id);
	if (sex == 'M')
	{
	    MGrade.push_back(grade);
	    FGrade.push_back(_INF);
	}
	else
	{
	    MGrade.push_back(INF);
	    FGrade.push_back(grade);
	}	 
    }
    int flag = 0;
    int b = min_element(MGrade.begin(), MGrade.end()) - MGrade.begin();
    int a = max_element(FGrade.begin(), FGrade.end()) - FGrade.begin();
    if (FGrade[a] == _INF)
    {
	flag = 1;
	cout << "Absent\n";
    }
    else
	cout << NAME[a] << " " << ID[a] << "\n";
    if (MGrade[b] == INF)
    {
	flag = 1;
	cout << "Absent\n";
    }
    else
	cout << NAME[b] << " " << ID[b] << "\n";
    if (flag)
	cout << "NA\n";
    else
	cout << FGrade[a] - MGrade[b] << "\n";
    return 0;
}
 				  
				  
