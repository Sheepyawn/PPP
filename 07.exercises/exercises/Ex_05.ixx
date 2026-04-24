export module Ex_05;

import PPP;
import Ex_02;
using namespace std;

// function for exercise_5
// 返回输入数组的逆序新数组
vector<int> reverse_vector_1(const vector<int>& v)
{
	vector<int> nv;
	size_t size = v.size();
	for (size_t i = 0; i < size; ++i)
	{
		nv.push_back(v[size - 1 - i]);
	}
	return nv;
}

// function for exercise_5
// 将输入数组逆序排列。
void reverse_vector_2(vector<int>& v)
{
	size_t size = v.size();
	for (size_t i = 0; i < size; ++i)
	{
		swap(v[i], v[size - 1 - i]);
	}
}

// Write two functions that reverse the order of elements in a vector<int>.
export void Ex_05()
{
	vector<int> v{ 1, 3, 5, 7, 9 };
	vector<int> v1;

	v1 = reverse_vector_1(v);
	print_vector("v1", v1);

	reverse_vector_2(v);
	print_vector("reversed v", v);
}