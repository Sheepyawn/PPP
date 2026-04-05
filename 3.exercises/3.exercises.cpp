module exercises;

import std;
using namespace std;

//输入字符串，遍历打印其每个字符和对应的ASCII值
void exercise2()
{
	std::cout << "Please enter a string" << endl;
	string s;
	cin >> s;
	for (char c : s)
		cout << c << '\t' << int(c) << endl;
}

//打印中位数
void exercise3()
{
	vector<double> temps;
	for (double temp; cin >> temp;)
		temps.push_back(temp);

	double sum = 0;
	for (double x : temps)
		sum += x;
	cout << "Average temperature: " << sum / temps.size() << '\n';

	ranges::sort(temps);
	cout << "Median temperature: ";
	if (temps.size() % 2 != 0)
		cout << temps[temps.size() / 2] << '\n';
	else
		cout << (temps[temps.size() / 2 - 1] + temps[temps.size() / 2]) / 2 << endl;
}

//输入一组城市间的距离，打印最短、最长和平局距离
void exercise4()
{
	cout << "Please enter the distances between two neibouring cities." << endl;
	vector<double> distances;
	double distance;
	
	if (!(cin >> distance))
	{
		cout << "You haven't entered a value!" << endl;
		return;
	}
	distances.push_back(distance);
	double smallest = distance; 
	double greatest = distance;
	double sum = distance;

	while (cin >> distance)
	{
		distances.push_back(distance);
		if (distance > greatest)
			greatest = distance;
		else if (distance < smallest)
			smallest = distance;

		sum += distance;
	}

	cout << "The greatest distance between two neibouring cities is " << greatest << endl
		<< "The smallest distance between two neibouring cities is " << smallest << endl
		<< "The mean distance between two neibouring cities is " << sum / distances.size() << endl;
}

//1到100猜数字
void exercise5()
{
	cout << "Think a number between 1 and 100 and I'll try to figure it out." << endl;
	int low = 1, high = 100, mid;
	char answer;

	while (low < high)
	{
		mid = (low + high + 1) / 2;
		cout << "Is the number smaller than " << mid << " ? (y/n)" << endl;
		cin >> answer;
		if (answer == 'y')
			high = mid - 1;
		else if (answer == 'n')
			low = mid ;
		else
			cout << "I don't understand your input, please enter 'y' or 'n'." << endl;
	}
	cout << "The number must be " << low << " !" << endl;
}

//遍历1到100检查上一个函数
void check_exercise5()
{
	for (int i = 1; i < 100; i++)
	{
		int low = 1, high = 100, mid;
		while (low < high)
		{
			mid = (low + high + 1) / 2;
			if (i < mid)
				high = mid - 1;
			else
				low = mid;
		}
		if (low != i)
			cout << "Found a problem, the input number is " << i << endl;
	}
}

//简易四则运算
void exercise6()
{
	cout << "Please enter two values and an operator.(+, -, *, /)" << endl;
	double v1, v2;
	char op;
	cin >> v1 >> v2 >> op;
	if (op == '+')
		cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2;
	else if (op == '-')
		cout << "The difference between " << v1 << " and " << v2 << " is " << v1 - v2;
	else if (op == '*')
		cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2;
	else if (op == '/')
		cout << "The division of " << v1 << " and " << v2 << " is " << v1 / v2;
	else
		cout << "Sorry I don't understand that operator.";
		cout << endl;
}

