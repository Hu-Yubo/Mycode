#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    vector<int> X;
    cin >> a >> b;
    while (1)
    {
	if (a == 0)
	    break;
	X.push_back(a % b);
	a = a / b;
    }
    int flag = 1;
    a = 0;
    b = X.size() - 1;
    while(a <= b)
    {
	if (X[a] != X[b])
	{
	    flag = 0;
	    break;
	}
	a++;
	b--;
    }
    if (flag)
	cout << "Yes" << "\n";
    else
	cout << "No" << "\n";
    for (int i = X.size() - 1; i >= 0; i--)
    {
	if (i == X.size() - 1)
	    cout << X[i];
	else
	    cout << " " << X[i];
    }
    return 0;
}
	    
    
    
