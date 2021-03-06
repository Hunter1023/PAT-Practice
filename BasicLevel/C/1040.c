﻿#include <stdio.h>
#include <string.h>

int main() {
	char str[100001];
	scanf("%s", str);
	int cntP = 0, cntPAT = 0, cntT = 0, len = strlen(str);
	for(int i = 0; i < len; i++) { //获取T的数量 
		if(str[i] == 'T')
			cntT++; 
	}
	for(int i = 0; i < len; i++) {
		if(str[i] == 'P') { //统计当前共有多少个P 
			cntP++; 
		} else if(str[i] == 'A') { //当前A能构成的PAT数量 = 之前P的数量 * 之后T的数量
			cntPAT = (cntPAT + ((long long)cntP * cntT)) % 1000000007; //类型转换是为了防止溢出 
		} else {
			cntT--;
			if(cntT == 0) //之后无T，必然不会再形成PAT
				break;
		}
	}
	printf("%d\n", cntPAT);	
	return 0;
}