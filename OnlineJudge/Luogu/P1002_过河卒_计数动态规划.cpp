#include <iostream>
#include <cstring>
#include <vector> 
using namespace std;

// Ҫ֪������(i, j)�Ŀ������� Ҫ��֪��(i-1, j) ��(i, j-1)�Ŀ�����
// dp[i][j]��ʾ����i, j�Ŀ�����
// ״̬ת�Ʒ��� dp[i][j] = dp[i][j-1] + dp[i-1][j];
//  


int row, col;
int cx, cy;
	
int dir[9][2] = {
	{2, 1}, {1, 2}, {2, -1}, {1, -2}, {-2, -1}, {-1, -2}, {-1, 2}, {-2, 1}, {0, 0}
};

bool inMap(int x, int y){
	return (x >= 0 && y >= 0 && x < row+1 && y < col+1);
}

int main(){
	
	cin >> row >> col >> cx >> cy;
	
	long long dp[22][22];
	bool vis[22][22]; 
	memset(dp, 0, sizeof(dp));
	memset(vis, true, sizeof(vis));
	
	for (int i = 0; i <= 8; i++){
		int dx = cx + dir[i][0];
		int dy = cy + dir[i][1];
		if (inMap(dx, dy))
			vis[dx][dy] = false; // ��ǲ��ܹ��ĵط�		
	}
	dp[0][0] = 1;
	
	
	for (int i = 0; i <= row; i++){  
		for (int j = 0; j <= col; j++){  // 
			if (i == 0 && j == 0)
				continue; 
			if (!vis[i][j] || i == cx && j == cy){
				dp[i][j] = 0;
				continue;
			}
			if (i-1 < 0) // ����ó�ʼ�����Ӧ��i, jΪ1, 1, ��ô���Ա�����ж�����
				dp[i][j] = dp[i][j-1];
			else if (j-1 < 0)
				dp[i][j] = dp[i-1][j];
			else 
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	
	 cout << dp[row][col];
	
}
