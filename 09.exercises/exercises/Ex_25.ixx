// 为第6章的计算器添加一个指令：from x, 它从文件x获取输入。
// 再添加一个指令：to y， 它把输出写到文件 y。
// 根据6.3的想法写一些测试用例来测试。

export module Ex_25;

export void Ex_25();

import functions;
import std;
using namespace std;

const char number = '8';
const char quit = 'Q';
const string quitkey = "exit";
const char print1 = '\n';
//const char print1 = ';';
const string prompt = ">";
//const string result = "= ";
const char variable = 'v';
const char let = 'L';
const string letkey = "let";
//const string declkey = "#";
const char square_root = 'S';
const string sqrtkey = "sqrt";
const char power = 'P';
const string powkey = "pow";
const char underscores = '_';
const char help = 'H';
const string helpkey = "help";
const char from = 'f';
const string fromkey = "from";
const char to = 't';
const string tokey = "to";
const char file = 'F';

void error(std::string s)
{
    throw runtime_error(s);
}

void error(string s1, string s2)
{
    throw runtime_error{ s1 + s2 };
}


class Token {
public:
    char kind;
    double value;
    string name;

    Token() : kind{ 0 }
    {}
    Token(char ch) : kind{ ch }, value{ 0 }
    {}
    Token(char ch, double val) : kind{ ch }, value{ val }
    {}
    Token(char ch, string n) : kind{ ch }, name{ n }
    {}
};

class Token_stream {
public:
    Token_stream(istream& istream) : is(istream) {};
    Token get();                // get a Token
    void putback(Token t);      // put a token back
    void ignore(char c);
    double get_from_file();
    double fill_to_file();
private:
    bool full{ false };         // is there a Token in the buffer?
    Token buffer{ '0' };        // here is where putback() stores a Token
    istream& is;
};

class Variable
{
public:
    string name;
    double value;
};

class Symbol_table
{
public:
    double get_value(string s);
    void set_value(string s, double d);
    bool is_declared(string var);
    double define_name(string var, double val);
    //double handle_variable(Token& t);
    //Symbol_table(string s, double n) : name{ name }, value{ n } {};
private:
    vector<Variable> var_table;
};

//定义需要用的全局变量。
Symbol_table st;
vector<string> results;

void Token_stream::putback(Token t)
{
    buffer = t;                 // copy t to buffer
    full = true;                // buffer is now full
};

Token Token_stream::get()
{
    if (full)
    {
        full = false;
        return buffer;
    }
    char ch = ' ';
    while (ch != '\n' && isspace(ch) && is.good())
    {
        is.get(ch);
        if (is.eof())
            ch = '\n';
    }

    switch (ch) {
    case '\n':
        return Token{ print1 };
    case help:
    case '(':
    case ')':
    case '{':
    case '}':
    case '!':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '=':
    case ',':
        return Token{ ch };
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        is.putback(ch);
        double val;
        is >> val;
        return Token{ number, val };
    }
    default:
        if (isalpha(ch))     //标准库函数，检查字符是不是字母。有效范围为[-1,255]输入中文字符会报错。
        {
            string s;
            s += ch;
            while (is.get(ch) && (isalpha(ch) || isdigit(ch) || (ch == underscores)))
                //isdigit(), 字符串中的所有字符都是数字字符，则返回 True，否则返回 False。
                s += ch;
            is.putback(ch);
            if (s == letkey)
                //如果s == "let", 创建一个kind等于let的Token。
                return Token{ let };
            if (s == sqrtkey)
                //如果s == "sqrt", 创建一个kind等于square_root的Token。
                return Token{ square_root };
            if (s == powkey)
                //如果s == "pow", 创建一个kind等于pow的Token。
                return Token{ power };
            if (s == quitkey)
                //如果s == "quit", 创建一个kind等于quit的Token。
                return Token{ quit };
            if (s == helpkey)
                //如果s == "help", 创建一个kind等于quit的Token。
                return Token{ help };
            if (s == fromkey)
                return Token{ from };
            if (s == tokey)
                return Token{ to };
            //否则，创建一个kind为variable, name为s的Token。
            return Token{ variable, s };
        }
        error("Bad token");
        return Token{};
    }
};

// This code first looks at the buffer. 
// If there is a c there, we are finished after discarding that c; 
// otherwise, we need to read characters from cin until we find a c.
void Token_stream::ignore(char c)
{
    if (full && c == buffer.kind)
    {
        full = false;
        return;
    }
    full = false;

    char ch = 0;
    while (is.get(ch))
        if (ch == c)
            return;
    if (!is)
        is.clear();
}

void clean_up_mess(Token_stream& ts)
{
    ts.ignore('\n');
    //ts.ignore(';');
}

double Symbol_table::get_value(std::string s)
{
    for (const Variable& v : var_table)
        if (v.name == s)
            return v.value;
    error("trying to read undefined variable ", s);
    return -100;
}

