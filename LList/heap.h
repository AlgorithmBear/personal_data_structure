#pragma once
template<class E, class comp>class heap {
private:
	E* Heap;//ָ�������ݵ�����
	int maxsize;
	int n;//��ǰ�������ݵĸ���
	void siftDown(int pos) {
		while (!isLeaf(pos)) {
			int j = leftChild(pos);
			int rc = rightChild(pos);
			if (rc < n && Heap[j] < Heap[rc]) {
				j = rc;
			}  //ѡ���ӽڵ��нϴ���Ǹ������ýڵ�Ƚ�
			if (Heap[pos] > Heap[j])
				return;
			swap(Heap, j, pos);
			pos = j;   //����ô��⣬Ϊʲô��������ӽڵ�����down��
		}
	}

public:
	heap(E * h,int num,int max) {//����ָ���������׵�ַ
		Heap = h;
		n = num;
		maxsize = max;
	}
	int size() const {//�ں����������const��ֹ�˸ú����ı���ĳ�Ա����
		return n;
	} 
	bool isLeaf(int pos) const {
		return   (pos >= n / 2) && (pos < n); //���Ǻ���⣬����ä�£��ܽڵ�������һ�������ȫ����������˵�����������һ�еĽڵ�
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