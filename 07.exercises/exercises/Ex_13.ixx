export module Ex_13;

export void Ex_13();

import PPP;
import empty_check;
using namespace std;

struct string_numbers
{
	string longest;
	string shortest;
	string lexicographically_first;
	string lexicographically_last;
	vector<size_t> numbers;
};

string_numbers get_string_numbers(const vector<string>& s)
{
	if_empty_vector(s);
	string_numbers s_nums;
	size_t longest = 0;
	size_t shortest = 0;
	string lf = s[0];
	string ll = s[0];
	size_t each_size;
	size_t s_size = s.size();
	for (size_t i = 0; i < s_size; ++i)
	{
		each_size = s[i].size();
		s_nums.numbers.push_back(each_size);
		if (s[longest].size() < each_size)
			longest = i;
		if (s[shortest].size() > each_size)
			shortest = i;
		if (s[i] < lf)
			lf = s[i];
		if (s[i] > ll)
			ll = s[i];
	}
	s_nums.longest = s[longest];
	s_nums.shortest = s[shortest];
	s_nums.lexicographically_first = lf;
	s_nums.lexicographically_last = ll;
	return s_nums;
}

// function for exercise_13
void print_vector(const string& s, const vector<size_t>& v)
{
	if_empty_vector(v);
	cout << s << '\n';
	for (size_t x : v)
		cout << x << '\n';
}

// Write a function that takes a vector<string> argument and returns a vector<int> containing the number of characters in each string.
// Also find the longest and the shortest string and the lexicographically first and last string.
void Ex_13()
{
	vector<string> s{ "Strang", "Orwell", "Huxley", "Stroustrup", "Marx", "Courant", "quit" };
	string_numbers s_nums = get_string_numbers(s);
	print_vector("数组的各个字符串的字符数", s_nums.numbers);
	cout << "The longest string: " << s_nums.longest << '\n'
		<< "The shortest string: " << s_nums.shortest << '\n'
		<< "The lexicographically_first: " << s_nums.lexicographically_first << '\n'
		<< "The lexicographically_last: " << s_nums.lexicographically_last << '\n';

}