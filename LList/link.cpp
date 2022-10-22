#pragma once
#include"link.h"
#include<iostream>
template<class E>
	link<E>::link(const E& elemval, link* nextval) {
		this->element = elemval;
		this->next = nextval;
	}
template<class E>
	link<E>::link(link* nextval) {
		this->next = nextval;
	}
template<class E>
void* link<E>::operator new(size_t ) {
	if (freelist == NULL)
		return ::new link;
	link<E>* temp = freelist;
	freelist = freelist->next;
	return temp;
	}
template<class E>
void link<E>::operator delete(void * ptr) {
	(link<E>*)ptr->next = freelist;
	freelist = ptr;
}

template<class E>
link<E> *link<E>::freelist = NULL;