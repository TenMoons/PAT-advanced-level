#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100001;

struct car {
	char plate[8];  // 车牌号
	int hh, mm, ss;  // 时间
	bool flag;  // 状态，true为in，false为out
}cars[maxn];

bool cmp1(car a, car b) {  // 按时间先后排序
	if (a.hh != b.hh)
		return a.hh < b.hh;
	else if (a.mm != b.mm)
		return a.mm < b.mm;
	else
		return a.ss < b.ss;
}

bool cmp2() {

}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);  //n记录数，k查询数
	for (int i = 0; i < n; i++) {
		char status[4];
		scanf("%s %d %d %d %s", cars[i].plate, &cars[i].hh, &cars[i].mm, &cars[i].ss, status);
		if (strcmp(status, "in") == 0)
			cars[i].flag = true;
		else
			cars[i].flag = false;
	}
	sort(cars, cars + n, cmp1);
	int p = 0;
	for (int i = 0; i < n; i++) {
		if (cars[i].flag == true && p == 0) {  // 该车的第一个in记录
			p = 1;
		}
		if (cars[i].flag == false && p == 1) {  // 该车的第一个in记录与其后第一个out记录匹配
			p = 2;
		}
		if(p==2)
	}
	system("pause");
	return 0;
}