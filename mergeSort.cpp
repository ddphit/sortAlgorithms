//归并排序：分解（将当前区间一分为二），求解：递归地对两个子区间进行归并排序，组合：将已排序的两个子区间合并

#include<iostream>
using namespace std;

void msort(int a[], int temp[], int , int);
void merge(int a[], int temp[], int, int, int);

void mergeSort(int a[], int len){
	int *temp=new int[len];
	if(temp!=NULL){
		msort(a,temp,0,len-1);
		delete[] temp;
	}
}

void msort(int a[], int temp[],int low, int high){
	int i=0;
	int mid=high-(high-low)/2;
	msort(a, temp,low,mid);
	msort(a,temp,mid+1,high);
	merge(a,temp,low,mid+1,high);
}

void merge(int a[], int temp[], int low, int mid, int high){
	int ind=low;
	int len=high-low+1;
	while(low<=mid-1&&mid<=high){
		if(a[low]<=a[mid])temp[ind++]=a[low++];
		else
			temp[ind++]=a[mid++];
	}
	while(low<=mid-1){
		temp[ind++]=a[low++];
	}
	while(mid<=high){
		temp[ind++]=a[mid++];
	}
	
	for(int i=0;i<len;++i)a[i]=temp[i];
}

