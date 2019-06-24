/*
计算与给定时间相隔多少天
输入格式：YYYYMMDD
假定给定时间为：20190624
 */

#include<iostream>
#include<cstdio>
using namespace std;

const int y_ = 2019, m_ =6,d_ = 24;
int monthday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int is_runnian(int y){
    int ans = 0;
    if(y%4==0 && y%100!=0){
        ans = 1;
    }
    if(y%400==0){
        ans = 1;
    }
    return  ans;
}

bool compare(int y1,int m1,int d1,int y2,int m2,int d2){
    if(y1 <= y2)
        return true;
    if(y1 <= y2 && m1 <= m2)
        return true;
    if(y1 <= y2 && m1 <= m2 && d1 <= d2)
        return true;
    
    return false;
}

int main(){
    int date;
    int y1,m1,d1,count;
    int y2,m2,d2;
    while(cin >> date){
        count = 0;
        y1 = date / 10000;
        m1 = (date % 10000) / 100;
        d1 = date % 100; 
        if(compare(y1,m1,d1,y_,m_,d_)){         //确保y1m1d1日期在y2m2d2之前
            y2 = y_;m2 = m_;d2 = d_;
        }
        else{
            y2 = y1;m2 = m1;d2 = d1;
            y1 = y_;m1 = m_;d1 = d_;
        }
        printf("%d %d %d %d %d %d\n",y1,m1,d1,y2,m2,d2);

        while(y1<y2){
            count+=(365+is_runnian(++y1));      //加的时候要判断下一年是不是闰年而不是当年是不是闰年
        }
        while (m1>m2){
            count-= monthday[--m1];             //减的时候要减去上个月的日期，而不是这个月的
            if(m1==2){
                count-=is_runnian(y2);
            }
        }
        while (m1<m2){
            if(m1==2){
                count+=is_runnian(y2);
            }
            count+= monthday[m1++];
        }
        
        count += (d2-d1);
        count = count>=0?count:-count;
        printf("%d\n",count);
    }
    return 0;

}


