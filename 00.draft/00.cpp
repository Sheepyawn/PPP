import PPP;
using namespace std;



int main()
{
    double x = 0;
    double y = 0;
    int x_scale = 0;
    int y_scale = 0;
    for (int i = 0; i < 10; ++i)
    {
        cout << x++ << '\t' << y++ << '\t' << x_scale++ << '\t' << y_scale++ << '\n';
        x, y, x_scale, y_scale = 0;
    }
}