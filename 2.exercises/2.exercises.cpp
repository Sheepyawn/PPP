module exercises;

import std;
using namespace std;

//把英里转换为千米
void exercise2()
{
	std::cout << "Please enter miles and I'll convert it to kilometers.\n";
	float miles;
	std::cin >> miles;
	miles = miles * 1.609;
	std::cout << "It's " << miles << " kilometers.";
}

//对输入的两个整数做四则运算
void exercise4()
{
	cout << "Please enter two integer values." << endl;
	int val1, val2;
	cin >> val1 >> val2;
	if (val1 < val2)
		cout << val1 << " is smaller than " << val2;
	else if (val1 > val2)
		cout << val1 << " is larger than " << val2;
	else
		cout << val1 << " equals " << val2;
	cout << endl;
	int sum = val1 + val2;
	int difference = val1 - val2;
	int product = val1 * val2;
	int ratio = val1 / val2;		//这里定义ratio为flaot,得到的结果仍是整数。因为val1和val2是整数，执行的是整数除法，结果也是整数。

	cout << val1 << " + " << val2 << " == " << sum << endl
		<< val1 << " - " << val2 << " == " << difference << endl
		<< val1 << " * " << val2 << " == " << product << endl
		<< val1 << " / " << val2 << " == " << ratio << endl;
}

//对输入的两个浮点数做四则运算
void exercise5()
{
	cout << "Please enter two integer values." << endl;
	float val1, val2;
	cin >> val1 >> val2;
	if (val1 < val2)
		cout << val1 << " is smaller than " << val2;
	else if (val1 > val2)
		cout << val1 << " is larger than " << val2;
	else
		cout << val1 << " equals " << val2;
	cout << endl;
	float sum = val1 + val2;
	float difference = val1 - val2;
	float product = val1 * val2;
	float ratio = val1 / val2;

	cout << val1 << " + " << val2 << " == " << sum << endl
		<< val1 << " - " << val2 << " == " << difference << endl
		<< val1 << " * " << val2 << " == " << product << endl
		<< val1 << " / " << val2 << " == " << ratio << endl;
}

//排序输入的3个整数
void exercise6()
{
	cout << "Please enter three integer values." << endl;
	int v1, v2, v3;
	cin >> v1 >> v2 >> v3;
	//if (v1 < v2)
	//{
	//	if (v1 < v3)	
	//	{
	//		if (v2 < v3)	//v1 < v2 < v3
	//			;
	//		else            //v1 < v3 < v2
	//			std::swap(v2, v3);
	//	}
	//	else                //v3 < v1 < v2
	//	{
	//		std::swap(v1, v3);
	//		std::swap(v2, v3);
	//	}
	//}
	//else
	//{
	//	if (v2 < v3)        
	//	{
	//		if (v1 < v3)	//v2 < v1 < v3
	//			std::swap(v1, v2);
	//		else            //v2 < v3 < v1
	//		{
	//			std::swap(v1, v2);
	//			std::swap(v2, v3);
	//		}
	//	}
	//	else               //v3 < v2 < v1
	//	{
	//		std::swap(v1, v3);
	//	}
	//}

	if (v1 > v2) swap(v1, v2);
	if (v1 > v3) swap(v1, v3);
	if (v2 > v3) swap(v2, v3);

	cout << v1 << ", " << v2 << ", " << v3 << endl;
}

//排序输入的3个字符串
void exercise7()
{
	cout << "Please enter three string values." << endl;		//Steinbeck, Hemingway, Fitzgerald,
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	if (s1 > s2)swap(s1, s2);
	if (s1 > s3)swap(s1, s3);
	if (s2 > s3)swap(s2, s3);
	cout << s1 << ", " << s2 << ", " << s3 << endl;
}

//判断输入数的奇偶
void exercise8()
{
	cout << "Please enter an integer value." << endl;
	int val1;
	cin >> val1;
	
	//int val2 = val1 / 2 * 2;
	//if (val1 != val2)

	if(val1 % 2 != 0)
		cout << "The value " << val1 << " is an odd number.";
	else
		cout << "The value " << val1 << " is an even number.";
	cout << endl;
}

//输入1到4的拼写，打印这个数。
void exercise9()
{
	cout << "Please enter a spelled-out number." << endl;
	string s;
	cin >> s;
	if (s == "zero")
		cout << "You have entered 0!" << endl;
	else if (s == "one")
		cout << "You have entered 1!" << endl;
	else if (s == "two")
		cout << "You have entered 2!" << endl;
	else if (s == "three")
		cout << "You have entered 3!" << endl;
	else if (s == "four")
		cout << "You have entered 4!" << endl;
	else
		cout << "Not a number I know. :(" << endl;
}

//四则运算
void exercise10()
{
	cout << "Please enter an integer, an operand and an integer." << endl;
	int v1, v2;
	string operation;
	cin >> v1 >> operation >> v2;
	if (operation == "+")
		cout << v1 << " + " << v2 << " == " << v1 + v2;
	else if (operation == "-")
		cout << v1 << " - " << v2 << " == " << v1 - v2;
	else if (operation == "*")
		cout << v1 << " * " << v2 << " == " << v1 * v2;
	else if (operation == "/")
		cout << v1 << " / " << v2 << " == " << v1 / v2;
	else
		cout << "You are kidding!";
	cout << endl;
}

//计算不同的硬币的总价值
void exercise11()
{
	int pennies, nickels, dimes, quarters, half_dollars, one_dollars;

	cout << "How many pennies do you have?" << endl;
	cin >> pennies;
	cout << "How many nickels do you have?" << endl;
	cin >> nickels;
	cout << "How many dimes do you have?" << endl;
	cin >> dimes;
	cout << "How many quarters do you have?" << endl;
	cin >> quarters;
	cout << "How many half_dollars do you have?" << endl;
	cin >> half_dollars;
	cout << "How many one_dollars do you have?" << endl;
	cin >> one_dollars;

	cout << "You have " << pennies;
	if (pennies == 1)
		cout << " penny." << endl;
	else
		cout << " pennies." << endl;

	cout << "You have " << nickels;
	if (nickels == 1)
		cout << " nickel." << endl;
	else
		cout << " nickels." << endl;

	cout << "You have " << dimes;
	if (dimes == 1)
		cout << " dime." << endl;
	else
		cout << " dimes." << endl;

	cout << "You have " << quarters;
	if (quarters == 1)
		cout << " quarter." << endl;
	else
		cout << " quarters." << endl;

	cout << "You have " << half_dollars;
	if (half_dollars == 1)
		cout << " half_dollar." << endl;
	else
		cout << " half_dollars." << endl;

	cout << "You have " << one_dollars;
	if (one_dollars == 1)
		cout << " one_dollar." << endl;
	else
		cout << " one_dollars." << endl;

	float value = pennies + 5 * nickels + 10 * dimes + 25 * quarters + 50 * half_dollars + 100 * one_dollars;
	value = value / 100;
	cout << "The value of all of your coins is " << value << "dollars" << endl;
}
