#include <iostream>
#include <cstring>
using namespace std;
/*
* dp�����±��ֵ�ĺ��� 
* ״̬ת�Ʒ����Ǳ�ʾʲô��˼ 
* dp������γ�ʼ�� 
* ������˳������㣬�Ե��������Զ����� 
*
* ͨ����ӡdp�������жϳ������ȷ��(��forxѭ���б���dp����) 
*/



/*
*  �����⣺ ���������j�����i��ʼһ���� i+s[i] >= j; 
*  dp���� bool dp[N] ��ʾ�ܷ�����i 
* ״̬ת�Ʒ���  dp[j] = dp[j] || dp[i] && i+s[i] >= j;  
* ��ʼ������һ�������ܵ���dp[0]Ϊtrue�� ����δ֪��ȫ��Ϊfalse 
* ����˳�򣺺����Ƿ�����������ǰ��ģ���ǰ������� 
*
*
*/


int main(){
	int m;
	cin >> m;
	int s[1000];
	for (int i = 0; i < m; i++){
		cin >> s[i];
	}
	bool dp[1000];
	memset(dp, false, sizeof(dp));
	dp[0] = true;
	
	for (int j = 1; j < m; j++){
		for (int i = 0; i < j; i++){
			dp[j] = dp[j] || (dp[i] && i+s[i] >= j);
			if (dp[j])
				break;
		}
	}
	cout << dp[m-1];
}
