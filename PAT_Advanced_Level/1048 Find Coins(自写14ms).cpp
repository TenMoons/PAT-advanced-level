#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int val[501] = { 0 };  // ÿ����ֵ������

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	bool flag = false;  // �Ƿ��н�
	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		val[tmp]++;
	}
	int min = m;
	for (int i = 1; i <= 500; i++) {
		for (int j = i; j <= 500; j++) {
			if (val[i] == 0 || val[j] == 0)
				continue;
			if (i + j == m && i != j || (i + j == m && i == j && val[i] >= 2)) {
				flag = true;
				int tmp = i < j ? i : j;
				min = min < tmp? min:tmp;  // minΪ������Сֵ
			}
		}
	}
	if (flag)
		printf("%d %d", min, m - min);
	else
		printf("No Solution");
	system("pause");
	return 0;
}