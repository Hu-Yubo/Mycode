// 结构体的运用不熟练，网上参考的
#include <iostream>
using namespace std;

struct
{
    char key;
    int next;
    bool flag;
}node[100001];

int main()
{
    int ad1, ad2, n;
    cin >> ad1 >> ad2 >> n;
    for (int i = 0; i < n; i++)
    {
	int t1, t2;
	char a;
	cin >> t1 >> a >> t2;
	node[t1] = {a, t2, false};
    }
    for (int i = ad1; i != -1; i = node[i].next)
	node[i].flag = true;
    for (int i = ad2; i != -1; i = node[i].next)
    {
	if (node[i].flag)
	{
	    printf("%05d", i);
	    return 0;
	}
    }
    printf("-1");
    return 0;
}
