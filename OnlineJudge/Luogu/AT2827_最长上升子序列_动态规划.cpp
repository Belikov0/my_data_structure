#include <iostream>
using namespace std;

// Ҫ֪����ĳһ���β������������У�Ҫ��֪����ǰһ���β������������еĳ���
// ״̬ת�Ʒ��̣�dp[i] = max(dp[i], dp[j]+1��;
//               ��iΪ��β������������г���ʱiǰ��������������ټ�1
// �߽��������ʼ����ÿһ��������һλ�����г���������һ��ʱ�������1
// ����˳�򣬴�ǰ������ 
// ʱ�临�Ӷ�O(n2) 

int main(){
	// longest ascending subarray
	int n; 
	int a[100];
	cin >> n; 
	int dp[100];
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i] = 1;
	} 
	
	for (int i = 1; i <= n; i++){
		for (int j = 1;j < i; j++){
			if (a[i] > a[j]) //�����i����ڵ�j���ô����i��ŵ���j����湹������������ 
				dp[i] = max(dp[i], dp[j]+1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		ans = max(ans, dp[i]);  // ����ȡ�����ֵ 
	}
	cout << ans;
} 
