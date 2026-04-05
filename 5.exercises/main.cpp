import exercises;

import std;
using namespace std;

int main()
{
	try {
		exercise4();
		//exercise5();
		//exercise6();
		//exercise8();

	}
	catch (exception& e)
	{
		cerr << "Exception: " << e.what() << '\n';
		return 1;
	}
	catch (...)
	{
		cerr << "Unknown exception" << '\n';
		return 2;
	}
}