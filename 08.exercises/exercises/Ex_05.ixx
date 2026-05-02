// 实现图书类
// 成员有：ISBN、title、author、copyright date、checked out（书是否已被借出）。

export module Ex_05;

export void Ex_05();
export class Book;
export class ISBN;
export enum class Genre;

import PPP;
import functions;
using namespace std;

class ISBN
{
public:
	ISBN(int, int, int, char);
	bool valid();
	int get_group() const { return group; }
	int get_publisher() const { return publisher; }
	int get_title() const { return title; }
	char get_check() const { return check; }
	bool operator==(const ISBN& other) const
	{ 
		return group == other.group && publisher == other.publisher && title == other.title;
	}
	string string_ISBN() const;
private:
	int group;
	int publisher;
	int title;
	char check;
};

ISBN::ISBN(int g, int p, int t, char c):group(g), publisher(p), title(t), check(c)
{
	if (!valid())
		PPP::error("Invalid ISBN: " + string_ISBN());
}

string ISBN::string_ISBN() const
{
	return 	to_string(group) + '-' +
			to_string(publisher) + '-' +
			to_string(title) + '-' +
			check;			// check本身就是字符，不需要to_string
}

bool ISBN::valid()
// 检验ISBN的有效性。
{
	int group_digit = get_digit(group);
	int publisher_digit = get_digit(publisher);
	int title_digit = get_digit(title);

	constexpr int gmax = 5;				// group的最大有效位数。
	constexpr int pmin = 2;				// publisher的最小有效位数。
	constexpr int pmax = 7;				// publisher的最大有效位数。
	constexpr int tmax = 6;				// title的最大有效位数。
	constexpr int valid_digits = 10;	// ISBN的有效位数

	if (gmax < group_digit)
		return false;
	if (publisher_digit < pmin || pmax < publisher_digit)
		return false;
	if (tmax < title_digit)
		return false;
	if ((group_digit + publisher_digit + title_digit) != valid_digits - 1)
		return false;
	if (!(('0' <= check && check <= '9') || check == 'X'))
		PPP::error("The check digit of " + string_ISBN() + " should be a character between '0' and '9' or 'X'.");

	// 计算并检验ISBN的有效位：
	int multiplier = 2;
	int sum = 0;

	// 从低位到高位。每次对10取模，获得最低位的数；再乘以权重。
	for (int i = title; i > 0; i /= 10)
	{
		sum += (i % 10) * multiplier;
		++multiplier;
	}
	for (int i = publisher; i > 0; i /= 10)
	{
		sum += (i % 10) * multiplier;
		++multiplier;
	}
	for (int i = group; i > 0; i /= 10)
	{
		sum += (i % 10) * multiplier;
		++multiplier;
	}

	char check_digit;
	const int int_check = 11 - sum % 11;
	switch (int_check)
	{
	case 11:
		check_digit = '0';
		break;
	case 10:
		check_digit = 'X';
		break;
	default:
		check_digit = int_check + '0';
		break;
	}
	if (check_digit != check)
		return false;
	return true;
}

enum class Genre
{
	fiction, nonfiction, periodical, biography, children
};

class Book
{
public:
	Book(string, string, int, ISBN, Genre);
	ISBN get_ISBN() const { return isbn; }
	string get_title() const { return title; }
	string get_author() const { return author; }
	int get_copyright_date() const { return copyright_date; }
	Genre get_genre() const { return genre; }
	bool is_checked_out() const { return checked_out; }
	void check_in() { checked_out = false; }				// 还书
	void check_out() { checked_out = true; }				// 借书
private:
	string title;
	string author;
	int copyright_date;
	ISBN isbn;
	Genre genre;
	bool checked_out = false;				// 默认未借出
};

Book::Book(string t, string a, int cd, ISBN isbn, Genre g): title{t}, author{a}, copyright_date{cd}, isbn{ isbn }, genre{g}
{
	constexpr int max_copyright_date = 2026;				// 最大版权年份
	constexpr int min_copyright_date = 1000;				// 最小版权年份
	constexpr int max_title_size = 500;						// 最长标题长度
	constexpr int max_author_size = 50;						// 最长作者长度
	// 检查title的有效性
	if (t.size() == 0 || max_title_size < t.size())
		PPP::error("Invalid title");
	// 检查author的有效性
	if (a.size() == 0 || max_author_size < a.size())
		PPP::error("Invalid author");
	// 检查copyright_date的有效性
	if (copyright_date < min_copyright_date || max_copyright_date < copyright_date)
		PPP::error("Invalid copyright date");

	// ISBN的有效性在构造时就已经检查过了。
}

void Ex_05()
{
	Book b1("Programming:principles and practice using C++", "Bjarne Stroustrup", 2014, ISBN(0, 321, 99278, '4'), Genre::nonfiction);
	cout << b1.is_checked_out() << '\n';
	b1.check_out();
	cout << b1.is_checked_out() << '\n';
	Book b2("A Tour of C++", "Bjarne Stroustrup", 2023, ISBN(0, 13, 681648, '8'), Genre::nonfiction);				// The correct check digit should be '7'.
	//Book b3("Flatland", "Edwin A.Abbott", 2006, ISBN(0, 19, 280598, 3), Genre::fiction);
}