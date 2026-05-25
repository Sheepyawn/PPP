#pragma once
#include "PPP/Simple_window.h"
#include "PPP/Graph.h"
#include "PPP.h"

using namespace Graph_lib;

double one(double) { return 1; }
double slope(double x) { return 0.5 * x; }
double square(double x) { return x * x; }
double dcos(double d) { return cos(d); }
double sloping_cos(double x) { return cos(x) + slope(x); }
double dlog(double x) { return log(x); }
double dsin(double x) { return sin(x); }
double dexp(double x) { return exp(x); }

constexpr int xmax = 600;                         // window size
constexpr int ymax = 400;

constexpr int x_orig = xmax / 2;                 // position of (0,0) is center of window
constexpr int y_orig = ymax / 2;
constexpr Point orig{ x_orig,y_orig };

constexpr int r_min = -10;                        // range [-10:11)
constexpr int r_max = 11;

constexpr int n_points = 400;                    // number of points used in range

constexpr int x_scale = 30;                       // scaling factors
constexpr int y_scale = 30;

void eg_13_2();
void eg_13_4();
void eg_13_6();


int main()
{
    try
    {
        Application app;

        //eg_13_2();
        //eg_13_4();
        eg_13_6();

    }
    catch (...)
    {
        cout << "something went wrong\n";
    }
}




void eg_13_2()
{
    // 13-2
    Simple_window win{ Point{100,100},xmax,ymax,"Three functions" };

    Function s{ one,r_min,r_max,orig,n_points,x_scale,y_scale };
    Function s2{ slope,r_min,r_max,orig,n_points,x_scale,y_scale };
    Function s3{ square,r_min,r_max,orig,n_points,x_scale,y_scale };

    win.attach(s);
    win.attach(s2);
    win.attach(s3);
    win.wait_for_button();

    Text ts{ Point{100, y_orig - 40},"one" };
    Text ts2{ Point{100, y_orig + y_orig / 2 - 20},"0.5*x" };
    Text ts3{ Point{x_orig - 100, 20},"x*x" };
    win.attach(ts);
    win.attach(ts2);
    win.attach(ts3);
    win.set_label("Function graphing: label functions");
    win.wait_for_button();

    constexpr int xlength = xmax - 40; // make the axis a bit smaller than the window
    constexpr int ylength = ymax - 40;

    Axis x{ Axis::x,Point{20,y_orig}, xlength, xlength / x_scale, "one notch == 1" };
    Axis y{ Axis::y,Point{x_orig, ylength + 20}, ylength, ylength / y_scale, "one notch == 1" };
    x.set_color(Color::red);
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);
    win.wait_for_button();

    // 13-3
    Function s4{ dcos,r_min,r_max,orig,400,30,30 };
    s4.set_color(Color::blue);
    Function s5{ sloping_cos, r_min,r_max,orig,400,30,30 };
    s5.set_color(Color::green);

    x.label.move(-160, 0);
    x.notches.set_color(Color::dark_red);
    win.attach(s4);
    win.attach(s5);
    win.wait_for_button();

    Function f1{ dlog, 0.000001, r_max, orig, 200, 30, 30 };
    Function f2{ dsin, r_min, r_max, orig, 200, 30, 30 };
    f2.set_color(Color::blue);

    Function f3{ dcos, r_min, r_max, orig, 200, 30, 30 };
    Function f4{ dexp, r_min, r_max, orig, 200, 30, 30 };

    win.attach(f1);
    win.attach(f2);
    win.attach(f3);
    win.attach(f4);
    win.wait_for_button();
}


int fac(int n)
{
    int r = 1;
    while (n > 1)
    {
        r *= n;
        --n;
    }
    return r;
}

double dfac(int n)
{
    double r = 1.0;
    while (n > 1)
    {
        r *= n;
        --n;
    }
    return r;
}

//double term(double x, int n) { return pow(x, n) / fac(n); }
double term(double x, int n) { return pow(x, n) / dfac(n); }

double exp_n(double x, int n)
{
    double sum = 0;
    for (int i = 0; i < n; ++i)
        sum += term(x, i);
    return sum;
}

void eg_13_4()
{
    Simple_window win{ Point{100,100},xmax,ymax,"13_4" };

    constexpr int xlength = xmax - 40; // make the axis a bit smaller than the window
    constexpr int ylength = ymax - 40;
    Axis x{ Axis::x,Point{20,y_orig}, xlength, xlength / x_scale, "one notch == 1" };
    Axis y{ Axis::y,Point{x_orig, ylength + 20}, ylength, ylength / y_scale, "one notch == 1" };
    x.set_color(Color::red);
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);
    win.wait_for_button();

    Function real_exp{ dexp,r_min,r_max,orig,200,x_scale,y_scale };
    real_exp.set_color(Color::blue);
    win.attach(real_exp);
    win.wait_for_button();

    for (int n = 0; n < 50; ++n) {
        ostringstream ss;
        ss << "exp approximation; n==" << n;
        win.set_label(ss.str());

        // get next approximation:
        Function e{ [n](double x) { return exp_n(x,n); },r_min,r_max,orig,200,x_scale,y_scale };

        win.attach(e);
        win.wait_for_button();
        win.detach(e);
    }
}

