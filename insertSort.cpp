//直接插入排序

#include<iostream>
using namespace std;

void insertAls(int a[], int n){
	if(a==NULL||n<=0)return;
	int j=0;	
	for(int i=1;i<n;++i){
		int temp=a[i];  //降序排列
		for(j=i-1;j>=0&&a[j]<temp;--j)  {
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
}

int main(){
	int a[]={7,3,5,8,9,1,2,4,6};
	cout<<"input the array is:\n";
	insertAls(a,9);
	for(int i=0;i<9;++i)
		cout<<a[i]<<"   ";
	return 0;
}
