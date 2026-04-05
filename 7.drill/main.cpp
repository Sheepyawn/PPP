import drill;
import std;

int main()
{
	try
	{
		//drill_1();
		//drill_2();
		drill_3();
		//drill_4();

		return 0;
	}
	catch (std::exception& e)
	{
		std::cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...)
	{
		std::cerr << "Oops: unknown exception!" << '\n';
		return 2;
	}
}

