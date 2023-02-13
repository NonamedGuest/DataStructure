#include "Deque.h"

Deque::Deque() :
	m_iCount(0),
	m_front(nullptr),
	m_rear(nullptr)
{

}

Deque::~Deque()
{

}

int Deque::is_empty()
{
	return (m_front == nullptr);
}

// 연결리스트로 구현하기 때문에 가득 찰 경우가 없다.
int Deque::is_full()
{
	return 0;
}

char Deque::get_front()
{
	if (is_empty())
	{
		return -1;
	}
	
	return m_front->m_chData;
}

char Deque::get_rear()
{
	if (is_empty())
	{
		return -1;
	}

	return m_rear->m_chData;
}

void Deque::add_front(char _chData)
{
	tNode*	pNewNode = new tNode;
	pNewNode->m_chData = _chData;

	if (is_empty())
	{
		m_front = m_rear = pNewNode;
	}
	else
	{
		// front 조정
		pNewNode->m_pNext = m_front;
		m_front->m_pPrev = pNewNode;
		m_front = pNewNode;

		// rear 조정
		m_rear->m_pNext = m_front;
		m_front->m_pPrev = m_rear;
	}

	++m_iCount;
}

void Deque::add_rear(char _chData)
{
	tNode*	pNewNode = new tNode;
	pNewNode->m_chData = _chData;

	if (is_empty())
	{
		m_front = m_rear = pNewNode;
	}
	else
	{
		// rear 조정
		pNewNode->m_pPrev = m_rear;
		m_rear->m_pNext = pNewNode;
		m_rear = pNewNode;

		// front 조정
		m_rear->m_pNext = m_front;
		m_front->m_pPrev = m_rear;
	}

	++m_iCount;
}

char Deque::delete_front()
{
	if (is_empty())
		return -1;

	char reVar = m_front->m_chData;

	tNode* pDeleteNode = m_front;

	m_front->m_pNext->m_pPrev = m_rear;
	m_front = m_front->m_pNext;

	delete pDeleteNode;

	return reVar;
}

char Deque::delete_rear()
{
	if (is_empty())
		return -1;

	char reVar = m_rear->m_chData;

	tNode* pDeleteNode = m_rear;

	m_rear->m_pPrev->m_pNext = m_front;
	m_rear = m_rear->m_pPrev;

	delete pDeleteNode;

	return reVar;
}

void Deque::Print()
{
	tNode* pNext = m_front;
	for (int i = 0; i < m_iCount; ++i)
	{
		std::cout << pNext->m_chData << " ";
		pNext = pNext->m_pNext;
	}
	std::cout << "\n";
}

int Deque::Palindrome()
{
	tNode*	pNext = m_front;
	tNode*	pPrev = m_rear;
	
	int iVar = 1;

	int iCall = m_iCount / 2;

	for (int i = 0; i < iCall; ++i)
	{
		if (pNext->m_chData != pPrev->m_chData)
			iVar = -1;

		pNext = pNext->m_pNext;
		pPrev = pPrev->m_pPrev;
	}

	return iVar;
}