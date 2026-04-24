export module Ex_04;

import PPP;
import Ex_02;
import Ex_03;
using namespace std;

// Find an approximation of that maximum number by using fibonacci().
export void Ex_04()
{
	vector<int> v;
	fibonacci(1, 2, v, 50);
	print_vector("斐波拉契数列：", v);
}