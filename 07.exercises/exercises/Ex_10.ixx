export module Ex_10;

import PPP;
import empty_check;
using namespace std;


// fuction for exercise_10
double maxv(const vector<double>& v)
{
	if_empty_vector(v);
	double max = v[0];
	for (double x : v)
	{
		if (x > max)
			max = x;
	}
	return max;
}

// Write a function maxv() that returns the largest element of a vector argument.
export void Ex_10()
{
	vector<double> v{ 1.0, 0.99999, 1.000001, 0.5, 1.05 - 1, };
	double max = maxv(v);
	cout.precision(10);
	cout << "The max num of the vector is " << max << '\n';
}