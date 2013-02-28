//============================================================================
// Name        : Hello.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <future>

using namespace std;

void bar()
{
	cout << "!!!Hello World!!!" << endl;
}

int main() {
	future<void> f1(async(bar));

	return 0;
}
