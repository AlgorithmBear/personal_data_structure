#pragma once
#include<iostream>
using namespace std;

class test {
public:
	static	void printHello() {
		cout << "test";
	}
};
int main() {
	//std::cout << sizeof(size_t)<<"   "<<sizeof(unsigned int);
	test::printHello();
}