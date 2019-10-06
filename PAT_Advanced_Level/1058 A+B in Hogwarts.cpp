#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int main() {
	int ag, as, ak, bg, bs, bk;
	int sg, ss, sk;
	scanf("%d.%d.%d %d.%d.%d", &ag, &as, &ak, &bg, &bs, &bk);
	sk = ak + bk;
	ss = as + bs;
	sg = ag + bg;
	if (sk >= 29) {
		ss++;
		sk %= 29;
	}
	if (ss >= 17) {
		sg++;
		ss %= 17;
	}
	printf("%d.%d.%d", sg, ss, sk);
	system("pause");
	return 0;
}