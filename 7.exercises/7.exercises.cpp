module exercises;

import PPP;
using namespace std;
import calculator;

void if_empty_vector(const vector<string>& v)
{
	if (v.size() == 0)
		PPP::error("There's nothing in the vector. It's empty.");
}

void if_empty_vector(const vector<int>& v)
{
	if (v.size() == 0)
		PPP::error("There's nothing in the vector. It's empty.");
}

void if_empty_vector(const vector<size_t>& v)
{
	if (v.size() == 0)
		PPP::error("There's nothing in the vector. It's empty.");
}

void if_empty_vector(const vector<double>& v)
{
	if (v.size() == 0)
		PPP::error("There's nothing in the vector. It's empty.");
}

// 改进第6章的计算器，用显式参数和istream&
void exercise_1()
{
	//function of calculator.ixx
	calculate();
}

// function for exercise_2, exercise_3
// 输出数组中的所有数。s标志输出。
void print_vector(const string& s, const vector<int>& v)
{
	if_empty_vector(v);
	cout << s << '\n';
	for (int x : v)
		cout << x << '\n';
}

// Write a function print() that prints a vector of ints to cout. 
// Give it two arguments: a string for “labeling” the output and a vector.
void exercise_2()
{
	vector<int> v{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	print_vector("数组：", v);
}

// function for exercise_3
// 生成斐波拉契数列，存入空数组v。
// v[0] = x, v[1] = y, n是存入数组的数据个数。
void fibonacci(unsigned int x, unsigned int y, vector<int>& v, size_t n)
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
void exercise_3()
{
	vector<int> v;
	fibonacci(1, 2, v, 10);
	print_vector("斐波拉契数列：", v);
}

// Find an approximation of that maximum number by using fibonacci().
void exercise_4()
{
	vector<int> v;
	fibonacci(1, 2, v, 50);
	print_vector("斐波拉契数列：", v);
}

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
void exercise_5()
{
	vector<int> v{1, 3, 5, 7, 9};
	vector<int> v1;

	v1 = reverse_vector_1(v);
	print_vector("v1", v1);

	reverse_vector_2(v);
	print_vector("reversed v", v);
}

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
void exercise_6()
{
	vector<string> v{ "a man", "a plan", "a canal-panama"};
	vector<string> v1;

	v1 = reverse_vector_1(v);
	print_vector("v1", v1);

	reverse_vector_2(v);
	print_vector("reversed v", v);
}

// function for exercise_7
// 初始化string数组
void init_name(vector<string>& name)
{
	cout << "Enter names, type 'finished' to end input." << '\n';
	string s;
	while(cin >> s)
	{
		if (s == "finished")
			break;
		name.push_back(s);
	}
}

// function for exercise_7
// 检查两个数组大小是否想等。
void check_if_match(const vector<string>& v1, const vector<unsigned int>& v2)
{
	if (v1.size() != v2.size())
		PPP::error("The two vectors have different sizes.");
}

// function for exercise_7
// 初始化unsigned int数组
void init_age(const vector<string>& name ,vector<unsigned int>& age)
{
	//check_if_match(name, age);
	size_t name_size = name.size();
	unsigned int v;
	for (size_t i = age.size(); i < name_size; ++i)
	{
		cout << "Enter the age of " << name[i] << '\n';
		cin >> v;
		age.push_back(v);
	}
}

// function for exercise_7
 //打印数组对
void print_pairs(const vector<string>& v1, const vector<unsigned int>& v2)
{
	check_if_match(v1, v2);
	size_t size = v1.size();
	for (size_t i = 0; i < size; ++i)
	{
		cout << v1[i] << ", " << v2[i] << '\n';
	}
}

// function for exercise_7
// 使数组2中的数据和数组1相应的数据配对。
void sort_and_match(vector<string>& v1, vector<unsigned int>& v2)
{
	check_if_match(v1, v2);
	vector<string> v1_copy = v1;
	vector<unsigned int> v2_copy(v2.size());

	sort(v1.begin(), v1.end());
	cout << "Complete the sort of v1." << '\n';

	size_t size = v1_copy.size();
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			if (v1_copy[i] == v1[j])
			{
				v2_copy[j] = v2[i];
				break;
			}
			if (j + 1 == size)
				PPP::error("Unable to find a match name.");
		}
	}
	v2 = v2_copy;
	cout << "Complete the matching of v2 to v1." << '\n';
}

