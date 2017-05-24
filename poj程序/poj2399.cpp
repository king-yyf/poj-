#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//poj 2399 在讨论区中的数据都正确，不知道为什么错

bool cmp(int a1, int a2){
    return a1 > a2;
}
int mod1[][3] =
{
    {1,4,7},
    {2,5,8}
};

int judge3(vector<int> v,bool flag){
    int sum = 0;
    for(int i = 0; i < v.size(); ++i){
        sum += v[i];
    }
    if(flag) sum +=5;
    return sum % 3;
}

void decode(vector<int> v, bool flag){
    for(int i = 0; i < v.size(); ++i){
        char ch = (char)(v[i] + '0');
        cout<<ch;
    }
    if(flag)
        cout<<"5";
}

void maxRes(string str){
    vector<int> vec;
    bool flag = false;
    for(int i = 0; i < str.length(); ++i){
        int digit = str[i] - '0';
        vec.push_back(digit);
    }
    sort(vec.begin(),vec.end(),cmp);
    if(vec[0] == 0){
        cout<<"0";
        return;
    }
    if(vec[vec.size() - 1] != 0){
        vector<int>::iterator it1 = find(vec.begin(),vec.end(),5);
        if(it1 != vec.end()){
            vec.erase(it1);
            flag = true;
        }else{
            cout<<"impossible";
            return;
        }
    }
    int rem = judge3(vec,flag);
    if(rem == 0){
        decode(vec,flag);
        return;
    }
    vector<int>::iterator it;
    for(int j = 0; j < 3; ++j){
        it = find(vec.begin(),vec.end(),mod1[rem - 1][j]);
        if(it != vec.end()){
            vec.erase(it);
            decode(vec,flag);
            return;
        }
     }
    for(int i = 0; i < 3; ++i){
        it = find(vec.begin(),vec.end(),mod1[rem % 2][i]);
        if(it != vec.end()){
            vec.erase(it);
            for(int j = i; j < 3; ++j){
                it = find(vec.begin(),vec.end(),mod1[rem % 2][j]);
                if(it != vec.end()){
                    vec.erase(it);
                    decode(vec,flag);
                    return;
                }
            }
        }
    }
    cout<<"impossible";
}

int main(){
    string str;
    cin>>str;
    //getchar();
    maxRes(str);
    return 0;
}

