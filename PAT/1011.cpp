#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    vector<float> V[3];
    float f;
    int i;
    for (i = 0; i < 9; i++)
    {
	cin >> f;
	V[i/3].push_back(f);
    }
    vector<int> m(3);
    m[0] = max_element(V[0].begin(), V[0].end()) - V[0].begin();
    m[1] = max_element(V[1].begin(), V[1].end()) - V[1].begin();
    m[2] = max_element(V[2].begin(), V[2].end()) - V[2].begin();
    for (i = 0; i < 3; i++)
    {
	if (m[i] == 0)
	    cout << "W" << " ";
	else if (m[i] == 1)
	    cout << "T" << " ";
	else
	    cout << "L" << " ";
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << (V[0][m[0]]*V[1][m[1]]*V[2][m[2]]*0.65-1)*2;
    return 0;
}
    
