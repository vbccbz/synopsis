
// дружественные функции
#if 0

// френд имеет доступ к прайвт полями у параметров (указателя, ссылки, объекта) и даже аналогично у локальных переменных
// френд имеет доступ не сам по себе (как обычные методы имеют доступ к прайвт перменным), а через локальный объект, или ссылку, или указатель, с типом того, кто назвал френда френдом.
#if 0

// class definition
//	friend function declaration
// friend function definition

#include <iostream>
// отсутствие this это синтаксический сахар внутри класса
// для вызова паблик поля вне класса всегда нужен объект, указатель или ссылка (к прайвет доступ и вовсе заблокирован)
class X {
public:
	X(int var1, int var2, int var3) {
		a = var1;// this->a is eq var1;
		b = var2;
		c = var3;
	}
	void Print(void) {
		std::cout << a << b << c << std::endl;
	}
private:
	int a;
	int b;
	int c;
	friend void foo(X*, X&, X); //оказывается, позволяет одновременно объявить функцию и предоставить ей cтатус дружественной
};

void foo(X* ptrX, X& refX, X x) {
	ptrX->a = 1;
	refX.b = 2;
	x.c = 3;
}

int main(void) {
	X x(0, 0, 0);
	x.Print();
	foo(&x, x, x);
	x.Print();
	return 0;
}

#endif

// можно и так, но в этом примере не оценить смысл
#if 0

// class declaration // нужно для объявления функции
// friend function declaration
// class definition
//	friend function declaration
// friend function definition

#include <iostream>
class X;
void foo(X*, X&, X);

class X {
public:
	X(int var1, int var2, int var3) {
		a = var1;
		b = var2;
		c = var3;
	}
	void Print(void) {
		std::cout << a << b << c << std::endl;
	}
private:
	int a;
	int b;
	int c;
	friend void foo(X*, X&, X);
};

void foo(X* ptrX, X& refX, X x) {
	ptrX->a = 1;
	refX.b = 2;
	x.c = 3;
}

int main(void) {
	X x(0, 0, 0);
	x.Print();
	foo(&x, x, x);
	x.Print();
	return 0;
}

#endif

// лол
#if 0

#include <iostream>
using namespace std;

class Point {
public:
	Point(int var) {
		x = var;
	}
private:
	int x;
	friend int main(void);
};

int main(void) {
	Point a(1);
	std::cout << a.x;
	return 0;
}

#endif

#endif
// дружественный метод
#if 0
// френд метод может работать с прайвт полями у объекта, указателя или ссылки 

// бесполезный пример
#if 0

struct Y {
	void f(void);
};

void Y::f(void) {// дружественный метод бессмысленен, если не использует объект, указатель или ссылку 
	;
}

struct X {
	friend void Y::f(void);// метод должен быть объявлен (определение не обязательно) перед дружбой (почему-то это не касается классов и функций)
};

int main(int argc, char* argv[]) {
	X x;
	Y y;
	y.f();
	return 0;
}

#endif

// бесполезный пример можно сделать и так
#if 0

struct Y {
	void f(void);
};

struct X {
	friend void Y::f(void);
};

void Y::f(void) {
	;
}

int main(int argc, char* argv[]) {
	X x;
	Y y;
	y.f();
	return 0;
}

#endif

// Короче.
// Всё это читать-писать беспонту - два примера ниже нужно просто раскурить.

// Если в методе нет попыток доступа к полям через указатель или ссылку, и не создается и не передается объект Х (на это компилятор будет ругаться даже в отсутствие попыток доступа к полям), то:
#if 0

#include <iostream>
struct X;// incomplete type specification of X 

struct Y {
	void f(X*, X&);
};

void Y::f(X* ptr, X& ref) {
	std::cout << ptr << &ref << std::endl;
	// иные манипуляции невозможны
}

struct X {
	friend void Y::f(X*, X&);
private:
	int x = 0; //инициализировать лень, иначе c4700, но есть non-static data member initializers available with -std=c++11 и старше
};

int main(int argc, char* argv[]) {
	X x;
	Y y;
	y.f(&x, x);
	return 0;
}

#endif
// Итоговый способ
#if 1

#include <iostream>
struct X;

struct Y {
	void f(X*, X&, X);
};

struct X {
	friend void Y::f(X*, X&, X);
private:
	int x = 0;
};

void Y::f(X* ptr, X& ref, X x) {// это возможно благодаря двум вещам: struct X; и struct X { }; ПЕРЕД Y::f ( )
	std::cout << ptr->x << ref.x << x.x << std::endl;
}

int main(int argc, char* argv[]) {
	X x;
	Y y;
	y.f(&x, x, x);
}

#endif

#endif
// дружественные структуры и классы
#if 0

// структура дружественная, c Z* и Z те же приколы. 
// в объявлениях возможны только объявления (и некоторые определения), а не инструции
// соответственно, опять же, смысл от дружбы проявляется в методах друга - если в этих методах есть объект, указатель или ссылка - то у него есть доступ к прайвет.

// дружественный класс из философии
#if 0

#include <iostream>

class Apple {
	friend class Human;// friend class forward declaration (elaborated class specifier) ???
public:
	Apple(int);
private:
	int weight;
};

Apple::Apple(int weight) {
	this->weight = weight;
}

class Human {
public:
	void TakeApple(Apple&);
};

void Human::TakeApple(Apple& apple) {
	std::cout << apple.weight << std::endl;
}

int main() {
	Apple apple(300);
	Human man;
	man.TakeApple(apple);
	return 0;
}

#endif

// дружественный клас симплкод
#if 0

#include <iostream>
class Human;// ???

class Apple;

class Human {//можно перенести за Apple, тогда можно будет убрать class Apple; , но class Human; все равно придется написать.
public:
	void TakeApple(Apple&);
};

class Apple {  //инкапсуляция apple немного нарушена
	friend Human;// friend class declaration (simple type specifier) (since c++11)
public:
	Apple(int);
private:
	int weight;
};

Apple::Apple(int weight) {
	this->weight = weight;
}

void Human::TakeApple(Apple& apple) {
	std::cout << apple.weight << std::endl;
}

int main() {
	Apple apple(300);
	Human man;
	man.TakeApple(apple);
	return 0;
}

#endif

// вложенный дружественный класс
#if 0
#include <iostream>
using namespace std;

struct Holder {
private:
	int a;
public:
	Holder();

	struct Pointer;// ???
	friend struct Pointer;

	struct Pointer {
	private:
		Holder* h;
		int p;
	public:
		Pointer(Holder* h);
		void f(void);
	};

};

Holder::Holder() {
	a = 0;
}

Holder::Pointer::Pointer(Holder* rv) {
	h = rv;
	p = rv->a;
}

inline void Holder::Pointer::f(void) {
	;
}

int main() {
	Holder h;
	Holder::Pointer hp(&h);
}
#endif

#endif
// сheshire 294
#if 0
// main.cpp
#include <iostream>

#include "handle.h"
int main(void) {
	Handle h;
	h.initialize();
	h.change(1);
	std::cout << h.read();
	h.cleanup();
	return 0;
}
// handle.h
#ifndef HANDLE_H
#define HANDLE_H
class Handle {
	struct Cheshire;
	Cheshire* smile;
public:
	void initialize();
	void cleanup();
	int read();
	void change(int);
};
#endif
// handle.cpp
#include "handle.h"
struct Handle::Cheshire {
	int i;
};
void Handle::initialize() {
	smile = new Cheshire;
	smile->i = 0;
}
void Handle::cleanup() {
	delete smile;
}
int Handle::read() {
	return smile->i;
}
void Handle::change(int x) {
	smile->i = x;
}
#endif
// заполнители и аргументы по умолчанию, они точно так же работают в методах
#if 0
#include <iostream>
void print(int, int, int = 0);
void print(int, int x, int y/*=0*/) {
	std::cout << x << y << std::endl;
}
int main(void) {
	print(5, 6);//60
	print(5, 6, 7);//67
	return 0;
}
#endif
// aggregate initialization
#if 0
class test {
public:
	test(int = 0, int = 0);// позволяет не создавать void конструктор
private:
	int a;
	int b;
};
test::test(int a, int b) {
	this->a = a;
	this->b = b;
}

int main(void) {
	int arr1[3] = { 1,2,3 };// 
	test arr2[3] = { {1,2} };
	test arr3[] = { test(1,2), test(3,4), test(5,6) };

	return 0;
}
#endif
// aggregate initialization simplecode
#if 0
#include <iostream>
#include <string>

