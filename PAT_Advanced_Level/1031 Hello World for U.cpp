/* 注：本题个人解法与算法笔记上两种解法均不相同 */
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	char s[81];
	scanf("%s", s);
	int n1, n2;
	int max = 0;
	int length = strlen(s);
	for (n1 = 1; n1 < length; n1++) {
		for (n2 = 3; n2 <= length; n2++) {
			if (n1 * 2 + n2 -2 == length ) {
				if (n1 > max && n1 <= n2)
					max = n1;
			}
		}
	}
	n2 = length - 2 * max + 2;
	int i;
	for (i = 0; i < max-1; i++) {
		cout << s[i];
		int tmp = length - i - 1;
		for (int j = 1; j <= n2 - 2; j++)
			printf(" ");
		cout << s[tmp];
		printf("\n");
	}
	for (int j = i; j < length - i; j++)
		cout << s[j];
	system("pause");
	return 0;
}