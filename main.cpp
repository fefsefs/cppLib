#include <iostream>
#include "linkedList.h"
int main(void){
	using namespace pDStructures;

	linkedListNode<int> headTest(1);

	int a = 9;

	std::cout << headTest.getData() << std::endl;	

	std::cout << headTest.setData(a) << std::endl;
	
	std::cout << headTest.getData() << std::endl;

	return 0;
}