class Pixel {
public:
	Pixel(void) {
		this->r = 0;
		this->g = 0;
		this->b = 0;
	}
	Pixel(int r, int g, int b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
	std::string GetInfo(void) {
		return "Pixel: r = " + std::to_string(this->r) +
			" g = " + std::to_string(this->g) +
			" b = " + std::to_string(this->b);
	}

private:
	int r;
	int g;
	int b;
};

int main(void) {
	Pixel arr1[5]{ {11, 2, 3} };
	Pixel arr12[5] = { {11, 2, 3} };
	Pixel arr2[5]{ Pixel(1, 22, 3), Pixel(5, 5, 5) };
	Pixel arr3[5] = { Pixel(1, 22, 3), Pixel(5, 5, 5) };

	arr1[1] = Pixel(11, 11, 11);
	arr1[2] = Pixel{ 12, 12, 12 };
	arr1[3] = { 13, 13, 13 };

	for (size_t i = 0; i < 5; i++) {
		std::cout << arr1[i].GetInfo() << '\n';
	}
	std::cout << std::endl;

	Pixel* arr = new Pixel[5];

	arr[1] = Pixel(1, 2, 3);
	arr[1] = { 1, 2, 3 };
	arr[1] = Pixel{ 1, 2, 3 };

	for (size_t i = 0; i < 5; i++) {
		std::cout << arr[i].GetInfo() << '\n';
	}

	delete[] arr;
	return 0;
}

#endif
// union
#if 0
// union могут быть безымянными в с++ и в с, если входят в состав чего-нибудь (в отличие от enum, которые могут быть безымянными всегда)
#include <iostream>

class A {
public:
	A(int);
	A(char);
	void print(void);
private:
	union {
		int i;
		char c;
	};
};
A::A(int var) {
	i = var;
}
A::A(char var) {
	c = var;
}
void A::print(void) {
	std::cout << i << " " << c << std::endl;
}

int main(void) {
	A a1(123);
	A a2('A');
	a1.print();
	a2.print();

	return 0;
}
#endif
// enum
#if 0
#include <iostream>

class PC {
public:
	enum PcState {
		OFF,
		ON,
		SLEEP
	};
	PcState GetState(void) {
		return this->state;
	}
	void SetState(PcState state) {
		this->state = state;
	}
private:
	PcState state;
};

int main(void) {
	PC pc;
	pc.SetState(PC::PcState::ON);
	if (pc.GetState() == PC::PcState::ON) {
		std::cout << "pc is on" << std::endl;
	}
	return 0;
}
#endif
// CV-qualifiers, read-only, constant, constexpr
#if 0
/*
Как перестать тупить с const? Изучить основы.
И вообще это тупо. Зачем сначала рассказывать про const, потом вынужденно преждевременно цеплять static, когда можно сначала рассказать про static, а уже потом объяснять const?
/////////////////////////////////////////////////////////////
C99
Tokens
A token is the minimal lexical element of the language in translation phases 7 and 8.
The categories of tokens are:
	identifier
	keyword
	constant
		integer constant
		other
	string literal
	punctuator
A preprocessing token is the minimal lexical element of the language in translation phases 3 through 6.
The categories of preprocessing tokens are:
	header names
	identifiers
	preprocessing numbers
	character constants
	string literals
	punctuators
	single non-white-space characters that do not lexically match the other preprocessing token categories.
Preprocessing tokens can be separated by white space; this consists of  comments (described later), or white-space characters (space, horizontal tab, new-line, vertical tab, and formfeed), or both. As described in 6.10, in certain circumstances during translation phase 4, white space (or the absence thereof) serves as more than preprocessing token separation. White space may appear within a preprocessing token only as part of a header name or between the quotation characters in a character constant or string literal.

An identifier is an arbitrarily long sequence of digits, underscores, lowercase and uppercase Latin letters, and Unicode characters specified using \u and \U escape notation (since C99).

A declaration is a C language construct that introduces one or more identifiers into the program and specifies their meaning and properties.

There are 4 namespaces in C, see 6.2.3 in the C99 Standard:
	global name space, for all other identifiers
	label names
	the tags of structures, unions, and enumerations
	the members of structures or unions (not a single name space ... as many as structures or unions are defined)

/////////////////////////////////////////////////////////////
C++
There are five kinds of tokens:
	identifiers
	keywords
	literals
		integer literal
		other
	operators (operator-or-punctuator)
	other separators

An identifier is an arbitrarily long sequence of digits, underscores, lowercase and uppercase Latin letters, and most Unicode characters.

Declarations introduce (or re-introduce) names into the C++ program. Each kind of entity is declared differently. Definitions are declarations that are sufficient to use the entity identified by the name.

Namespaces provide a method for preventing name conflicts in large projects.

А "константы" - вообще разное. Сам по себе термин часто применяется не по месту. Ну это ладно. В С++ константы похожи на обычные переменные. Их видно в отладчике. С другой стороны, если нет запросов к адресу (например, &var), то компилятор не выделяет память под константу, а использует её значение в инструкциях. Но, если вдруг будет взятие адреса, то под константу будет выделена память. Т.е. оптимизация как бы ухудшается, но это лишний раз наглядно демонстрирует саму технологию. В С const имеет значительно меньший функционал.

  "Константная ссылка" и "константный указатель" - ошибочно, но общеупотребляемо.
  const references и const point - правильно.

  l-value
  r-value
  value categorries
*/

int main(void) {
	// Disable variable-length automatic arrays in gcc: -Werror=vla or -Wvla
	// vla - like built-in feature for dynamic array, depricated feature.
#define vla
#ifdef vla
	int a = 1;
	int arra[a]; // can be vla in C and in Cpp
	int const b = 1;// the C compiler cannot treat a "b" as a compile-time constant, the Cpp can
	int arrb[b]; // can be vla in C and will be non-vla in Cpp
#endif
#define CPP
#ifdef CPP
	int v1 = 1;
	//! int constexpr ce1 = v1;
	int const v2 = v1;
	//! int constexpr ce2 = v2;

	int const cv3 = 1;
	int constexpr ce3 = cv3;
	int constexpr ce4 = 1;

	int arr1[ce3];
	int arr2[ce4];
#endif
#define Cgcc81
#ifdef Cgcc81
	static int const sic = 5;
	static int si = sic;//static can be initialized by const in C gcc 8.1
	// note: const != constant or constant expression
	// В остальных случаях в C static должны инициализироваться только константами.
	// Однако, даже с такой темой массивы там будут создаваться vla, потому что это будет не константа.
#endif
#ifdef CPP
	static int sinc = 5;
	static int si2 = sinc;
#endif
	return 0;
}
#endif
// ссылки
#if 0
// "константная ссылка" - суть допущение, и не более того.
// ссылка - единственный тип данных на языке с++, который не обладает идентичностью.
// в отличие от указателей, ссылки - псевдоним имени объекта и не более того.
// это - единственный тип данных на языке, у которого нет собственных объектов.
// и нет квалификаторов, потому что не к чему их применять, потому что нет объекта, который можно(или нельзя) было бы изменить.
int main(void) {
	int var = 0;
	int const cvar = 0;
	//! int& ref = 0;// initial value of reference to non-const must be an lvalue
	int const& cref = 0;
	int&& rref = 0; // References to r-values extend the lifetime of the referenced value
	int const&& crref = 0;

	var += 1;
	//! cvar += 1;
	//!
	//! cref += 1;
	rref += 1;
	//! crref += 1;

	int var2 = var;
	int const cvar2 = var;
	int& ref2 = var;
	int const& cref2 = var;
	//! int&& rref2 = var; // an rvalue reference cannot be bound to an lvalue
	//! int const&& crref2 = var; // an rvalue reference cannot be bound to an lvalue

	var2 += 1;
	//! cvar2 += 1;
	ref2 += 1;
	//! cref2 += 1;
	//!
	//! 

	// With C++'s non-reseatable references ref1 still points to i and i is assigned the value. With reseatable references ref would point to k after evaluating this code. int k = 3; ref1 = k; // is equivalent to i = k; not to int& ref = k;
	//const int& refc{ 2 + 3 };//extended initializer lists int const & lv с++=11
	return 0;
}
#endif
// передача в функцию по ссылке и возврат в ссылку
#if 0
#include <iostream>
using namespace std;
void r(int& ref) {
	++ref;
}
int& arr(int number) {
	static int array[5] = { 1,2,3,4,5 };
	return array[number];
}
int f(void) {
	return 5;
}
int main(void) {
	int var = 1;
	r(var);
	cout << var << endl;  // 2

	arr(1) = 5;
	cout << arr(1) << endl;

	//int& ref = f(); // cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
	int const& cref = f();
	int&& rref = f();
	rref += 1;

	return 0;
}
#endif
// перегрузки ссылок
#if 0
void f1(int i) {}
//! void f1(const int i) {}//function 'void f1(int)' already has a body , определение перегрузки невозможно

void f2(int i) {}
void f2(int& i) {}

void f3(int& i) {}
void f3(const int& i) {}

//! void f4(int i) {}
//! void f4(const int& i) {}// определение перегрузки возможно, но вызов невозможен

int main(void) {
	int a = 1;
	int const b = 2;

	f1(a);
	f1(b);

	//! f2(a);// ambiguous
	f2(b);// calls f2(int)

	f3(a);// calls f3(int &)
	f3(b);// calls f3(const int&)

	//! f4(a); // ambiguous
	//! f4(b); // ambiguous

	return 0;
}
#endif

// ctor essential 1
#if 0
// К этому момент нужно чётко представлять механизмы передачи и возврата больших данных через стек в простом С-стиле.
// -fno-elide-constructors
struct A {
	int data;
	char code;
	A(int var1 = 0, char c = '\0') {
		data = var1;
		code = c;
	}
	A(A& var) {
		data = var.data;
		code = var.code;
	}
	A(A const& var) {
		data = var.data;
		code = var.code;
	}
	//! A(A var) {
	//!	  data = var.data;
	//!	  code = var.code;
	//! }	
	A(A&& var) {
		data = var.data;
		code = var.code;
		//var.memory = nullptr;
	}
};
A f(void) {
	A a;
	return a;
}
void v(A a) {

}
int main(void) {
	A a1;

	A const a2(2, 'z');

	A a3(a1);  // & или const &
	// адрес a3 неявно передается в конструктор

	A a4(a2);  // const&
	// адрес a4 неявно передается в конструктор

	// напоминание: возвращаемые данные f выделяются в стеке кадра main 
	A a5(f()); // const& или &&
	// адрес a5 неявно передается в f
	// return вызывает const &
		// но компилятор может пропустить этот вызов (оптимизация) и решать задачу в С стиле
			// тогда возможна ещё одна оптимизация: компилятор даже не будет создавать локальный a, а будет изменять a5 напрямую
	// или
	// return вызывает &&
		// && вызывается только с r-value
		// && позволяет изменять то, на что ссылается
		// адреса данных переносятся в a5
		// адреса данные в && обнуляются для защиты от delete
			// но компилятор может пропустить этот вызов (оптимизация) и решать задачу в С стиле
				// тогда возможна ещё одна оптимизация: компилятор даже не будет создавать локальный a, а будет изменять a5 напрямую

	// напоминание: передаваемые данные в v заталкиваются в стек кадра main 
	v(a1);// & или const&
	v(a2);// const&
	v(f());// const& или &&

	//! A a5.A();
	//! expected initializer before '.' token
	//! f().A();
	//! f().A(2, 'z');
	//! f()A();
	//! f()(2, 'z');
	return 0;
}
#endif
// ctor essential 2
#if 0
#include <iostream>
using namespace std;

class HowMany2 {
	int name;
	static int counter;
public:
	HowMany2(int id) {
		++counter;
		name = counter;
		cout << this << " " << name << " " << " (int) " << endl;
	}
	HowMany2(const HowMany2& h) {
		++counter;
		name = counter;
		cout << this << " " << name << " " << " (const HowMany2&) " << endl;
	}
	~HowMany2() {
		cout << this << " " << name << " " << " ~() " << endl;
	}
};

int HowMany2::counter = 0;

HowMany2 foo1 (void) {
#if 1
	HowMany2 h (123); 
	return h;
#else
	return HowMany2(123);// rvo
#endif
// Читай про различия  return value optimization и named return value optimization.

}

HowMany2 foo2 (HowMany2 x) {
	return x;
}

int main(void) {
	// foo1 ();

	// HowMany2 h1 (foo1());

	// HowMany2 h2 (2);

	// HowMany2 h3 (foo2 (h2));
	// without opt copy: h2 to x >>>> copy x to temporary >>>> copy temporary to h3
	// with    opt copy: h2 to x >>>>                     >>>> copy x to h3       

	// foo2 (h1);
	// without opt copy: h1 to x >>>> copy x to temporary 
	// with    opt copy: h1 to x >>>> copy x to temporary 

	cout << "end\n";
}

#endif
// ctor essential 3
#if 0

#endif
// мусор конструктор перемещения &&
#if 0
#include <iostream>
using namespace std;

#include <string>
struct myString {
	char* str;
	size_t length;

	myString(void) {
		str = nullptr;
		length = 0;
	}

	myString(char const* other_str) {
		length = strlen(other_str);
		str = new char[1 + this->length];
		if (str != nullptr) {
			for (size_t i = 0; i < length; ++i) {
				str[i] = other_str[i];// this->str[i] = str[i];
			}
			str[length] = '\0';
		}
	}

	myString operator+(myString const& other) {
		myString temp;
		temp.str = new char[1 + length + other.length];//other.length в class работает за счёт дружественности, в struct за счёт public
		temp.length = 1 + length + other.length;

		size_t c = 0;
		for (size_t i = 0; i < length; ++i, ++c) {
			temp.str[c] = str[i];
		}
		for (size_t i = 0; i < other.length; ++i, ++c) {
			temp.str[c] = other.str[i];
		}
		temp.str[length + other.length] = '\0';

		return temp;  //в этот момент вызывается const & или const &&
		// память для возвращаемого объекта уже выделена в main ранее
		// либо это временный объект, либо это локальный объект
		// адрес этого объекта передаётся неявно
		// адрес temp передаётся явно в const & или const &&
	}

	myString(myString const& other) {
		length = other.length;

		str = new char[1 + length];
		if (str != nullptr) {
			for (size_t i = 0; i < length; ++i) {
				str[i] = other.str[i];
			}
			str[length] = '\0';
		}
	}

	myString(myString&& other) { //конструктор перемещения может использоваться вместо конструктора копирования
		length = other.length;

		str = other.str;
		other.str = nullptr;//защищает str от деструктора, который будет очищать other.str объекта tmp
		// удобство кп в том, что он обрабатывает данные локальных объектов, которые будут уничтожены и не применяется к данным локальных объектов, которые не будут уничтожены
	}

	myString& operator=(myString const& other) {
		if (this->str != nullptr) {
			delete[] this->str;
		}
		this->length = strlen(other.str);
		this->str = new char[1 + this->length];
		for (size_t i = 0; i < this->length; ++i) {
			this->str[i] = other.str[i];
		}
		this->str[this->length] = '\0';
		return *this;
	}

	~myString(void) { delete[] str; }

