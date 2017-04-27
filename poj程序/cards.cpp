/* 模拟扑克牌游戏之 数据结构
*version:cards
*author:杨云飞 
*date:2017/3/4
*/
#include <iostream>
using namespace std;
const int NCARDS=52;
const int NSUITS=4;
char values[]="23456789TJQKA";
char suits[]="cdhs";
int rankCards(char value,char suit){
	int cards=0;
	for(int i=0;i<NCARDS/NSUITS;i++){
		if(values[i]==value){
			for(int j=0;j<NSUITS;j++){
				if(suits[j]==suit){
					cards=i*NSUITS+j;
				}
			}
		}
	}
	return cards;
}
char getValue(int cards){
	return values[cards/NSUITS] ;
}
char getSuit(int cards){
	return suits[cards%NSUITS] ;
}
int main(){
	for(int i=0;i<NCARDS;++i){
		char value=getValue(i);
		char suit=getSuit(i);
		cout<<value<<"\t"<<suit<<endl;
		cout<<i<<"\t"<<rankCards(value,suit)<<endl;
	}
}
