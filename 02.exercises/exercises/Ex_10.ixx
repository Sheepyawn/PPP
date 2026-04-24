export module Ex_10;

export void Ex_10();

import std;
using namespace std;

//四则运算
void Ex_10()
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