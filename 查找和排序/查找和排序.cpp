

#include<iostream>
#include "SSearch.h"
using namespace std;

int main()
{
	SSearch<float> s[4];
	int n,k;
	float m;
	
	cout << "����������Ԫ�صĸ�����";
	cin >> n;
	for (int i = 0; i < 4; i++) {
		s[i].Create(n);
	}

	for ( i = 0; i < 4; i++) {
		cout << "ѡ������ʽ���۰��������1������������2������ѡ������3����������4������";
			cin >> k;
			if (k == 1) {
				cout << "�۰���������";
				s[k - 1].BInsertSort();
				s[k - 1].Display();
				cout << "��������Ҫ���ҵ�ֵ��";
				cin >> m;
				cout << "˳����ҽ��Ϊ��" << s[k-1].SeSearch(m) << endl;
				cout << "�۰���ҽ��Ϊ��" << s[k-1].BiSearch_1(m) << endl;
				cout << "�۰���ҽ��Ϊ��" << s[k-1].BiSearch_2(m) << endl;
			}
			else if (k == 2) {
				cout << "���������";
				s[k - 1].BInsertSort();
				s[k - 1].Display();
				cout << "��������Ҫ���ҵ�ֵ��";
				cin >> m;
				cout << "˳����ҽ��Ϊ��" << s[k - 1].SeSearch(m) << endl;
				cout << "�۰���ҽ��Ϊ��" << s[k - 1].BiSearch_1(m) << endl;
			}
			else if (k == 3) {
				cout << "��ѡ�������";
				s[k - 1].BInsertSort();
				s[k - 1].Display();
				cout << "��������Ҫ���ҵ�ֵ��";
				cin >> m;
				cout << "˳����ҽ��Ϊ��" << s[k - 1].SeSearch(m) << endl;
				cout << "�۰���ҽ��Ϊ��" << s[k - 1].BiSearch_1(m) << endl;
			}
			else if (k == 4) {
				cout << "�������";
				s[k - 1].BInsertSort();
				s[k - 1].Display();
				cout << "��������Ҫ���ҵ�ֵ��";
				cin >> m;
				cout << "˳����ҽ��Ϊ��" << s[k - 1].SeSearch(m) << endl;
				cout << "�۰���ҽ��Ϊ��" << s[k - 1].BiSearch_1(m) << endl;
			}
	}

	
	return 0;
}