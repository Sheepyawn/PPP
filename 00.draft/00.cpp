import PPP;
using namespace std;

struct B {
    virtual void f() const { cout << "B::f " << '\n'; }
    void g() const { cout << "B::g " << '\n'; }             // not virtual
};

struct D : B {
    void f() const { cout << "D::f " << '\n'; }               // overrides B::f
    void g() { cout << "D::g " << '\n'; }
};

struct DD : D {
    void f() { cout << "DD::f " << '\n'; }                      // doesn’t override D::f (not const)
    void g() const { cout << "DD::g " << '\n'; }
};

void call(const B& b)
// a D is a kind of B, so call() can accept a D
// a DD is a kind of D and a D is a kind of B, so call() can accept a DD
{
    b.f();
    b.g();
}

int main()
{
    B b;
    D d;
    DD dd;
    call(b);
    call(d);
    call(dd);

    b.f();
    b.g();

    d.f();
    d.g();

    dd.f();
    dd.g();
}