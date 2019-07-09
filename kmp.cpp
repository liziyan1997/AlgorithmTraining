#include<iostream>
#include<cstring>
using namespace std;

int next_[20];

void get_next_(char *str){              //next数组的含义是当第j位失配时j滑动到next[j]继续匹配
    next_[0] = -1;
    int k=-1;
    int j=0;
    int len = strlen(str);
    while(j<len-1){
        if(k==-1 || str[j]==str[k]){
            next_[++j] = ++k;           //k==-1没有查找到相同的前缀，那么next[j+1] = 0                  
        }                               //如果str[j]==str[k] 那么next[j+1] = next[j]+1 = k+1;
        else{
            k = next_[k];               //如果当前的前k个字符组成的前缀没有匹配，那么尝试next[k]个字符组成的前缀是否匹配
        }                               //如果所有前缀都不匹配那么k=next[0]=-1把next[j+1]设置为0
    }
    for(int i=0;i<len;i++){             //打印next
        cout << next_[i] << ' ';
    }
    cout << endl;
}

int kmp(char *str,char *key){
    int i=0,j=0;
    int len_str = strlen(str);
    int len_key = strlen(key);

    while(i<len_str && j < len_key){
        if(j == -1 || str[i]==key[j]){  //next[0]=-1即如果上一个next[j]=0，表示key从j=0就失配时i向前滑动一位，j归0
            i++;
            j++;
        }
        else{
            j = next_[j];               //失配时回到有相同前缀的位置开始匹配
        }
    }
    if(j==len_key){
        return i-j;
    }
    else{
        return -1;
    }
}

int main(){
    char str[20] = "abcbcababcabca";
    char key[20] = "abcabc";
    get_next_(key);
    int ans = kmp(str,key);
    cout << ans << endl;
    return 0;
}

