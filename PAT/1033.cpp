#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double C_max, D_total, D_avg;
int N;
vector<double> D_stat;
vector<double> P_stat;
int Now_stat = 0;
double Now_D, Now_C = 0;
double Now_P = 0;
double D_max;

int Input()
{
    double d;
    double p;
    for (int i = 0; i < N; i++)
    {
	cin >> p >> d;
	if (d >= D_total)
	    continue;
	else
	{
	    if (D_stat.empty())
	    {
		D_stat.push_back(d);
		P_stat.push_back(p);
	    }
	    else
	    {
		vector<double>::iterator it = D_stat.begin();
		while (d > *it)
		{
		    it++;
		    if (it == D_stat.end())
			break;
		}
		int a = it - D_stat.begin();
		D_stat.insert(it, d);
		P_stat.insert(P_stat.begin() + a, p);
	    }
	}
    }
    return 0;
}



int main()
{
    cin >> C_max >> D_total >> D_avg >> N;
    D_max = C_max * D_avg;
    Input();
    vector<double>::iterator it;
    while (Now_D != D_total)
    {
	for (it = D_stat.begin() + Now_stat; it != D_stat.end(); it++)
	    if (*it > Now_D + D_max)
		break;
	if (it == D_stat.begin() + Now_stat + 1) // No station forward
	{
	    if (Now_D + D_max < D_total)
	    {
		cout << "The maximum travel distance = " << setiosflags(ios::fixed) << setprecision(2) << Now_D + D_max;
		Now_D += D_max;
		break;
	    }
	    else
	    {
		cout << setiosflags(ios::fixed) << setprecision(2) << Now_P + (D_total - Now_D) / D_avg * P_stat[Now_stat];
		Now_D = D_total;
	    }
	}
	else
	{
	    int i = min_element(P_stat.begin()+Now_stat+1, P_stat.begin()+(int)(it-D_stat.begin())) - P_stat.begin();
	    if (P_stat[i] < P_stat[Now_stat])
	    {
		if (Now_C * D_avg < D_stat[i] - D_stat[Now_stat])
		{
		    Now_P += ((D_stat[i]-D_stat[Now_stat])/D_avg - Now_C)*P_stat[Now_stat];
		    Now_C = 0;
		    Now_stat = i;
		    Now_D = D_stat[i];
		}
		else
		{
		    Now_C -= (D_stat[i] - D_stat[Now_stat]) / D_avg;
		    Now_stat = i;
		    Now_D = D_stat[i];
		}
	    }
	    else
	    {
		Now_P += (C_max - Now_C) * P_stat[Now_stat]; //加满
		Now_C = C_max - (D_stat[i] - D_stat[Now_stat]) / D_avg;
		Now_stat = i;
		Now_D = D_stat[i];
	    }
	}
    }
    return 0;
}
