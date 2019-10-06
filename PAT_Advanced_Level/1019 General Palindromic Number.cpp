#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int main() {
	int N, b;  // N:given non-negative number; b:base
	scanf("%d %d", &N, &b);
	int num[50];
	int i = 0, sign = 1;;
	while (N != 0) {  // arrry num£ºN in b-base reversely
		num[i++] = N % b;
		N /= b;
	}
	for (int j = 0; j < i / 2; j++) {
		if (num[j] != num[i - j - 1]) {
			sign = 0;
			break;
		}
	}
	if (sign == 1)
		printf("Yes\n");
	else printf("No\n");
	for (int j = i - 1; j >= 0; j--) {
		if (j == i - 1)
			printf("%d", num[j]);
		else
			printf(" %d", num[j]);
	}
	system("pause");
	return 0;
}