export module Ex_03;

import PPP;
import Ex_02;
using namespace std;

// function for exercise_3, exercise_4
// 生成斐波拉契数列，存入空数组v。
// v[0] = x, v[1] = y, n是存入数组的数据个数。
export void fibonacci(unsigned int x, unsigned int y, vector<int>& v, size_t n)
{
	if (v.size() != 0)
		PPP::error("non-empty vector");
	if (n < 3)
		PPP::error("the size of vecotr should be greater than 3");
	if (x < 0)
		PPP::error("invalid x");
	if (y < 1)
		PPP::error("invalid y");
	v.push_back(x);
	v.push_back(y);

	for (size_t i = 0; i < n - 2; ++i)
	{
		int num = v[i] + v[1 + i];
		v.push_back(num);
	}

}

// Create a vector of Fibonacci numbers and print them using the function from exercise 2.
export void Ex_03()
{
	vector<int> v;
	fibonacci(1, 2, v, 10);
	print_vector("斐波拉契数列：", v);
}