	void Print(void) {
		cout << this->str << endl;
	}
};

int main(void) {
	myString string1("Hello");
	myString string2("LOL");
	myString result;

	result = string1 + string2;
	//result.operator=(string1.operator+(string2));
	//result.operator=( ...temporary... );

	result.Print();
	return 0;
}
#endif
// особенности дефолтных конструкторов
#if 0
#include <iostream>
#include <string>
using namespace std;
// WithCC
class WithCC {
public:
	WithCC(void) { cout << "WithCC void" << endl; }
	WithCC(const WithCC&) { cout << "WithCC &" << endl; }
};
class Composite {
	WithCC withcc;
public:
	// empthy
	// Composite(void) { cout << "Composite void" << endl; }
	// Composite(void) : withcc() { cout << "Composite void" << endl; }

	// empthy
	// Composite(Composite& ref) : withcc ( ref.withcc ) { cout << "Composite &" << endl; }

	// Composite(Composite& ref) { cout << "Composite &" << endl; }
	// Composite(Composite& ref): withcc() { cout << "Composite &" << endl; }
};
// main
int main(void) {
	Composite c;
	Composite c2 = c; // Calls copy-constructor
}
#endif
// странный прикол с  массивным мембером
#if 0
#include <stdio.h>
#define ? ? ?
struct test {
	int i[10];
	int j;
};

struct test foo(void) {
	struct test var;
	var.i[0] = 123;
	return var;
}

struct test const fooc(void) {
	struct test var;
	var.i[0] = 123;
	return var;
}

int main() {
#ifdef C
	foo().i[0] = 1;
	fooc().i[0] = 1;
#endif  // C
#ifdef CPP
	foo().i[0] = 1; // но ведь foo().j = 1; не работает!!! и это не должно работать.
	//! fooc().i[0] = 1;
#endif  // CPP

	return 0;
}
#endif

// const object
#if 0
// инициализация по умолчанию нулем, конечно же, не работает
class X {
	int i;
public:
	X(int ii);
	int f(void);
	int fc(void) const;
};
X::X(int ii) : i(ii) {
	;
}
int X::f(void) {
	++i;
	return i;
}
int X::fc(void) const {
	//! ++i;
	return i;
}

int main(void) {
	X x1(10);
	x1.f();
	x1.fc();
	const X x2(20);
	//! x2.f();
	x2.fc();
	return 0;
}
#endif

// operator =  and ctor
#if 0
class MyClass {
	int data;

public:
	MyClass (void)  { data = 0; }
	MyClass (int d) { data = d; }
	MyClass (MyClass const & other) { data = other.data; }
	MyClass & operator= (MyClass const & other) { data = other.data; return *this;	}
	~MyClass(void) { ; }
};
int main(void) {
	//! MyClass a(); // Это можно было бы уточнить намного раньше, но здесь это к месту из-за нюансов с =. Выглядит логично, но не работает, потому что это потребовало бы чрезмерной доработки анализатора, потому что выглядит как объявление функции. 
	// MyClass a; without parentheses void constructor is called.
	// MyClass a(1); with (value) non-void constructor is called.

	MyClass a;
	MyClass b(5);
	MyClass c(b);
	a = b;      // a.operator=(b);
	a = b = c;  // a.operator=(b.operator=(c));

	MyClass d = c;  // the copying constr works, because d has not created yet

	return 0;
}
#endif
// operator = and temporary
#if 0
class X {
  int i;
public:
  X(int ii = 0);
  // void operator= ( X & ) ;
  void operator= ( X const & ) ;
  // void operator= ( X & ) const;
  // void operator= ( X const & ) const;
};

  X::X (int ii) { i = ii; }
	void X::operator= (X const & ref) { ; }

X f6 (void) { 
	return X(123); 
	// local data1, X::X (123), 
	// local data2, X::X(X const &)
	// copy data2 in register
}
int main (void) {
  f6() = ( X(1) ); // X::X (1), f6(), from register to stack, X::operator= (X const &)
	//! f6() = X(1); in Eckel ;-)
  return 0;
}
#endif
// operator = 3 with automatic conversion
#if 0
class ByteE { 
  unsigned char b;
public:
  explicit ByteE(unsigned char bb = 0) : b(bb) {}
  ByteE & operator= (const ByteE & right) {
    if(this == &right) return *this;
    b = right.b;
    return *this;
  }
  ByteE & operator= (const int & right) { // or change to int 
    b = right;
    return *this;
  }
}; 

class Byte { 
  unsigned char b;
public:
  Byte(unsigned char bb = 0) : b(bb) {}
  Byte & operator= (const Byte & right) {
    if(this == &right) return *this;
    b = right.b;
    return *this;
  }
}; 

int main(void) {
  ByteE b1(1), b2(2);
  b1 = b2; 
  b1 = 2; 
	
	Byte b3(3), b4(4);
  b3 = b4; 
  b3 = 4; // automatic conversion via corresponding constructor
} 
#endif

// перегрузка оператора [], ссылки с массивами
#if 0
#include <iostream>
using namespace std;

class TestClass {
public:
	int& operator[](int index) {
		return arr[index];
	}

private:
	int arr[5]{ 11, 22, 33, 44, 55 };
};
int main(void) {
	TestClass a;
	cout << a[0] << endl;// 11 
	cout << a.operator[](0) << endl;// 11  
	a[0] = 66;
	cout << a[0] << endl;// 66 
	return 0;
}
#endif
// перегрузка операторов ++
#if 0
#include <iostream>
using namespace std;

class Point {
private:
	int x;
	int y;

public:
	Point(void) {
		cout << this << " cons void" << endl;
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		cout << this << " cons int int" << endl;
		this->x = x;
		this->y = y;
	}
	Point(Point const& other) {
		cout << this << " cons class&" << endl;
		this->x = other.x;
		this->y = other.y;
	}
	bool operator==(Point const& other) {
		return bool(this->x == other.x && this->y == other.y);
	}
	bool operator!=(Point const& other) {
		return bool(this->x != other.x && this->y != other.y);
	}
	Point operator+(Point const& other) {
		cout << this << " class operator+ (class&)" << endl;
		Point sum(this->x + other.x, this->y + other.y);
		return sum;
	}
	Point& operator=(Point const& other) {
		cout << this << " class& operator= (class&)" << endl;
		this->x = other.x;
		this->y = other.y;
		return *this;
	}
	Point& operator++(void) {
		++this->x;
		++this->y;
		return *this;
	}
	Point operator++(int value) {
		Point temp(*this);
		++this->x;
		// this->x++;
		++this->y;
		// this->y++;
		return temp;
	}
	void print(void) { cout << this->x << ' ' << this->y << endl; }
	~Point(void) { cout << this << " des" << endl; }
};
int main(void) {
	Point a(1, 2);
	Point b(3, 4);
	bool result = (a == b);
	++a;
	a++;

	return 0;
}
#endif
// ->
#if 0
struct Some {
  int a;
  int b;
};

int main(void){
  struct Some data;
  data.a = 0;
  struct Some * ptr = & data;
  (*ptr).b = 2;

  return 0;
}
main:
  pushl %ebp
  movl %esp, %ebp
  subl $16, %esp
  movl $0, -12(%ebp)
  leal -12(%ebp), %eax
  movl %eax, -4(%ebp)
  movl -4(%ebp), %eax
  movl $2, 4(%eax)
  movl $0, %eax
  leave
  ret
#endif
// operator->()
#if 0
#include <iostream>

class Some {
public:
	int a;
	Some* operator -> (void) {
		return this;
	}
};

int main(void) {
	Some s;
	s.a = 1;
	std::cout << s.a << std::endl;

	Some* ptr;
	ptr = &s;     //  Some * ptr (&s);
	(*ptr).a = 2;
	ptr->a = 2;   
	std::cout << s.a << std::endl;

	   s.operator->();
	(*(s.operator->() )).a = 3;
	(* s.operator->() ) .a = 3;
	(  s.operator->() )->a = 4;
	std::cout << s.a << std::endl;

	   s->a                = 4;//! (*s).a = 4;
	std::cout << s.a << std::endl;

	// .member или ->member  
	// нельзя (или очень затруднительно по смыслу) представить как sometype function (sometype member) { }
	// потому что подсчётом оффсета в стеке и арифметикой указателей занимается сам компилятор
	// а здесь объединяется два оператора -> в одном

	return 0;
}
#endif

// указатели, new, delete
#if 0

// vptr = iptr;//C, C++
// iptr = vptr;//C
//! iptr = vptr; // iptr = (int*)vptr; //C++

// A new-expression returns a pointer to an object of the exact type that you
// asked for.

#include <iostream>
using namespace std;

class MyClass {
  int data;

 public:
  MyClass(void) {
    cout << "MyClass:MyClass (void)" << endl;
  }
  MyClass(int d) {
    cout << "MyClass:MyClass (int )" <<endl;
    data = d;
  }
  ~MyClass(void) { 
		cout << "MyClass:~MyClass (void)" <<endl; 
	}
};

int main(void) {
  int* pa = 0;
  pa = NULL;
  pa = nullptr;  // for correct overloading (-std=c++11)

  pa = new int;
  delete pa;

  int size = 5;
  pa = new int[size];
  delete[] pa;

  pa = new int(1);
  std::cout << *pa << std::endl;
  delete pa;

  int A1[] = {1, 2, 3};
  int A2[]{1, 2, 3};

  int const sizeC = 3;
  int constexpr sizeCCC = 3;  //{3}
  int A3[sizeC]{1, 2, 3};

  MyClass* mcp = 0;
  mcp = new MyClass(123);
  delete mcp;

  mcp = new MyClass[3];
  delete []mcp;

  return 0;
}
#endif
// overloading new and delete 1
#if 0
// Call delete for a void* almost certainly going to be a bug if pointer is
// reffering to a type with destructor, because compiler will not call
// destructor. Vice versa, but compiler will warn. But operator delete itself
// have void * parameter by standart. So do not confuse. 
// new and void* operator new (size_t sz){;}  are not the same thing.
// new[] and void* operator new[] (size_t sz){;}  are not the same thing.
// All of this is static function (implicitly).

// new
// 1. local  overloaded new
// 2. global overloaded new
// 3. default new

// new []
// 1. local  overloaded new []
// 2. global overloaded new []
// 3. global overloaded new
// 4. default new []

#include <stdio.h>
#include <stdlib.h>

class MyClass {
  int arr[10];

 public:
  MyClass(void);
  ~MyClass(void);
  void* operator new(size_t sz);
  void* operator new[](size_t sz);
  void operator delete(void* m);
  void operator delete[](void* m);
};

MyClass::MyClass(void) { ; }

MyClass::~MyClass(void) { ; }

void* MyClass::operator new(size_t sz) {
  puts("operator MyClass::new");
  void* m = malloc(sz);
  if (!m) puts("out of memory");
  return m;
}
void* MyClass::operator new[](size_t sz) {
  puts("MyClass::operator new[]");
  void* m = malloc(sz);
  return m;
}

void MyClass::operator delete(void* m) {// 'operator delete' takes type 'void*' as first parameter
  puts("operator delete");
  free(m);
}
void MyClass::operator delete[](void* m) {
  puts("operator delete");
  free(m);
}

void* operator new(size_t sz) {
  puts("operator new");//Notice that printf( )and puts( )are used rather than iostreams. This is because when an iostream object is created (like the global cin, cout, and cerr), it calls new to allocate memory. With printf(), you don’t get into a deadlock because it doesn’t call new to initialize itself.
  void* m = malloc(sz);
  return m;
}
void* operator new[](size_t sz) {
  puts("operator new[]");
  void* m = malloc(sz);
  return m;
}

void operator delete(void* m) { 
  puts("operator delete");
  free(m);
}
void operator delete[](void* m) {
  puts("operator delete[]");
  free(m);
}

int main(void) {
  MyClass* ptr = 0;
  asm("nop");

  ptr = new MyClass;
  asm("nop");
  delete ptr;
  asm("nop");

  ptr = new MyClass[5];
  asm("nop");
  delete[] ptr;
  asm("nop");

  return 0;
}
#endif
// overloading new and delete 2
#if 0
#include <new>  // Size_t definition
using namespace std;
class Widget {
  enum { sz = 10 };
  int i[sz];

