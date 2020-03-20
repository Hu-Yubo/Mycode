#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<char, char> m;
    m.insert(pair<char, char>('1', '@'));
    m.insert(pair<char, char>('0', '%'));
    m.insert(pair<char, char>('l', 'L'));
    m.insert(pair<char, char>('O', 'o'));
    vector<string> ID;
    vector<string> PSWD;
    string id;
    string pswd;
    for (int i = 0; i < N; i++)
    {
	cin >> id >> pswd;
	int flag = 0;
	for (int j = 0; j < pswd.length(); j++)
	    if (pswd[j] == '1' || pswd[j] == '0' || pswd[j] == 'l' || pswd[j] == 'O')
	    {
		flag = 1;
		pswd[j] = m[pswd[j]];
	    }
	if (flag)
	{
	    ID.push_back(id);
	    PSWD.push_back(pswd);
	}
    }
    if (ID.empty())
    {
	if (N == 1)
	    cout << "There is 1 account and no account is modified";
	else
	    cout << "There are " << N << " accounts and no account is modified";
    }
    else
    {
	cout << ID.size() << "\n";
	for (int i = 0; i < ID.size(); i++)
	    cout << ID[i] << " " << PSWD[i] << "\n";
    }
    return 0;
}
    
    
