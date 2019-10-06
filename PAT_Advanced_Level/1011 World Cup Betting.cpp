#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int main() {
	char wtl[3] = { 'W', 'T', 'L' };
	float sum = 1.0;
	int index = 0;
	for (int i = 0; i < 3; i++) {
		float tmp = 0.0;
		for (int j = 0; j < 3; j++) {
			float a;
			scanf("%f", &a);
			if (a > tmp) {
				tmp = a;
				index = j;
			}
		}
		printf("%c ", wtl[index]);
		sum *= tmp;
	}
	sum = (sum*0.65 - 1) * 2;
	printf("%.2f", sum);
	system("pause");
	return 0;
}