//拼写0到9的数字
void exercise7()
{
	vector<string> nums{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	int num;

	cout << "Please enter an integer between 0 and 9 and I'll spell it out" << '\n';
	cin >> num;
	if (num < 0 || num > 9)
		cout << "I can only spell the integer between 0 and 9" << '\n';
	else
		cout << "It's " << nums[num] << '\n';
}

//国王赏不起的米。给1000、1000000、1000000000粒米要多少个格子
void exercise9()
{
	int sum = 0;
	int square = 0, grain = 1;
	for (int i = 1000; i <= 1000000000; i *= 1000)
	{
		while (sum < i)
		{
			++square;
			sum = sum + grain;
			grain *= 2;
			cout << square << " squares of grains amonut to " << sum << '\n';
		}
		cout << "To give the inventor at least " << i << " grains, " << square << " squares are needed." << '\n';
		if (i == 1000000000)
			break;
	}
}

//研究double打印64个格子的米的精度
void exercise10()
{
	//int sum = 0;
	double sum = 0;

	//int grain = 1;
	double grain = 1;
	
	for (int square = 1; square < 65; ++square)
	{
		sum += grain;
		grain *= 2;
		cout << square << "squares of grains amount to " << sum << '\n';
	}
}

//剪刀石头布
void exercise11()
{
	cout << "Please enter '0' to represent 'Rock', '1' to represent 'Paper'and '2' to represent 'Scissors'.(Enter a character to exit.)" << '\n';
	int input;	

	clock_t start_time = clock();
	clock_t current_time;
	int duration;

	string result;
	int win = 0, lose = 0, draw = 0;

	while (cin >> input)
	{
		current_time = clock();
		duration = (current_time - start_time);
		duration %= 3;

		switch (input)
		{
			case 0:
				switch (duration)
				{
					case 0:
						result = "Draw";
						++draw;
						break;

					case 1:
						result = "You Lose";
						++lose;
						break;

					case 2:
						result = "You Win";
						++win;
						break;
				}
				break;

			case 1:
				switch (duration)
				{
					case 0:
						result = "You Win";
						++win;
						break;

					case 1:
						result = "Draw";
						++draw;
						break;

					case 2:
						result = "You Lose";
						++lose;
						break;
				}
				break;

			case 2:
				switch (duration)
				{
				case 0:
					result = "You Lose"; 
					++lose;
					break;

				case 1:
					result = "You Win";
					++win;
					break;

				case 2:
					result = "Draw";
					++draw;
					break;
				}
				break;

			default:
				result = "Please enter 0, 1, or 2.";
				break;
		}
		cout << result << '\n';
	}

	cout << "You have won " << win << " times, "
		<< "drawn " << draw << " times, "
		<< "lost " << lose << " times.";
}

//找出1到100的质数
void exercise12()
{
	vector<int> primes = { 2 };
	bool is_prime;

	for (int i = 2; i < 101; ++i)
	{
		is_prime = true;
		for (int j = 0; j < primes.size(); ++j)
		{
			if (i % primes[j] == 0)
			{
				is_prime = false;
				break;
			}
		}
		if (is_prime)
			primes.push_back(i);
	}
	cout << "prime numbers between 0 and 100:" << '\n';
	for (int i = 0; i < primes.size(); ++i)
		cout << primes[i] << '\n';
}

//找出前n个自然数
void exercise14()
{
	cout << "Enter a num and I'll return the first n primes." << '\n';
	int n;
	cin >> n;

	vector<int> primes = { 2 };
	bool is_prime;

	for (int i = 2; primes.size() < n; ++i)
	{
		is_prime = true;
		for (int j = 0; j < primes.size(); ++j)
		{
			if (i % primes[j] == 0)
			{
				is_prime = false;
				break;
			}
		}
		if (is_prime)
			primes.push_back(i);
	}
	cout << "The first " << n << " primes are: " << '\n';
	for (int i = 0; i < n; ++i)
		cout << primes[i] << '\n';
}

//找众数
void exercise15()
{
	cout << "Please enter a set of integers." << '\n';
	vector<int> nums;
	vector<int> groups;			//相同的值
	vector<int> group_value;	//相同的值的个数，两个vector数组下标对应。
	bool is_match;

	for (int num; cin >> num;)
	{
		nums.push_back(num);
		is_match = false;

		//遍历groups，查找是否有与输入值相等的值。有就把值的个数加一；没有就添加输入值进vector。
		for (int i = 0; i < groups.size(); ++i)
		{
			if (num == groups[i])
			{
				++group_value[i];
				is_match = true;
				break;
			}
		}
		if (!is_match)
		{
			groups.push_back(num);
			group_value.push_back(1);
		}
	}

	if (groups.size() < 1)
		cout << "You haven't entered an integer!" << '\n';
	else
	{
		int location = -1;

		int frequency = 0;
		for (int i = 0; i < group_value.size(); ++i)
			if (frequency < group_value[i])
			{
				frequency = group_value[i];
				location = i;
			}

		//没有处理有多个众数的情况。
		cout << "The integer which appears most is " << groups[location] << ", it appears " << group_value[location] << " times." << '\n';
	}
}

//找出字符串的最小、最大和出现次数最多的单词
void exercise16()
{
	cout << "Please enter a sequence of strings." << '\n';
	vector<string> sequence;
	vector<string> string_group;
	vector<int> string_frequencies;
	bool has_appeared;

	for (string s; cin >> s;)
	{
		sequence.push_back(s);
		has_appeared = false;

		for (int i = 0; i < string_group.size(); ++i)
		{
			if (s == string_group[i])
			{
				++string_frequencies[i];
				has_appeared = true;
				break;
			}
		}
		if (!has_appeared)
		{
			string_group.push_back(s);
			string_frequencies.push_back(1);
		}
	}

	if (string_group.size() < 1)
		cout << "You haven't entered a string!" << '\n';
	else
	{
		int location = -1;
		int more_frequency = 0;
		for (int i = 0; i < string_frequencies.size(); ++i)
		{
			if (more_frequency < string_frequencies[i])
			{
				more_frequency = string_frequencies[i];
				location = i;
			}
		}

		string biggest = " ";
		string smallest = "~";
		for (int i = 0; i < string_group.size(); ++i)
		{
			string s = string_group[i];
			if (biggest < s)
				biggest = s;
			if (smallest > s)
				smallest = s;
		}

		cout << "The min string is " << smallest << '\n'
			<< "The max string is " << biggest << '\n'
			<< "The mod string is " << string_group[location] << '\n';		//没有处理有多个众数的情况。
	}

}

//求一元二次方程的解
void exercise17()
{
	cout << "Please enter a, b and c of a quadratic equation ax² + bx + c = 0." << '\n';
	double a, b, c, θ, solution1, solution2;
	cin >> a >> b >> c;
	θ = b * b - 4 * a * c;

	if (θ > 0)
	{
		cout << "方程有实数解" << '\n';
		solution1 = (-b + sqrt(θ)) / (2 * a);
		solution2 = (-b - sqrt(θ)) / (2 * a);
		cout << "方程的解为：" << '\n'
			<< solution1 << " 和 " << solution2 << '\n';
	}
	else
	{
		cout << "方程没有实数解" << '\n';
		cout << "方程的解为：" << '\n'
			<< -b / (2 * a) << " + " << sqrt(-θ) / (2 * a) << "i" << " 和 "
			<< -b / (2 * a) << " - " << sqrt(-θ) / (2 * a) << "i" << '\n';
	}
}


//输入一对名字和值，检查是否重复输入。
//rework version in Chapter5 exercise4
void exercise18()
{
	cout << "Please enter a set of name-and-value pairs.(Input 'NoName 0' to terminate)" << '\n';
	vector<string> names;
	vector<int> scores;
	string name;
	int value;
	bool duplicate_name;

	while (cin >> name >> value)
	{
		if (name == "NoName" && value == 0)
			break;
		duplicate_name = false;
		
		for (const string &x : names)
		{
			if (name == x)
			{
				duplicate_name = true;
				break;
			}
		}
		if (duplicate_name)
		{
			cout << "It's a duplicate name, you have entered it before." << '\n';
		}
		else
		{
			names.push_back(name);
			scores.push_back(value);
		}
	}
	cout << "You have completed entering!" << "\n";

	for (int i = 0; i < names.size(); ++i)
	{
		cout << names[i] << '\t' << scores[i] << '\n';
	}

	cout << "Input 1 to search by name." << "\n"
		<< "Input 2 to search by value" << "\n"
		<< "Input a character to exit." << "\n";

	int input;
	while (cin >> input)
	{
		switch (input)
		{
		case 1:
		{
			cout << "Please enter the name you want to search:" << '\n';
			string search_name;
			cin >> search_name;
			size_t size = names.size();
			int search_value;
			bool has_found = false;
			for (int i = 0; i < size; ++i)
			{
				if (search_name == names[i])
				{
					search_value = scores[i];
					has_found = true;
					break;
				}
			}
			if (has_found)
				cout << search_name << " 的成绩是 " << search_value << '\n';
			else
				cout << "name not foud" << '\n';
			break;
		}

		case 2:
		{
			cout << "Please enter the value you want to search:" << '\n';
			int search_value;
			cin >> search_value;
			size_t size = scores.size();
			vector<string> search_names;
			for (int i = 0; i < size; ++i)
			{
				if (search_value == scores[i])
				{
					search_names.push_back(names[i]);
				}
			}
			if (search_names.size() < 1)
			{
				cout << "score not found" << '\n';
			}
			else
			{
				cout << "成绩为 " << search_value << " 的人有：" << '\n';
				for (const string &x : search_names)
					cout << x << "\n";
			}
			break;
		}

		default:
			cout << "Sorry I don't understand that." << '\n';
			break;
		}

		cout << "Input 1 to search by name." << "\n"
			<< "Input 2 to search by value" << "\n"
			<< "Input a character to exit." << "\n";
	}
}