struct Distribution
{
    int year;
    double young, middle, old;
};

istream& operator>>(istream& is, Distribution& d)
// assume format: { year : young middle old }
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Distribution dd;

    if (is >> ch1 >> dd.year >> ch2 >> dd.young >> dd.middle >> dd.old >> ch3) 
    {
        if (ch1 != '{' || ch2 != ':' || ch3 != '}') // format error
            is.clear(ios_base::failbit);
        else
            d = dd;
    }
    return is;
}

class Scale {         // data value to coordinate conversion
    int cbase;        // coordinate base
    int vbase;        // base of values
    double scale;
public:
    Scale(int b, int vb, double s) :cbase{ b }, vbase{ vb }, scale{ s } {}
    int operator()(double v) const { return cbase + (v-vbase)*scale; }            // see §21.2
};

void eg_13_6()
{
    constexpr int xmax = 600;    // window size
    constexpr int ymax = 400;

    constexpr int xoffset = 100;  // distance from left-hand side of window to y axis
    constexpr int yoffset = 60;    // distance from bottom of window to x axis

    constexpr int xspace = 40;   // space beyond axis
    constexpr int yspace = 40;

    constexpr int xlength = xmax - xoffset - xspace;         // length of axes
    constexpr int ylength = ymax - yoffset - yspace;

    constexpr int base_year = 2010;
    constexpr int end_year = 2040;

    constexpr double xscale = double(xlength) / (end_year-base_year);
    constexpr double yscale = double(ylength) / 100;

    Scale xs{ xoffset,base_year,xscale };       // xs(double year)返回某一年的x坐标（= xoffset + (year - base_year) * xscale
    Scale ys{ ymax - yoffset,0,-yscale };       // ys(double v)返回某一个百分数的y坐标。

    const string file_name = "japanese-age-data.txt";
    ifstream ifs{ file_name };

    Simple_window win{ Point{100,100},xmax,ymax,"Aging Japan" };
    if (!ifs)
    {
        Text err_label{ Point{ 20, 20 }, "Can't openfile" };
        win.attach(err_label);
        win.wait_for_button();
        PPP::error("can't open ", file_name);
    }

    Axis x{ Axis::x, Point{xoffset,ymax - yoffset}, xlength, (end_year-base_year) / 5,   // one notch per 5 years
                  "year "
                  "2010     2015     2020      2025      "
                  "2030      2035    2040"
    };

    x.label.move(-100, 0);
    x.label.set_font_size(10);

    Axis y{ Axis::y, Point{xoffset,ymax - yoffset}, ylength, 10,"% of population" };

    int now = 2026;
    Line current_year{ Point{xs(now),ys(0)},Point{xs(now),ys(100)} };
    current_year.set_style(Line_style::dash);

    Open_polyline children;
    Open_polyline adults;
    Open_polyline aged;

    for (Distribution d; ifs >> d; ) {
        // ... data validation ...
        if (d.year < base_year || end_year < d.year)
            PPP::error("year out of range");

        double all = d.young + d.middle + d.old;
        if (all - 100 > 1.5 || 100 - all > 1.5)       // take rounding errors into account
            PPP::error("percentages don't add up");

        // ... use the data ...
        const int x = xs(d.year);
        children.add(Point{ x,ys(d.young) });
        adults.add(Point{ x,ys(d.middle) });
        aged.add(Point{ x,ys(d.old) });
    }

    Text children_label{ Point{20,children.point(0).y},"age 0−14" };
    children.set_color(Color::red);
    children_label.set_color(Color::red);
    children_label.set_font_size(10);
    children_label.set_style(Line_style::dash);

    Text adults_label{ Point{20,adults.point(0).y},"age 15−64" };
    adults.set_color(Color::blue);
    adults_label.set_color(Color::blue);
    adults_label.set_font_size(10);
    Text aged_label{ Point{20,aged.point(0).y},"age 65+" };
    aged.set_color(Color::dark_green);
    aged_label.set_color(Color::dark_green);
    aged_label.set_font_size(10);
    aged_label.set_style(Line_style::dashdotdot);

    win.attach(children);
    win.attach(adults);
    win.attach(aged);

    win.attach(children_label);
    win.attach(adults_label);
    win.attach(aged_label);

    win.attach(x);
    win.attach(y);
    win.attach(current_year);

    win.wait_for_button();

}

