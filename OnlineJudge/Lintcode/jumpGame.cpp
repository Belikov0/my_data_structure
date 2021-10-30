#include <iostream>
#include <cstring>
using namespace std;
/*
* dp数组下标和值的含义 
* 状态转移方程是表示什么意思 
* dp数组如何初始化 
* 遍历的顺序：内外层，自底向上与自顶向下 
*
* 通过打印dp数组来判断程序的正确性(在forx循环中遍历dp数组) 
*/



/*
*  子问题： 如果能跳到j，则从i开始一定有 i+s[i] >= j; 
*  dp数组 bool dp[N] 表示能否跳到i 
* 状态转移方程  dp[j] = dp[j] || dp[i] && i+s[i] >= j;  
* 初始化：第一格总是能到，dp[0]为true， 后面未知，全设为false 
* 遍历顺序：后面是否能跳到依赖前面的，从前往后遍历 
*
*
*/


int main(){
	int m;
	cin >> m;
	int s[1000];
	for (int i = 0; i < m; i++){
		cin >> s[i];
	}
	bool dp[1000];
	memset(dp, false, sizeof(dp));
	dp[0] = true;
	
	for (int j = 1; j < m; j++){
		for (int i = 0; i < j; i++){
			dp[j] = dp[j] || (dp[i] && i+s[i] >= j);
			if (dp[j])
				break;
		}
	}
	cout << dp[m-1];
}
