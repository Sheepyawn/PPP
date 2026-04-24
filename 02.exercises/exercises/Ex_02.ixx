export module Ex_02;

export void Ex_02();

import std;

//把英里转换为千米
void Ex_02()
{
	std::cout << "Please enter miles and I'll convert it to kilometers.\n";
	double miles;
	std::cin >> miles;
	miles = miles * 1.609;
	std::cout << "It's " << miles << " kilometers.";
}