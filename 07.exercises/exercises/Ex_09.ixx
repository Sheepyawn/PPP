export module Ex_09;

export void Ex_09();

import PPP;
using namespace std;

// function for exercise_9
// 检查两个数组大小是否想等。
void check_if_match(const vector<double>& v1, const vector<double>& v2)
{
	if (v1.size() != v2.size())
		PPP::error("The two vectors have different sizes.");
}

// function for exercise_9
// 打印数组对
void print_pairs(const vector<double>& v1, const vector<double>& v2)
{
	check_if_match(v1, v2);
	size_t size = v1.size();
	for (size_t i = 0; i < size; ++i)
	{
		cout << v1[i] << ", " << v2[i] << '\n';
	}
}

// function for exercise_9
double calculate_value(const vector<double>& v1, const vector<double>& v2)
{
	check_if_match(v1, v2);
	size_t size = v1.size();
	double price = 0;
	for (size_t i = 0; i < size; ++i)
	{
		price += v1[i] * v2[i];
	}
	return price;
}

// Write a function that given two vector<double>s price and weight 
// computes a value (an “index”) that is the sum of all price[i]*weight[i]. 
void Ex_09()
{
	vector<double> price{ 1.5, 3.0, 100, 50 };
	vector<double> weight{ 50, 25, 0.1, 0.8 };
	print_pairs(price, weight);
	cout << "value == " << calculate_value(price, weight) << '\n';
}