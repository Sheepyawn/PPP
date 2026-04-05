module drill;

import std;
using namespace std;

//打印输入的两个数
void drill_1()
{
	int v1 = 0, v2 = 0;
	std::cout << "Please enter two values." << endl;
	while (cin >> v1 >> v2)
	{
		cout << "v1 == " << v1 << ", v2 == " << v2 << endl;
	}
}

//比较输入的两个数的大小
void drill_2to5()
{
	double v1 = 0, v2 = 0;
	cout << "Please enter two values." << endl;
	while (cin >> v1 >> v2)
	{
		if (v1 == v2)
			cout << "Both numbers are " << v1 << endl;
		else
		{
			if (v1 > v2)
				swap(v1, v2);
			cout << "The smaller value is " << v1 << ", the larger value is " << v2 << endl;
			if (v2 - v1 < 0.01)
				cout << "The numbers are almost equal." << endl;
		}
	}
}

//输入一组不同单位的长度，打印最长、最短、平均长度，输入个数，长度之和
//输入：1m, 10in, 50in, 2ft, 4ft, 5ft, -2m, -100in, -7ft
void drill_6to9()
{
	double v1 = 0, smallest = numeric_limits<double>::max(), largest = numeric_limits<double>::min(), sum = 0;
	string unit;
	int number = 0, l_bit = -1, s_bit = -1;
	vector<double> values;
	vector<string> units;

	cout << "Please enter a value and a unit" << endl;
	while (cin >> v1 >> unit)
	{
		cout << "You have entered " << v1 << unit << endl;

		values.push_back(v1);
		units.push_back(unit);
		
		//全部转换成m单位制
		if (unit == "m"){}

		else if (unit == "cm")
			v1 *= 0.01;
		else if (unit == "in")
			v1 *= 2.54 * 0.01;
		else if (unit == "ft")
			v1 *= 12 * 2.54 * 0.01;
		else
			cout << "Sorry I don't know a unit called " << unit << endl;

		if (v1 > largest)
		{
			largest = v1;
			l_bit = values.size() - 1;
			cout << "It's the largest so far." << endl;
		}
		if (v1 < smallest)
		{
			smallest = v1;
			s_bit = values.size() - 1;
			cout << "It's the smallest so far." << endl;
		}
		sum += v1;
		
	}

	if (values.size() != units.size())
		cout << "值数组和单位数组的大小不等！" << endl;
	else if (values.size() == 0)
		cout << "You haven't entered a value!" << endl;
	else
	{
		for (int i = 0; i < values.size(); ++i)
			cout << "You have entered " << values[i] << units[i] << endl;

		cout << "the smallest number you have entered is " << values[s_bit] << units[s_bit] << endl
			<< "the largest number you have entered is " << values[l_bit] << units[l_bit] << endl
			<< "You have enter " << values.size() << " numbers" << endl
			<< "the sum of numbers that you have entered is " << sum << " m" << endl;
	}
}
