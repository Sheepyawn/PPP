#include "PPP/Simple_window.h"
#include "PPP/Graph.h"
#include "PPP.h"
#include "11.exercises.h"

int main()
{
    try
    {
        Application app;                // Must construct a QApplication before a QWidget
        Ex_01();
    }
    catch (...)
    {
        cout << "something went wrong\n";
    }
}


