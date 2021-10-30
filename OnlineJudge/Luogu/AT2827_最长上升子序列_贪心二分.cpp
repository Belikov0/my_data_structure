#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int INF = 0x7f7f7f7f;
int binarySearch(int* dp, int right, int target){ // to find the 
    int left = 1;
    while (left <= right){
    	int mid = (left+right)/2; 
        if (dp[mid] < target)  
            left = mid+1; // if smaller than or equil to target, then search in the right part
        else 
            right = mid-1;
        
    }
    return left; // left is the first one that let dp[left] be bigger than target
}


int main(){

    int size;
    cin >> size;
    int a[100010];
    int dp[100010]; 
    for (int i = 1; i <= size; i++){
        cin >> a[i];
        dp[i] = INF;
    }

    // initialization
    dp[1] = a[1];
    int len = 1;
    
    for (int i = 2; i <= size; i++){
        if (a[i] > dp[len])
            dp[++len] = a[i];
        else if (a[i] < dp[len]){
				*lower_bound(dp+1, dp+len+1, a[i]) = a[i]; 
				// 在有序数列中二分查找，返回第一个大于或等于a[i]的地址 
				// 使用二分查找降低时间复杂度，思想为贪心
				// 每个上升子序列的最后一位越小，那么它往后继续递增的可能就越大 
        }
    }
    
    cout << len;
	
}


