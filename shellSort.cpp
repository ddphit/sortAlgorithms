//希尔排序

#include<iostream>
using namespace std;

void shellSort(int a[], int len){
	if(a==NULL||len<=0)return ;
	int i,j,h, temp;
	for(h=len/2;h>0;h=h/2){
	//下面与直接插入排序一样    升序排列
		for(i=h;i<len;++i){
			temp=a[i];
			for(j=i-h;j>=0&&temp<a[j];j=j-h){
				a[j+h]=a[j];
			}
			a[j+h]=temp;
		}
	}
}

int main(){
	int a[]={7,3,5,8,9,1,2,4,6};
	cout<<"sort Array is:\n";
	shellSort(a,9);
	for(int i=0;i<9;++i)cout<<a[i]<<"   ";
	return 0;
}
