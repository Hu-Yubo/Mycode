#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int i;
    vector<long int> Coupon(N);
    for (i = 0; i < N; i++)
    {
	long int t;
	cin >> t;
	Coupon.push_back(t);
    }       
    cin >> N;
    vector<long int> Product(N);
    for (i = 0; i < N; i++)
    {
	long int t;
	cin >> t;
	Product.push_back(t);
    }
    sort(Coupon.begin(), Coupon.end(), greater<long int>());
    sort(Product.begin(), Product.end(), greater<long int>());
    long int Value = 0;
    i = 0;
    while((Coupon[i]>0 && Product[i]>0) && i < Coupon.size())
    {
	Value += Coupon[i]*Product[i];
	i++;
    }
    reverse(Coupon.begin(), Coupon.end());
    reverse(Product.begin(), Product.end());
    i = 0;
    while((Coupon[i]<0 && Product[i]<0) && i < Coupon.size())
    {
	Value += Coupon[i]*Product[i];
	i++;
    }
    cout << Value;
    return 0;
}
