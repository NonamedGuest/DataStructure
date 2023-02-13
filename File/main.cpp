#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BST.h"

struct tChar
{
	char	tmp[64];
};

int main()
{
	BST tree;
	tChar* pWordTable = new tChar[64];
	int i = 0;

	FILE* pFile = fopen("test.txt", "r+t");

	if (NULL != pFile)
	{
		while (fscanf(pFile, "%s", (pWordTable + i)->tmp) != EOF)
		{
			tree.insert((pWordTable + i)->tmp);
			++i;
		}
		fclose(pFile);
	}
	else 
	{
		std::cout << "������ ������ �ʾҽ��ϴ�.\n";
	}

	std::cout << "===========================================================\n";
	std::cout << "Words                    Count\n";
	std::cout << "===========================================================\n";
	tree.in_order(tree.get_root());


	return 0;
}