#include <iostream>
using namespace std;

// 要知道以某一项结尾的最长上升子数列，要先知道其前一项结尾的最长上升子数列的长度
// 状态转移方程：dp[i] = max(dp[i], dp[j]+1）;
//               以i为结尾的最长上升子数列长度时i前面所有项中最长的再加1
// 边界条件与初始化：每一项自身有一位的数列长，无论哪一项时首项，都是1
// 计算顺序，从前向后遍历 
// 时间复杂度O(n2) 

int main(){
	// longest ascending subarray
	int n; 
	int a[100];
	cin >> n; 
	int dp[100];
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i] = 1;
	} 
	
	for (int i = 1; i <= n; i++){
		for (int j = 1;j < i; j++){
			if (a[i] > a[j]) //如果第i项大于第j项，那么将第i项放到第j项后面构成上升子数列 
				dp[i] = max(dp[i], dp[j]+1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		ans = max(ans, dp[i]);  // 遍历取得最大值 
	}
	cout << ans;
} 
