/*堆排序：
1. 小根堆：所有子节点都大于其父节点。
2. 大根堆：所有子节点都小于其父节点
堆排序是树形选择排序，在堆排序过程中，将其看做一颗完全二叉树的顺序存储结构。主要分为三步：
1.建堆；
2.将根节点与最后的元素交换
3.重建堆。
*/

#include<iostream>
using namespace std;

int heapSize=0;
//返回左子结点索引
int Left(int index){return ((index<<1)+1);}
//返回右子节点索引
int Right(int index){return ((index<<1)+2);}

//交换值
void swap(int *a,int *b){int temp=*a;*a=*b;*b=temp;}

//最大堆
void maxHeap(int a[], int index){
	int max=0;
	int left=Left(index);
	int right=Right(index);
	
	if((left<=heapSize)&&(a[left]>a[index]))max=left;
	else
		max=right;

	if((right<=heapSize)&&(a[right]>a[max]))max=right;
	
	if(max!=index){
		swap(&a[index],&a[max]);
		maxHeap(a,max);
	}
}

void buildHeap(int a[], int len){
	int i;
	heapSize=len;
	for(i=(len>>1);i>=0;i--)maxHeap(a,i);
}

void heapSort(int a[], int len){
	int i;
	buildHeap(a,len-1);

	for(i=len-1;i>=1;--i){
		swap(&a[0],&a[i]);
		heapSize;
		maxHeap(a, 0);
	}
}

int main(){
	int a[]={45,68,20,39,88,97,46,59};
	heapSort(a, 8);
	for(int i=0;i<8;++i)cout<<a[i]<<"   ";
	cout<<endl;
	return 0;
}
