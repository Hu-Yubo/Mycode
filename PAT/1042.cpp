#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> Card;
vector<int> Order(54);

void Initial()
{
    int i;
    string s = "S";
    for (i = 1; i <= 13; i++)
    {
	s += to_string(i);
	Card.push_back(s);
	s = "S";
    }
    s = "H";
    for (i = 1; i <= 13; i++)
    {
	s += to_string(i);
	Card.push_back(s);
	s = "H";
    }
    s = "C";
    for (i = 1; i <= 13; i++)
    {
	s += to_string(i);
	Card.push_back(s);
	s = "C";
    }
    s = "D";
    for (i = 1; i <= 13; i++)
    {
	s += to_string(i);
	Card.push_back(s);
	s = "D";
    }
    Card.push_back("J1");
    Card.push_back("J2");
}

void Shuffle()
{
    vector<string> Temp(54);
    for (int i = 0; i < 54; i++)
	Temp[Order[i]] = Card[i];
    Card = Temp;
}
int main()
{
    int times;
    cin >> times;
    Initial();
    for (int i = 0; i < 54; i++)
    {
	scanf("%d", &Order[i]);
	Order[i]--;
    }
    for (int i = 0; i < times; i++)
	Shuffle();
    for (int i = 0; i < 54; i++)
	if (i == 0)
	    cout << Card[i];
	else
	    cout << " " << Card[i];
    return 0;
}
