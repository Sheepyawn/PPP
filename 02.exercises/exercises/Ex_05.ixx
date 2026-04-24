export module Ex_05;

export void Ex_05();

import std;
using namespace std;

//对输入的两个浮点数做四则运算
void Ex_05()
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