export module empty_check;

import PPP;
using namespace std;

export void if_empty_vector(const vector<string>& v)
{
	if (v.size() == 0)
		PPP::error("There's nothing in the vector. It's empty.");
}

export void if_empty_vector(const vector<int>& v)
{
	if (v.size() == 0)
		PPP::error("There's nothing in the vector. It's empty.");
}

export void if_empty_vector(const vector<size_t>& v)
{
	if (v.size() == 0)
		PPP::error("There's nothing in the vector. It's empty.");
}

export void if_empty_vector(const vector<double>& v)
{
	if (v.size() == 0)
		PPP::error("There's nothing in the vector. It's empty.");
}