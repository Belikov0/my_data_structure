#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5004;
const int INF = 0x7f7f7f7f;

int main(){
	int len[N];
	int wid[N];
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> len[i] >> wid[i];
	
	for (int i = N-1; i >= 0; i--){
		for (int j = 0; j < i; j++){
			if (len[j] < len[j+1]){
				swap(len[j], len[j+1]);
				swap(wid[j], wid[j+1]);
			}
			if (len[j] == len[j+1] && wid[j] < wid[j+1]){
				swap(wid[j], wid[j+1]);
			}
		}
	}
	
	int rem[N]; // ����ÿ�������е����һλ 
				// �������ʣ�rem��һ������ 
	int ans = 1;
	for (int i = 0; i < n; i++){
		rem[i] = INF;
	}
	rem[0] = wid[0];
	
	for (int i = 0; i < n; i++){
		int flag = 0;
		for (int j = 0; j < ans; j++){ // ���� 
			if (wid[i] <= rem[j] ){
				//�����rem�д���һ�������ڵ���wid, ����Բ����Ҳ����� 
				rem[j] = wid[i]; 
				flag = 1;
				break;
			}
		}
		// ���wid�����е����������һλ���������������� 
		if (flag == 0){
			rem[ans++] = wid[i];
		}
//		*lower_bound(rem, rem+n, wid[i]) = wid[i]; 
	}
	
//	cout << upper_bound(rem, rem+n, INF-1)-rem << endl;
	cout << ans << endl;
	
	return 0;
} 
