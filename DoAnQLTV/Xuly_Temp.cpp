#include "XuLy_Temp.h"

void initList_TEMPLIST(LIST_TEMPLIST& l)
{
	l.pHead = l.pTail = NULL;

}

NODE_TEMPLIST* GetNode_TEMPLIST(uint index, uint MADG)
{
	NODE_TEMPLIST* p = new NODE_TEMPLIST;
	if (p == NULL) {
		return NULL;
	}
	p->tl.index = index;
	p->tl.MADG = MADG;
	p->pNext = NULL;
	return (p);
}

void AddTailList_TEMPLIST(LIST_TEMPLIST& l, uint index, uint MADG)
{
	// tao Node
	NODE_TEMPLIST* p = GetNode_TEMPLIST(index, MADG);
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;

	}
}

NODE_TEMPLIST* Middle(NODE_TEMPLIST* start, NODE_TEMPLIST* last)
{
	if (start == NULL)
		return NULL;
	NODE_TEMPLIST* slow = start;
	NODE_TEMPLIST* fast = start->pNext;

	while (fast != last)
	{
		fast = fast->pNext;
		if (fast != last)
		{
			slow = slow->pNext;
			fast = fast->pNext;
		}
	}
	return slow;
}

// nen su dung tim kiem tuyen tinh vi cai nao cung bigO(n)
NODE_TEMPLIST* BinarySearch_TEMPLIST(LIST_TEMPLIST l, uint index)
{
	NODE_TEMPLIST* start = l.pHead;
	NODE_TEMPLIST* last = NULL;
	do
	{	//tim phan tu giua
		NODE_TEMPLIST* mid = Middle(start, last);
		// neu phan tu giua null
		if (mid == NULL)
			return NULL;

		// neu gia tri do bang voi phan tu giua
		if (mid->tl.index == index)
			return mid;
		// neu gia tri do lon hon phan tu giua
		else if (mid->tl.index < index)
			start = mid->pNext;
		// neu gia tri nho hon phan tu giua
		else
			last = mid;
	} while (last == NULL || last->pNext != start);
	return NULL;
}

void ClearAll_TEMPLIST(LIST_TEMPLIST& l)
{
	NODE_TEMPLIST* p;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
