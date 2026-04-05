import _6;

import std;
using namespace std;


int main()
{
    try
    {
        calculate();
        return 0;
    }
    catch (exception& e)
    {
        cerr << "error: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }
}
