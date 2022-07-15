// first realization (not optimum)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 500;

int ne[N] = {0}; // the longest same pre-suffix

// j = ne[j-1]的实现
// ne[j] 的含义为在j位置为止最长相等前后缀的长度为ne[j]
// 
void getNext(string& s){
    if (s.size() < 2)
        return;
    int i = 0; // prefix pointer
    int j = 1; // suffix pointer
    while ( j < s.size()){
        if (s[i] == s[j]){
            ne[j++] = ++i;
        }else if (i > 0){
            i = ne[i-1];
        }else{
            ne[j++] = 0;
        }
    }
}


int kmp(string& t, string& s){
    int i = 0; //text pointer
    int j = 0; // pattern pointer
    while (i < t.size() && j < s.size()){
        if (j == 0 && t[i] != s[j]) // a.避免下标为j==0时下标为-1  b.比配模式串首字母失败时，仅移动文本串指针
            i++;
        else if (t[i] == s[j])
            i++,j++;
        else
            j = ne[j-1];
    }
    if (i == t.size() && j != s.size())
        return -1;
    return i; // 返回匹配完成时下标i在文本串的位置，在i-1处完成匹配
}



int main(){
    string s = "aabaaac";
    string t = "aabaaabaaac";
    getNext(s);
    for (int i = 0; i < s.size(); i++){
        cout << ne[i] << " ";
    }
    int rear = kmp(t, s);
    int front = rear-s.size();
    cout << endl << rear << endl;
    for (int i = front; i < rear; i++){
        cout << t[i];
    }
    
    return 0;
}


// second realization(not optimum)
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N = 500;

int ne[N] = {0};

void getNext(string& s){
    int i = 1;//控制后缀
    int j = 0;//控制前缀
    ne[0] = -1;
    while (i < s.size()){
        if (s[j] == s[i])
            ne[++i] = ++j;
        else if(j != 0){
            j = ne[j];
        }else{
            i++;
        }
    }
}

int kmp(string& t, string& s){
    int i = 0;
    int j = 0;
    while (i < t.size() && j < s.size()){
        if (t[i] == s[j])
            i++, j++;
        else if (j != 0){
            j = ne[j];
        }else
            i++;
    }
    if (i == t.size() && j != s.size())
        return -1;
    return i-s.size();//返回起始位置下标
}

int main(){
    string s = "aabaaf";
    string t = "aabaabaaf";
    getNext(s);
    for (int i = 0; i < s.size(); i++){
        cout << ne[i] << " ";
    }
    cout << endl;
    cout << kmp(t, s) << endl;
    cout << 10%1 << endl;

    return 0;
}