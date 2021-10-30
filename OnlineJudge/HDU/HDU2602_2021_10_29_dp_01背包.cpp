#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int T;
	cin >> T;
	int N, V;
	int v[1005], w[1005];
	int dp[10005];
	while (T--){
		cin >> N >> V;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < N; i++){
			cin >> v[i];
		}
		for (int i = 0; i < N; i++){
			cin >> w[i];
		}
		
		for (int i = 0; i < N; i++){
			for (int j = V; j >= w[i]; j--){
				dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
			}
		}
		cout << dp[V] << endl;
	}
} 
