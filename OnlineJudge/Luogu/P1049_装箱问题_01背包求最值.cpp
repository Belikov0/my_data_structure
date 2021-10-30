#include <iostream>
#include <cstring>
using namespace std;

/* �����⣺Ҫʹʣ���ݻ�Vʱ�����Ž⣬��Ȼ���ݻ�V-v[i]ʱ�����Ž�
 * ״̬ת�Ʒ��̣�dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]]+v[i]);
 *               dp[j] = max(dp[j], dp[j-v[i]]+v[i]);
 * �߽������ͳ�ʼ�����ݻ�V == 0ʱ dp[0] == 0
 *                 �����ֵ����ȫ����ʼΪ0
 * ���˳��dp[j] ������ dp[j- v[i]]����⣬ �Ե�����
 *                 a. ��ÿ�������Ե�����, ��Ϊÿ������ֻ��ʹ��һ��
 *
 */


int main(){
    int V, n;
    cin >> V >> n;
    int dp_1[36][2005];
    int dp_2[20005];
    int v[36];
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    memset(dp_1, 0, sizeof(dp_1));
    memset(dp_2, 0, sizeof(dp_2));

    // ��ά���飬i ��ʾ ����ʹ�õ����ӵ�������j��ʾʣ���ݻ�Vʱ�����Ž�
    // ��ÿ������i�Ե�����
    for (int i = 0; i < n; i++){ // ÿ������ֻ����һ��
//        cout << i + 1 << " stuffs to fill the big box: " << endl;
        for (int j = V; j >= v[i]; j--){
//            dp_1[i][j] = dp_1[i-1][j];  ���ڳ�ʼ��Ϊ0��������һ�����ʡ��
            dp_1[i][j] = max(dp_1[i-1][j], dp_1[i-1][j-v[i]]+v[i]);
//            cout << "The volume of " << j << " can hold " << dp_1[i][j] << " when " << i+1 << " stuffs." << endl;
        }
    }

    // һά���飬j��ʾʣ���ݻ�Vʱ�����Ž�
    // ��ʣ���ݻ�����Ե�����
//    for (int j = 0; j <= V; j++){
//        for (int i = 0; i < n; i++){ // ����д�������ʾÿ������������޸����ӿ���ʹ��
//            if (j >= v[i]){
//                dp_2[j] = max(dp_2[j], dp_2[j-v[i]]+v[i]);
//            }
//        }
//    }

    for (int i = 0; i < n; i++){ // ÿ������ֻ����һ��
//        cout << i + 1 << " stuffs to fill the big box: " << endl;
        for (int j = V; j >= v[i]; j--){
            dp_2[j] = max(dp_2[j], dp_2[j-v[i]]+v[i]);
//            cout << "The volume of " << j << " can hold " << dp_2[j] << " when " << i+1 << " stuffs." << endl;
        }
    }


//    cout << V - dp_1[n-1][V] << endl;
    cout << V - dp_2[V] << endl;

    return 0;


}

