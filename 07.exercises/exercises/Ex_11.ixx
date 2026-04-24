export module Ex_11;

export void Ex_11();

import PPP;
import empty_check;
using namespace std;

struct vector_values
{
	double smallest;
	double largest;
	double median;
	double mean;
};

// function for exercise_11
// 计算数组的最大、最小、中位数、平均数。
vector_values get_vector_values(vector<double> v)
{
	if_empty_vector(v);
	double median;
	double mean;
	double sum = 0;
	sort(v.begin(), v.end());
	for (double x : v)
	{
		//if (largest < x)
		//	largest = x;
		//if (smallest > x)
		//	smallest = x;
		sum += x;
	}
	mean = sum / v.size();
	if (v.size() % 2 == 0)
		median = (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2;
	else
		median = v[v.size() / 2];
	vector_values vv;
	vv.largest = v[v.size() - 1];
	vv.smallest = v[0];
	vv.median = median;
	vv.mean = mean;
	return vv;
}

// Write a function that finds the smallest and the largest element of a vector argument 
// and also computes the mean and the median.
void Ex_11()
{
	vector<double> v{ -1, 1, 0, 2, 8, -4 };
	vector_values vv = get_vector_values(v);

	cout << "largest == " << vv.largest << '\n'
		<< "smallest == " << vv.smallest << '\n'
		<< "median == " << vv.median << '\n'
		<< "mean == " << vv.mean << '\n';
}