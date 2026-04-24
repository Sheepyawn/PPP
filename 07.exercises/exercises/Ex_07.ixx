export module Ex_07;

export void Ex_07();

import PPP;
using namespace std;

// function for exercise_7
// 初始化string数组
export void init_name(vector<string>& name)
{
	cout << "Enter names, type 'finished' to end input." << '\n';
	string s;
	while (cin >> s)
	{
		if (s == "finished")
			break;
		name.push_back(s);
	}
}

// function for exercise_7
// 检查两个数组大小是否想等。
void check_if_match(const vector<string>& v1, const vector<unsigned int>& v2)
{
	if (v1.size() != v2.size())
		PPP::error("The two vectors have different sizes.");
}

// function for exercise_7
// 初始化unsigned int数组
void init_age(const vector<string>& name, vector<unsigned int>& age)
{
	//check_if_match(name, age);
	size_t name_size = name.size();
	unsigned int v;
	for (size_t i = age.size(); i < name_size; ++i)
	{
		cout << "Enter the age of " << name[i] << '\n';
		cin >> v;
		age.push_back(v);
	}
}

// function for exercise_7
 //打印数组对
void print_pairs(const vector<string>& v1, const vector<unsigned int>& v2)
{
	check_if_match(v1, v2);
	size_t size = v1.size();
	for (size_t i = 0; i < size; ++i)
	{
		cout << v1[i] << ", " << v2[i] << '\n';
	}
}

// function for exercise_7
// 使数组2中的数据和数组1相应的数据配对。
void sort_and_match(vector<string>& v1, vector<unsigned int>& v2)
{
	check_if_match(v1, v2);
	vector<string> v1_copy = v1;
	vector<unsigned int> v2_copy(v2.size());

	sort(v1.begin(), v1.end());
	cout << "Complete the sort of v1." << '\n';

	size_t size = v1_copy.size();
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			if (v1_copy[i] == v1[j])
			{
				v2_copy[j] = v2[i];
				break;
			}
			if (j + 1 == size)
				PPP::error("Unable to find a match name.");
		}
	}
	v2 = v2_copy;
	cout << "Complete the matching of v2 to v1." << '\n';
}

// Read five names into a vector<string> name, 
// then prompt the user for the ages of the people named and store the ages in a vector<double> age.
// Then print out the five(name[i], age[i]) pairs.Sort the names(sort(name.begin(), name.end())) and print out the(name[i], age[i]) pairs.
// exercise_8:Do the previous exercise but allow an arbitrary number of names.
void Ex_07()
{
	vector<string> name{ "Strang", "Orwell", "Huxley", "Stroustrup", "Marx", "Courant" };
	vector<unsigned int> age{ 92, 47, 69, 76, 65, 84 };

	init_name(name);
	init_age(name, age);

	cout << "Pairs:" << '\n';
	print_pairs(name, age);
	sort_and_match(name, age);
	cout << "Pairs after sort:" << '\n';
	print_pairs(name, age);
}