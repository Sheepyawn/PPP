module drill;

import PPP;
using namespace std;
import drill_2;
import drill_3;
#include "foo.h";

void swap_v(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_cr(const int& a, const int& b)
{
	int temp;
	temp = a;
	//a = b;
	//b = temp;
}

void drill_1()
{
	cout << "type 'v' to use swap_v(), type 'r' to use swap_r()" << '\n';
	char ch = 0;
	cin >> ch;
	//swap_v;
	int x = 7;
	int y = 9;
	switch (ch)
	{
	case 'v':
	{
		swap_v(x, y);
		swap_v(7, 9);
		break;
	}
	case 'r':
	{
		swap_r(x, y);
		//swap_r(7, 9);
		break;
	}
	default:
		PPP::error("unknown character.");
	}
	cout << "x == " << x << ", y == " << y << '\n';

	const int cx = 7;
	const int cy = 9;
	switch (ch)
	{
	case 'v':
	{
		swap_v(cx, cy);
		swap_v(7.7, 9.9);
		break;
	}
	case 'r':
	{
		//swap_r(cx, cy);			//cx, cy是常量
		//swap_r(7.7, 9.9);
		break;
	}
	default:
		PPP::error("unknown character.");
	}
	cout << "cx == " << cx << ", cy == " << cy << '\n';

	double dx = 7.7;
	double dy = 9.9;
	switch (ch)
	{
	case 'v':
	{
		swap_v(dx, dy);
		swap_v(7.7, 9.9);
		break;
	}
	case 'r':
	{
		//swap_r(dx, dy);			//无法用double类型的值初始化"int &"类型的引用。
		//swap_r(7.7, 9.9);
		break;
	}
	default:
		PPP::error("unknown character.");
	}
	cout << "dx == " << dx << ", dy == " << dy << '\n';

}

void drill_2()
{
	X::var = 7;
	X::print();                  // print X’s var
	using namespace Y;
	var = 9;
	print();                       // print Y’s var

	{
		using Z::var;
		using Z::print;
		var = 11;
		print();              // print Z’s var
	}

	print();                       // print Y’s var
	X::print(); // print X’s var
}

void drill_3()
{
	print_foo();
	set_foo(365);
	print_foo();

	int x = get_foo();
	cout << "x == " << x << '\n';
}

void drill_4()
{
	print_foo();

	print(365);
}