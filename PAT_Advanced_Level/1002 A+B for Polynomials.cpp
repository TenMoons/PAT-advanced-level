#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

const int MAX = 1001;
double p[MAX] = {};  // ��Ŷ���ʽ���±�Ϊָ����p[i]Ϊϵ��

int main() {
	int K, n, count = 0;
	double a;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {  // �����һ������ʽ
		scanf("%d %lf", &n, &a);
		p[n] += a;  
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {  // ����ڶ�������ʽ
		scanf("%d %lf", &n, &a);
		p[n] += a;  // ָ����ͬ�����
	}
	for (int i = 0; i < MAX; i++) 
		if (p[i] != 0)  // ͳ�Ʒ����������
			count++;
	printf("%d", count);
	for (int i = MAX - 1; i >= 0; i--)
		if (p[i] != 0)
			printf(" %d %.1f", i, p[i]);  // ��ָ����������������ʽ
	system("pause");
	return 0;
}