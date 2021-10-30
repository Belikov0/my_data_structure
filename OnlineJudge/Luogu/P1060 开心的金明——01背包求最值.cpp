#include <iostream>
#include <cstring> 
using namespace std;

// Ҫ֪�� N Ԫ�ܹ�������ܼ�ֵ�����Ž⣬ ��Ҫ֪�� N - p[i] �ܹ�������ܼ�ֵ�����Ž� 
// ״̬ת�Ʒ��̣� dp[N] = max(dp[N], dp[N-p[i]]+v[i])
// �߽����ʼ��0Ԫ�ܹ����ֵΪ0�������ֵ���ɳ�ʼ������Ϊ0��
// ����˳��ÿ����Ʒֻ��һ����������Ʒ�Ե����� 
 
int main(){
	
	
	int N, m;
	cin >> N >> m;
	int p[30], v[30]; 
	for (int i = 0; i < m; i++){
		cin >> p[i] >> v[i];
		v[i] *= p[i];
	}//�����������
	
	int dp[30010];
	memset(dp, 0, sizeof(dp));
	
	for (int i = 0; i < m; i++){
		cout << "while there are(is) " << i+1 << " category(s)"<<endl; 
		for (int j = N; j >= p[i]; j--){  
			// ����Ҫ���� 
			// Ҫ��֤��dp[j]ʱ��dp[j-w[i]]��״̬��dp[i-1][j-w[i]] (������)  
			// �����p[i]��ʼ���������ڵ���֮���j, dp[j-w[i]]�������Ѿ����޸Ĺ���dp[i][j-w[i]]������Ӧ��Ҫ��dp[i-1][j-w[i]] 
			// dp[i][j-w[i]]���Ѿ����ڵ�i�׶ε�״̬�������Ѿ�ʹ�ù���i����Ʒ
			// �������ȫ�������⣬��ôӦ��˳��
			dp[j] = max(dp[j], dp[j-p[i]]+v[i]);
			cout << "If " << j << " equipped, the max value is " << dp[j] << endl;
		}
	}
	
	cout << dp[N] << endl;
	
	return 0;
	
} 
