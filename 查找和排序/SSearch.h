#pragma once
template<class T>
struct Node {
	T key;
	/*
	....根据需要添加。
	*/
};
template<class T>
class SSearch {
private:
	Node<T> *ST;//表首址；
	int len;//表长；
public:
	SSearch();//构造函数；
	~SSearch();//析构函数，删除表空间；
	void Create(int n);//创建时根据用户需求，再为相应的数据元素赋值；
	void Display();//输出静态表中的数据元素；
	int SeSearch(T key);//从表中最后一个元素开始顺序查找；
	void Ascendsort();//升序排列；
	int BiSearch_1(T key);//折半查找，非递归算法；
	int BiSearch_2(T key);//折半查找，递归算法；
	int BiSearch(int x, int y, T key);//折半查找递归；
	int GetLength();//返回表长；
	void BInsertSort();//折半插入排序；
};
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
	cout << "请输入" << len << "个数据元素：";
	for (int i = 1; i < len+1; i++) {
		cin >> e.key;
		ST[i] = e;
	}
}
template<class T>
void SSearch<T>::Display() {
	int i;
	cout << "静态表中的数据元素为：";
	for (i = 1; i < len ; i++) {
		cout << ST[i].key << ",";
		
	}
	if (i = len) cout << ST[i].key << endl;
}
template<class T>
int SSearch<T>::SeSearch(T key) {
	ST[0].key = key;
	for (int i = len; ST[i].key<>key; i++);
	if (i == 0) cout << "查找不成功！" << endl;
	return i;
}
template<class T>
int SSearch<T>::BiSearch_1(T key) {
	if (len == 0 && ST == NULL) {
		cout << "静态表不存在，请重新建立表\n";
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
	k = BiSearch(0, len, key);
	return k;
}
template<class T>
int SSearch<T>::GetLength() {
	return len;
}
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