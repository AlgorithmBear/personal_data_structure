#pragma once
#include<iostream>
#include"LLink.h"
#include"link.h"
using namespace std;


int main() {
	CLink<int>test;
	int a[2] = { 0,1 };
	int* b = a;
	for (int i = 0; i < 2; i++) {
		cout << b[i];
	}

}