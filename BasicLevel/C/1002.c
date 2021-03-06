﻿#include <stdio.h>
#include <string.h>

int main() {
	const char pinyin[10][5] = {"ling", "yi", "er", "san", "si",
							"wu", "liu", "qi", "ba", "jiu"};
	int num, sum = 0; 
	while(scanf("%1d", &num) != EOF)
		sum += num;
	char ans[4]; //给出的数 < 10^100，故各位数字之和最多为900  
	sprintf(ans, "%d", sum);
	for(int i = 0; i < strlen(ans); i++) {
		if(i != 0)
			printf(" ");
		printf("%s", pinyin[ans[i] - '0']);
	}
    return 0;
}