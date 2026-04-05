module _3;

import std;
using namespace std;

//输入数+1
void e3_3_1()
{
	cout << "Please enter the value of v_input." << endl;
	int v_input;
	cin >> v_input;

	//constexpr int num1 = 1 + v_input;
	const int num2 = 1 + v_input;
	cout << "num2 == " << num2 << endl;

	//num2 = num2 + 100;
}


//转换货币，用if语句
void e3_4_1_1()
{
	cout << "Please enter yen('y'), kroner('k'), or pounds('p') and I'll convert it into dollars." << endl;
	double value;
	string unit = " ";
	cin >> value >> unit;
	if (unit == "y")
		cout << value << unit << " is " << value * 0.0065 << " dollars";
	else if (unit == "k")
		cout << value << unit << " is " << value * 0.1589 << " dollars";
	else if (unit == "p")
		cout << value << unit << " is " << value * 1.3647 << " dollars";
	else
		cout << "Sorry I don't know a unit called " << unit;

	cout << endl;
}

//转换货币，用switch
void e3_4_1_2()
{
	cout << "Please enter yen('y'), kroner('k'), or pounds('p') and I'll convert it into dollars." << endl;
	double value;
	char unit = ' ';
	cin >> value >> unit;
	switch (unit)
	{
	case 'y':
		cout << value << unit << " is " << value * 0.0065 << " dollars";
		break;
	case 'k':
		cout << value << unit << " is " << value * 0.1589 << " dollars";
		break;
	case 'p':
		cout << value << unit << " is " << value * 1.3647 << " dollars";
		break;
	default:
		cout << "Sorry I don't know a unit called " << unit;
	}

	cout << endl;
}

//输出ASCII中小写字母及其对应的序号
void e3_4_2_t1()
{
	int i = 97;
	while (i < 123)
	{
		cout << i << '\t' << char(i) << endl;
		i++;
	}
}

//输出ASCII中大小写字母及其对应的序号
void e3_4_2_t2()
{
	for (int i = 97; i < 123; i++)
		cout << i << '\t' << char(i) << endl;

	for (int i = 65; i < 91; i++)
		cout << i << '\t' << char(i) << endl;
}

//返回平方，通过自增x次实现
int square(int x)
{
	int sum = 0;
	for (int i = 0; i < x; i++)
		sum += x;
	return sum;
}

//输出1到100的平方
void e3_5()
{
	for (int i = 0; i < 100; i++)
		cout << i << "² == " << square(i) << endl;
}

//输入一组温度，返回平均温度
void e3_6()
{
	vector<double> temps;
	for (double temp; cin >> temp;)
		temps.push_back(temp);

	double sum = 0;
	for (double x : temps)		//  == 	for (int i = 0; i < temps.size(); i++)	double x = temps[i];
		sum += x;
	cout << "Average temperatrue: " << sum / temps.size() << '\n';
}

//输入一组字符串，对其排序，只输出不重复的字符串。
//输入：a man a plan a canal panama
void e3_6_4()
{
	vector<string> words;
	for (string temp; cin >> temp;)		//结束循环：windows -> ctrz+Z; linux -> ctrl+D
		words.push_back(temp);
	cout << "Number of words:" << words.size() << '\n';

	ranges::sort(words);

	for (int i = 0; i < words.size(); ++i)
		if (i == 0 || words[i - 1] != words[i])
			cout << words[i] << "\n";
}

//替换敏感词“broccoli”和“Broccoli”为“BLEEP”
void e3_6_4t()
{
	vector<string> words;
	cout << "Please enter a few words." << endl;
	for (string word; cin >> word;)
		words.push_back(word);

	for (string& word : words)
		if (word == "Broccoli" || word == "broccoli")
			word = "BLEEP";

	for (string word : words)
		cout << word << endl;
}