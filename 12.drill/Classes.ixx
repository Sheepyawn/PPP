export module Classes;

import PPP;
using namespace std;

export class B1;
export class D1;
export class D2;
export class B2;
export class D21;
export class D22;
export void f(B2&);

class B1
{
public:
	virtual void vf() const { cout << "B1::vf()" << '\n'; }
	void f() const { cout << "B1::f()" << '\n'; }
	virtual void pvf() const =0 { cout << "B1::pvf()" << '\n'; }			// drill_5
};

class D1 : public B1
{
public:
	void vf() const override { cout << "D1::vf()" << '\n'; }
	void f() const { cout << "D1::f()" << '\n'; }							// drill_4
	virtual void pvf() const override { cout << "D1::pvf()" << '\n'; }		// drill_5, drill_6
};

//drill_6
class D2 : public D1
{
public:
	void pvf() const override { cout << "D2::pvf()" << '\n'; }
};

//drill_7
class B2
{
public:
	virtual void pvf() const =0 { cout << "B2::pvf()" << '\n'; }
};

class D21 : public B2
{
public:
	void pvf() const override { cout << "D21::data: " << data << '\n'; }
	string data;
};

class D22 : public B2
{
public:
	void pvf() const override { cout << "D22::data: " << data << '\n'; }
	int data;
};

void f(B2& b2)
{
	b2.pvf();
}