 public:
  Widget() { ; }
  ~Widget() { ; }
  void* operator new(size_t sz) {
    return ::new char[sz]; // return ::operator new (sz);
  }
  void* operator new[](size_t sz) {
    return ::new char[sz];
  }
  void operator delete(void* p) {
    ::delete[] p; // compiler will warn, but it is not a problem, because Widget:delete take responsibility for the good call 1 destructor  
  }
  void operator delete[](void* p) {
    ::delete[] p; // compiler will warn, but it is not a problem, because Widget:delete[] take responsibility for the good call 1 destructor 
  }
};
int main() {
  Widget* w = new Widget;
  delete w;
  Widget* wa = new Widget[25];
  delete[] wa;
}
#endif
// set_new_handler( )
#if 0
#include <cstdlib>   // exit();
#include <iostream>  // cerr
#include <new>       // set_new_handler()

using namespace std;
int count = 0;

void out_of_memory() {
	cerr << "memory exhausted after " << count << endl;
	exit(111);
}

int main() {
	set_new_handler(out_of_memory);
	while(1) {
		count++;
		new int[100000]; // Exhausts memory
	}
  return 0;
}
#endif
// manual exception
#if 0
#include <stddef.h>  //size_t
#include <stdlib.h>  //malloc

#include <iostream>  //cerr
#include <new>       //bad_alloc

using namespace std;

class Framis {
  char c[10];

 public:
  Framis() { ; }
  ~Framis() { ; }
  //void* operator new[](size_t) throw(bad_alloc);//-std=c++03
  void* operator new[](size_t) ;//-std=c++11
};

//void* Framis::operator new[](size_t sz) throw(bad_alloc) {//-std=c++03
void* Framis::operator new[](size_t sz) {//-std=c++11
  if (sz <= 50) {
    return malloc(sz);
  }
  throw bad_alloc();
}

int main(void) {
  try {
    new Framis[22];
  } catch (bad_alloc) {
    cerr << "Out of memory!" << endl;
  }
  return 0;
}
#endif
// explicit call to constructor and destructor
#if 0
#include <iostream>  

using namespace std;
class Widget {
  int data;

 public:
  Widget(void) { 
    std::cout << "Widget::Widget(void)"<<std::endl; 
  }
  ~Widget(void) {
    std::cout << "Widget::~Widget(void)"<<std::endl; 
  }
  
};

int main() {
	//! Widget::Widget();
	Widget();//create temporary, call construcotor for him, immediately call destructor for him
  
	Widget w;// declare object, define object and call constructor for him
  Widget w2();//warning: empty parentheses were disambiguated as a function declaration [-Wvexing-parse]
  
	//! w.Widget();
  w.~Widget();//  w.Widget::~Widget();
	
	Widget wp = new Widget;
	Widget wp2 = new Widget(); // :D
	delete wp;
	delete wp2;

	// second call destructor for w 
	return 0;
}
#endif
// placement new delete
#if 0
#include <iostream>  // Size_t definition
#include <new>       // Size_t definition
using namespace std;
class Widget {
  int data;

 public:
  Widget() { ; }
  Widget(int var) { data = var; }
  ~Widget() { ; }
  void* operator new(size_t sz, void * p) {
    return p;
  }
};

int main() {
  char arr [10];
  for (int i = 0; i<10; ++i) { 
    std::cout << (int) arr [i] << ' ';
  }
  std::cout << std::endl;

  Widget* w = new (arr) Widget(0x20202020);
  for (int i = 0; i<10; ++i) { 
    std::cout << (int)arr [i] << ' ';
  }
  std::cout << std::endl;

  w->~Widget();// w->Widget::~Widget(); // Explicit destructor call // ONLY use with placement!
	// delete w; // warning 'void operator delete(void*)' called on unallocated object 'arr' or stderr: free(): invalid pointer
}
#endif
// :D
#if 0
#include <iostream> 
#include <new>       // Size_t definition
using namespace std;
class Widget {
  int data;

 public:
  Widget() { ; }
  Widget(int var) { data = var; }
  ~Widget() { cout << "des" << endl; }
  // void* operator new(size_t sz, void * p) {
  //   return p;
  // }
  void operator delete(void * p) {
     ( (Widget*)p )-> Widget::~Widget();
  }
};

int main() {
  char arr [10];
  for (int i = 0; i<10; ++i) { 
    std::cout << (int) arr [i] << ' ';
  }
  std::cout << std::endl;

  Widget* w = new (arr) Widget(0x20202020);
  for (int i = 0; i<10; ++i) { 
    std::cout << (int)arr [i] << ' ';
  }
  std::cout << std::endl;

  delete w; // :D

  return 0;
}
#endif

// the constructor initializer list 1
#if 0
// it was originally developed for use in inheritance
#include <iostream>

class A {
public:
	A(int, char);
	void print(void);
private:
	const int constanta;
	char nonconstanta;
};
A::A(int var, char c) : constanta(var), nonconstanta(c) {
	;
}
void A::print(void) {
	std::cout << constanta << std::endl;
	std::cout << nonconstanta << std::endl;
}

int main(void) {
	A a(123, 'A');
	a.print();
	float pi(3.14159);// you can treat a built-in type as if it has a constructor
	return 0;
}
#endif
// constructor initializer list 2
#if 0
#include <iostream>
class Y {
public:
	Y(void);
	Y(int);
	void f(void);
};
Y::Y(void) { std::cout << "Initializing Y\n"; }
void Y::f(void) { std::cout << "Using Y\n"; }

class X {
public:
	X(void);
	X(Y& y);
};
X::X(void) { std::cout << "Initializing X\n"; }
X::X(Y& y) { y.f(); }

class Z {
public:
	Z(void);
protected:
	Y y_;// почему-то влияет последовательность 
	// ой ЛОЛ C14:Order.cpp
	// the order of constructor calls for member objects is completely unaffected by the order of the calls in the constructor initializer list
	X x_;
};
//↑↑   // Bad: should have listed x_ before y_
// Z::Z(void) : y_(), x_(y_) {
// Z::Z(void) : x_(y_), y_() {
// Z::Z(void) : x_(y_) {
// Z::Z(void) : y_() {
Z::Z(void) {
	;
}
int main(void) {
	Z z;
	return 0;
}

#endif
// static const (упрощенно)
#if 0
// эта фигня появилась в константах, потому что была нужна, но идейно она идет после пространств имен и статиков
// У статических констант в классах есть одна отличительная особенность: инициализация должна выполняться в точке определения. Это относится только статическим константам; как бы вам ни хотелось использовать инициализацию в точке определения в других ситуациях, она не будет работать, потому что остальные переменные должны инициализироваться конструктором или другими функциями класса.
class test {
private:
	static int const size = 10;// костыль на костыле
	// const одинаковые у всех объектов хочется
	// но нельзя инициализировать мемберов (до с++11)
	// constructor initializer list дергать каждый раз не хочется
	// тогда нужен static
	// но static в сочетании с const отличается от просто static
	int arr[size];
};
int main(void) {
	test obj;
	return 0;
}
#endif

// volatile
#if 0
class Comm {
public:
	int foo(void) const; // const для красоты
	int foov(void) volatile const; // const для красоты
};

int Comm::foo(void) const {
	return 1;
}
int Comm::foov(void) volatile const {
	return 2;
}

int main(void) {
	Comm Port;
	Port.foo();
	Port.foov();

	volatile Comm PortV;
	//! PortV.foo(); 
	PortV.foov(); // Error, read() not volatile
	return 0;
}
#endif
// inline
#if 0
#include <iostream>
#include <string>
using namespace std;
class Point {
	int i, j, k;
public:
	Point() : i(0), j(0), k(0) { }
	Point(int ii, int jj, int kk)
		: i(ii), j(jj), k(kk) { }
	void print(const string& msg = "") const {// inline implicity if has definition here... inline учитывается перед определением, а не объявлением (что абсолютно логично, если подумать подольше)
		if (msg.size() != 0) cout << msg << endl;
		cout << "i = " << i << ", "
			<< "j = " << j << ", "
			<< "k = " << k << endl;
	}
};
int main() {
	Point p, q(1, 2, 3);
	p.print("value of p");
	q.print("value of q");
}
#endif
// static in class (non-const, const)
#if 0
//MyClass.h
#pragma once

class MyClass {
	int data;
	int const c;
	static int s;
	static int const sic = 10;//спэсфский уникальный штуковина, это работает только с таким типом
	static double const sdc;
	static int ai[5];
public:
	MyClass(int = 0); // 
	int get_data(void);
	int get_c(void);
	int get_s(void);
	int get_sic(void);
	double get_sdc(void);
	static int Count;
};
//MyClass.cpp
#include "MyClass.h"

MyClass::MyClass(int var) : data(var), c(var) {
	// data(var) можно заменить на data = var; или this->data = var;
	// c(var) иначе никак

}

int MyClass::get_data(void) {
	return data;
}

int MyClass::get_c(void) {
	return c;
}

int MyClass::s = 123;//Эти определения обладают внутренним связыванием, поэтому могут размещаться в заголовочных файлах.
// непонятно как это, выдает ошибку already defined in main.obj

int MyClass::get_s(void) {
	return s;
}

int MyClass::get_sic(void) {
	return sic;
}

double const MyClass::sdc = 3.14;

double MyClass::get_sdc(void) {
	return sdc;
}

int  MyClass::ai[5];

int MyClass::Count = 0;

//main.c
#include <iostream>

#include "MyClass.h"

int main(void) {
	MyClass mc1;
	std::cout << mc1.get_data() << std::endl;//0

	MyClass mc2(2);
	std::cout << mc2.get_c() << std::endl;//2

	MyClass mc3(3);
	std::cout << mc3.get_s() << std::endl;//123

	MyClass mc4(4);
	std::cout << mc4.get_sic() << std::endl;//10

	MyClass mc5(5);
	std::cout << mc4.get_sdc() << std::endl;//3.14

	std::cout << MyClass::Count << std::endl;//0

	return 0;
}
//

// жесть
#if 0

#include <iostream>

class A {
public:
	static int const var1;
	static int const var2 = 2;// try literal (constant - in C...) ?

