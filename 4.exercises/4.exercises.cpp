module exercises;

import std;
using namespace std;

double ctok(double c)
{
	//int k = c + 273.25;
	//return int
	if (c < -273.15)
	{
		cout << "I don't think that's a right value." << '\n';
		return -1;
	}
	return c + 273.15;
}

double ktoc(double k)
{
	if (k < 0)
	{
		cout << "I dont' think that's a right value." << "\n";
		return -300;
	}
	return k - 273.15;
}

//摄氏度和开氏度的转换
void exercise2()
{
	double t = 0;
	char m = '\t';
	std::cout << "Input a temperature in Celsius(C) or Kelvin(K) and I'll convert it to the other." << '\n';
	cin >> t >> m;
	switch (m)
	{
	case 'C':
	{
		double k = ctok(t);
		if (k == -1)
			cout << "Your input must be greater than -273.15C!" << '\n';
		else
			cout << "It's " << k << "K" << '\n';
		break;
	}
	case 'K':
	{
		double c = ktoc(t);
		if (c == -300)
			cout << "Your input must be greater than 0K!" << '\n';
		else
			cout << "It's " << c << "C" << '\n';
		break;
	}
	default:
	{
		cout << "You must enter a value with the suffix of 'C' or 'K'!";
		break;
	}
	}	
}


//求一元二次方程的根
void exercise7()
{
	cout << "Please enter a, b, c for ax²+ bx +c = 0, and I' ll print the roots of the equation." << '\n';
	double a, b, c;
	cin >> a >> b >> c;
	cout << "The quadratic eqaution is \"" << a << "x² + " << b << "x + " << c << " = 0\"." << '\n';
	double θ;
	θ = b * b - 4 * a * c;
	if (θ < 0)
		cout << "The equation has no real roots. Sorry I can't solve this equation." << '\n';
	else
	{ 
		double sqθ = sqrt(θ);
		double x1, x2;
		if (θ == 0)
		{
			x1 = (-b + sqθ) / (2 * a);
			cout << "It has a double root at " << x1 << '\n';
		}
		else
		{
			x1 = (-b + sqθ) / (2 * a);
			x2 = (-b - sqθ) / (2 * a);
			cout << "Its roots are " << x1 << " and " << x2 << '\n';
		}
	}
}


//输入一串数字，求前n个数的和。
void exercise8()
{
	cout << "Please enter some integers(press '|' to stop): " << '\n';
	vector<double> v;
	vector<double> differences;
	differences.push_back(0);
	double previous = 0, difference = 0;
	char c = ' ';
	int n = -1;

	while (c != '|')
	{
		if (cin >> n)
		{
			v.push_back(n);
			difference = n - previous;
			differences.push_back(difference);
			previous = n;
		}
		else
		{
			cin.clear();
			cin >> c;
			if (c != '|')
				cout << "That's not an integer! If you want to stop input, enter '|'." << '\n';
		}
	}

	//打印所有输入的数
	cout << "Integers you have entered: " << '\n';
	size_t size = v.size();
	for (int i = 0; i < size; ++i)
		cout << v[i] << '\n';
	cout << "That's " << size << "numbers in total." << '\n';

	cout << "Pleasee enter the number of values you want to sum: " << '\n';
	int number = 0;
	double sum = 0;

	bool b = true;
	while (b)
	{
		if (cin >> number)
		{
			if (number > size)
				cout << "That's more than the integers you have entered: " << size << " , Please think of another number." << '\n';
			else if (number < 0)
				cout << "The numbers should be greater than 0! Please think of another number." << '\n';
			else
				b = false;
		}
		else
		{
			cin.clear();
			cin >> c;
			cout << "That's not an integer! Please enter an integer." << '\n';
		}

	}
	cout << "The sum of the first " << number << " numbers ( ";
	for (int i = 0; i < number; ++i)
	{
		cout << v[i] << " ";
		sum += v[i];
	}
	cout << ")is " << sum << '\n';

	//输出difference数组--其中每个元素的值等于v数组位置对应的值与其前一个值的差
	cout << "differences：" << '\n';
	for (int i = 0; i < size; ++i)
	{
		cout << "v[" << i + 1 << "] - v[" << i << "] == " << differences[i + 1] << '\n';
	}
}


//Fibonacci series
void exercise11()
{
	cout << "How many terms do you want to request of a Fibonacci series?" << '\n';
	int num = -1;
	bool b = false;
	string s = "-1";
	
	while (!b)
	{
		if (cin >> num)
		{
			if (num < 1)
				cout << "Your enter value should be greater than 0!" << '\n';
			else
				b = true;
		}
		else
		{
			cin.clear();
			cin >> s;
			cout << "You should enter an integer!" << '\n';
		}
	}
	if (num == 1)
		cout << "The first term of Fibonacci series is 0" << '\n';
	else if (num == 2)
		cout << "The first 2 terms of Fibonacci series are 0 and 1" << '\n';
	else
	{
		vector<int> Fibonacci;
		int term = -1;
		Fibonacci.push_back(0);
		Fibonacci.push_back(1);
		for (int i = 2; i < num; ++i)
		{
			term = Fibonacci[i - 1] + Fibonacci[i - 2];
			Fibonacci.push_back(term);
		}

		cout << "The first " << num << " terms of Fibonacci series are:\n";
		for (int i = 0; i < Fibonacci.size(); ++i)
			cout << Fibonacci[i] << '\n';
	}
}


