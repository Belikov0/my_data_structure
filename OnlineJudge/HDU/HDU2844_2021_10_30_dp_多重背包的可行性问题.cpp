#include <iostream>
#include <cstring>
using namespace std;
/*HDU2844 
	朴素的多重背包算法(暴力拆分)
		将每一种n个硬币都视为单独的硬币
	 	转化为01背包问题 
	二进制拆分
		将多个背包按照二进制组合成新的背包
		转化为01背包问题 
		
	可行性问题：可以使用数组优化！！ 
	
	dp数组：dp[j]表示是否能够组成面值
	状态转移方程 dp[j] =  dp[j-a[i]]
	初始化：显然，不放纸币可以组成面值为0
	计算顺序：可以重复放置，对价值来说顺序计算
	 
*/
int main(){
	int n, m;
	int a[105], c[1005];
	bool dp[100005]; 
	int ans = 0;
	while (1){
		cin >> n >> m;
		if (n == 0 && m == 0)
			return 0;
		
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){ 
			cin >> c[i];
		}
		
		memset(dp, false, sizeof(dp));
		dp[0] = true; // 初始化 
		int num[100005]; 
		for (int i = 0; i < n; i++){
			memset(num, 0, sizeof(num)); // num 表示对要放入第i个物品时， 第i个物品已经放入的数量 
			for (int j = a[i]; j <= m; j++){
				if (dp[j-a[i]] && !dp[j] && num[j-a[i]] < c[i]){
					ans++;
					num[j] = num[j-a[i]]+1;
					dp[j] = true;
				}
			}
		}
		cout << ans << endl;
		ans = 0;
	} 
	
	
	return 0;
}
