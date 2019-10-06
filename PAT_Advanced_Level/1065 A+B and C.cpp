#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int main() {
	int T;
	scanf("%d", &T);

	for(int i = 1; i <= T; i++){
		long long a, b, c;	
		bool flg = true;
		scanf("%lld %lld %lld", &a, &b, &c);		
		long long res = a + b;
		if (a > 0 && b > 0 && res <= 0)flg = true;
		else if (a < 0 && b < 0 && res >= 0)flg = false;
		else if (res <= c)flg = false;
		if (flg) 
			printf("Case #%d: true\n", i);
		else 
			printf("Case #%d: false\n", i);
	}
	system("pause");
	return 0;
}
