export module Ex_07;

export void Ex_07();

import std;
using namespace std;

//排序输入的3个字符串
void Ex_07()
{
	cout << "Please enter three string values." << endl;		//Steinbeck, Hemingway, Fitzgerald,
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	if (s1 > s2)swap(s1, s2);
	if (s1 > s3)swap(s1, s3);
	if (s2 > s3)swap(s2, s3);
	cout << s1 << ", " << s2 << ", " << s3 << endl;
}