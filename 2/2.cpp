module _2;

import std;
using namespace std;

//打招呼
void e2_1()
{
	std::cout << "Please enter your first name:\n";
	std::string first_name;
	std::cin >> first_name;
	std::cout << "Hello," << first_name << "!\n";
}

//年龄转换成月份
void e2_3()
{
	cout << "Please enter your first name and age\n";
	string first_name = "???";
	double age = -1;
	cin >> first_name >> age;
	cout << "Hello, " << first_name << "(age " << age * 12 << " months)\n";		//Carlos 22; Carlos		22; Car los 22;
}

//比较两个字符串
void e2_4()
{
	//cout << "Please enter a floating-point value: ";
//int n = 0;
//cin >> n;
//cout << "n == " << n
//	<< "\nn+1 == " << n + 1
//	<< "\nthree times n == " << 3 * n
//	<< "\ntwice n == " << n + n
//	<< "\nn squared == " << n * n
//	<< "\nsquare root of n == " << sqrt(n)
//	<< "\nn mod 2 == " << n % 2
//	<< "\nn / 2 * 2 + n % 2 == " << n/2*2+n%2
//	<< '\n';


//cout << "Please enter your first and second name\n";
//string first;
//string second;
//cin >> first >> second;

//string name = first + ' ' + second;
//cout << "Hello, " << name << '\n';


	cout << "Please enter two names\n";
	string first;
	string second;
	cin >> first >> second;
	if (first == second)
		cout << "that's the same name twice\n";
	if (first < second)
		cout << first << " is alphabetically before " << second << '\n';
	if (first > second)
		cout << first << " is alphabetically after " << second << '\n';
}

//输入一串字符，找出重复的字符
//输入：The cat cat jumped
void e2_5()
{
	string previous;
	string current;
	while (cin >> current)		//输入ctrl+z结束循环；cin会跳过空白字符，连续输入空白字符，没有内容会被读取，current一直未被赋值。
	{
		if (previous == current)
			cout << "repeated word: " << current << "\n";
		previous = current;
	}

	//cin >> previous >> current;
	//cout << "previous == " << previous << ", current == " << current << " \n";
}

//输入一串字符串，找出连续的相同字符串的位置
//输入：She she laughed "he he he!" because what he did did not look very very good good
void e2_5_3()
{
	int number_of_words = 0;
	string previous;
	string current;
	while (cin >> current)
	{
		++number_of_words;
		if (previous == current)
			cout << "word number " << number_of_words << " repeated: " << current << "\n";
		previous = current;
	}
}

//使用字符串类型自带的的.size()函数
void e2_6()
{
	std::string s = "Goodbye, cruel world! ";
	std::cout << s << ", siez = " << s.size() << '\n';
}

//输入双精度浮点数，打印与它数值相同的整数、字符类型的输出结果
//输入：2， 3， 127， 1000， -5， 56， 89， 128， 56.9， 56.2
void e2_9()
{
	double d = 0;
	while (std::cin >> d)
	{
		int i = d;
		char c = i;
		std::cout << "d==" << d
			<< " i==" << i
			<< " c==" << c
			<< " char(" << c << ")\n";
	}
}