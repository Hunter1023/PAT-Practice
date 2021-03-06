﻿#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b) {
	return *(int *)a - *(int *)b; //升序 
}

int main() {
	int N;
	scanf("%d", &N);
	int arr1[N], arr2[N];
	for(int i = 0; i < N; i++)
		scanf("%d", &arr1[i]);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr2[i]);
	int orderCnt =  1; //有序的数量
	for(int i = 0; i < N - 1 && arr2[i] <= arr2[i+1]; i++) //统计中间序列有序的数量 
		orderCnt++;
	int isInsert = 1; //是否为插入排序 
	for(int i = orderCnt + 1; i < N; i++) {//插入排序：未排序部分和初始序列一定相同
		if(arr1[i] != arr2[i]) {
			isInsert = 0;
			break;
		} 
	} 
	if(isInsert) { //插入排序 
		printf("Insertion Sort\n");
		qsort(arr1, orderCnt + 1, sizeof(int), cmp); 
	} else { //归并排序 
		printf("Merge Sort\n");
		int flag = 1; //循环的标记 
		for(int step = 2; flag && step / 2 < N; step *= 2) { //每 step 个元素一组 
			flag = 0;
            for(int i = 0; i < N; i++) { //比较两个序列  
                if(arr1[i] != arr2[i]) { //如果有元素不同，继续归并 
                    flag = 1;
                    break; 
                }
            }
            int i; 
			for(i = 0; i + step < N; i += step) //归并排序 
				qsort(arr1 + i, step, sizeof(int), cmp);
			qsort(arr1 + i, N - i, sizeof(int), cmp); //对末尾数量不足 step 的元素排序  
		}
	}
	for(int i = 0; i < N; i++) {//输出数组
		if(i != 0)
			printf(" ");
		printf("%d", arr1[i]);
	}
	return 0;
}