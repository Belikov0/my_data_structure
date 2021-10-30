#include <iostream>
#include <cstring>
using namespace std;
// 使用二维数组
//  dp[j] = min (dp[j], dp[j-w[i]]+v[i]); 
const int INF = 0x7f7f7f7f; 
int main(){
	int T;
	cin >> T;
	int e, f;  
	int N;
	int W;
	int w[600], v[600];
	while (T--){
		cin >> e >> f;
		W = f - e; // 容量
		cin >> N;
		for (int i = 0; i < N; i++){
			cin >> v[i] >> w[i];
		}
		
//		int dp[10005];
//		memset(dp, INF, sizeof(dp));
//		dp[0] = 0;
//		
//		for (int i = 0; i < N; i++){
//			for (int j = w[i]; j<= W; j++){
//				dp[j] = min (dp[j], dp[j-w[i]]+v[i]); 
//			}
//		}

		int dp[500][1000];
		memset(dp, INF, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 0; i < N; i++){
			dp[i][0] = 0;
		}
		
		
		for (int j = 1; j <=W; j++){
			for (int i = 0; i < N; i++){
				dp[i][j] = min(dp[i][j], dp[i][j-w[i]]+v[i]); 
			}
		}
		if (dp[N-1][W] < INF)
			cout << "The minimum amount of money in the piggy-bank is " << dp[N-1][W] << "."  << endl;
		else 
			cout << "This is impossible." << endl; 
	}  
}
