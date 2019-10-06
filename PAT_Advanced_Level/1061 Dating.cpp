//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#include<stdlib.h>
#include<string.h>
int main() {
	char s[4][61];
	int i, count1 = 0;
	char date = '0', hour = '0';
	int min = 0;;
	for (i = 0; i < 4; i++) {
		scanf("%s", s[i]);
		getchar();
	}
	for (i = 0; i < strlen(s[0]); i++) {
		if (s[0][i] == s[1][i]) {
			if (count1 == 0 && s[0][i] >= 'A' && s[0][i] <= 'G') {
				count1++;
				date = s[0][i];
				continue;
			}
			if (count1 == 1 && s[0][i] >= '0' && s[0][i] <= '9' || s[0][i] >= 'A' && s[0][i] <= 'N') {
				count1++;
				hour = s[0][i];
				continue;
			}
			if (count1 > 2)
				break;
		}
	}
	for (i = 0; i < strlen(s[2]); i++) {
		if (s[2][i] == s[3][i] && (s[2][i] >= 'a' && s[2][i] <= 'z' || s[2][i] >= 'A' && s[2][i] <= 'Z')) {
			min = i;
			break;
		}
	}
	switch (date) {
	case 'A':printf("MON ");
		break;
	case 'B':printf("TUE ");
		break;
	case 'C':printf("WED ");
		break;
	case 'D':printf("THU ");
		break;
	case 'E':printf("FRI ");
		break;
	case 'F':printf("SAT ");
		break;
	case 'G':printf("SUN ");
		break;
	}
	if (hour >= '0' && hour <= '9')
		printf("0%c:", hour);
	else
		printf("%d:", hour - 55);
	if (min >= 0 && min <= 9)
		printf("0%d", min);
	else
		printf("%d", min);
	//	system("pause");
	return 0;
}