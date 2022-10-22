#pragma once
template<class E, class comp>class heap {
private:
	E* Heap;//指向存放数据的数组
	int maxsize;
	int n;//当前堆上数据的个数
	void siftDown(int pos) {
		while (!isLeaf(pos)) {
			int j = leftChild(pos);
			int rc = rightChild(pos);
			if (rc < n && Heap[j] < Heap[rc]) {
				j = rc;
			}  //选出子节点中较大的那个，跟该节点比较
			if (Heap[pos] > Heap[j])
				return;
			swap(Heap, j, pos);
			pos = j;   //不怎么理解，为什么是往大的子节点往下down。
		}
	}

public:
	heap(E * h,int num,int max) {//传入指向该数组的首地址
		Heap = h;
		n = num;
		maxsize = max;
	}
	int size() const {//在函数后面加上const禁止了该函数改变类的成员变量
		return n;
	} 
	bool isLeaf(int pos) const {
		return   (pos >= n / 2) && (pos < n); //不是很理解，但是盲猜，总节点数量的一半对于完全满二叉树来说，就是最底下一行的节点
	}
	int leftChild(int pos)const {
		return 2 * pos + 1;
	}
	int rightChild(int pos) const {
		return 2 * pos + 2;
	}
	int parent(int pos)const {
		return (pos - 1) / 2;
	}
	void buildHeap() {

	}

	void swap(int pos, int pos) {

	}

	void inser(const E& it)  {
		if (n >= maxsize) {

		}
		Heap[n++] = it;
		siftDown();
	}
};