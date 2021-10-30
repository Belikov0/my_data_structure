#include <iostream>
#include <cstring>
using namespace std;

/* 子问题：要使剩余容积V时有最优解，必然在容积V-v[i]时有最优解
 * 状态转移方程：dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]]+v[i]);
 *               dp[j] = max(dp[j], dp[j-v[i]]+v[i]);
 * 边界条件和初始化：容积V == 0时 dp[0] == 0
 *                 求最大值，可全部初始为0
 * 求解顺序：dp[j] 依赖于 dp[j- v[i]]的求解， 自底向上
 *                 a. 对每个箱子自底向上, 因为每个箱子只能使用一次
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

    // 二维数组，i 表示 可以使用的箱子的数量，j表示剩余容积V时的最优解
    // 由每个箱子i自底向上
    for (int i = 0; i < n; i++){ // 每个箱子只能用一次
//        cout << i + 1 << " stuffs to fill the big box: " << endl;
        for (int j = V; j >= v[i]; j--){
//            dp_1[i][j] = dp_1[i-1][j];  由于初始化为0，所以这一句可以省略
            dp_1[i][j] = max(dp_1[i-1][j], dp_1[i-1][j-v[i]]+v[i]);
//            cout << "The volume of " << j << " can hold " << dp_1[i][j] << " when " << i+1 << " stuffs." << endl;
        }
    }

    // 一维数组，j表示剩余容积V时的最优解
    // 由剩余容积情况自底向上
//    for (int j = 0; j <= V; j++){
//        for (int i = 0; i < n; i++){ // 错误写法，这表示每个体积都有无限个箱子可以使用
//            if (j >= v[i]){
//                dp_2[j] = max(dp_2[j], dp_2[j-v[i]]+v[i]);
//            }
//        }
//    }

    for (int i = 0; i < n; i++){ // 每个箱子只能用一次
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

