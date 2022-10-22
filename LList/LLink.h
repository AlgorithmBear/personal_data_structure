#pragma once
#include"link.h"

template<class E>
class CLList : public CLink<E>{
private:
	CLink<E>* head;
	CLink<E>* curr;
	int num;
	void Clear() {
		CLink<E>* tmp = head->next;
		CLink<E>* tmp1;
		while (tmp != NULL) {
			tmp1 = tmp;
			tmp = tmp->next;
			head->next = tmp;
			delete tmp1;
		}
	}
public:
	CLList() {
		curr=head = new CLink<E>();
		num = 0; 
	}
	~CLList() {
		while (head != NULL) {
			CLink* temp;
			temp = head;
			head = head->next;
			delete temp;
		}
	}


};


//------------------综合题3---------------------
template<class E>
CLList<E>* MergeList(CLList<E>* listA, CLList<E>* listB) {
	CLList<E>* ret;
	ret->head = listA->head;
	ret->curr = NULL;
	listA->curr = listA->head->next;
	listB->curr = listB->head->next;
	while (listA->curr != NULL || listB->curr != NULL) {
		if (listA->curr == NULL && listB->curr != NULL) {
			while (listB->curr != NULL) {
				CLink* tmp;
				tmp = listB->curr;
				listB->curr = listB->curr->next;
				tmp->next = ret->curr;
				ret->curr = temp;
				ret->head->next = ret->curr;
			}

		}
		if (listA->curr != NULL && listB->curr == NULL) {
			while (listA->curr != NULL) {
				CLink* tmp;
				tmp = listA->curr;
				listA->curr = listB->curr->next;
				tmp->next = ret->curr;
				ret->curr = temp;
				ret->head->next = ret->curr;
			}

		}
		if (listA->curr ！== NULL && listB->curr != NULL) {
			if(listA->curr->elem<=listB->curr->elem) {
				CLink* tmp;
				tmp = listA->curr;
				listA->curr = listA->curr->next;
				tmp->next = ret->curr;
				ret->curr = temp;
				ret->head->next = ret->curr;
			}
			else {
				CLink* tmp;
				tmp = listB->curr;
				listB->curr = listB->curr->next;
				tmp->next = ret->curr;
				ret->curr = temp;
				ret->head->next = ret->curr;
			}
		}
	}

	return ret;
}








//-----------------综合题7-----------------
template<class E>
CLink<E>* Locate(CLList<E> * lList,int pos) {
	CLink* ret = lList->head->next;
	for (int i = 1; i <= pos; i++) {
		if (ret== NULL&&i<=pos)
			return NULL;
		ret = ret->next;
	}
	return ret;
}

template<class E>
CLink<E>* GetMax(CLList<E>* lList) {
	CLink<E>* maxPos, * tmp;
	maxPos = tmp = lList->head->next;
	while (tmp != NULL) {
		if (maxPos->elem < tmp->elem) {
			maxPos = tmp;
		}
		tmp = tmp->next;
	}
	return maxPos;
}

template<class E>
int Number(CLList<E>* lList,E elemVal) {
	CLink<E>* tmp;
	int ret = 0;
	tmp = lList->head->next;
	while (tmp != NULL) {
		if (tmp->elem == elemVal)
			ret++;
		tmp = tmp->next;
	}
	return ret;
}

template<class E>
CLList<E> Create(E*, int num) {
	CLink<E>* head=new CLink<E>();
	CLink<E>* tmp;
	CLink<E>* curr;
	for (int i = 0; i < num; i++) {
		tmp = new CLink<E>(E[i], NULL);
		curr->next = tmp;
		curr = curr->next;
	}
	return head;
}

template<class E>
void tidyup(CLList<E>& list) {
	CLink<E>* pre, * after;
	if (list.head->next == NULL )
		return;
	pre = list.head->next;
	after = pre->next;
	while (after != NULL) {
		if (pre->elem == after->elem) {
			pre->next = after->next;
			delete after;
			after = pre->next;
		}
		pre = after;
		after = after->next;
	}
}