	void print(void) {
		std::cout << &var1 << std::endl;
		//! std::cout << &var2 << std::endl;
	}
};

int const A::var1 = 1;

int main() {
	std::cout << A::var1 << std::endl;
	std::cout << &(A::var1) << std::endl;
	std::cout << A::var2 << std::endl;
	//! std::cout << &(A::var2) << std::endl;

	int var3 = 3;
	int const var4 = 4;
	std::cout << &var3 << std::endl;
	std::cout << var3 << std::endl;
	std::cout << &var4 << std::endl;
	std::cout << var4 << std::endl;

	int array1[var4];
	int array2[A::var1];

	A a;
	a.print();

	return 0;
}
#endif

#endif
// more static
#if 0
//static objects of class types
	//assignment to zero has meaning only for built-in types; user - defined types must be initialized with constructor calls.
	//arrays of static objects of class types  
	//static const objects of class types
	//arrays of static const objects of class types  
//static data members in classes that are nested inside other classes
//you cannot have static data members inside local classes(a local class is a class defined inside a function)
#endif
// static member functions
#if 0
//доступны отовсюду
//Because they have no this pointer, static member functions can neither access non - static data members nor call non - static member functions.
//Конструкторы (фактически это non-static member function) не могут инициализировать static member в constructor initializer list, но могут изменять их в теле.
#include <iostream>

class A {
	static int data;
	int i;

public:
	static void set(int);
	static int get(void);
};

int A::data = 123;

void A::set(int var) {
	data = var;
	//! i = 555;  // a nonstatic member reference must be relative (to a specific object)
	//! this->i = 555;  //'this' may only be used inside a nonstatic member function weight = 555;
}

int A::get(void) {
	return A::data;
}//трында невнимательная int get(void) { return data; }

int main() {
	A::set(456);//что ты делаш в выводе std::cout << A::set(456) << std::endl;
	//! std::cout << A::data << std::endl; // из-за private
	std::cout << A::get() << std::endl;
	A a;
	std::cout << a.get() << std::endl;

	return 0;
}
#endif
// the "singleton" pattern
#if 0
#include <iostream>
using namespace std;
class Egg {
	static Egg e;
	int i;
	Egg(int ii) : i(ii) {}
	Egg(const Egg&); // Prevent copy-construction
public:
	static Egg* instance() { return &e; }
	int val() const { return i; }
};
Egg Egg::e(47);
int main() {
	//! Egg x(1); // Error -- can't create an Egg
	 // You can access the single instance:
	cout << Egg::instance()->val() << endl;
}
#endif
// static initialization dependency
#if 0
//file1
extern int x;
int y = x + 1;
//file2
extern int y;
int x = y + 1;
//main
#include <iostream>
using namespace std;
int main() {
	extern int x;
	extern int y;
	cout << "x " << x << endl;
	cout << "y " << y << endl;
	return 0;
}
//
g++ main.o f1.o f2.o
C : \Users\G\Desktop\cpp > a
x 1
y 2

g++ main.o f2.o f1.o
C : \Users\G\Desktop\cpp > a
x 2
y 1

// скорее всего, влияет не последовательность команд, а внутренняя логика, поэтому здесь видна только разница..
// вообще непонятно как это
#endif

// composition 1
#if 0
// the has-a relationship
// we don't need to use functions of Stack with StringStack itself
// instead we need to modify function of Stack for our needs in StringStack
#include <iostream>
#include <string>

using namespace std;

class Stack {
  struct Link {
    void* data;
    Link* next;
    Link(void* dat, Link* nxt): 
      data(dat), next(nxt) {}
  }* head;
public:
  Stack() : head(0) {

  }
  ~Stack() { 

  }
  void push(void* dat) {
    head = new Link(dat, head);
  }
  void* pop() {
    if(head == 0) return 0;
    void* result = head->data;
    Link* oldHead = head;
    head = head->next;
    delete oldHead;
    return result;
  }
  void* peek() const { 
    return head ? head->data : 0;
  }
};

class StringStack  {
  Stack s;
 public:
  void push(string* str) { s.push(str); }
  string* peek() const { return (string*)s.peek(); }
  string* pop() { return (string*)s.pop(); }
  ~StringStack() {
    string* top = pop();
    while (top) {
      delete top;
      top = pop();
    }
  }
};

int main(void){
  string line1("Hello!");
  string line2("I'm string!");
  
  StringStack  textlines;
  textlines.push(new string(line1));
  textlines.push(new string(line2));
  
  string* s;
  while((s = textlines.pop()) != 0) {
    cout << *s << endl;
    delete s; 
  }

  return 0;
}
// template 15 chapter
#endif
// composition 2
#if 0
class Engine {
public:
	void start() const {}
	void rev() const {}
	void stop() const {}
};
class Wheel {
public:
	void inflate(int psi) const {}
};
class Window {
public:
	void rollup() const {}
	void rolldown() const {}
};
class Door {
public:
	Window window;
	void open() const {}
	void close() const {}
};
class Car {
public:
	Engine engine;
	Wheel wheel[4];
	Door left, right; 
};

#endif
// composition operator=
#if 0
class Cargo {
public:
  Cargo& operator=(const Cargo&) {
		;     
    return *this;
  }
};

class Truck {
  Cargo b;
public:
  Truck const & operator= ( Truck const & r){
    b = r.b; // b.operator=(r.b); // b.Cargo::operator=(r.b);
    return *this;
  }
};

int main() {
  Truck a, b;
  a = b; // Prints: "inside Cargo::operator=()"
}
#endif

// useless inheritance
#if 0
// the is-a relationship here is broken
// using inheritance primarily to reuse code, and not to maintain the common interface of the base class (which is an essential aspect of polymorphism)
// C14:InheritStack.cpp
#include <iostream>
#include <string>

using namespace std;

class Stack {
  struct Link {
    void* data;
    Link* next;
    Link(void* dat, Link* nxt): 
      data(dat), next(nxt) {}
  }* head;
public:
  Stack() : head(0) {	; }
  ~Stack() { ; }
  void push(void* dat) {
    head = new Link(dat, head);
  }
  void* pop() {
    if(head == 0) return 0;
    void* result = head->data;
    Link* oldHead = head;
    head = head->next;
    delete oldHead;
    return result;
  }
  void* peek() const { 
    return head ? head->data : 0;
  }
};

class StringStack : private Stack  {
 public:
  void push(string* str) { Stack::push(str); }
  string* peek() const { return (string*)Stack::peek(); }
  string* pop() { return (string*)Stack::pop(); }
  ~StringStack() {
    string* top = pop();
    while (top) {
      delete top;
      top = pop();
    }
  }
};

int main(void){
  string line1("Hello!");
  string line2("I'm string!");
  
  StringStack  textlines;
  textlines.push(new string(line1));
  textlines.push(new string(line2));
  
  string* s;
  while((s = textlines.pop()) != 0) {
    cout << *s << endl;
    delete s; 
  }

  return 0;
}

#endif
// true inheritance 
#if 0
//: C14:FName2.cpp
// new type has exactly the same interface as the existing type (plus any other member functions you want to add)
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// class FName1 {
//   ifstream file; // a composition doesn't allow to call ifstream::close() of private object outside the class itself
// public:
//   operator ifstream&() { return file; } //  automatic type conversion happens only in function calls, not during member selection. So this approach won’t work.
//   void close (void){ file.close(); } // This will work if there are only a few functions you want to bring through from the ifstream class.
// Subtyping solves the problem

class FName2 : public ifstream {
  string fileName;
  bool named;

 public:
  FName2() : named(false) {}
  FName2(const string& fname) : ifstream(fname.c_str()), fileName(fname) {
    named = true;
  }
  string name() const { return fileName; }
  void name(const string& newName) {
    if (named) return;  // Don't overwrite
    fileName = newName;
    named = true;
  }
};

void function ( ifstream & r){
	;
}

int main() {
  FName2 file("FName2.cpp");
  cout << "name: " << file.name() << endl;
  
	string s;
  getline(file, s);  // These work too!
	function (file);

  file.seekg(-200, ios::end);
  file.close();

}
#endif
// inheritance and operator= 1
#if 0

class Byte { 
  unsigned char b;
public:
  Byte(unsigned char bb = 0) : b(bb) {}
  Byte& operator=(Byte const & right) {
    if(this == &right) return *this;
    b = right.b;
    return *this;
  }
}; 

class Byte2 : public Byte {
public:
  // Constructors don't inherit:
  Byte2(unsigned char bb = 0) : Byte(bb) {}  
  // operator= does not inherit
  // Only the SameType = SameType operator= is synthesized
  Byte2& operator=(Byte const & right) {
    Byte::operator=(right);
    return *this;
  }
  Byte2& operator=(int i) { 
    Byte::operator=(i);// will work due to non-explicit call to Byte::Byte (unsigned char)
    return *this;
  }
};

int main() {
	Byte b(1);
	Byte2 b2(2), b3(3);
  b2 = b3;// is synthesized
	b2 = b;
	b2 = 47;

	return 0;
}

#endif
// inheritance and operator= 2
#if 0

class Base {
  int data;
public:
  // Base & operator= (Base const & r) {// can be synthesized automatically
  //   data = r.data;  
  //   return *this;
  // }
};

class Derived : public Base {
  int data;
public:
  // Derived & operator= (Derived const & r){ // can be synthesized automatically
  //   Base::operator=(r);
  //   data = r.data;
  //   return *this;
  // }
	Derived const & operator= (Base const & r){//will not be synthesized automatically
    Base::operator=(r);
    return *this;
  }
};

int main() {
  Base b;
  Derived d1;
  
  Base & r = d1;
  //! Derived & d = b;
	
  b = d1;
	d1 = b;

	return 0;
}

#endif

// inner class
#if 0
#include <iostream>
#include <string>
class Image {
public:
	Image(void) {}
	void GetImageInfo(void) {
		for (int i = 0; i < LENGTH; i++) {
			std::cout << pixels[i].GetInfo() << std::endl;
		}
	}
	~Image(void) {}

private:
	class Pixel {
	public:
		Pixel(int r, int g, int b) {
			this->r = r;
			this->g = g;
			this->b = b;
		}
		std::string GetInfo(void) {
			return "Pixel: r = " + std::to_string(this->r) +
				" g = " + std::to_string(this->g) +
				" b = " + std::to_string(this->b);
		}

	private:
		int r;
		int g;
		int b;
	};
	static const int LENGTH = 3;  // const для массива, static для Image
	//static constexpr int LENGTH = 3;
	Pixel pixels[LENGTH]{
	 Pixel(0, 4, 64),
	 Pixel(4, 14, 10),
	 Pixel(111, 4, 24) };
};

int main(void) {
	Image img;
	img.GetImageInfo();

	return 0;
}
#endif
// aggregation, composition
#if 0
#include <iostream>
#include <string>

class Cap {  //aggregation
public:
	Cap(void) {}
	~Cap(void) {}
	std::string GetColor(void) {
		return this->color;
	}

private:
	std::string color = "red";
};

class Human {
public:
	Human(void) {}
	~Human(void) {}
	void Think(void) { brain.Think(); }  //делегирование паттерн
	void InspectCap(void) {
		std::cout << "man's cap is " << cap.GetColor() << std::endl;
	};

private:
	class Brain {  //composition
	public:
		Brain(void) {}
		~Brain(void) {}
		void Think(void) { std::cout << "I'm thinking" << std::endl; }

