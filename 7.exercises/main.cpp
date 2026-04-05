import exercises;
import std;

int main()
{
	try
	{
		//exercise_1();
		//exercise_2();
		//exercise_3();
		//exercise_4();
		//exercise_5();
		//exercise_6();
		//exercise_7();
		//exercise_9();
		//exercise_10();
		//exercise_11();
		//exercise_12();
		exercise_13();

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