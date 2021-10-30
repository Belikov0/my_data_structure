#include <iostream>
#include <cstring>
using namespace std;
/*HDU2844 
	���صĶ��ر����㷨(�������)
		��ÿһ��n��Ӳ�Ҷ���Ϊ������Ӳ��
	 	ת��Ϊ01�������� 
	�����Ʋ��
		������������ն�������ϳ��µı���
		ת��Ϊ01�������� 
		
	���������⣺����ʹ�������Ż����� 
	
	dp���飺dp[j]��ʾ�Ƿ��ܹ������ֵ
	״̬ת�Ʒ��� dp[j] =  dp[j-a[i]]
	��ʼ������Ȼ������ֽ�ҿ��������ֵΪ0
	����˳�򣺿����ظ����ã��Լ�ֵ��˵˳�����
	 
*/
int main(){
	int n, m;
	int a[105], c[1005];
	bool dp[100005]; 
	int ans = 0;
	while (1){
		cin >> n >> m;
		if (n == 0 && m == 0)
			return 0;
		
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){ 
			cin >> c[i];
		}
		
		memset(dp, false, sizeof(dp));
		dp[0] = true; // ��ʼ�� 
		int num[100005]; 
		for (int i = 0; i < n; i++){
			memset(num, 0, sizeof(num)); // num ��ʾ��Ҫ�����i����Ʒʱ�� ��i����Ʒ�Ѿ���������� 
			for (int j = a[i]; j <= m; j++){
				if (dp[j-a[i]] && !dp[j] && num[j-a[i]] < c[i]){
					ans++;
					num[j] = num[j-a[i]]+1;
					dp[j] = true;
				}
			}
		}
		cout << ans << endl;
		ans = 0;
	} 
	
	
	return 0;
}