	private:
	};
	Brain brain;
	Cap cap;
};

int main(void) {
	Human man;
	man.Think();
	man.InspectCap();
	return 0;
}
#endif
// public, private, protected inheritance данные
#if 0
#include <iostream>
#include <string>

class Father {
public:
	std::string msgPublic = "msgPublic";
private:
	std::string msgPrivate = "msgPrivate";
protected:
	std::string msgProtected = "msgProtected";
};

class Publ : public Father {
public:
	void PrintPubl(void) {
		std::cout << msgPublic << std::endl;
		// ...
		std::cout << msgProtected << std::endl;
	}
private:

protected:
	//inh	std::string msgProtected = "msgProtected";
};

class Prv : private Father {  // public, protected > private
public:
	void PrintPrv(void) {
		std::cout << msgPublic << std::endl;
		// ...
		std::cout << msgProtected << std::endl;
	}
private:
	//inh	std::string msgPublic = "msgPublic";
	//inh 	std::string msgProtected = "msgProtected";
protected:

};

class Prot : protected Father {  // public , protected > protected
public:
	void PrintProt(void) {
		std::cout << msgPublic << std::endl;
		// ...
		std::cout << msgProtected << std::endl;
	}
private:

protected:
	//inh	std::string msgPublic = "msgPublic";
	//inh 	std::string msgProtected = "msgProtected";
};


int main(void) {
	Father a;
	a.msgPublic;

	Publ p;
	p.msgPublic;
	p.PrintPubl();

	Prv b;
	b.PrintPrv();

	Prot c;
	c.PrintProt();

	return 0;
}

#endif
// public, private, protected inheritance методы
#if 0
#include <iostream>
#include <string>

class Human {
public:
	void SetName(std::string name) { this->name = name; }
	std::string GetName(void) { return this->name; }
	std::string name = "none";
};

class Student : public Human {
public:
	//inh SetName
	//inh GetName
	void Learn(void) { //новый метод
		std::cout << GetName() << ": " << "I learn" << std::endl;
	}
	void Learn(std::string str) {//его перегрузка
		std::cout << GetName() << ": " << "I learn" << ' ' << str << std::endl;
	}
};

class ExStudent : public Student {
public:
	//inh SetName
	//inh GetName
	void Learn(void) { //экранирует область видимости Human::Student
		std::cout << GetName() << ": " << "I learn more" << std::endl;// идентификатор метода (независимо от оставшейся сигнатуры) экранирует метод предка и его перегрузки 
		using Human::Studen::Learn; // чтобы перегрузить нужно так (и параметры)
	}
};

class Test : public Student {
public:
	//inh SetName
	//inh GetName
	//inh Learn(void)
	//inh Learn(std::string str)
};

int main(void) {
	Student student1;
	ExStudent ex1;
	Test test1;

	student1.SetName("student1");
	ex1.SetName("ex1");
	test1.SetName("test1");

	student1.Learn();		//student1: I learn
	student1.Learn("it");	//student1: I learn it
	ex1.Learn();			//ex1: I learn more
	//ex1.Learn("it");		//err, такой реализации нет.
	test1.Learn();			//test1: I learn
	test1.Learn("it");		//test1: I learn it

	return 0;
}

#endif
// вызов конструктора предка из конструктора наследника
#if 0

#include <iostream>
#include <string>

class A {
public:
	A(void) {
		std::cout << "A void cons" << std::endl;
		this->msg = "none";
	}
	A(std::string msg) {
		std::cout << "A string cons" << std::endl;
		this->msg = msg;
	}
	~A(void) { std::cout << "A des" << std::endl; }
	void PrintMsg(void) { std::cout << msg << std::endl; }
private:
	std::string msg;
};

class B : public A {
public:
	B(void) : A() {// по умолчанию компилятор вызовет А(void)
		std::cout << "B void cons" << std::endl;
		this->var = 555;
	}
	B(std::string message) : A(message) {// по умолчанию компилятор вызовет А(void)
		std::cout << "B string cons" << std::endl;
		this->var = 666;
	}
	~B(void) { std::cout << "B des" << std::endl; }
	//PrintMsg() унаследован
private:
	int var;
	//private inheritance:
		//msg не унаследован, но доступен через унаследованные методы
};

// обычный режим работы
#if 0

int main(void) {
	A a;
	//A void cons

	B b;
	//A void cons
	//B void cons

	B b2("test");
	//A string cons
	//B string cons

	return 0;
	//B des
	//A des

	//B des
	//A des

	//A des
}

#endif

//работа операторов new и delete
#if 1

int main(void) {
	A* ptra = new A;
	//A void cons

	delete ptra;
	//A des

	B* ptrb = new B;
	//A void cons
	//B void cons
	delete ptrb;
	//B des
	//A des

	return 0;
}

#endif

#endif
// делегирующие конструкторы
#if 0
#include <iostream>
#include <string>

class Human {
public:
	Human(std::string name) {
		this->name = name;//если мы хотим изменить этот метод, то нам достаточно изменить его в одном месте.
		this->age = 0;
		this->weight = 0;
	}
	Human(std::string name, int age) : Human(name) {
		this->age = age;
	}
	Human(std::string name, int age, int weight) : Human(name, age) {
		this->weight = weight;
	}

private:
	std::string name;
	int age;
	int weight;
};

int main() {
	Human man1("Bob", 30, 85);
	return 0;
}
#endif
// виртуальные методы, полиморфизм
#if 0
// Функции позволяют утилизировать код. Далее, указатели на функции позволяют значительно менять логику функции в зависимости от того, с какими функциями она вызывается. Главное - строго соответствие типу указателя. Еще далее, наследование позволяет утилизировать код повторно, но с еще большей гибкостью. С одной стороны новый класс - это другой класс, т.е. сущность другого типа. И перегрузкой это не исправить, потому что придется создавать огромное количество перегрузок. Для этого и существуют виртуальные методы. Если компилятор видит несоответствие типов указателя и объекта - то он проверит их родственность. Затем он проверит наличие метода virtual. При соблюдении этих условий компилятор сможет разыменовать указатель класса А, указывающий на объект класса Б!
#include <iostream>

class A {
public:
	virtual void Shoot(void) {
		std::cout << "A!" << std::endl;
	}
};

class B : public A {
public:
	void Shoot(void) override { // override требует идентичности
		std::cout << "B!" << std::endl;
	}
};

class C : public A {
public:
	void Shoot(void) override {
		std::cout << "C!" << std::endl;
	}
};

class D : public C {
public:
	//int Shoot(void) {// err, overriding virtual function return type differs and is not covariant
	//void Shoot(int x) {// работает, но player.ShootOrAnyName(&d); даст С!

	//int  Shoot(void) override   {// err, override требует идентичности
	//void Shoot(int x) override {// err, override требует идентичности

