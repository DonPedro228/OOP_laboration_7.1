#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <ctime> 
#include <numeric> 
using namespace std;


int RandomNumber() { return (std::rand() % 100); }
void print(vector<int> a)
{
	for (int i : a)
		cout << i << " ";
	cout << endl;
}
int main()
{
	srand(unsigned(time(0)));
	int n;
	cout << "n = ? "; cin >> n;
	vector<int> v(n);
	generate(v.begin(), v.end(), RandomNumber);
	print(v);


	auto result = std::minmax_element(v.begin(), v.end());
	cout << "min is " << *result.first;
	cout << ", at position " << (result.first - v.begin()) << '\n';
	cout << "max is " << *result.second;
	cout << ", at position " << (result.second - v.begin()) << '\n';
	

	auto min_value = *result.first;
	auto max_value = *result.second;

	auto sum_min_max = min_value + max_value;
	double avg_min_max = sum_min_max / 2.0;

	cout << "AVG of min and max = " << avg_min_max << endl;
	return 0;
}