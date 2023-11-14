#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>


class My_cat {
	char* name;
	int weight;


public:
	My_cat();
	My_cat(const char* name);
	My_cat(const My_cat& cat);
	My_cat(My_cat&& cat);
	~My_cat();

	// eat 함수 선언
	// drink 함수 선언
	My_cat& eat(int num);
	My_cat& drink(int num);
	void show_status() const;
};

My_cat::My_cat() :name(NULL), weight(10) { }



My_cat::My_cat(const char* cat_name) : weight(10) {
	name = new char[strlen(cat_name) + 1];
	strcpy(name, cat_name);
}

My_cat::My_cat(const My_cat& cat) : weight(10) { // Copy constructor
	std::cout << "Copy constructor invocation ! " << std::endl;
	name = new char[strlen(cat.name) + 1];
	strcpy(name, cat.name);
}
/*
My_cat::My_cat(My_cat&& cat) : weight(10){

}*/

My_cat::~My_cat() {		// Destructor
	if (name) delete[] name;
}

/* eat 함수 구현 */
My_cat& My_cat::eat(int num){
	weight += num;
	return *this;
}
My_cat& My_cat::drink(int num){
	weight += num;
	return *this;
}


/* drink 함수 구현 */

void My_cat::show_status() const {
	std::cout << " Weight : " << weight << std::endl;
}
int main() {
	My_cat cat1("Nabi");	// Cat 1 생성
	cat1.show_status();

	cat1.eat(4);
	cat1.show_status();

	cat1.drink(1);
	std::cout << " and drinking water -> ";
	cat1.show_status();

	cat1.eat(4);
	cat1.show_status();
	
	cat1.drink(1);
	std::cout << " and drinking water -> ";
	cat1.show_status();

	cat1.eat(4).eat(5).eat(6); // hint: 이런 형태의 연산 지원을 위해서는 this 키워드와 레퍼런스 활용이 요구됨
	cat1.show_status();

	cat1.drink(1).drink(2);
	std::cout << " and drinking water -> ";
	cat1.show_status();

	getchar();
	return 0;
}
