#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
void print(vector<tuple<int, int, int>> a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << get<0>(a[i]) << "-" << get<1>(a[i]) << "-" << get<2>(a[i]) << endl;
	}
	cout << endl;
}
bool sort1(tuple<int, int, int> a, tuple<int, int, int> b)
{

	return (get<0>(a) < get<0>(b));
}
bool sort2(tuple<int, int, int> a, tuple<int, int, int> b)
{

	return (get<1>(a) < get<1>(b));
}
bool sort3(tuple<int, int, int> a, tuple<int, int, int> b)
{
	if (get<2>(a) == get<2>(b))
	{
		sort2(a, b);
	}
	return (get<2>(a) < get<2>(b));
}
int main()
{
	vector<tuple <int, int, int> > personas;
	int n, d, m, a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> d;
		cin >> m;
		cin >> a;
		personas.push_back(make_tuple(d, m, a));
	}
	sort(personas.begin(), personas.end(), sort1);
	print(personas, n);
	sort(personas.begin(), personas.end(), sort2);
	print(personas, n);
	sort(personas.begin(), personas.end(), sort3);
	print(personas, n);

}
