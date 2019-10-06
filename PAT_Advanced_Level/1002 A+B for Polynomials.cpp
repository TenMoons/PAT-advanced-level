#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

const int MAX = 1001;
double p[MAX] = {};  // 存放多项式，下标为指数，p[i]为系数

int main() {
	int K, n, count = 0;
	double a;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {  // 输入第一个多项式
		scanf("%d %lf", &n, &a);
		p[n] += a;  
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {  // 输入第二个多项式
		scanf("%d %lf", &n, &a);
		p[n] += a;  // 指数相同的相加
	}
	for (int i = 0; i < MAX; i++) 
		if (p[i] != 0)  // 统计非零项的项数
			count++;
	printf("%d", count);
	for (int i = MAX - 1; i >= 0; i--)
		if (p[i] != 0)
			printf(" %d %.1f", i, p[i]);  // 按指数降幂输出结果多项式
	system("pause");
	return 0;
}