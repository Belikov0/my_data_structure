#include <iostream>
#include <cstring>
using namespace std;
const int INF = 500;
const int RINF = 0x7f7f7f7f;
/*初始化dp[0][0] = dp[1][0] = dp[2][0] = 0
  表示没有房子时不要钱 
*/ 


int main(){
	int N; // the amount of houses
	cin >> N;
	 //9
//11 31 30 29 5 21 31 10 9 17 6 28 22 26 9 17 8 3 26 9 6 14 3 18 21 23 31
	int cost[INF][3];
	for (int i = 1; i <= N; i++){
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
//		cout << cost[i][0] << " " << cost[i][1] << " " << cost[i][2] << endl;
	}
	int color[INF];
	int dp[3][INF]; // the minimum cost while there are j houses and the last one is in coloe i
	memset(dp, RINF, sizeof(dp));
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[2][0] = 0;
	for (int j = 1; j <= N; j++){
//			cout << cost[j][0] << " " << cost[j][1] << " " << cost[j][2] << endl;
		for (int i = 0; i < 3; i++){
			dp[i][j] = 10000; // 用于求最小值 
			for (int k = 0; k < 3; k++){
				if (i == k)
					continue;
				dp[i][j] = min(dp[i][j], dp[k][j-1]+cost[j][i]);
				
			}
//			cout << "The house " << j << " for color " << i << ": "<<dp[i][j] << endl;
		}
		cout << endl;
	}
	
	int ans = 0x7f7f7f7f;
	cout << ans << endl;
	for (int i = 0; i <= 2; i++){
		ans = min(dp[i][N], ans);
	}
	cout << endl <<ans;
	
}