//"Bulls and Cows"。 猜4位不重复的数字组合，返回“Bull”或者“Cow”。
//“Bull”代表数字正确且位置正确；“Cow”代表数字正确，但位置不正确。
void exercise12()
{
	//生成4位不重复数字组合
	vector<char> target;
	time_t seconds = time(0);
	default_random_engine engine(seconds);
	uniform_int_distribution<int> dist(48, 57);
	int random_num = '#';
	bool different = true;
	for (int i = 0; i < 4; ++i)
	{
		//检查是否和已插入数字重复
		random_num = char(dist(engine));
		for (char& x : target)
		{
			if (random_num == x)
			{
				different = false;
				break;
			}
		}
		if (different)
		{
			target.push_back(random_num);
		}
		else
		{
			--i;
			different = true;
		}	
	}
	cout << "Random number is ready!" << '\n';

	//透视
	//cout << "The target is:";
	//for (int i = 0; i < target.size(); ++i)
	//	cout << target[i];
	//cout << '!' << '\n';

	cout << "Bulls and Cows! Have a try to guess my number." << '\n'
		<< "You get a 'Bull' for each digit that is correct and in the correct position." << '\n'
		<< "You get a 'Cow' for each digit that is correct but in the wrong position." << '\n'
		<< "Please enter a 4-digit number with different digits." << '\n';
	
	//
	vector<char> input;
	int count = 1;
	bool incorrect = true;
	bool valid_input = false;
	int Bull = 0;
	int Cow = 0;
	while (incorrect)
	{
		//输入数据
		string s = " ";
		std::cin >> s;
		if (s.size() != 4)
		{
			cout << "Invalid input. Your number should have exactly 4 digits." << '\n';
			continue;
		}
		else
		{
			for (int i = 0; i < 4; ++i)
			{
				//检查每位输入是否是0到9
				if (s[i] < '0' || s[i] > '9')
				{
					cout << s[i] << "is not a number." << '\n';
					break;
				}
				//检查每位输入是否已重复
				for (char& x : input)
				{
					if (s[i] == x)
					{
						different = false;
						break;
					}
				}
				if (different)
					input.push_back(s[i]);
				else
				{
					cout << "Invalid input. All digits must be different." << '\n';
					break;
				}
			}
		}

		//for (char& c : input)
		//	std::cout << c << '\n';
		if (input.size() == 4)
			valid_input = true;

		//核对答案
		if (valid_input)
		{
			for (int i = 0; i < 4; ++i)
			{
				//因为4位各不相同，所以直接找是否有相同的。
				for (char& x : target)
				{
					if (input[i] == x)
						++Cow;
				}
				if (input[i] == target[i])
				{
					++Bull;
					--Cow;
				}
			}
			cout << Bull << " Bull and " << Cow << " Cow" << '\n';

			if (Bull == 4)
				break;
		}

		//恢复默认值
		different = true;
		valid_input = false;
		input.clear();
		cin.clear();		//单独输入ctrl+z会使cin为错误状态，程序进入死循环。
		Cow = 0;
		Bull = 0;
		++count;
	}
	cout << "Bravo! You guessed it! ";
	for (char& c : target)
		cout << c;
	cout << " is the right answer!\n" << "Rounds you have spent: " << count << '\n';
}


//读入多对数据，计算特殊名称对应的值之和。
void exercise14()
{
	vector<string> day_of_the_week
	{"Monday", "Mon.", "Tuesday", "Tues.", "Wednesday", "Wed.",
	"Thursday", "Thur.", "Friday", "Fri.", 
	"Saturday", "Sat.", "Sunday", "Sun."};

	vector<string> days;
	vector<int> values;
	string s;
	string num;
	int number = 0;
	bool no_stop = true;
	bool is_integer = true;
	bool is_negative = false;

	cout << "Enter a set of string and value pairs, but only the day of the week string's value will be summed up." << '\n'
		<< "Enter 'Stop!' to end input." << '\n';

	//输入数据
	while (no_stop)
	{
		cin >> s;
		if (s == "Stop!")
			break;

		cout << "You have entered a string. Now enter its value." << '\n';
		cin >> num;

		for (int i = 0; i < num.size(); ++i)
		{
			if (num[0] == '-' && num.size() > 1)
			{
				is_negative = true;
				continue;
			}
			if (num[i] < '0' || num[i] > '9')
			{
				cout << num << " is not an integer. Please enter another pair." << '\n';
				is_integer = false;
				break;
			}
		}

		//存数据
		if (is_integer)
		{
			int digit = 1;
			if (is_negative)
			{
				for (int i = num.size() -1; i > 0; --i)
				{
					number += (num[i] - '0') * digit;
					digit *= 10;
				}
				number = -number;
			}
			else
			{
				for (int i = num.size() - 1; i > -1; --i)
				{
					number += (num[i] - '0') * digit;
					digit *= 10;
				}
			}
			values.push_back(number);
			days.push_back(s);

			cout << "A pair has been input. You can enter another one." << '\n'
				<< "If you want to end input, enter 'Stop!'." << '\n';

			//for (int i = 0; i < days.size(); ++i)
			//{
			//	cout << "days == " << days[i] << ", value == " << values[i] << '\n';
			//}
		}
		number = 0;
		is_integer = true;
		is_negative = false;
	}
	//比较数据，输出
	int rejected = 0;
	int sum = 0;
	bool match = false;
	for (int i = 0; i < days.size(); ++i)
	{
		for (string& s : day_of_the_week)
		{
			if (days[i] == s)
			{
				match = true;
				break;
			}
		}
		if (match)
			sum += values[i];
		else
			++rejected;

		match = false;
	}
	cout << "The sum of the day-of-the-week values is " << sum << '.' << '\n'
		<< rejected << " numbers have been rejected." << '\n';
}