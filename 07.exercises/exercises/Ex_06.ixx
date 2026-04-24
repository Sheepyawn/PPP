export module Ex_06;

import PPP;
import empty_check;
using namespace std;

// function for exercise_6
// 返回输入数组的逆序新数组
vector<string> reverse_vector_1(const vector<string>& v)
{
	vector<string> nv;
	size_t size = v.size();
	for (size_t i = 0; i < size; ++i)
	{
		nv.push_back(v[size - 1 - i]);
	}
	return nv;
}

// function for exercise_6
// 将输入数组逆序排列。
void reverse_vector_2(vector<string>& v)
{
	size_t size = v.size();
	for (size_t i = 0; i < size; ++i)
	{
		swap(v[i], v[size - 1 - i]);
	}
}

// function for exercise_6
void print_vector(const string& s, const vector<string>& v)
{
	if_empty_vector(v);
	cout << s << '\n';
	for (string x : v)
		cout << x << '\n';
}

// Write versions of the functions from exercise 5, but with a vector<string>.
export void Ex_06()
{
	vector<string> v{ "a man", "a plan", "a canal-panama" };
	vector<string> v1;

	v1 = reverse_vector_1(v);
	print_vector("v1", v1);

	reverse_vector_2(v);
	print_vector("reversed v", v);
}