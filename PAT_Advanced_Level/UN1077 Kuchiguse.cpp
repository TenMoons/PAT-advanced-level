#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	getchar();
	char words[100][256];
	int len = 0;
	int min = 260;  // 最小长度
	for (int i = 0; i < N; i++) {
		fgets(words[i], 256, stdin);
		int len = strlen(words[i]);
		if (len < min)
			min = len;
		reverse(words[i], words[i] + len);  // 反转字符串
	}
	int sign = 1;
	for (int i = 0; i < min; i++) {
		char c = words[0][i];
		bool isSame = true;
		for (int j = 1; j < N; j++) {
			if (words[j][i] != c) {
				isSame = false;
				break;
			}
		}
		if (isSame)len++;
		else break;
	}
	if (len)
		for (int i = len - 1; i >= 0; i--)
			printf("%c", words[0][i]);
	else
		printf("nai");  // 无公共前缀
	system("pause");
	return 0;
}