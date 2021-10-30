#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int M = 205;

/*  将整数n划分成k份的方法数目dp[n][k]  
	分为含有1和不含由1的考虑
	若要转移为不含有1，则可以从n中取k个数分别分给每一个保证不为1，那么前驱状态为dp[n-k][n]
	若要转移为含有1，则可以从n个数中取一个1单独放置，剩下的划分成k-1份，前驱状态为dp[n-1][k-1] 
*/ 
int main(){
	int n, k;
	cin >> n >> k;
	int dp[205][9];
	memset(dp, 0, sizeof(dp));
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++){
			if (i == j){
				dp[i][j] = 1;
			}else if (i < j){
				dp[i][j] = 0;
			}else{
				dp[i][j] = dp[i-j][j]+dp[i-1][j-1];
			}		
		}
	}
	cout << dp[n][k];
	return 0;
}
