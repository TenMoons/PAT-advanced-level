#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

const int N = 54;
char mp[5] = { 'S', 'H', 'C', 'D', 'J' };  // �Ƶı��
int start[N + 1], end[N + 1], next[N + 1];  // start�ǳ�ʼ״̬��end�Ǳ任���״̬��next��Ҫ��ı任����

int main() {
	int K;  // repeat times
	scanf("%d", &K);
	for (int i = 1; i <= N; i++) // ��ʼ���Ƶı��
		start[i] = i;
	for (int i = 1; i <= N; i++)  // �任����
		scanf("%d", &next[i]);
	while (K-- > 0) {
		for (int i = 1; i <= N; i++)   //�任
			end[next[i]] = start[i];
		for (int i = 1; i <= N; i++)  // Ϊ����һ���ظ����еĵ���
			start[i] = end[i];
	}
	for (int i = 1; i <= N; i++) {
		start[i]--;
		if(i != N)
			printf("%c%d ", mp[start[i] / 13], start[i] % 13 + 1);
		else 
			printf("%c%d", mp[start[i] / 13], start[i] % 13 + 1);
	}
	system("pause");
	return 0;
}