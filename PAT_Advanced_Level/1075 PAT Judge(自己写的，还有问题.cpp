#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int score[6] = { 0 };  // ÿ���ֵ
struct student {
	int id;
	int prosc[6] = { -2, -2, -2, -2, -2, -2 };  // ����÷�
	int sum = 0;  // �ܷ�
	int count = 0;  // AC����Ŀ��
	int count2 = 0;  // �÷ֵ���Ŀ��
	int r;  // ����
}s[100001];

bool cmp(student a, student b) {
	if (a.sum != b.sum)
		return a.sum > b.sum;  // ���ֽܷ�������
	else if (a.count != b.count)
		return a.count > b.count;  // ���ܷ���ͬ����AC������������
	else
		return a.id < b.id;  // ��AC����ͬ����id��������
}

int main() {
	int n, k, m;  // nΪ�û�����kΪ��������mΪ�ύ��
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= k; i++)
		scanf("%d", &score[i]);
	for (int i = 0; i < m; i++) {
		int uid, proid, pros = 0;
		scanf("%d %d %d", &uid, &proid, &pros);  // �����û�uid�� �ύ���proid���������pros
		s[uid].id = uid;
		if (pros != -1)  //  ������ͨ���˱��룬���ύ������1
			s[uid].count2++;
		if (pros > s[uid].prosc[proid])  // ����÷ֱ�֮ǰ�ĸߣ�����µ÷�
			s[uid].prosc[proid] = pros;
		if (s[uid].prosc[proid] == score[proid])  // AC����1
			s[uid].count++;
	}
	for (int i = 1; i <= n; i++) {  // �����ܷ�
		for (int j = 1; j <= k; j++) {
			if(s[i].prosc[j] != -2 && s[i].prosc[j] != -1)
				s[i].sum += s[i].prosc[j];
		}
	}
	sort(s, s + n + 1, cmp);
	s[0].r = 1;
	for (int i = 1; i < n; i++) {  // ��������
		if (s[i].sum == s[i - 1].sum)
			s[i].r = s[i - 1].r;
		else
			s[i].r = i + 1;

	}
	for (int i = 0; i < n; i++) {
		if (s[i].count2 != 0) {
			printf("%d %05d %d", s[i].r, s[i].id, s[i].sum);
			for (int j = 1; j <= k; j++) {
				if (s[i].prosc[j] == -2)
					printf(" -");
				else if (s[i].prosc[j] == -1)
					printf(" 0");
				else printf(" %d", s[i].prosc[j]);
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}