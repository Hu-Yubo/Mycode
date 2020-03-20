#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool IsSymmetric(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return (s == t);
}

int main()
{
    string s;
    getline(cin, s);
    int length = 0;
    for (int i = 0; i < s.length(); i++)
	for (int j = 1; j <= s.length()-i; j++)
	    if (IsSymmetric(s.substr(i,j)) && j > length)
		length = j;
    cout << length;
    return 0;
}
