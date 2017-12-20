#pragma once
template<class T>
struct Node {
	T key;
	/*
	....������Ҫ��ӡ�
	*/
};
template<class T>
class SSearch {
private:
	Node<T> *ST;//����ַ��
	int len;//����
public:
	SSearch();//���캯����
	~SSearch();//����������ɾ����ռ䣻
	void Create(int n);//����ʱ�����û�������Ϊ��Ӧ������Ԫ�ظ�ֵ��
	void Display();//�����̬���е�����Ԫ�أ�
	int GetLen();
	int SeSearch(T key);//�ӱ������һ��Ԫ�ؿ�ʼ˳����ң�
	void Ascendsort();//�������У�
	int BiSearch_1(T key);//�۰���ң��ǵݹ��㷨��
	int BiSearch_2(T key);//�۰���ң��ݹ��㷨��
	int BiSearch(int x, int y, T key);//�۰���ҵݹ飻
	void BInsertSort();//�۰��������
	void QuitSort();//��������
	void SelectSort();//��ѡ������
	int SelectMinKey(int n);
	void HeapSort();//������
};
template<class T>
int SSearch<T>::GetLen() {
	return len;
}
template <class T>
SSearch<T>::SSearch() {
	ST = NULL;
	len = 0;
}
template<class T>
SSearch<T>::~SSearch() {
	delete ST;
	len = 0;
}
template<class T>
void SSearch<T>::Create(int n) {
	len = n;
	ST =  new Node<T>[len+1];
	Node<T>e;
	cout << "������" << len << "������Ԫ�أ�";
	for (int i = 1; i < len+1; i++) {
		cin >> e.key;
		ST[i] = e;
	}
}
template<class T>
void SSearch<T>::Display() {
	int i;
	cout << "��̬���е�����Ԫ��Ϊ��";
	for (i = 1; i < len ; i++) {
		cout << ST[i].key << ",";
		
	}
	if (i = len) cout << ST[i].key << endl;
}


/************˳�����************/
template<class T>
int SSearch<T>::SeSearch(T key) {
	ST[0].key = key;
	for (int i = len; ST[i].key<key||ST[i].key>key; i++);
	if (i == 0) cout << "���Ҳ��ɹ���" << endl;
	return i;
}
/************˳�����************/


/************�۰����************/
template<class T>
int SSearch<T>::BiSearch_1(T key) {
	if (len == 0 && ST == NULL) {
		cout << "��̬�����ڣ������½�����\n";
		return -1;
	}
	else {
		int low = 1, high = len, mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (key == ST[mid].key) { 
				return mid;
				break;
			}
			else if (key < ST[mid].key) high = mid - 1;
			else if (key > ST[mid].key) low = mid + 1;
		}
		return -1;
	}
}
template<class T>
int SSearch<T>::BiSearch(int x, int y, T key) {
	int mid = (x + y) / 2;
	if (ST[mid].key == key) {
		return mid;
	}
	else if (x > y)
		return -1;
	else if (key < ST[mid].key) return BiSearch(x, mid - 1, key);
	else
		return BiSearch(mid + 1, y, key);
}
template<class T>
int SSearch<T>::BiSearch_2(T key) {
	int k;
	k = BiSearch(1, len, key);
	return k;
}
/************�۰����************/



/************�۰��������************/
template<class T>
void SSearch<T>::BInsertSort() {
	int high, low, mid;
	for (int i = 2; i <=len; i++) {
		ST[0].key = ST[i].key;
		low = 1;
		high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (ST[0].key <= ST[mid].key)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (int j = i - 1; j >= high + 1; --j)
			ST[j + 1].key = ST[j].key;
		ST[high + 1].key = ST[0].key;
	}
}
/************�۰��������************/



/************��������************/
template<class T>
int Partition(Node<T> *ST,int low,int high) {
	T pivotkey;
	ST[0].key = ST[low].key;
	pivotkey = ST[low].key;
	while (low < high) {
		while (low < high&&ST[high].key >= pivotkey) --high;
		ST[low].key = ST[high].key;
		while (low < high&&ST[low].key <= pivotkey) ++low;
		ST[high].key = ST[low].key;
	}
	ST[low].key = ST[0].key;
	return low;
}

template<class T>
void Qsort(Node<T> *ST, int low, int high) {
	int mid;
	if (low < high) {
		mid = Partition(ST, low, high);
		Qsort(ST, low, mid-1);//�Ե��ӱ��������
		Qsort(ST, mid+1, high);//�Ը��ӱ��������

	}
}

template<class T>
void SSearch<T>::QuitSort() {
	Qsort(ST, 1, len);
}
/************��������************/


/************��ѡ������************/
template<class T>
int SSearch<T>:: SelectMinKey(int n){
	int min = n;
	T minkey;
	minkey = ST[n].key;
	for (int i = n + 1; i < len; i++) {
		if (ST[i].key < minkey) {
			minkey = ST[i].key;
			min = i;
		}
	}
	return min;
}

template<class T>
void SSearch<T>::SelectSort() {
	int j;
	T t;
	for (int i = 1; i < len; i++) {
		j = SelectMinKey(i);
		if (i != j) {
			t = ST[i].key;
			ST[i].key = ST[j].key;
			ST[j].key = t;
		}
	}
}
/************��ѡ������************/


/************������************/
template<class T>
void HeapAdjust(Node<T> *ST, int s, int m) {
	T rc = ST[s].key;
	for (int j = 2 * s; j <= m; j *= 2) {
		if (j < m&&ST[j].key <= ST[j + 1].key) j++;
		if (rc > ST[j].key) break;
		ST[s].key = ST[j].key;
		s = j;
	}
	ST[s].key = rc;
}

template<class T>
void SSearch<T>::HeapSort() {
	T value;
	for (int i = len / 2; i > 0; i--) {
		HeapAdjust(ST, i, len);
	}
	for (int i = len; i > 1; --i) {
		value = ST[1].key;
		ST[1].key = ST[i].key;
		ST[i].key = value;
		HeapAdjust(ST, 1, i - 1);
	}
}
/************������************/

