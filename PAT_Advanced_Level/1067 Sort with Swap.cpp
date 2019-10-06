#define _CRT_SECURE_NO_WARNINGS
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100010];

int main() {
	int n, num;
	int count = 0;
	scanf("%d", &n);
	int left = n - 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		a[num] = i;  // num的位置是i
		if (num == i && num != 0)  // 除0外在本位上的数
			left--;
	}
	int k = 1;  // 除0外不在本位的最小数
	while (left > 0) {
		if (a[0] == 0) {
			while (k < n) {
				if (a[k] != k) {
					swap(a[0], a[k]);
					count++;
					break;
				}
				k++;
			}
		}
		while (a[0] != 0) {
			swap(a[0], a[a[0]]);
			count++;
			left--;
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}
