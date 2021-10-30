#include <iostream>
#include <cstring>
using namespace std;

int main(){
	
	int height, width;
	cin >> height >> width; 
	long long dp[100][100];
   
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int j = 1; j < width; j++){  // 显然，第一列除去0，0都不能达到
	    for (int i = 0; i < height; i++){// 其次，由于题意是由左边推右边，所以列放外面，先计算每一列由上到下才能推下一列 
            if (i == 0)
                dp[i][j] = (dp[i][j-1]+dp[i+1][j-1])%1000000007; // 可能数据过大 
            else if (i == height-1)
                dp[i][j] = (dp[i][j-1]+dp[i-1][j-1])%1000000007;
            else 
                dp[i][j] = (dp[i][j-1]+dp[i+1][j-1]+dp[i-1][j-1])%1000000007;
            cout << "(" << i << ", " << j << ") is " << dp[i][j] << endl;
            }
        }
    cout << dp[0][width-1];
}
