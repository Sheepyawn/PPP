module _5;

import std;
using namespace std;

class Token
{
public: 
	char kind;
	double value;
	Token(char k) :kind{k}, value{0.0}{}
	Token(char k, double v) :kind{k}, value{v}{}
};

void error(std::string s)
{
	throw runtime_error(s);
}

void e5_3_3()
{
	//Token t;
	//t.kind = '+';
	//Token t2;
	//t2.kind = '8';
	//t2.value = 3.14;
	//Token tt = t;
	//if (tt.kind != t.kind)
	//	cerr << "impossible!";
	//t = t2;
	//cout << t.value << '\n';

	Token t1{ '+' };
	Token t2{ '8', 11.5 };
	cout << t1.kind << '\t' << t1.value << '\n'
		<< t2.kind << '\t' << t2.value << '\n';

}

class Token_stream
{
public:
	Token get();
	void putback(Token t);
private:
	bool full = false;
	Token buffer {'0'};
};

//如果buffer为空，把Token复制给buffer，full设置为true
void Token_stream::putback(Token t)
{
	if (full)
		cerr << "putback() into a full buffer" << '\n';
	buffer = t;
	full = true;
}

//从buffer或缓冲区获取数字或运算符，返回一个Token，返回后ts为空；
//如果ts.buffer非空，返回buffer，ts设置为空。
//如果ts.buffer为空，从缓冲区获取一个字符。
//		如果是运算符号字符，创建kind为该运算符的Token，返回它；
//		如果是数字字符，从缓冲区获取整个数字，创建kind为‘8’的Token，返回它。
//获取输入后会消耗掉缓冲区的数字或字符，下次调用时获取的就是下一个数字或字符。
Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch = 0;
	if (!(cin >> ch))
		cerr << "no input" << '\n';

	switch(ch)
	{
		case ';':
		case 'q':
		case '(': case ')': case '{': case '}': case '!':
		case '+': case '-': case '*': case'/':
			return Token{ ch };
		case '.':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);	//将一个字符放回输入流中，然后在缓冲区中持续读取数字，直到cin >> val;(double类型)失败。
			double val = 0;
			cin >> val;
			return Token{ '8', val };
		}
		default:
			cerr << "Bad Token" << '\n';
	}
}

//全局变量 ts
Token_stream ts;

double expression();
// expression() calls term() which calls primary() which calls expression(). 
// This means that we can’t just define those three functions: there is no order that allows us to define every function before it is used. 
// We need at least one declaration that isn’t also a definition. 
// We chose to declare (“forward declare”) expression().

//处理阶乘
//		不能处理连续阶乘 x!!。可以去看第六章的secondary();
void factorial(double &d)
{
	Token c = ts.get();
	if (c.kind == '!')
	{
		if (int(d) == d)
		{
			if (d == 0)
				d = 1;
			else
				for (int i = d - 1; i > 0; --i)
					d *= i;
		}
		else
			cerr << "'integer' expected before '!'" << '\n';
	}
	else
		ts.putback(c);
}

//处理括号和数字
//如果是括号，调用expression()计算括号里的表达式，返回运算结果。
//如果是数字，返回数字的值。
double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')')
			cerr << "'(' expected" << '\n';
		factorial(d);
		return d;
	}
	case '{':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}')
			cerr << "'{' expected" << '\n';
		factorial(d);
		return d;
	}
	case '8':
	{
		factorial(t.value);
		return t.value;
	}
	default:
		error("primary expected");
	}
}

//处理 左值 （*或/) 右表达式的情况，返回运算结果；
//如果不是，返回左值。
double term()
{
	double left = primary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0)
				cerr << "divide by zero" << '\n';
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

// 处理 左值 (+或-) 右表达式的情况，返回运算结果；
// 如果不是，返回左值。
double expression()
{
	double left = term();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

//从左往右递归
//从右往左计算
//left一定是数字

void calculator()
{
	double val = 0;
	while (cin)
	{
		Token t = ts.get();

		if (t.kind == 'q')
			break;
		if (t.kind == ';')
			cout << "=" << val << '\n';
		//如果输入是数字，存入ts的buffer
		else
			ts.putback(t);
		val = expression();
	}
}