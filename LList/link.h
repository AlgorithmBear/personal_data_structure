#pragma once
template<class E>
class link {
private:
	static link* freelist;
public:
	E element;
	link* next;
	link(const E& elemval, link* nextval = NULL);
	link(link* nextval = NULL);
	void* operator new(size_t);
	void operator delete(void *ptr);
};