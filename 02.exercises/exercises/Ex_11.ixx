export module Ex_11;

export void Ex_11();

import std;
using namespace std;

//计算不同的硬币的总价值
void Ex_11()
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

	double value = pennies + 5 * nickels + 10 * dimes + 25 * quarters + 50 * half_dollars + 100 * one_dollars;
	value = value / 100;
	cout << "The value of all of your coins is " << value << "dollars" << endl;
}
