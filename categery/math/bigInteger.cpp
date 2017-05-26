//
//  main.cpp
//  bigint
//
//  Created by Yang Yunfei on 2017/5/25.
//  Copyright © 2017年 Yang Yunfei. All rights reserved.
//
#include<cstdio>
#include<cstring>
using namespace std;
struct BigInteger{
    int digit[1000];
    int size;
    void init(){
        size = 0;
        memset(digit,0,sizeof(digit));
    }
    void save(char str[]){
        init();
        int len = strlen(str);
        int weigh = 1,cur = 0, cnt = 0;
        for(int i = len - 1; i > -1; --i){
            cur += (str[i] - '0') * weigh;
            //tmp += cur;
            cnt++;
            weigh *= 10;
            if(cnt == 4 || i == 0){
                digit[size++] = cur;
                cnt = cur = 0;
                weigh = 1;
            }
        }
    }
    void output(){
        printf("%d",digit[size - 1]);
        for(int i = size - 2; i >= 0; --i){
            printf("%04d",digit[i]);
        }
        printf("\n");
    }
    BigInteger operator + (const BigInteger & other) const {
        BigInteger * ret = new BigInteger();
        ret->init();
        int carry = 0;
        for(int i = 0; i < other.size || i < size; ++i){
            int tmp = other.digit[i] + digit[i] + carry;
            carry = tmp / 10000;
            tmp %= 10000;
            ret->digit[ret->size ++] = tmp;
        }
        if(carry){
            ret->digit[ret->size++] = carry;
        }
        return *ret;
    } 
}var1, var2, sum;
char str1[1002], str2[1002];
int main(){
    printf("main\n");
    while(scanf("%s%s",str1,str2) != EOF){
        // printf("%s\n",str1);
  //       printf("%s\n",str2);
        var1.save(str1);
        //var1.output();
        var2.save(str2);
      //  var2.output();
        sum = var1 + var2;
        sum.output();
    } 
    return 0;
}
