//快速排序，冒泡排序属于交换排序

#include<iostream>
using namespace std;

void quickSort(int a[], int low, int high){
	if(a==NULL||low>=high)return ;
	if(low<high){
		int temp=a[low];
		int i=low;
		int j=high;
		while(i<j){
			while(i<j&&a[j]>temp)--j;
			if(i<j)a[i++]=a[j];
			while(i<j&&a[i]<temp)++i;
			if(i<j)a[j--]=a[i];
		}
		a[i]=temp;
		quickSort(a,low,i-1);
		quickSort(a,i+1,high);
	}
}

int main(){
	int a[]={54,38,96,23,15,72,60,45,83};
	quickSort(a,0,8);
	for(int i=0;i<9;++i)cout<<a[i]<<"   ";
	return 0;
}
