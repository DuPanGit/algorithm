#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int *a, int l, int h){
	int f = 1;
	int t = a[l];
	int i = l;
	int j = h;
	while(i<j){
		if(f){
			if(t<=a[j]){
				j--;
			}else{
				//第i位置填入数后，指针向后移动一位
				a[i] = a[j];
				i++;
				f = 0;
			}
		}else{
			if(t>=a[i]){
				i++;
			}else{
				//
				a[j] = a[i];
				j--;
				f=1;
			}
		}
	}
	a[i] = t;
	return i;
}

int quickSort(int *a, int l, int h){
	if(l<h){
		int p = partition(a,l,h);
		quickSort(a,l,p-1);
		quickSort(a,p+1,h);
	}
}

int main(){
	int a[] = {2,9,6,5,3,4,7,1,8};
	int n=9;
	//随机化
	srand(time(0));
	int t;
	int j;
	for(int i=0;i<n;i++){
		j = rand() % n;
		t = a[i];
		a[i]=a[j];
		a[j]=t;
	}
	//end随机化
	quickSort(a,0,n-1);
	
	for(int i=0; i<n; i++){
		printf("%d  ",a[i]);
	}
	printf("\n");
}
