#pragma once

struct Word
{
	char*		pWord;
	int			iCount;

	static int compare_word(const char*, const char*);
};

struct tBSTNode
{
	Word		Data;
	tBSTNode*	pParent;
	tBSTNode*	pLChild;
	tBSTNode*	pRChild;

	tBSTNode(char* _data) :
		Data{ _data, 1 },
		pParent(nullptr),
		pLChild(nullptr),
		pRChild(nullptr)
	{

	}
};

class BST
{
private:
	tBSTNode*	m_pRoot;
	int			m_iCount;

public:
	void insert(char* _data);

	void in_order(tBSTNode* _tNode);

	void search(tBSTNode* _tNode, char* _data);

	tBSTNode* get_root();

public:
	BST();
	~BST();
};