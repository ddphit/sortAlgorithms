//直接选择排序，堆排序属于选择排序

#include<iostream>
using namespace std;

void selectSort(int a[], int len){
	int j=0;
	int index=0;
	for(int i=0;i<len;++i){
		int min=a[i];
		for(j=i+1;j<len-1;++j){
			if(a[j]<min){
				min=a[j];
				index=j;		
			}
		}
		a[index]=a[i];	
		a[i]=min;
	}
}

int main(){
	int a[]={54,38,96,23,15,72,60,45,83};
	selectSort(a,9);
	for(int i=0;i<9;++i)cout<<a[i]<<"   ";
	return 0;
}
