#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int INF = 0x7f7f7f7f;
/*
 dp[i][j] 表示前列长i，后列长j时的修改次数
 		那么列长i对应的下表为i-1，注意下表修改
 状态转移：前列长i，后列长j的字符串修改次数状态 
 		   可以由前列长i, 后列长j-1和 前列长i-1, 后列长j的字符串修改次数状态通过增添得到 
		   也可以由前列长i-1, 后列长j-1的状态同时增加一位，比较他们是否相等来得到 
 状态转移方程：
 	a.两个同时增加一位，如果相同，则不用修改 dp[i][j] = dp[i-1][j-1]
	b.比较是否需要增添删除，由则有：dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
 边界：如果一列为0，则修改次数为另一列长，两列都为0则为0 
 顺序：自底向上 
*/ 
int main(){
	string a, b;
	cin >> a;
	cin >> b;
	int la = a.size();
	int lb = b.size();
	int dp[2005][2005];
	int x = 0;
	for (int i = 0; i <= la; i++){
		for (int j = 0; j <= lb; j++){
			if (i == 0){
				dp[i][j] = j;
				continue;
			}
			if (j == 0){
				dp[i][j] = i;
				continue;
			}
			// 这种代码也可以 
//			x = 1;
//			if (a[i-1] == b[j-1])
//				x = 0;
//			dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+x);

			if (a[i-1] == b[j-1]) // 注意下标关系，dp[1]表示要放入a[0]的情况，即第一位 
				dp[i][j] = dp[i-1][j-1];
			else 
				dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1);
		}
	}
	int ans = dp[la][lb];
	cout << ans;
} 
