#include <iostream>

class A {
public:
	A() {
		std::cout << "constructor A" << std::endl;
	}
	void f() {
		std::cout << "A";
	}
};

class B : public virtual A {
public:
	B() {
		std::cout << "constructor B" << std::endl;
	}
	void f() {
		std::cout << "B";
	}
};

class C : public virtual A {
public:
	C() {
		std::cout << "constructor C" << std::endl;
	}
	void f() {
		std::cout << "C";
	}
};

class E : public virtual C {
public:
	E() {
		std::cout << "constructor E" << std::endl;
	}
	void f() {
		std::cout << "E";
	}
};

class D : public virtual C, public virtual E {
public:
	D() {
		std::cout << "constructor D" << std::endl;
	}
	void f() {
		std::cout << "D";
	}
};

class F : public virtual A, public virtual C, public virtual D, public virtual E {
public:
	F() {
		std::cout << "constructor F" << std::endl;
	}
	void f() {
		std::cout << "F";
	}
};

int main() {
	F object;
	object.f();

	return 0;
}
