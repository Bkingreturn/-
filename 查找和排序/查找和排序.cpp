// 查找和排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include "SSearch.h"
using namespace std;

int main()
{
	SSearch<int>s;
	int n, m;
	cout << "请输入数据元素的个数：";
	cin >> n;
	s.Create(n);
	cout << "排序后的序列为："<<endl;
	s.BInsertSort();
	s.Display();
	cout << "请输入想要查找的值：";
	cin >> m;
	cout << "顺序查找结果为：" << s.BiSearch_1(m) << endl;
	cout << "折半查找结果为：" << s.BiSearch_2(m)<< endl;
	return 0;
}

