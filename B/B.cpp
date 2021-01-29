/* this solution is wrong. */
/* correct solution is to think from the back. */
#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;
  int a[1001], b[1001];
  for(int i=0; i<=1000; ++i){
    if(i>=1 && i<=A) cin >> a[i];
    else a[i] = 0;
  }
  for(int i=0; i<1000; ++i){
    if(i>=1 && i<=B) cin >> b[i];
    else b[i] = 0;
  }

  int dp[1001][1001];
  dp[0][0] = {};
  for(int i=1; i<=1000; ++i){
    if(i%2==1){
      dp[i][0] = dp[i-1][0] + a[i];
    }else{
      dp[i][0] = dp[i-1][0];
    }
  }
  for(int i=1; i<=1000; ++i){
    if(i%2==1){
      dp[0][i] = dp[0][i-1] + b[i];
    }else{
      dp[0][i] = dp[0][i-1];
    }
  }

  for(int i=1; i<=A; ++i){
    for(int j=1; j<=B; ++j){
      if((i+j)%2 == 1){
        dp[i][j] = max(dp[i-1][j]+a[i], dp[i][j-1]+b[j]);
      }else{
        dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  cout << dp[A][B] << endl;
  

  for(int i=0; i<=A; ++i){
    for(int j=0; j<=B; ++j){
      cout << dp[i][j] << '\t';
    }
    cout << endl;
  }


  return 0;
}
