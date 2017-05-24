#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int main(){
    string str;
    while(cin>>str){
        stack<char> s;
        cout<<str<<endl;
        vector<char> ans(str.length());
        for(int i = 0; i < str.length(); ++i){
            if(str[i] == '('){
                s.push(str[i]);
                ans[i] = ' ';
            }else if(str[i] == ')'){
                if(s.empty())
                    ans[i] = '?';
                else{
                    s.pop();
                    ans[i] = ' ';
                }
            }else
                ans[i] = ' ';

        }
        while(!s.empty()){
            ans[s.top()] = '&';
            s.pop();
        }
        for(int j = 0;j < ans.size(); ++j){
            cout<<ans[j];
        }
        cout<<endl;
    }
    return 0;
}
