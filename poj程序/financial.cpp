/*
*project:1004
*version:Financial Management
*author:—Ó‘∆∑… 
*Memory:248k	
*Time:0ms
*note:
*date:2017/3/4
*/
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("case.txt","r",stdin);
	double s,digit;
	for(int i=0;i<12;i++){
		cin>>digit;
		s+=digit;
	}
	cout<<"$"<<s/12<<endl;
	return 0;
}
