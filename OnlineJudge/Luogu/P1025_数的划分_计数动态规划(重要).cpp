#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int M = 205;

/*  ������n���ֳ�k�ݵķ�����Ŀdp[n][k]  
	��Ϊ����1�Ͳ�����1�Ŀ���
	��Ҫת��Ϊ������1������Դ�n��ȡk�����ֱ�ָ�ÿһ����֤��Ϊ1����ôǰ��״̬Ϊdp[n-k][n]
	��Ҫת��Ϊ����1������Դ�n������ȡһ��1�������ã�ʣ�µĻ��ֳ�k-1�ݣ�ǰ��״̬Ϊdp[n-1][k-1] 
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
