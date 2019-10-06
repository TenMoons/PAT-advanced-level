#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

struct stu {
	char name[11];
	char gender;
	char sno[11];
	int grade;
}mlow, fhigh, tmp;

void init() {
	mlow.grade = 101;
	fhigh.grade = -1;
}

int main() {
	int n;
	init();
	scanf("%d", &n);
	int sign = 0;
	if (n == 1) sign = 1;
	while (n--) {
		scanf("%s %c %s %d", tmp.name, &tmp.gender, tmp.sno, &tmp.grade);
		if (tmp.gender == 'M' && tmp.grade <= mlow.grade) 	
				mlow = tmp;
		else if (tmp.gender == 'F' && tmp.grade >= fhigh.grade)
				fhigh = tmp;		
	}
	if (fhigh.grade == -1) printf("Absent\n");
	else printf("%s %s\n", fhigh.name, fhigh.sno);
	if (mlow.grade == 101) printf("Absent\n");
	else printf("%s %s\n", mlow.name, mlow.sno);
	if (fhigh.grade == -1 || mlow.grade == 101) printf("NA\n");
	else printf("%d\n", fhigh.grade - mlow.grade);
	system("pause");
	return 0;
}