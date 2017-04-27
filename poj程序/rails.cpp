/*
	@author ���Ʒ�
	@time 2017��3��2��/23��32 
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
			po=j; //po��ĿǰΪֹ��ջ�����ֵ 
			s.push(j);	
		}
		if(s.top()!=a[i]){
			return 0;
		}
		s.pop();
	}
	return 1;	
} 
/*check����˵������ʵ�ϣ�һ����ջ����ȷ��ʱ����ÿ�����ĳ�ջ˳����ȷ����*��po��ĿǰΪֹ��ջԪ����������
��ʼ��Ϊ0.����һ����ջԪ��(x)����po�Ļ�����[po+1,x]������Ԫ�ض���ջ����x�������ɣ�����po����������һ��
��ջԪ������ջ�У��Ҿ���ջ��Ԫ��/
