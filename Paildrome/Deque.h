#pragma once
#include <iostream>
// 스택과 큐의 특징을 모두 합쳐 놓은 자료구조

// - 앞에서 데이터를 가져올 수 있고, 삭제도 할 수 있으며,
// - 뒤에서 데이터를 가져올 수 있고, 삭제도 가능하다.

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
	int		m_iCount;			// 덱에 들어있는 현재 데이터 개수
	tNode*	m_front;			// 덱의 제일 앞
	tNode*	m_rear;				// 덱의 제일 뒤

public:
	int		is_empty();			// 현재 덱의 내부가 비어있는 지 확인
	int		is_full();			// 현재 덱의 내부가 가득 차 있는 지 확인

	char	get_front();		// 덱의 제일 앞에서 데이터를 얻어오는 함수
	char	get_rear();			// 덱의 제일 뒤에서 데이터를 얻어오는 함수

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

