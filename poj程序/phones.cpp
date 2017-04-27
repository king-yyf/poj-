/*
*project:1002
*version:487-3279
*author:—Ó‘∆∑… 
*Memory:5200K	
*Time:1980ms
*note:
*date:2017/3/4
*/
#include<iostream>
#include<map>
#include<string>
using namespace std;

typedef pair<string,int> PAIR;

/**
* override the operator "<<" to print the pair values;
*
* @param a pair type data.
*
* @return a out stream object.
*
*/
ostream& operator<<(ostream &out,const PAIR&p){
	return out<<p.first<<" "<<p.second;
}

/**
* input a line of string and return a standard string value of output
*
* @param reader The string value of the phones.
*
* @return The standard value returned by the phones.
*
*/

string parserStr(string s){       
	string result;
	for(int i=0;i<s.size();i++){
		if(s[i]>='A'&&s[i]<='Y'){
			if(s[i]<='P'){
				result.push_back(char((s[i]-'A')/3+'2'));
			}else if(s[i]>='R'){
				result.push_back(char((s[i]-'Q')/3+'7'));
			}
		}
		if(s[i]>='0'&&s[i]<='9'){
			result.push_back(s[i]);
		}
	}
	result.insert(3,1,'-');
	return result;
}

bool comp(const PAIR& lhs,const PAIR& rhs){
	return lhs.second<rhs.second;
}
int main(){
	int n;
	string s;
	//freopen("case.txt","r",stdin);
	cin>>n;
	map<string, int> phones;
	map<string, int>::iterator it;
	while(n--){
		cin>>s;
		int cnt=0;
		it=phones.find(parserStr(s)); 
		if(it!=phones.end()){
			phones[parserStr(s)] =phones[parserStr(s)]+1;
		}else{
			phones.insert(pair<string,int>(parserStr(s),1));
		}
	} 
	bool dup=true;
	for(map<string, int>::iterator iter = phones.begin();iter != phones.end();++iter){
		if(iter->second>1){
			dup=false;
			cout<<*iter<<endl;
		}
	}
	if(dup){
		cout<<"No duplicates."<<endl;
	}
	return 0;
} 

/*	sort by value
vector<PAIR> list(phones.begin(),phones.end()); 
	sort(list.begin(),list.end(),comp);
	for(int i=0;i<list.size();++i){
		if(list[i].second>1){
			cout<<list[i]<<endl;
		}
	}*/