	void Shoot(void) override {
		std::cout << "D!" << std::endl;
	}
};

class Player {
public:
	void ShootOrAnyName(A* gun) {
		gun->Shoot();
	}
};

int main(void) {
	A a;
	B b;
	C c;
	D d;

	A* aPtr = &a;// не удивляет
	B* bPtr = &b;// тоже не удивляет
	aPtr = &b; // может указывать на наследника

	aPtr->Shoot();//B!
	(*aPtr).Shoot();//B!

	Player player;
	player.ShootOrAnyName(&a);//A!
	player.ShootOrAnyName(&b);//B!
	player.ShootOrAnyName(&c);//C!
	player.ShootOrAnyName(&d);//D!

	return 0;
}
#endif
// чисто виртуальный метод, абстрактный класс
#if 0
#include <iostream>

class Weapon {  // дальнейшее развитие предыдущей идеи, удобен древовидностью, удобно, когда мы понятия не имеем какие еще наследники будут и какая у них будет реализация - player всегда сможет воспользоваться их методом Shoot
public:
	virtual void Shoot(void) = 0;//из-за одной чистой виртуальной функции класс является абстрактным, поэтому нельзя создавать его экземпляры
	void foo(int x) {}//но методы внутри создавать можно, они будут просто наследоваться
};

class Gun : public Weapon {
public:
	void Shoot(void) override {
		std::cout << "BANG!" << std::endl;
	}
};

class SubmacineGun : public Gun {
public:
	void Shoot(void) override {
		std::cout << "BANG!BANG!BANG!" << std::endl;
	}
};

class Bazooka : public Weapon {
public:
	void Shoot(void) override {
		std::cout << "BAAAAAAAM!" << std::endl;
	}
};

class Player {
public:
	void Shoot(Weapon* weapon) {
		weapon->Shoot();
	}
};

int main(void) {
	Gun pistol;
	SubmacineGun uzi;
	Bazooka rpg;

	Player player1;

	player1.Shoot(&pistol);
	player1.Shoot(&uzi);
	player1.Shoot(&rpg);

	Weapon* ptr;
	ptr = &pistol;
	ptr->Shoot();

	return 0;
}
#endif
// интерфейсы
#if 0
#include <iostream>
#include <string>

// человек может ехать на чем угодно, что имеет два колеса, велосипедный руль и педали.
// или метод может выводить данные из любой базы данных

//какой-то интерфейс
class Interface {
public:
	virtual void Foo1(void) = 0;
	virtual void Foo2(void) = 0;
private:

};

//класс, который умеет работать с наследниками интерфейса, которые будут передаваться сюда с помощью полиморфизма
class User {
public:
	void Use(Interface& ref) {
		ref.Foo1();
		ref.Foo2();
	}
	void Use1(Interface& ref) {
		ref.Foo1();
	}
	void Use2(Interface& ref) {
		ref.Foo2();
	}
private:

};

//не "класс наследует интерфейс", а "класс реализует интерфейс"
class Tech1 : public Interface {
public:
	void Foo1(void) override {
		//все, что угодно
	}
	void Foo2(void) override {
		//все, что угодно
	}
private:
};

//не "класс наследует интерфейс", а "класс реализует интерфейс"
class Tech2 : public Interface {
public:
	void Foo1(void) override {
		//все, что угодно
	}
	void Foo2(void) override {
		//все, что угодно
	}
private:
};

//возможно множественное наследование интерфейсов

int main() {
	User user;

	Tech1 t1;
	user.Use(t1);
	user.Use1(t1);
	user.Use2(t1);

	Tech2 t2;
	user.Use(t2);


	return 0;
}
#endif
// вызов виртуального метода базового класса
#if 0
#include <iostream>

class Msg {
public:
	Msg(std::string str) {
		this->str = str;
	}
	virtual std::string GetMsg(void) {
		return this->str;
	}
private:
	std::string str;
};

class BracketMsg : public Msg {
public:
	BracketMsg(std::string str) : Msg(str) {
		;
	}
	std::string GetMsg(void) override {
		//return "[" + this->str + "]";// нет доступа к private
		//std::string ret = GetMsg();// бесконечные вызовы
		std::string ret = ::Msg::GetMsg();
		return "[" + ret + "]";
	}
private:
	//str унаследован, но доступен только через унаследованные методы (если они есть), либо через костыль вышеописанный
};

class Printer {
public:
	void Print(Msg* ptr) {
		std::cout << ptr->GetMsg() << std::endl;
	}
};

int main() {
	Printer nomad;
	BracketMsg message("Hello!");
	nomad.Print(&message);

	return 0;
}
#endif
// виртуальный деструктор
#if 0

//операторы new и delete не могут работать c полиморфизмом без виртуального деструктора
#if 0

#include <iostream>
#include <string>
class A {
public:
	A(void) { std::cout << "A void cons" << std::endl; }
	~A(void) { std::cout << "A des" << std::endl; }

private:
};

class B : public A {
public:
	B(void) { std::cout << "B void cons" << std::endl; }
	~B(void) { std::cout << "B des" << std::endl; }

private:
};

int main(void) {
	A* ptra;
	ptra = new B;// оператор new работает с классом В, создает сущность класса В
	// A void cons
	// B void cons
	delete ptra;// оператор delete работает с классом А, в классе А нет деструктора класса В
	// A des
	// !!!!!!!!!!!!!!!!!!!!!!!!!

	return 0;
}

#endif
// добавление виртуального деструктора
#if 0

#include <iostream>
#include <string>
class A {
public:
	A(void) { std::cout << "A void cons" << std::endl; }
	virtual ~A(void) { std::cout << "A des" << std::endl; }
};

class B : public A {
public:
	B(void) { std::cout << "B void cons" << std::endl; }
	~B(void) override { std::cout << "B des" << std::endl; }// вызывается и наследник, и предок
};

int main(void) {
	A* ptra;
	ptra = new B;
	// A void cons
	// B void cons
	delete ptra;
	// B des
	// A des

	return 0;
}
#endif

#endif
// чисто виртуальный деструктор
#if 0
#include <iostream>
#include <string>
class A {
public:
	A(void) { std::cout << "A void cons" << std::endl; }
	virtual ~A(void) = 0;
};
A::~A(void) {};

class B : public A {
public:
	B(void) { std::cout << "B void cons" << std::endl; }
	~B(void) override { std::cout << "B des" << std::endl; }
};

int main(void) {
	A* ptra;
	ptra = new B;
	// A void cons
	// B void cons
	delete ptra;
	// B des

	return 0;
}
#endif
// множественное наследование, порядок вызова конструкторов и деструкторов
#if 0
#include <iostream>
// можно унаследовать один класс от нескольких других классов

class Car {
public:
	Car(void) {
		std::cout << "Car cons" << std::endl;
	}
	~Car(void) {
		std::cout << "Car des" << std::endl;
	}
	void Drive(void) {
		std::cout << "I'm driving" << std::endl;
	}
};

class Airplane {
public:
	Airplane(void) {
		std::cout << "Airplane cons" << std::endl;
	}
	~Airplane(void) {
		std::cout << "Airplane des" << std::endl;
	}
	void Fly(void) {
		std::cout << "I'm fly" << std::endl;
	}
};

class FlyingCar : public Car, public Airplane {
public:
	FlyingCar(void) {
		std::cout << "FlyingCar cons" << std::endl;
	}
	~FlyingCar(void) {
		std::cout << "FlyingCar des" << std::endl;
	}
};

int main(void) {
#if 0
	FlyingCar fc;
	fc.Drive();
	fc.Fly();
	//Car cons
	//Airplane cons
	//FlyingCar cons
	//I'm driving
	//I'm fly
	//FlyingCar des
	//Airplane des
	//Car des
#endif
#if 0
	FlyingCar fc;
	Car* ptr = &fc;
	Airplane* ptr2 = &fc;
#endif
#if 0
	FlyingCar* ptr;
	ptr = new FlyingCar;
	delete ptr;
	//Car cons
	//Airplane cons
	//FlyingCar cons
	//FlyingCar des
	//Airplane des
	//Car des
#endif
	return 0;
}
#endif
// одинаковые методы базовых классов при множественном наследовании
#if 0
#include <iostream>

class Car {
public:
	Car(void) {
		//std::cout << "Car cons" << std::endl;
	}
	~Car(void) {
		//std::cout << "Car des" << std::endl;
	}
	void Use(void) {
		std::cout << "Use Car" << std::endl;
	}
};

class Airplane {
public:
	Airplane(void) {
		//std::cout << "Airplane cons" << std::endl;
	}
	~Airplane(void) {
		//std::cout << "Airplane des" << std::endl;
	}
	void Use(void) {
		std::cout << "Use Airplane" << std::endl;
	}
};

class FlyingCar : public Car, public Airplane {
public:
	FlyingCar(void) {
		//std::cout << "FlyingCar cons" << std::endl;
	}
	~FlyingCar(void) {
		//std::cout << "FlyingCar des" << std::endl;
	}
};

int main() {
	FlyingCar fc;
	((Car)fc).Use();//fc приводится к Car
	((Airplane)fc).Use();

	return 0;
}
#endif
// ромбовидное наследование и виртуальное наследование
#if 0
//ромбовидное наследование
#if 0
#include <iostream>
#include <string>

class A {
public:
	A(int var) {
		std::cout << "A cons" << std::endl;
		this->var = var;
	}
private:
	int var;
};

class B1 : public A {
public:
	B1(int x) : A(x) {
		std::cout << "B1 cons" << std::endl;
	}
private:
	//private inheritance:
		//var унаследован
};

class B2 : public A {
public:
	B2(int x) : A(x) {
		std::cout << "B2 cons" << std::endl;
	}
private:
	//private inheritance:
		//var унаследован
};

class C : public B1, public B2 {
public:
	C(int x, int y) : B1(x), B2(y) {
		std::cout << "C cons" << std::endl;
	}
private:
	//private inheritance:
		//var унаследован
};

int main() {
	C c(1, 2);
	return 0;
}
//A cons
//B1 cons
//A cons
//B2 cons
//C cons
#endif
//виртуальное наследование
#if 0
#include <iostream>
#include <string>

class A {
public:
	A(void) {
		this->var = 0;
	}
	A(int var) {
		std::cout << "A cons" << std::endl;
		this->var = var;
	}
private:
	int var;
};

class B1 : public virtual A {
public:
	B1(void) {
		std::cout << "B1 cons" << std::endl;
	}
private:
	//private inheritance:
		//var унаследован
};

class B2 : public virtual A {
public:
	B2(void) {
		std::cout << "B2 cons" << std::endl;
	}
private:
	//private inheritance:
		//var унаследован
};

class C : public B1, public B2 {
public:
	C(int x) : A(x) {
		std::cout << "C cons" << std::endl;
	}
private:
	//private inheritance:
		//var унаследован
};

int main() {
	C c(1);
	return 0;
}
//A cons
//B1 cons
//B2 cons
//C cons
#endif

#endif

// Построчное копирование файлов Эккель
#if 0
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(void) {
	ifstream in("Scopy1.cpp"); // Открытие файла для чтения
	string s;

	ofstream out("Scopy2.cpp"); // Открытие файла для записи
	
	while (getline(in, s)) // Символ новой строки при чтении теряется...
		out << s << "\n";// ... поэтому его необходимо передать отдельно.

	ifstream in("FillString.cpp"); // Открытие файла для чтения
	string s, line;
	while(getline(in, line))
		s += line + "\n";
	std::cout << s;

 ifstream in("Fillvector.cpp");
 string line;
 vector<string> v;
 while(getline(in, line))
 	v.push_back(line); // Add the line to the end

 for(int i = 0; i < v.size(); i++)
 	cout << i << ": " << v[i] << endl;

}
#endif
// работа с файлами
#if 0

#include <iostream>
#include <string>
	// cin, cout, cerr, clog
#include <fstream>
	// ifstream - чтение
	// fstream - запись и чтение
	// ofstream - запись
// Do not mistake header and class.

int main() {
	std::string path = "myFile.txt";

	//recreating, opening
	std::ofstream fout;
	fout.open(path);
	//if (!fout.is_open()) {//catch лучше обработка исключений
	//	std::cout << "err" << std::endl;
	//}
	fout << "our data\n";
	fout.close();
	//recreating, opening, adding
	fout.open(path, std::ofstream::app);
	fout << "enother data\n";
	fout.close();

	//reading
	std::ifstream fin;
	fin.open(path);
	char ch;
	while (fin.get(ch)) {
		std::cout << ch;
	}
	fin.close();

	//reading in string
	fin.open(path);
	std::string str;
	while (!fin.eof()) {
		str = " ";
		fin >> str;// >> считывает данные до первого пробела...
		std::cout << str << std::endl;// \n в "enother data\n" имеет символ переноса, eof не считает этот символ за символ конца файла, поэтому цикл срабатывает, fin не считает этот символ за символ, и не выполняет запись в str.
	}
	fin.close();

	//reading in string better
	fin.open(path);
	if (!fin.is_open()) {
		std::cout << "err" << std::endl;
	}
	while (!fin.eof()) {
		std::getline(fin, str);
		std::cout << str << std::endl;
	}
	fin.close();

	//reading in string not better
	fin.open(path);
	if (!fin.is_open()) {
		std::cout << "err" << std::endl;
	}
	char strOfChar[50];
	while (!fin.eof()) {
		fin.getline(strOfChar, 50);
		std::cout << strOfChar << std::endl;
	}
	fin.close();

	return 0;
}
#endif
// запись объекта в файл
#if 0
#include <fstream>
#include <iostream>

class Point {
public:
	Point(void) {
		x = y = z = 0;
	}
	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void Print(void) {
		std::cout
			<< "x " << x
			<< " y " << y
			<< " z " << z
			<< std::endl;
	}
	int x;
	int y;
	int z;
};

int main() {
	Point dot1(0x1234, 0x123456, 0x12345678);
	Point dot2(15, 11, 36);
	std::string path = "point.txt";

	std::ofstream fout;
	fout.open(path, std::ofstream::app);
	if (!fout.is_open()) {
		std::cout << "err" << std::endl;
	}
	fout.write((char*)&dot1, sizeof(Point));
	fout.write((char*)&dot2, sizeof(Point));
	fout.close();

	std::ifstream fin;
	fin.open(path);
	if (!fin.is_open()) {
		std::cout << "err" << std::endl;
	}
	Point pnt;
	while (fin.read((char*)&pnt, sizeof(Point))) {//возвращает true пока удается считать блок
		pnt.Print();
	}
	fin.close();

	return 0;
}
#endif
// чтение и запись в файл c помощью fstream
#if 0
#include <fstream>
#include <iostream>

int main() {
	std::string path = "fstream.txt";
	std::string msg;

	std::fstream fs;
	fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);
	if (!fs.is_open()) {
		std::cout << "err" << std::endl;
	}

	int value;
	std::cin >> value;

	if (value == 1) {
		std::cin >> msg;
		fs << msg << '\n';
	}
	if (value == 2) {
		while (!fs.eof()) {
			msg = "";
			fs >> msg;
			std::cout << msg << std::endl;
		}
	}

	fs.close();

	return 0;
}
#endif

// перегрузка >> <<
#if 0
// public переменные
#if 0
#include <fstream>
#include <iostream>
#include <string>
class Point {
public:
	Point(void) {
		x = y = z = 0;
	}
	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	int x;
	int y;
	int z;
};

//перегружаем операторы для классов, в которые не можем влзеть
//классы острим, фстрим и пр. свзаны по цепочке наследования
std::ostream& operator<< (std::ostream& os, const Point& point) {
	os << point.x << " " << point.y << " " << point.z;
	return os;
}

std::istream& operator>> (std::istream& is, Point& point) {
	is >> point.x >> point.y >> point.z;
	return is;
}

int main() {
	Point dot(1, 2, 3);
	std::string msg;
	std::string path = "fstream.txt";
	std::fstream fs;

	//int x = 5;
	//std::cin >> x; // работает, потому что есть реализация
	//std::cout << x;  
	//fs >> x;          
	//fs << x;          

	//std::cin  >> dot; // пока не работает
	//std::cout << dot; 
	//fs >> dot;        // и мы не можем влезть в класс fstream, например  
	//fs << dot;        

	//дальше идет магия с классом...

	std::cout << dot << std::endl;

	fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);
	fs << dot << "\n";
	fs.close();

	fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);
	fs >> dot;
	fs.close();

	std::cout << dot << std::endl;

	fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);
	while (true) {
		dot.x = dot.y = dot.z = 0;
		fs >> dot;
		if (fs.eof()) {//для борьбы с выводом нулей
			break;
		}
		std::cout << dot << std::endl;
	}
	fs.close();

	return 0;
}
#endif
// private переменные
#if 1
#include <fstream>
#include <iostream>
#include <string>
class Point {
public:
	Point(void) {
		x = y = z = 0;
	}
	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
private:
	int x;
	int y;
	int z;
	friend std::ostream& operator<< (std::ostream& os, const Point& point);
	friend std::istream& operator>> (std::istream& is, Point& point);

};

//перегружаем операторы для классов, в которые не можем влзеть
//классы острим, фстрим и пр. свзаны по цепочке наследования
std::ostream& operator<< (std::ostream& os, const Point& point) {
	os << point.x << " " << point.y << " " << point.z;
	return os;
}

std::istream& operator>> (std::istream& is, Point& point) {
	is >> point.x >> point.y >> point.z;
	return is;
}

int main() {
	Point dot(1, 2, 3);
	std::string msg;
	std::string path = "fstream.txt";
	std::fstream fs;

	std::cout << dot << std::endl;

	fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);
	fs << dot << "\n";
	fs.close();

	fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);
	fs >> dot;
	fs.close();

	std::cout << dot << std::endl;

	fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);
	while (true) {
		Point dot;
		fs >> dot;
		if (fs.eof()) {
			break;
		}
		std::cout << dot << std::endl;
	}
	fs.close();

	return 0;
}
#endif
#endif
//  try catch обработка исключений
#if 0
#include <fstream>
#include <iostream>
#include <string>

int main(void) {
	std::string path = "nocreated";

	std::ifstream fin;
	fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);// чтобы включить try catch...

#if 0
	try // если что-то не так, то эта часть бросит исключение
	{
		std::cout << "trying" << std::endl;
		fin.open(path);//если здесь будет ошибка, то следующая инструкция не будет выполнена
		std::cout << "successfully opened";
	}
	catch (const std::exception& ex) //  если тру бросила исключение, то эта часть кода его пытается поймать
	{
		std::cout << ex.what() << std::endl;// возвращаемое методом зависит от разработчика класса
		std::cout << "err open" << std::endl;
	}
