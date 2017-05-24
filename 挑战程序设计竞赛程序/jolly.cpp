#include<iostream>
#include<set>
#include<cmath>
using namespace std;
int main(){
	int n,pre,num;
	set<int > nums;
	while(cin>>n){
		if(n==1){
			cout<<"Jolly"<<endl;
		}else{
			for(int i=0;i<n;++i){
				cin>>num;
				if(n>0){
					nums.insert(abs(num-pre));
				}
				pre=num;
			}
			if(nums.size()==n-1){
				cout<<"Jolly"<<endl;
		    }else{
				cout<<"Not jolly"<<endl;
			}
			nums.clear();
		}	
	}
	return 0;
} 
