/*模板的特化template specialization：
1. 函数模板的特化：当函数模板需要对某些类型进行特别处理时。
2. 类模板的特化
*/

#include<iostream>
using namespace std;
#include<string.h>
template<class T>
class compare{
	public:
		bool isEqual(T a, T b){
			return a==b;
		}
};

template<>
class compare<char *>{
	public:
		bool isEqual(char *a, char *b){
			return strcmp(a,b)==0;
		}
};

template<class W>
bool isEu(W a,W b){
//	cout<<sizeof(W)<<endl;
	return a==b;
}
template<>
bool isEu(char *a, char *b){
	cout<<"hello"<<endl;
	return strcmp(a, b)==0;
}

int main(){
	char str1[]="hello";
	char str2[]="hello";
	cout<<&str1<<"   "<<&str2<<endl;
//	cout<<isEu(str1,str2)<<endl;
//	cout<<isEu(3,6)<<endl;
//	cout<<isEu(4,4)<<endl;
	compare<char *> c;
	compare<int> a;
	cout<<c.isEqual(str1,str2)<<endl;
	cout<<a.isEqual(2,2)<<endl;
	return 0;
}
