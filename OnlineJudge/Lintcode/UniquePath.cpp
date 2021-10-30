#include <iostream>
#include <cstring>
using namespace std;

int main(){
	
	int height, width;
	cin >> height >> width; 
	long long dp[100][100];
   
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int j = 1; j < width; j++){  // ��Ȼ����һ�г�ȥ0��0�����ܴﵽ
	    for (int i = 0; i < height; i++){// ��Σ�������������������ұߣ������з����棬�ȼ���ÿһ�����ϵ��²�������һ�� 
            if (i == 0)
                dp[i][j] = (dp[i][j-1]+dp[i+1][j-1])%1000000007; // �������ݹ��� 
            else if (i == height-1)
                dp[i][j] = (dp[i][j-1]+dp[i-1][j-1])%1000000007;
            else 
                dp[i][j] = (dp[i][j-1]+dp[i+1][j-1]+dp[i-1][j-1])%1000000007;
            cout << "(" << i << ", " << j << ") is " << dp[i][j] << endl;
            }
        }
    cout << dp[0][width-1];
}
