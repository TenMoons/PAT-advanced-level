#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int sum = a + b;
	char res[11];
	if (sum < 0) {
		sum = -sum;
		printf("-");
	}
    if (sum == 0)
		printf("0");
	else {
		int i = 0;
		while (sum != 0) {
			res[i++] = sum % 10 + '0';
			sum /= 10;
		} 
		for (int j = i - 1; j >= 0; j--) {
			printf("%c", res[j]);
			if (j % 3 == 0 && j != 0)
				printf(",");
		}
	}
	system("pause");
	return 0;
}