// Read five names into a vector<string> name, 
// then prompt the user for the ages of the people named and store the ages in a vector<double> age.
// Then print out the five(name[i], age[i]) pairs.Sort the names(sort(name.begin(), name.end())) and print out the(name[i], age[i]) pairs.
// exercise_8:Do the previous exercise but allow an arbitrary number of names.
void exercise_7()
{
	vector<string> name { "Strang", "Orwell", "Huxley", "Stroustrup", "Marx", "Courant"};
	vector<unsigned int> age{ 92, 47, 69, 76, 65, 84 };

	init_name(name);
	init_age(name, age);

	cout << "Pairs:" << '\n';
	print_pairs(name, age);
	sort_and_match(name, age);
	cout << "Pairs after sort:" << '\n';
	print_pairs(name, age);
}

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
void exercise_9()
{
	vector<double> price{ 1.5, 3.0, 100, 50 };
	vector<double> weight{ 50, 25, 0.1, 0.8 };
	print_pairs(price, weight);
	cout << "value == " << calculate_value(price, weight) << '\n';
}

// fuction for exercise_10
double maxv(const vector<double>& v)
{
	if_empty_vector(v);
	double max = v[0];
	for (double x : v)
	{
		if (x > max)
			max = x;
	}
	return max;
}

// Write a function maxv() that returns the largest element of a vector argument.
void exercise_10()
{
	vector<double> v{ 1.0, 0.99999, 1.000001, 0.5, 1.05 - 1, };
	double max = maxv(v);
	cout.precision(10);
	cout << "The max num of the vector is " << max << '\n';
}

struct vector_values
{
	double smallest;
	double largest;
	double median;
	double mean;
};

// function for exercise_11
// 计算数组的最大、最小、中位数、平均数。
vector_values get_vector_values(vector<double> v)
{
	if_empty_vector(v);
	double median;
	double mean;
	double sum = 0;
	sort(v.begin(), v.end());
	for (double x : v)
	{
		//if (largest < x)
		//	largest = x;
		//if (smallest > x)
		//	smallest = x;
		sum += x;
	}
	mean = sum / v.size();
	if (v.size() % 2 == 0)
		median = (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2;
	else
		median = v[v.size() / 2];
	vector_values vv;
	vv.largest = v[v.size() - 1];
	vv.smallest = v[0];
	vv.median = median;
	vv.mean = mean;
	return vv;
}

// Write a function that finds the smallest and the largest element of a vector argument 
// and also computes the mean and the median.
void exercise_11()
{
	vector<double> v{ -1, 1, 0, 2, 8, -4};
	vector_values vv = get_vector_values(v);

	cout << "largest == " << vv.largest << '\n'
		<< "smallest == " << vv.smallest << '\n'
		<< "median == " << vv.median << '\n'
		<< "mean == " << vv.mean << '\n';
}

// function for exercise_12
void print_until_ss(const vector<string>& v, const string& quit)
// print until the string called "quit" is found
{
	unsigned int count = 0;
	for (string s : v) {
		if (s == quit)
		{
			++count;
			if (count > 1)
				return;
		}
		cout << s << '\n';
	}
}

// Improve print_until_s() from §7.4.2.
// Then, write a print_until_ss() that prints until it sees a second occurrence of its quit argument.
void exercise_12()
{
	vector<string> s{ "Strang", "Orwell", "Huxley", "Stroustrup", "Marx", "Courant", "quit"};
	init_name(s);
	print_until_ss(s, "quit");
}

struct string_numbers
{
	size_t longest;
	size_t shortest;
	vector<size_t> numbers;
};

string_numbers get_string_numbers(const vector<string>& s)
{
	if_empty_vector(s);
	string_numbers s_nums;
	size_t longest = s[0].size();
	size_t shortest = s[0].size();
	size_t each_size;
	vector<size_t> numbers;
	for (string x : s)
	{
		each_size = x.size();
		s_nums.numbers.push_back(each_size);
		if (longest < each_size)
			longest = each_size;
		if (shortest > each_size)
			shortest = each_size; 
	}
	s_nums.longest = longest;
	s_nums.shortest = shortest;
	return s_nums;
}

// function for exercise_13
void print_vector(const string& s, const vector<size_t>& v)
{
	if_empty_vector(v);
	cout << s << '\n';
	for (int x : v)
		cout << x << '\n';
}

// Write a function that takes a vector<string> argument and returns a vector<int> containing the number of characters in each string.
// Also find the longest and the shortest string and the lexicographically first and last string.
void exercise_13()
{
	vector<string> s{ "Strang", "Orwell", "Huxley", "Stroustrup", "Marx", "Courant", "quit" };
	string_numbers s_nums = get_string_numbers(s);
	print_vector("数组的各个字符串的字符数", s_nums.numbers);
}