module drill;

import std;
using namespace std;

//注释部分是原题目，改正后控制台显示输出结果“Success!”

void drill_1()
{
	//Cout << "Success!\n";
	cout << "Success!";
}

void drill_2()
{
	//cout << "Success!\n;
	cout << "Success!\n";
}

void drill_3()
{
	//cout << "Success" << !\n"
	cout << "Success" << "!\n";
}

void drill_4()
{
	//cout << success << '\n';

	string success = "Success!\n";
	cout << success;
}

void drill_5()
{
	//string res = 7;
	//vector<int> v(10);
	//v[5] = res;
	//cout << "Success!\n";

	string res = "7";
	vector<string> v(10);
	v[5] = res;
	cout << "Success!\n";
}

void drill_6()
{
	//vector<int> v(10);
	//v(5) = 7;
	//if (v(5) != 7)
	//	cout << "Success!\n";

	vector<int> v(10);
	v[5] = 7;
	if (v[5] == 7)
		cout << "Success!\n";
}

void drill_7()
{
	//if (cond)
	//	cout << "Success!\n";
	//else cout << "Fail\n";

	if (cout)
		cout << "Success!\n";
	else cout << "Fail\n";
}

void drill_8()
{
	//bool c = false;
	//if (c)
	//	cout << "Success!\n";
	//else cout << "Fail!\n";

	bool c = false;
	if (!c)
		cout << "Success!\n";
	else cout << "Fail!\n";
}

void drill_9()
{
	//string s = "ape";
	//boo c = "fool" < s;
	//if (c)
	//	cout << "Success!\n";

	string s = "ape";
	bool c = "fool";
	if (c)
		cout << "Success!\n";
}

void drill_10()
{
	//string s = "ape";
	//if (s == "fool")
	//	cout << "Success!\n";

	string s = "ape";
	if (s != "fool")
		cout << "Success!\n";
}

void drill_11()
{
	//string s = "ape";
	//if (s == "fool")
	//	cout < "Success!\n";

	string s = "ape";
	if (s != "fool")
		cout << "Success!\n";
}

void drill_12()
{
	//string s = "ape";
	//if (s + "fool")
	//	cout < "Success!\n";

	string s = "ape";
	s = s + "fool";
	if (s != "ape")
		cout << "Success!\n";
}

void drill_13()
{
	//vector<char> v(5);
	//for (int i = 0; 0 < v.size(); ++i);
	//cout << "Success!\n";

	vector<char> v(5);
	for (int i = 0; i < v.size(); ++i)
		cout << "Success!\n";
}

void drill_14()
{
	//vector<char> v(5);
	//for (int i = 0; i <= v.size(); ++i);
	//cout << "Success!\n";

	vector<char> v(5);
	for (int i = 0; i < v.size(); ++i)
		cout << "Success!\n";
}

void drill_15()
{
	//string s = "Success!\n";
	//for (int i = 0; i < 6; ++i)
	//	cout << s[i];

	string s = "Success!\n";
	for (int i = 0; i < 9; ++i)
		cout << s[i];
}

void drill_16()
{
	//if (true)
	//	then
	//	cout << "Success!\n";
	//else cout << "Fail!\n";

	if (true)
		cout << "Success!\n";
	else cout << "Fail!\n";
}

void drill_17()
{
	//int x = 2000;
	//char c = x;
	//if (c == 2000)
	//	cout << "Success!\n";

	int x = 2000;
	char c = x;
	if (c != 2000)
		std::cout << "Success!\n";
}

void drill_18()
{
	//string s = "Success!\n";
	//for (int i = 0; i < 10; ++i)
	//	cout << s[i];

	string s = "Success!\n";
	for (int i = 0; i < 10; ++i)
		cout << s[i];
}

void drill_19()
{
	//vector v(5);
	//for (int i = 0; i <= v.size(); ++i);
	//cout << "Success!\n";

	vector<int> v(5);
	for (int i = 0; i <= v.size(); ++i)
		cout << "Success!\n";
}

void drill_20()
{
	//int i = 0; int j = 9; 
	//while (i < 10)
	//	++j;
	//if (j < i)
	//	cout << "Success!\n";

	int i = 0; int j = 9; 
	while (i < 10)
		++i;
	if (j < i)
		cout << "Success!\n";
}

void drill_21()
{
	//int x = 2;
	//double d = 5 / (x - 2);
	//if (d == 2 * x + 0.5)
	//	cout << "Success!\n";

	int x = 2;
	double d = 5 / double(x) + 2;
	if (d == 2 * x + 0.5)
		cout << "Success!\n";
}

void drill_22()
{
	//string<char> s = "Success!\n";
	//for (int i = 0; i <= 10; ++i)
	//	cout << s[i];

	string s = "Success!\n";
	for (int i = 0; i < s.size(); ++i)
		cout << s[i];
}

void drill_23()
{
	//int i = 0;
	//while (i < 10)
	//	++j;
	//if (j < i)
	//	cout << "Success!\n";

	int i = 0;
	while (i < 10)
		++i;
	if (5 < i)
		cout << "Success!\n";
}

void drill_24()
{
	//int x = 4;
	//double d = 5 / (x - 2);
	//if (d = 2 * x + 0.5)
	//	cout << "Success!\n";

	int x = 4;
	double d = 5 / double(x - 2);
	if (d + 6 == 2 * x + 0.5)
		std::cout << "Success!\n";
}

void drill_25()
{
	//cin << "Success!\n";

	cout << "Success!\n";
}