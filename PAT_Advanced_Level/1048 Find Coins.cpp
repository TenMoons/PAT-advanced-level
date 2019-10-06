#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int val[1000] = { 0 };  // 每个面值的数量

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	bool flag = false;  // 是否有解
	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		val[tmp]++;
	}
	for (int i = 1; i < m; i++) {
		if (val[i] && val[m - i]) {
			if (i == m - i && val[i] <= 1)
				continue;
			printf("%d %d", i, m - i);
			system("pause");
			return 0;
		}
	}
	printf("No Solution");
	system("pause");
	return 0;
}