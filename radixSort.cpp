/*基数排序：
基数排序是箱排序的改进和推广，箱排序又称桶排序（Bucket Sort),基本思想是：设置若干个箱子，依次扫描待排序的记录，把关键字等于k的记录全部都装入到第k个箱子里，然后按序号依次将各个箱子里面的记录连接起来。
基数排序是最低位优先(LSD)的排序方法。从低位到高位依次对数据进行箱排序，在d趟排序中，所需的箱子个数就是基数rd(可能的取值个数)。
*/

#include<iostream>
#include<string.h>
using namespace std;
int maxNum(int a[], int len){
	int max=a[0];
	for(int i=0;i<len;++i){
		if(max<a[i])
			max=a[i];
	}
	return max;
}

int digitNum(int num){
	int count=0;
	while(num!=0){
		count++;
		num=num/10;
	}
	return count;
}

int digitValue(int num, int k){
	while(k>0){
		num=num/10;
		--k;
	}
	return num%10;
}

void radixSort(int a[], int len){
	int *temp[10];  //指针数组，每个数组元素都是一个指针
	int count[10]={0,0,0,0,0,0,0,0,0,0};
	int max=maxNum(a, len);
	int nums=digitNum(max); //需要进行nums趟箱排序
	
	int i,j,k;
	for(i=0;i<10;++i){
		temp[i]=new int[len];
		memset(temp[i],0,sizeof(int)*len);
	}

	for(i=0;i<nums;++i){
		memset(count,0,sizeof(int)*10);
		for(j=0;j<len;++j){
			int boxIndex=digitValue(a[j],i);
			temp[boxIndex][count[boxIndex]]=a[j];
			count[boxIndex]++;
		}
		int index=0;
		for(j=0;j<10;++j){
			for(k=0;k<count[j];++k){
				a[index++]=temp[j][k];
			}
		}
	}
}

int main(){
	int a[]={22,32,19,53,47,29};
	radixSort(a,6);
	
	for(int i=0;i<6;++i)cout<<a[i]<<"   ";
	cout<<endl;
	return 0;
}
