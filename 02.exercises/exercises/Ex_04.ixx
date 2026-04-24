export module Ex_04;

export void Ex_04();

import std;
using namespace std;

//对输入的两个整数做四则运算
void Ex_04()
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