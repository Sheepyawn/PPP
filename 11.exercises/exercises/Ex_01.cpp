// 定义一个箭头类。这个类画一条带箭头的直线。

#include "11.exercises.h"
#include "PPP/Simple_window.h"

class Arrow : Shape
{
public:
	Arrow(Point p1, Point p2);
	//Arrow(Point p1, Point p2, int h);
	void draw_specifics(Painter& painter) const override;
private:
	int h = 50;				// length in x axis of arrow head.
};

Arrow::Arrow(Point p1, Point p2)
{
	// body
	add(p1);
	add(p2);
}

Arrow::draw_specifics(Painter& painter)


void Ex_01()
{
	const Point x{ 200, 200 };
	Simple_window win{ x, 600, 400, "Ex_01"};

	Arrow a{ Point{200, 200}, Point{400, 200} };
	win.attach(t);
	win.wait_for_button();
	Line
}