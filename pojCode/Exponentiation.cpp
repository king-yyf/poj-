/*
*project:1001
*version:AC+�������˷�
*author:���Ʒ� 
*Memory:236K
*Time:16MS
*note:
*date:2017/3/3
*/
#include <iostream>  
#include <string>  
#include <algorithm>  
#include <fstream>  
using namespace std;  
const int MAX_LEN = 1000;  
int ia[MAX_LEN];  
  
string subF(string str1, string str2)  
{      
     int i,j;  
     string result;  
     memset(ia,0,sizeof(ia));     // �ݴ�˷�����Ľ��  
  
     reverse(str1.begin(), str1.end());     // ����  
     reverse(str2.begin(), str2.end());  
  
     int point1, point2,point;               //     С��λ��  
     point1 = str1.find('.');      
     point2 = str2.find('.');  
     if(point1 != string::npos)               // ���ΪС������С����ɾ��  
          str1.erase(str1.begin()+point1);  
     else  
          point1 = 0;  
     if(point2 != string::npos)  
          str2.erase(str2.begin()+point2);  
     else  
          point2 = 0;  
     point1 > point2 ? point = point1 : point = point2;     // point��������С��λ��  
  
     int len1 = str1.size();  
     int len2 = str2.size();  
      
     for(i = 0; i < len1; i++)               // �˷�����  
          for(j = 0; j < len2; j++)  
               ia[i+j] += (str1[i]-'0')*(str2[j]-'0');  
  
     int len;     // �˻��ĳ���  
     for(i = 0; i < len1+len2; i++)          // ��λ����  
     {  
          if(ia[i] >= 10)  
          {  
               ia[i+1] += (ia[i]/10);  
               ia[i] %= 10;  
          }  
     }  
     if(ia[len1+len2-1] > 0)  
          len = len1+len2;  
     else  
          len = len1+len2-1;  
  
     for(i = len-1; i >= 0; i--)  
          result += char(ia[i]+'0');  
     if(point > 0)          // ����С����  
     {  
          result.insert(result.end()-point1-point2,'.');  
          for(i = result.size()-1; i >= 0; i--)     // ȥ��С�����ĺ���0  
          {  
               if(result[i] == '0')  
                    result.erase(result.begin()+i);  
               else if(result[i] == '.')  
               {  
                   result.erase(result.begin()+i);  
                   break;  
               }  
               else  
                    break;  
          }  
          while( (*result.begin()) == '0' )     // ȥ��С����ǰ��ǰ��0  
              result.erase(result.begin());  
     }  
     return result;  
}  
  
int main()  
{  
     string str1;  
     int n;  
     while(cin >> str1 >> n)  
     {  
         string str2("1");  
         while(n--)  
         {  
           str2 = subF(str1, str2);  
         }  
          cout << str2 << endl;  
     }  
     system("pause");  
     return 0;  
}  
