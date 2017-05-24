//题目见计算机机试指南p18
#include <iostream>
#include <cstdio>
#define LEAP_YEAR(y) (y % 4 == 0 && y % 100 != 0) || y % 400 == 0 ? 1 : 0;
using namespace std;
int days[][13] =
{
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};
struct Date{
    int year;
    int month;
    int day;
    Date(int y, int m, int d):year(y),month(m),day(d){}
    void nextDay(){
        day++;
        int leap = LEAP_YEAR(year);
        if(day > days[leap][month]){
            day = 1;
            month++;
            if(month > 12){
                month = 1;
                year++;
            }
        }
    }
    bool operator < (const Date & other) const{
        if(year != other.year)
            return year < other.year;
        else if(month != other.month)
                return month < other.month;
        else
            return day < other.day;
    }
    bool operator == (const Date & other){
        return year == other.year && month == other.month && day == other.day;
    }
};
int calDays(Date d1, Date d2){
    int cnt = 1;
    if(d1 < d2){
        while(!(d1 == d2)){
            d1.nextDay();
            cnt++;
        }
    }else{
        while(!(d1 == d2)){
            d2.nextDay();
            cnt++;
        }
    }
    return cnt;
}
int main(){
    int y, m, d;
    while(scanf("%4d%2d%2d",&y, &m, &d) != EOF){
        Date d1(y,m,d);
        scanf("%4d%2d%2d",&y, &m, &d);
        Date d2(y,m,d);
        printf("%d\n",calDays(d1,d2));
    }

    return 0;
}
