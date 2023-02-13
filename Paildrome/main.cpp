#include <iostream>
#include "Deque.h"


int main()
{
	Deque DQ;

	DQ.add_front('l');
	DQ.add_front('e');
	DQ.add_front('v');
	DQ.add_front('e');
	DQ.add_front('l');
	DQ.add_front('l');

	DQ.Print();
	DQ.delete_front();

	int wtf = DQ.Palindrome();
	std::cout << "DQ : " << wtf << std::endl;


	return 0;
}