#endif
#if 1
	try
	{
		std::cout << "trying" << std::endl;
		fin.open(path);
		std::cout << "successfully opened";
	}
	catch (const std::ifstream::failure& ex)
	{
		std::cout << ex.what() << std::endl;
		std::cout << ex.code() << std::endl;
		std::cout << "err open" << std::endl;
	}
#endif

	fin.close();

	return 0;
}
#endif
// генерация исключений
#if 0
#include <iostream>

#if 0
void Foo(int value) {
	if (value < 0) {
		throw value;
	}

	std::cout << value << std::endl;
}
int main(void) {
	Foo(55);
	try
	{
		Foo(-55);
	}
	catch (const int ex)
	{
		std::cout << "catched " << ex << std::endl;
	}

	return 0;
}
#endif
#if 0
void Foo(int value) {
	if (value < 0) {
		throw "value is less than 0";
	}

	std::cout << value << std::endl;
}
int main(void) {
	Foo(55);
	try
	{
		Foo(-55);
	}
	catch (const char* ex)
	{
		std::cout << "catched " << ex << std::endl;
	}

	return 0;
}
#endif
#if 1
void Foo(int value) {
	if (value < 0) {
		throw std::exception("values is less than zero");//exception это базовый класс для обработки исключений
	}

	std::cout << value << std::endl;
}
int main(void) {
	Foo(55);
	try
	{
		Foo(-55);
	}
	catch (const std::exception& ex)
	{
		std::cout << "catched " << ex.what() << std::endl;
	}

	return 0;
}
#endif
#endif
// собственный exception 122 заебало
#if 0
#include <iostream>

int main() {

	return 0;
}
#endif
// шаблонные функции, generic programming
#if 0

#include <iostream>

//function-template definitions begin with keyword template followed by a list of template parameters to the function template enclosed in angle brackets(<and >). The type template parameters of a function-template definition are used to specify the types of the function’s parameters, to specify the return type of the function and to declare variables within the function.
//template <class T1, class T2>
template <typename T1, typename T2>
void Foo(T1 a, T2* b, int c) {
	std::cout << a << " " << *b << " " << c << std::endl;
}

template <class T>
T Foo2(T a) {
	return a + 1;
}

int main(void) {
	int x = 123;
	char c = 'A';
	Foo(1, &x, 3);
	//When the compiler detects a Foo function invocation in the client program, the compiler uses its overload resolution capabilities to find a definition of function Foo that best matches the function call. 
	//In this case, the only Foo function with the appropriate number of parameters is the Foo function template. 
	//The compiler compares the type of Foo’s first argument(int) to the Foo function template’s first parameter(T1) and deduces that replacing the type parameter T1 with int would make the argument consistent with the parameter. Он делает тоже самое со вторым параметром. Then, the compiler substitutes int for T1 and int* for T2 throughout the template definitionand and compiles a Foo specialization that can display int, int* and int. 
	//The compiler creates two Foo specializations—one that expects an int, int*, int and one that expects a double, char* int.
	//For example, the function-template specialization for type int and int* is:
	//	void Foo(int a, int* b, int c) {
	//		std::cout << a << " " << *b << " " << c << std::endl;
	//	}
	Foo(3.14, &c, 3);
	std::cout << Foo2(5) << std::endl;//		10
	std::cout << Foo2(5.2) << std::endl;//		10.4
	std::cout << Foo2<int>(5.2) << std::endl;//	10

	return 0;
}
#endif
// шаблоны классов (обобщенные классы)
#if 0
#include <iostream>

//Class templates are called parameterized types, because they require one or more type parameters to specify how to customize a “generic class” template to form a class - template specialization.
template <typename T1, typename T2>//template <class T1, class T2>
class MyClass
{
public:
	MyClass(T1 value1, T2 value2) {
		this->value1 = value1;
		this->value2 = value2;
	}
	void DataTypeSize(void) {
		std::cout << sizeof(value1) << std::endl;
		std::cout << sizeof(value2) << std::endl;
	}
	T1 Foo(void) {
		return this->value1;
	}
private:
	T1 value1;
	T2 value2;
};

class Point
{
public:
	Point(void) {
		x = y = z = 0;
	}
	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	int x;
	int y;
	int z;
};

int main(void) {
	int a = 5;
	Point dot;

	MyClass <int, Point> temp(a, dot);// MyClass temp(a, dot);// 14 er 17 ok
	temp.DataTypeSize();
	a = 1 + temp.Foo();

	return 0;
}

#endif
// наследование шаблонных классов
#if 0
#include <iostream>
#include <string>
#include <typeinfo>

//template <typename T1>
template <class T1>
class TypeSize
{
public:
	TypeSize(T1 value)
	{
		this->value = value;
	}
	void DataTypeSize(void)
	{
		std::cout << sizeof(value) << std::endl;
	}
protected://для доступа ShowTypeName
	T1 value;
};

template <class T1>
//class TypeInfo : public TypeSize <int> // предок работает с кем угодно, наследник только с int
class TypeInfo : public TypeSize <T1> // из-за того, что класс шаблонный, то приходится указывать <>.
{
public:
	//TypeInfo(T1 value) : TypeSize (value) // err
	TypeInfo(T1 value) : TypeSize <T1>(value)
	{

	}
	void ShowTypeName(void)
	{
		//std::cout << typeid(value).name() << std::endl;//err
		std::cout << typeid(TypeSize<T1>::value).name() << std::endl;//typeid класс, который имеет методы
	}
private:
};

int main(void)
{
	int a = 5;
	TypeInfo <int> ti(a);
	ti.DataTypeSize();//4
	ti.ShowTypeName();//int

	return 0;
}
#endif
// специализация шаблона класса
#if 0
#include <iostream>
#include <string>

template <typename T>
class Printer {
public:
	void Print(T value) {
		std::cout << value << std::endl;
	}
};

template<>
class Printer <double> {
public:
	void Print(double value) {
		std::cout << "double " << value << std::endl;
	}
};

int main() {
	Printer <int> pi;
	pi.Print(545);

	Printer <std::string> ps;
	ps.Print("Hello");

	Printer <double> pd;
	pd.Print(3.13);

	return 0;
}
#endif
// bitset
#if 0
#include <bitset>
#include <iostream>

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits) {
	if (bits.test(3)) {
		bits <<= 1;
		bits.set(0);
	}
	else {
		bits <<= 1;
	}
	return bits;
}
void rotl(char* ptr) {
	char temp = *ptr;

	if (temp & (1 << 7)) {
		// 0000 0001
		// 1000 0000

		// 1000 0000
		//         &
		// 1xxx xxxx

		// 1000 0000

		temp <<= 1;  // temp = temp << 1 ;
		temp |= 1;
	}
	else {
		temp <<= 1;
	}

	*ptr = temp;
}
std::bitset<4> rotl2(std::bitset<4> bits) {
	const bool leftbit{ bits.test(3) };
	bits <<= 1;  // do left shift
	if (leftbit) bits.set(0);
	return bits;
}
std::bitset<4> rotl3(std::bitset<4> bits) {
	// bits << 1 does the left shift
	// bits >> 3 handle the rotation of the leftmost bit
	return (bits << 1) | (bits >> 3);
	//Xxxx

	//000X
	//    |
	//xxx0

	//xxxX
}

int main() {
	int y{ 5 };
	// std::bitset<2> bbb{x};
	std::bitset<2> aaa = y;

	unsigned int x = 5;
	std::bitset<2> bbb{ x };
	std::cout << bbb << std::endl;

	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

	return 0;
}
#endif
// string vector array
#if 0

// string
#if 0
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool isAnagram(std::string str1, std::string str2) {
	transform(str1.begin(), str1.end(), str1.begin(), tolower);
	transform(str2.begin(), str2.end(), str2.begin(), tolower);

	std::sort(str1.begin(), str1.end());
	std::sort(str2.begin(), str2.end());

	bool answ = false;
	if (str1 == str2) {
		answ = true;
	}
	return answ;
}

int main(void)
{
	string str1 = "abc";
	string str2 = "cba";
	cout << isAnagram(str1, str2);

	return 0;
}
#endif

// vector
#if 1
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <iterator>  // For std::begin and std::end
#include <vector>

using std::cout;
using std::endl;
using namespace std;

void printLength(const std::vector<int>& vct) {
	std::cout << vct.size() << std::endl;  // std::vector<int>::size_type
}

int main() {
	std::vector<int> Data;
	std::vector<int> Dataa{};
	std::vector<int> Dataaa(Data);
	std::vector<int> Data1(3);		// у вектора нельзя сразу и указать размер, и инициализировать
	std::vector<int> Data2{ 9, 7, 5 };
	std::vector Data3{ 9, 7, 5 };		//as with std::array, the type can be omitted since C++ 17

	Data.resize(5);
	//Data.reserve(5); // ???
	std::cout << Data.size() << std::endl;      // 5
	std::cout << Data.capacity() << std::endl;  // 5
	printLength(Data3);  // The size is: 3

	auto begin{ Data.begin() };
	auto end{ Data.end() };
	auto begin2 = std::begin(Data);
	auto end2 = std::end(Data);
	for (auto p = begin; p != end; ++p) {
		std::cout << *p << ' ';// 0 0 0 0 0
	}
	std::cout << std::endl;

	for (int i : Data) { // int i is iterator, that designed to traverse through a container  
		std::cout << i << ' ';// 0 0 0 0 0
	}
	std::cout << std::endl;

	Data = { 11, 22, 33 };// ????????????????????????
	//Note that although we assigned a smaller array to our vector, it did not reallocate its memory(the capacity is still 5). It simply changed its length, so it knows that only the first 3 elements are valid at this time.
	// The range for the subscript operator ([]) and at() function is based on the vector’s length 
	// Data[4] = 4; //err
	// Data[5] = 5; //err
	std::cout << Data.size() << std::endl;      // 5
	std::cout << Data.capacity() << std::endl;  // 3
	//Data.reserve(5); // можно добавить резерв, тогда cap сразу будет 5, а не 1,2,3

	for (int i : Data) {
		std::cout << i << ' ';  // 11 22 33
	}
	std::cout << std::endl;

	try
	{
		cout << "\nAttempt to display integers1.at( 15 )" << endl;
		cout << Data.at(15) << endl; // ERROR: out of range
	} // end try
	catch (out_of_range& ex)
	{
		cout << "An exception occurred: " << ex.what() << endl;
	}

	std::vector<int> stack{};

	stack.push_back(1);// push_back() pushes an element on the stack
	stack.push_back(2);
	stack.push_back(3);

	cout << stack.capacity() << endl;
	cout << stack.size() << endl;
	cout << stack.back() << endl; //top: 3 // back() returns the last element

	for (auto element : stack) {
		std::cout << element << ' ';
	}
	std::cout << std::endl;

	stack.pop_back();// pop_back() pops an element off the stack
	stack.pop_back();
	stack.pop_back();


	std::vector<int> data7;
	for (int i = 0; i < 15; ++i) { // Vectors may allocate extra capacity
		data7.push_back(i);
	}
	std::cout << "capacity " << data7.capacity() << ' '; // 19
	std::cout << "size " << data7.size() << std::endl; // 15

	for (auto element : data7) std::cout << element << ' ';

	return 0;
}
#endif

// array
#if 0
#include <array>
#include <iostream>

int main() {
	std::array<int, 5> Arr{ 1, 2, 3 };
	std::cout << Arr.size() << '\n';//5
	std::array Arr2{ 1, 2, 3 };
	std::cout << Arr2.size() << '\n';//3

	return 0;
}
#endif

#endif
//
#if 0
#include <iostream>

int main() {

	return 0;
}
#endif
