#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int nc, np;
	int c[maxn], p[maxn];
	scanf("%d", &nc);
	for (int i = 0; i < nc; i++)
		scanf("%d", &c[i]);
	sort(c, c + nc, cmp);
	scanf("%d", &np);
	for (int i = 0; i < np; i++)
		scanf("%d", &p[i]);
	sort(p, p + np, cmp);
	int sum = 0;
	int i;
	for (i = 0; i < nc && i < np; i++) {
		if (c[i] >= 0 && p[i] >= 0)
			sum += c[i] * p[i];
		else
			break;  // 正数乘积计算完毕
	}
	int j = nc - 1, k = np - 1;
	for (; j >= i && k >= i; j--, k--) {
		if (c[j] < 0 && p[k] < 0)
			sum += c[j] * p[k];
		else
			break;
	}
	printf("%d\n", sum);
	return 0;
}
