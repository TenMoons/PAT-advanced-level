#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100001;

struct car {
	char plate[8];  // ���ƺ�
	int hh, mm, ss;  // ʱ��
	bool flag;  // ״̬��trueΪin��falseΪout
}cars[maxn];

bool cmp1(car a, car b) {  // ��ʱ���Ⱥ�����
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
	scanf("%d %d", &n, &k);  //n��¼����k��ѯ��
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
		if (cars[i].flag == true && p == 0) {  // �ó��ĵ�һ��in��¼
			p = 1;
		}
		if (cars[i].flag == false && p == 1) {  // �ó��ĵ�һ��in��¼������һ��out��¼ƥ��
			p = 2;
		}
		if(p==2)
	}
	system("pause");
	return 0;
}