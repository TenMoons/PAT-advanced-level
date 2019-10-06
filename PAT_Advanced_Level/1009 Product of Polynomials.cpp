#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

const int MAX = 1001;
double res[2001] = {};  // ��Ž��
struct Poly {
	int exp;
	double coff;
}poly[MAX];

int main() {
	int K1, K2, exp, count = 0;
	double coff;
	scanf("%d", &K1);
	for (int i = 0; i < K1; i++)  // �����һ������ʽ
		scanf("%d %lf", &poly[i].exp, &poly[i].coff);
	scanf("%d", &K2);
	for (int i = 0; i < K2; i++) {  // ����ڶ�������ʽ
		scanf("%d %lf", &exp, &coff);
		for (int j = 0; j < K1; j++)
			res[exp + poly[j].exp] += (coff*poly[j].coff);
	}
	for (int i = 0; i <= 2000; i++)
		if (res[i] != 0.0)  // ͳ�Ʒ����������
			count++;
	printf("%d", count);
	for (int i = 2000; i >= 0; i--)
		if (res[i] != 0.0)
			printf(" %d %.1f", i, res[i]);  // ��ָ����������������ʽ
	system("pause");
	return 0;
}