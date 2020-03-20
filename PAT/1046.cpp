#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int N, M;
    cin >> N;
    vector<int> Dis_From_1(N+1);
    int a;
    Dis_From_1[0] = 0;
    for (int i = 1; i <= N; i++)
    {
	cin >> a;
	Dis_From_1[i] = a + Dis_From_1[i-1];
    }
    cin >> M;
    int b, d;
    for (int i = 0; i < M; i++)
    {
	cin >> a >> b;
	d = abs(Dis_From_1[a-1] - Dis_From_1[b-1]);
	cout << (d<(Dis_From_1[N]-d) ? d:Dis_From_1[N]-d) << "\n";
    }
    return 0;
}
