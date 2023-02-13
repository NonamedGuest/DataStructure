#pragma once
#include "BST.h"
#include <iostream>
#include <cstring>
#include <assert.h>

int Word::compare_word(const char* _one, const char* _another)
{
	// ���ο� �����Ͱ� ũ�� 1, ���ο� �����Ͱ� ������ -1, ������ 0
	int iCompare = 0;

	int iOneLeng = (strlen(_one) < strlen(_another)) ? strlen(_another) : strlen(_one);

	for (int i = 0; i < iOneLeng; ++i)
	{
		if (_one[i] < _another[i])
		{
			iCompare = 1;
			break;
		}
		else if (_one[i] > _another[i])
		{
			iCompare = -1;
			break;
		}
	}

	return iCompare;
}

void BST::insert(char* _data)
{
	tBSTNode* pNewNode = new tBSTNode(_data);
	int Dupl = 0;

	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		tBSTNode* pCurNode = m_pRoot;
		tBSTNode* pPrevNode = nullptr;
		int iCompare = 0, iDupl = 0;
		while (pCurNode)
		{
			// ���� ������ & ���ο� ������ ��
			iCompare = Word::compare_word(pCurNode->Data.pWord, pNewNode->Data.pWord);

			// LChild
			if (-1 == iCompare)
			{
				pPrevNode = pCurNode;
				pCurNode = pCurNode->pLChild;
			}
			// RChild
			else if (1 == iCompare)
			{
				pPrevNode = pCurNode;
				pCurNode = pCurNode->pRChild;
			}
			else if (0 == iCompare)
			{
				++pCurNode->Data.iCount;
				iDupl = Dupl = 1;
				break;
			}
		}
		
		if (nullptr == pPrevNode)
			return;

		iCompare = Word::compare_word(pPrevNode->Data.pWord, pNewNode->Data.pWord);
		if (-1 == iCompare && 0 == iDupl)
		{
			pPrevNode->pLChild = pNewNode;
			pNewNode->pParent = pPrevNode;
		}
		else if (1 == iCompare && 0 == iDupl)
		{
			pPrevNode->pRChild = pNewNode;
			pNewNode->pParent = pPrevNode;
		}
	}
	if (0 == Dupl)
		++m_iCount;
}

void BST::in_order(tBSTNode* _tNode)
{
	if (_tNode)
	{
		in_order(_tNode->pLChild);
		std::cout << _tNode->Data.pWord << "               " << _tNode->Data.iCount << "\n";
		in_order(_tNode->pRChild);
	}
}

void BST::search(tBSTNode* _tNode, char* _data)
{
	tBSTNode* pTarget = _tNode;
	int iCompare = 0, iCheck = 0;
	
	if (nullptr == pTarget)
	{
		assert(nullptr);
	}

	while (pTarget)
	{
		iCompare = Word::compare_word(pTarget->Data.pWord, _data);
		// Same
		if (0 == iCompare)
		{
			std::cout << "ã���� �ϴ� �ܾ �����մϴ� :: " << _data << "\n";
			iCheck = 1;
			break;
		}
		// LChild
		else if (-1 == iCompare)
		{
			pTarget = pTarget->pLChild;
		}
		// RChild
		else if (1 == iCompare)
		{
			pTarget = pTarget->pRChild;
		}
	}
	if (0 == iCheck)
		std::cout << "ã�� �ܾ �����ϴ�.\n";
}

tBSTNode* BST::get_root()
{
	return m_pRoot;
}

BST::BST() :
	m_pRoot(nullptr),
	m_iCount(0)
{
}

BST::~BST()
{
}