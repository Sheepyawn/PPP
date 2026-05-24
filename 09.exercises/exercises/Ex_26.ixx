// 写一个程序，它输出txt文件中所有由空格分隔的整数的和。
// For example, bears: 17 elephants 9 end should output 26.

export module Ex_26;

import PPP;
using namespace std;

export void Ex_26();

int sum_of_integres(const string& fname)
{
	ifstream ist{ fname };
	if (!ist)
		PPP::error("can't open file " + fname);

	int sum = 0;
	int x;
	while(true)
	{
		ist >> x;
		if (ist.eof())
			break;
		else if (ist.fail())
		{
			ist.clear();
			char ch;
			ist.get(ch);
		}
		else
			sum += x;
	}
	return sum;
}

void Ex_26()
{
	vector<int> integers;
	string fname = "exercises/Ex_26_input.txt";
	int sum = sum_of_integres(fname);

	cout << sum << '\n';
}