void Symbol_table::set_value(string s, double d)
{
    for (Variable& v : var_table)
        if (v.name == s)
        {
            v.value = d;
            return;
        }
    error("tring to write undefined variable ", s);
}

// 检查变量名字是否已定义
// var_table存放用户自定义变量的名字和数值。
bool Symbol_table::is_declared(string var)
{
    for (const Variable& v : var_table)
        if (v.name == var)
            return true;
    return false;
}

// 自定义变量
// 根据传入字符串和数值，创建Variable类型，存入var_table数组。
double Symbol_table::define_name(string var, double val)
{
    if (is_declared(var))
        error(var, " declared twice");
    var_table.push_back(Variable{ var, val });
    return val;
}

double expression(Token_stream& ts);        // forward declaration for primary to call

// This function is adapted from Chrinkus/stroustrup-ppp
// Original source: https://github.com/Chrinkus/stroustrup-ppp
// 这个函数处理表达式中的变量
// 如果变量后跟 “=”，就是给变量赋值。
// 如果没有，则返回变量的值。
double handle_variable(Token& t, Token_stream& ts)
{
    Token t2 = ts.get();
    if (t2.kind == '=')
        st.set_value(t.name, expression(ts));
    else
        ts.putback(t2);
    return st.get_value(t.name);
}

//定义变量。
//      变量名 = 表达式;
double declaration(Token_stream& ts)
{
    Token t = ts.get();
    if (t.kind != variable)
        error("variable expected in declaration");

    Token t2 = ts.get();
    if (t2.kind != '=')
    {
        ts.putback(t2);
        error("= missing in declaration of ", t.name);
    }
    double d = expression(ts);
    st.define_name(t.name, d);
    return d;
}

//算平方根
double square_root_func(Token_stream& ts)
{
    Token t = ts.get();
    if (t.kind != '(')
        error("'(' expected after sqrt");
    //ts.putback(t);            这里不把括号放回去，放回去的话计算sqrt(9) + 1就变成计算sqrt 9 + 1
    double d = expression(ts);
    if (d < 0)
        error("argument of sqrt() should be greater than 0");
    t = ts.get();
    if (t.kind != ')')
        error("')' expected after sqrt");
    return sqrt(d);
}

//幂
double power_func(Token_stream& ts)
{
    Token t = ts.get();
    if (t.kind != '(')
        error("'(' expected after pow");
    //ts.putback(t);    //这里不把括号放回去，因为expression()不能处理逗号
    double d1 = expression(ts);        //获取第一个参数
    t = ts.get();        //调用expression()后，ts的buffer里应该是‘,’。
    if (t.kind != ',')
        error("',' expected after the first argument of pow()");
    double d2 = expression(ts);       //获取第二个参数
    int index = int(d2);
    if (index != d2)
        error("index of pow() should be an integer");
    t = ts.get();
    if (t.kind != ')')
        error("')' expected after pow");
    return pow(d1, d2);
}

string string_result(double d)
{
    string s = to_string(d);
    const int last = static_cast<int>(s.size()) - 1;
    for (int i = last; 0 < i; --i)
    {
        if (s[i] != '0' && s[i] != '.')
            break;
        s.erase(i, 1);
    }
    return s;
}

 //从文件中读取数据并计算，然后存入results数组
double Token_stream::get_from_file()
// 创建文件输入流
// 把is为ifs的Tokens_sream传给exprssion, 获取结果。
// 把结果存进results数组
{
    string filename;
    is >> filename;             // from exercises/Ex_25_expressions.txt
    ifstream ifs{ filename };
    if (!ifs)
        error("can't open file: " + filename);
    Token_stream tfs{ ifs };
    while (ifs)
    {
        try
        {
            Token tf = tfs.get();
            if (tf.kind != print1)
                tfs.putback(tf);        // 这个程序是输入空格打印，而读文件读到空格或者换行会尝试打印而报错。所以这里把空格“吃掉”。
            if (tf.kind == quit)
                return 1;
            if (tf.kind == help)
                error("can't help you in a file");
            double result = expression(tfs);
            results.push_back(string_result(result));
        }
        catch (exception& e)
        {
            results.push_back(e.what());
            clean_up_mess(tfs);
        }
    }
    return 1;           // 总得返回点什么，返回1代表true。
}

double Token_stream::fill_to_file()
{
    string filename;
    is >> filename;             // to exercises/Ex_25_output.txt
    ofstream ofs{ filename };
    if (!ofs)
        error("can't open file: " + filename);
    if (results.size() == 0)
        error("there are no results available");
    for (string x : results)
        ofs << "= " << x << '\n';
    results.clear();            // 输出到文件后清空数组。
    return 1;
}

