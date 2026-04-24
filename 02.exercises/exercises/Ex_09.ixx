export module Ex_09;

export void Ex_09();

import std;
using namespace std;

//输入1到4的拼写，打印这个数。
void Ex_09()
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