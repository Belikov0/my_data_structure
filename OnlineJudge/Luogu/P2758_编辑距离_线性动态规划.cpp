#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int INF = 0x7f7f7f7f;
/*
 dp[i][j] ��ʾǰ�г�i�����г�jʱ���޸Ĵ���
 		��ô�г�i��Ӧ���±�Ϊi-1��ע���±��޸�
 ״̬ת�ƣ�ǰ�г�i�����г�j���ַ����޸Ĵ���״̬ 
 		   ������ǰ�г�i, ���г�j-1�� ǰ�г�i-1, ���г�j���ַ����޸Ĵ���״̬ͨ������õ� 
		   Ҳ������ǰ�г�i-1, ���г�j-1��״̬ͬʱ����һλ���Ƚ������Ƿ�������õ� 
 ״̬ת�Ʒ��̣�
 	a.����ͬʱ����һλ�������ͬ�������޸� dp[i][j] = dp[i-1][j-1]
	b.�Ƚ��Ƿ���Ҫ����ɾ���������У�dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
 �߽磺���һ��Ϊ0�����޸Ĵ���Ϊ��һ�г������ж�Ϊ0��Ϊ0 
 ˳���Ե����� 
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
			// ���ִ���Ҳ���� 
//			x = 1;
//			if (a[i-1] == b[j-1])
//				x = 0;
//			dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+x);

			if (a[i-1] == b[j-1]) // ע���±��ϵ��dp[1]��ʾҪ����a[0]�����������һλ 
				dp[i][j] = dp[i-1][j-1];
			else 
				dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1);
		}
	}
	int ans = dp[la][lb];
	cout << ans;
} 
