export module Ex_02;

import std;
import empty_check;
using namespace std;

// function for exercise_2, exercise_3
// 输出数组中的所有数。s标志输出。
export void print_vector(const string& s, const vector<int>& v)
{
	if_empty_vector(v);
	cout << s << '\n';
	for (int x : v)
		cout << x << '\n';
}

// Write a function print() that prints a vector of ints to cout. 
// Give it two arguments: a string for “labeling” the output and a vector.
export void Ex_02()
{
	vector<int> v{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	print_vector("数组：", v);
}