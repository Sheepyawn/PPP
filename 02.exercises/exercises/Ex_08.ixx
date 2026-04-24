export module Ex_08;

export void Ex_08();

import std;
using namespace std;

//判断输入数的奇偶
export void Ex_08()
{
	cout << "Please enter an integer value." << endl;
	int val1;
	cin >> val1;

	//int val2 = val1 / 2 * 2;
	//if (val1 != val2)

	if (val1 % 2 != 0)
		cout << "The value " << val1 << " is an odd number.";
	else
		cout << "The value " << val1 << " is an even number.";
	cout << endl;
}