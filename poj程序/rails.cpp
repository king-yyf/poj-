/*
	@author 杨云飞
	@time 2017年3月2日/23：32 
	poj 1363 rails
*/
#include<iostream>
#include<stack>
bool check(int * a,int n);
using namespace std;
int main(){
	int n; 
	while(cin>>n&&n){
		int *a=new int[n];
		while(cin>>a[0]&&a[0]){
			for(int i=1;i<n;i++){
				cin>>a[i];
			}
			if(check(a,n)){
				cout<<"Yes"<<endl;
			}else
				cout<<"No"<<endl;
		}
		cout<<endl;
	}
	return 0;
}
bool check(int * a,int n){
	stack<int > s; 
	int po=0;
	for(int i=0;i<n;i++){
		for(int j=po+1;j<=a[i];j++){
			po=j; //po是目前为止入栈的最大值 
			s.push(j);	
		}
		if(s.top()!=a[i]){
			return 0;
		}
		s.pop();
	}
	return 1;	
} 
/*check函数说明：事实上，一个出栈序列确定时，则每个数的出栈顺序是确定的*，po是目前为止入栈元素最大的数，
初始化为0.若下一个出栈元素(x)大于po的话，则[po+1,x]中所有元素都入栈，将x弹出即可（更新po），否则下一个
出栈元素已在栈中，且就是栈顶元素/
