/*
*project:1003
*version:Hangover
*author:—Ó‘∆∑… 
*Memory:248k	
*Time:0ms
*note:
*date:2017/3/4
*/
#include<iostream>
#include<cstdio>
using namespace std;

double sum(int n){
	double s=0.0;
	for(int i=2;i<=n+1;i++){
		s+=1.0/i;
	}
	return s;
}

int countCard(float fn){
	int n=1;
	while(sum(n)<fn){
		n++;
	}
	return n;
} 

int main(){
//	freopen("case.txt","r",stdin);
	float fn;
	while(cin>>fn&&fn){
		int n=countCard(fn);
		cout<<n<<" card(s)"<<endl;
	}
	return 0;
}

