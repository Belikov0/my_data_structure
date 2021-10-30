#include <iostream>
#include <cstring> 
using namespace std;

// 要知道 N 元能够购买的总价值的最优解， 需要知道 N - p[i] 能够购买的总价值的最优解 
// 状态转移方程： dp[N] = max(dp[N], dp[N-p[i]]+v[i])
// 边界与初始：0元能够买价值为0，求最大值，可初始化数组为0；
// 计算顺序：每件物品只有一个，按照物品自底向上 
 
int main(){
	
	
	int N, m;
	cin >> N >> m;
	int p[30], v[30]; 
	for (int i = 0; i < m; i++){
		cin >> p[i] >> v[i];
		v[i] *= p[i];
	}//提给条件部分
	
	int dp[30010];
	memset(dp, 0, sizeof(dp));
	
	for (int i = 0; i < m; i++){
		cout << "while there are(is) " << i+1 << " category(s)"<<endl; 
		for (int j = N; j >= p[i]; j--){  
			// 必须要逆序 
			// 要保证推dp[j]时，dp[j-w[i]]的状态是dp[i-1][j-w[i]] (如何理解)  
			// 如果从p[i]开始递增，对于递增之后的j, dp[j-w[i]]可能是已经被修改过的dp[i][j-w[i]]而不是应该要的dp[i-1][j-w[i]] 
			// dp[i][j-w[i]]是已经处于第i阶段的状态，可能已经使用过第i件物品
			// 如果是完全背包问题，那么应该顺序
			dp[j] = max(dp[j], dp[j-p[i]]+v[i]);
			cout << "If " << j << " equipped, the max value is " << dp[j] << endl;
		}
	}
	
	cout << dp[N] << endl;
	
	return 0;
	
} 
