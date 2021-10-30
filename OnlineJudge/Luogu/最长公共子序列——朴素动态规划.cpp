#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int M = 500;
int main(){
	string a, b;
	cin >> a >> b;
	int len1 = a.size();
	int len2 = b.size();
	
	
	int dp[M][M]; // 时间复杂度O(n*m) 
	memset(dp, 0, sizeof(dp));
	
	for (int i = 1; i < len1; i++){
		for (int j = 1; j < len2; j++){
			if (a[i-1] == b[i-1]) // 注意状态转移方程的理解 
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	cout << dp[len1][len2] << endl;
	return 0;
	
}
