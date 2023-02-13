#pragma once
#include <iostream>
// ���ð� ť�� Ư¡�� ��� ���� ���� �ڷᱸ��

// - �տ��� �����͸� ������ �� �ְ�, ������ �� �� ������,
// - �ڿ��� �����͸� ������ �� �ְ�, ������ �����ϴ�.

struct tNode
{
	char	m_chData;
	tNode*	m_pPrev;
	tNode*	m_pNext;
	
	tNode() :
		m_chData(0),
		m_pPrev(nullptr),
		m_pNext(nullptr)
	{

	}
};

class Deque
{
private:
	int		m_iCount;			// ���� ����ִ� ���� ������ ����
	tNode*	m_front;			// ���� ���� ��
	tNode*	m_rear;				// ���� ���� ��

public:
	int		is_empty();			// ���� ���� ���ΰ� ����ִ� �� Ȯ��
	int		is_full();			// ���� ���� ���ΰ� ���� �� �ִ� �� Ȯ��

	char	get_front();		// ���� ���� �տ��� �����͸� ������ �Լ�
	char	get_rear();			// ���� ���� �ڿ��� �����͸� ������ �Լ�

	void	add_front(char _chData);
	void	add_rear(char _chData);

	char	delete_front();
	char	delete_rear();

	void Print();

	int Palindrome();
	
public:
	Deque();
	~Deque();

};

