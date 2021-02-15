#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main(){
  int D;
  string N;
  cin >> D >> N;
  vector<int> n;
  for(auto num : N){
    n.push_back(num-'0');
  }
  int length = N.size();

  /* for(int i=0; i<length; ++i){ */
  /*   cout << n[i]; */
  /* } */
  /* cout << endl; */

  ll dp[length+1][D][2] = {}; //dp[i][j][k] -> i-1 digit, mod is j, k=0:the i-1 upper digits match N's(k=1 is otherwise)
  dp[0][0][0] = 1; //correspond to 0
  for(int i=0; i<length; ++i){
    for(int j=0; j<D; ++j){
      /* k=0 */
      dp[i+1][(j+n[i])%D][0] = (dp[i+1][(j+n[i])%D][0] + dp[i][j][0])%MOD;


      for(int num=0; num<n[i]; ++num){
        dp[i+1][(j+num)%D][1] = (dp[i+1][(j+num)%D][1] + dp[i][j][0])%MOD;
      }

      /* k=1 */
      for(int num=0; num<=9; ++num){
        dp[i+1][(j+num)%D][1] = (dp[i+1][(j+num)%D][1] + dp[i][j][1])%MOD;
      }
    }
  }

  cout << (dp[length][0][1] + dp[length][0][0] - 1)%MOD << endl;

  return 0;
}
