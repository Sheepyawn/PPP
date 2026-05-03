import Classes;
import PPP;
using namespace std;

int main()
{
	// drill_1
	// 定义一个类名为B1。
	// 这个类有虚函数vf(),非虚函数f()。
	// 两个函数都输出自己的名字。
	//cout << "drill_1" << '\n';
	//B1 b1;
	//b1.vf();
	//b1.f();

	// drill_2
	// 从B1派生一个D1类。
	// 覆写vf()。
	cout << '\n' << "drill_2" << '\n';
	D1 d1;
	d1.vf();
	d1.f();
	d1.pvf();

	// drill_3
	// 定义B1的引用，用D1对象初始化。
	cout << '\n' << "drill_3" << '\n';
	B1& ref = d1;
	ref.vf();
	ref.f();
	ref.pvf();

	// drill_4
	// 为D1定义函数f()。
	// 重复drill 1-3。

	// ref.vf()会输出：D1.vf()，ref.f()会输出：B1.f()。
	// 因为vf()是虚函数，会根据实际对象(d1)决定调用版本；
	// f()是非虚函数，根据引用类型(B1&)决定调用版本。


	// drill_5
	// 往B1里添加一个纯虚函数pvf()。
	// 重复drill 1-4。
	
	// 在B1中定义纯虚函数后，无法创建B1对象。
	// D1.pvf()和ref.pvf()都输出：D1::pvf()。


	// drill_6
	// 定义D1的派生类D2。
	// 在D2中覆写pvf()。
	cout << '\n' << "drill_6" << '\n';
	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();

	// drill_7
	// 定义类B2，带有纯虚函数pvf()。
	// 定义类D21，带有成员string data和覆写B2的pvf()的成员函数pvf()。
	// D21的pvf()输出data的值。
	// 定义类D22，基本和类D21一致，除了data类型为int。
	// 定义函数f()，参数为B2&类型，使用其参数调用pvf()。
	cout << '\n' << "drill_7" << '\n';
	D21 d21;
	d21.data = "d21";
	D22 d22;
	d22.data = 999;

	d21.pvf();
	d22.pvf();

	f(d21);
	f(d22);

	return 0;
}

