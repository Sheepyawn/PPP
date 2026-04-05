export module drill_2;

export import std;

export namespace X
{
	int var;
	void print()
	{
		std::cout << "This is namespace X, and var == " << var << '\n';
	}
}

export namespace Y
{
	int var;
	void print()
	{
		std::cout << "This is namespace Y, and var == " << var << '\n';
	}
}

export namespace Z
{
	int var;
	void print()
	{
		std::cout << "This is namespace Z, and var == " << var << '\n';
	}
}

