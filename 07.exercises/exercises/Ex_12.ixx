export module Ex_12;

import PPP;
import Ex_07;
using namespace std;

// function for exercise_12
void print_until_ss(const vector<string>& v, const string& quit)
// print until the string called "quit" is found
{
	unsigned int count = 0;
	for (string s : v) {
		if (s == quit)
		{
			++count;
			if (count > 1)
				return;
		}
		cout << s << '\n';
	}
}

// Improve print_until_s() from §7.4.2.
// Then, write a print_until_ss() that prints until it sees a second occurrence of its quit argument.
export void Ex_12()
{
	vector<string> s{ "Strang", "Orwell", "Huxley", "Stroustrup", "Marx", "Courant", "quit" };
	init_name(s);
	print_until_ss(s, "quit");
}