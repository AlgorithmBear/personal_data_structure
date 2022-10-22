#pragma once
template<class E>
class CLink {
private:
	static CLink* freelist;
public:
	E elem;
	CLink* next;
	CLink(const E& elemval, CLink* nextval) {
		this->elem = elemval;
		this->next = nextval;
	}
	CLink() {
		this->next = NULL;
	}
	void* operator new(size_t) {
		if (freelist == NULL)
			return ::new CLink;
		CLink<E>* temp = freelist;
		freelist = freelist->next;
		return temp;
	}
	void operator delete(void* ptr) {
		(CLink<E>*)ptr->next = freelist;
		freelist = ptr;
	}
};
