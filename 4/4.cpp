module _4;

import std;
using namespace std;

int area(int length, int width)
{
	return length * width;
}

int framed_area(int x, int y)
{
	return area(x - 2, y - 2);
}

void test(int x, int y, int z)
{
	int area1 = area(x, y);
	int area2 = framed_area(1, z);
	int area3 = framed_area(y, z);
	double ratio = double(area1) / (area3);
	cout << "ratio == " << ratio;
}

//运行时错误
void e4_5()
{
	test(-1, 2, 3);	//area3会等于0
}

int area4_5(int length, int width)
{
	//if (length <= 0 || width <= 0)
		return -999;
	return length * width;
}

int framed_area4_5(int x, int y)
{
	return area4_5(x - 2, y - 2);
}

//返回错误信息
// x>0; y>0; z-2<0; (y-2)*(z-2)>0; area2/area3 > 0 
// x>0;  0<y<2; z<2;	y>2时z>2(舍去,因为z<2);
// area1:	{-1, 1, 1}; {1, 1, 1}; 
// area2:	{1,	1, 3}; {1, 1, -1}; 
// area3:	{1, 3, 1}; {1, 1, 3}; {1, 3, 3}; {1, 1, -1}; 
// ratio:	1和3同时满足就行
void e4_5_t()
{
	int x, y, z;
	while ((cout << "输入x, y, z" << '\n') && (cin >> x >> y >> z))
	{
		int area1 = area4_5(x, y);
		if (area1 <= 0)
			cout << "non-positive area" << '\n';
		int area2 = framed_area4_5(1, z);
		int area3 = framed_area4_5(y, z);
		double ratio = double(area1) / area3;

		cout << "area1 == " << area1 << '\n'
			<< "area2 == " << area2 << '\n'
			<< "area3 == " << area3 << '\n'
			<< "ratio == " << ratio << '\n' << '\n';
	}
}

class Bad_area { };

int area4_6_1(int length, int width)
{
	if (length <= 0 || width <= 0)
		throw Bad_area{};
	return length * width;
}

int framed_area4_6_1(int x, int y)
{
	return area4_6_1(x - 2, y - 2);
}

void test4_6_1(int x, int y, int z)
{
	int area1 = area4_6_1(x, y);
	int area2 = framed_area4_6_1(1, z);
	int area3 = framed_area4_6_1(y, z);
	double ratio = area1 / area3;
}

//area4_6_1的参数不大于0，抛出异常
void e4_6_1()
{
	try {
		test4_6_1(-1, 2, 4);
	}
	catch (Bad_area) {
		cout << "Oops! bad arguments to area()\n";
	}
}

//数组越界异常
void e4_6_2()
{
	try
	{
		vector<int> v;
		for (int i; cin >> i;)
			v.push_back(i);
		for (int i = 0; i <= v.size(); ++i)
		//for (int i = 0; i < v.size(); ++i)
			//cout << "v[" << i << "] == " << v[i] << '\n';
			cout << "v[" << i << "] == " << v.at(i) << '\n';
	}
	catch (out_of_range)
	{
		cerr << "Oops! Range error\n";
	}
	catch (...)
	{
		cerr << "Exception: something went wrong" << '\n';
	}
}

void error(string s1, string s2)
{
	throw runtime_error{ s1 + s2 };
	//throw runtime_error( s1 + s2 );
}

//尝试捕获异常
void e4_6_3()
{
	try{
		error("Here's a runtime error. ", "And why not?");
		//throw out_of_range("Here's an out_of_range error");
		throw invalid_argument("Here's an invalid_argument error");
	}
	//catch()类比函数，rutime_error &e表明这个函数接收rutime_error类型的参数, &e表明引用参数的值而不是创建它的副本
	
	catch (runtime_error& e) {
		cerr << "runtime error: " << e.what() << '\n';
	}

	catch (out_of_range& e) {
		cerr << "out_of_range: " << e.what() << '\n';
	}

	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
	} 

	catch (...)
	{
		cerr << "Oops: unknow exception!" << '\n';
	}
}

//尝试在不捕获错误的情况下使用error()
void e4_6_t()
{
	cerr << "..." << '\n';
	error("Here's an error. ", "What's going on?");
	cerr << "..." << '\n';
}

//使用c++的随机库
void e4_7_5()
{
	default_random_engine engine;
	uniform_int_distribution<int> dist(1, 6);		//uniform distribution 均匀分布
	for (int i = 0; i < 10; ++i)
		cout << dist(engine) << ' ';
}