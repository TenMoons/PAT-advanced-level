#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int toll[24] = { 0 };  // 每小时费率:cents/min

struct record {
	char name[21];
	int mon, day, hour, min;
	bool status;  // 状态：status = true 表示online，status = false 表示offline
}rec[1001], tmp;

bool cmp(record a, record b) {
	int s = strcmp(a.name, b.name);
	if (s != 0)return s < 0;  // 按字典序排用户
	else if (a.mon != b.mon)return a.mon < b.mon;  // 月份递增
	else if (a.day != b.day)return a.day < b.day;  // 日期递增
	else if (a.hour != b.hour)return a.hour < b.hour;  // 小时递增
	else return a.min < b.min;  // 分钟递增
}

void get_ans(int on, int off, int &time, int &money) {
	tmp = rec[on];
	while (tmp.day < rec[off].day || tmp.hour < rec[off].hour || tmp.min < rec[off].min) {
		time++;
		money += toll[tmp.hour];
		tmp.min++;
		if (tmp.min >= 60) {
			tmp.min = 0;
			tmp.hour++;
		}
		if (tmp.hour >= 24) {
			tmp.hour = 0;
			tmp.day++;
		}
	}
}

int main() {
	int N;
	for (int i = 0; i < 24; i++)  // 输入资费
		scanf("%d", &toll[i]);
	scanf("%d", &N);  // 通话记录条数
	char sta[10];
	for (int i = 0; i < N; i++) {
		scanf("%s %d:%d:%d:%d %s", rec[i].name, &rec[i].mon, &rec[i].day, &rec[i].hour, &rec[i].min, sta);
		if (strcmp(sta, "on-line") == 0)  // sta = on-line
			rec[i].status = true;
		else  // sta = off-line
			rec[i].status = false;
	}
	sort(rec, rec + N, cmp);  // 排序
	int on = 0, off, next;  // on和off为配对的两条记录的下标，next为下一条记录
	while (on < N) {
		int needPrint = 0;  // 
		next = on;
		while (next < N && strcmp(rec[next].name, rec[on].name) == 0) {
			if (needPrint == 0 && rec[next].status == true)
				needPrint = 1;  // 遇到该用户的第一条开始通话记录on
			else if (needPrint == 1 && rec[next].status == false)
				needPrint = 2;  // 在on之后的第一条结束记录off
			next++;  // 循环直到下一条记录的客户名不同
		}
		if (needPrint < 2) {  // 有效通话记录未匹配成功
			on = next;
			continue;
		}
		int sum = 0;
		printf("%s %02d\n", rec[on].name, rec[on].mon);
		while (on < next) {
			while (on < next - 1 && !(rec[on].status == true && rec[on + 1].status == false))
				on++;  // 直到找到连续的online和offline
			off = on + 1;
			if (off == next) {  // 已经输出完所有配对成功的有效通话记录
				on = next;
				break;
			}
			printf("%02d:%02d:%02d ", rec[on].day, rec[on].hour, rec[on].min);
			printf("%02d:%02d:%02d ", rec[off].day, rec[off].hour, rec[off].min);
			int time = 0, money = 0;
			get_ans(on, off, time, money);
			sum += money;
			printf("%d $%.2f\n", time, money / 100.0);
			on = off + 1;
		}
		printf("Total amount: $%.2f\n", sum / 100.0);
	}
	system("pause");
	return 0;
}