////对定义变量或计算算式的表达式进行不同的处理。
//double statement(Token_stream& ts)
//{
//    Token t = ts.get();
//    switch (t.kind)
//    {
//
//    default:
//        //因为没有“let”，所以要把Token放回去，不然expression()从ts获取的是不完整的表达式。
//        ts.putback(t);
//        return expression(ts);
//    }
//}

// 处理表达式的括号，数字，数字前的正负号，自定义变量和函数。
//      如果是括号，返回里面的表达式的值。
//      如果是正负号，根据正负号返回后面的表达式的值或其相反数。
//      如果是数字，直接返回数字的值。
//      如果是变量，根据变量后是否是‘=’，决定是否更改变量的值，然后返回变量的值。
//      处理幂函数和求平方根函数
double primary(Token_stream& ts)
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':
    {
        double d = expression(ts);
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case '{':
    {
        double d = expression(ts);
        t = ts.get();
        if (t.kind != '}') error("'}' expected");
        return d;
    }
    case number:
        return t.value;
    case '-':
        return -primary(ts);
    case '+':
        return primary(ts);
    case variable:
        return handle_variable(t, ts);
    case let:
        //在进入定义之前，“let”放在这个函数的局部变量t里，进入定义后直接不用处理“let”。
        //return后，t被销毁，“let”被吃掉。
        return declaration(ts);
    case square_root:
        return square_root_func(ts);
    case power:
        return power_func(ts);
    case from:
        return ts.get_from_file();
    case to:
        return ts.fill_to_file();
    default:
        if (t.kind == print1)
            ts.putback(t);
        error("primary expected");
        return -1;
    }
}

// This function is adapted from Chrinkus/stroustrup-ppp
// Original source: https://github.com/Chrinkus/stroustrup-ppp
// 处理阶乘
double secondary(Token_stream& ts)
{
    double left = primary(ts);
    Token t = ts.get();
    while (true)
    {
        if (t.kind == '!')
        {
            if (left == 0)
                return 1;
            for (double i = left - 1; i > 0; --i)
                left *= i;
            t = ts.get();
        }
        else {
            ts.putback(t);
            return left;
        }
    }
}

// deal with * and / and %
double term(Token_stream& ts)
{
    double left = secondary(ts);
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '*':
            left *= secondary(ts);
            t = ts.get();
            break;
        case '/':
        {
            double d = secondary(ts);
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = secondary(ts);
            if (d == 0)
                error("%: divide by zero");
            left = fmod(left, d);       //fmod()，标准库函数 floating-point modulo
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);      // put t back into the Token_stream
            return left;
        }
    }
}

double expression(Token_stream& ts)         // deal with + and -
{
    double left = term(ts);           // read and evaluate a term
    Token t = ts.get();             // get next token from Token_stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term(ts);     // evaluate term and add
            t = ts.get();
            break;
        case '-':
            left -= term(ts);     // evaluate term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);      // put t back into the token stream
            return left;
        }
    }
}

void print_help()
{
    cout << "This calculator supports '+', '-', '*', '/', '%', '!' operations." << '\n'
        << "    To calculate, type expressions like '1+2', '8/4', '(11%(1+2)!)' and I'll return their answers." << '\n'
        << "Functions of sqrt() for square root and pow() for exponentiation are available too." << '\n'
        << "    To use sqrt(), type sqrt(9) and I'll return the square root of 9 (3)." << '\n'
        << "    To use pow(), type pow(5, 2) and I'll return x to the power of i (25)." << '\n'
        << "You can use 'let' to define a variable, as 'let x = {2 * (3 + 4) - 5 / 6};'." << '\n'
        << "    You can use the variable you have defined in later expressions." << '\n'
        << "    Examples: 'x', 'x+1', 'x%5', 'sqrt(x-2)', and 'pow(2*x, x)'" << '\n'
        << "    Special variables like pi = 3.1415926535, e = 2.7182818284 and k = 1000 are already defined in the calculator." << '\n'
        << "Command: from x —— get input from file x; Command: to y —— output result to file y." << '\n'
        << "Type a newline (Enter key) to end an expression." << '\n'
        << "Type 'exit' to exit the program." << '\n';
}

void calculate()
{
    st.define_name("pi", 3.1415926535);
    st.define_name("e", 2.7182818284);
    st.define_name("k", 1000);
    cout << "Simple Calculator (type 'help' for manual)" << '\n';
    Token_stream ts{ cin };
    while (cin)
    {
        try
        {
            std::cout << prompt;
            Token t = ts.get();
            while (t.kind == print1)
                t = ts.get();               //处理连续的“;”，把最后一个“;”存入ts的buffer。
            if (t.kind == quit)
                return;
            if (t.kind == help)
            {
                print_help();
                continue;
            }
            ts.putback(t);
            cout << "= " << expression(ts) << '\n';
        }
        catch (exception& e)
        {
            cerr << e.what() << '\n';
            clean_up_mess(ts);
        }
    }
}

void Ex_25()
{
    calculate();
}