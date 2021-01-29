#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  ll D;
  cin >> N >> D;

  ll D2=0, D3=0, D5=0;
  while(D%2==0){D/=2; ++D2;};
  while(D%3==0){D/=3; ++D3;};
  while(D%5==0){D/=5; ++D5;};
  if(D!=1){cout << 0 << endl; return 0;};

  long double dp[N+1][2*N+3][N+3][N+3]={};
  dp[0][0][0][0] = 1.0;

  for(int n=0; n<=N-1; ++n){
    for(int i=0; i<=2*N; ++i){
      for(int j=0; j<=N; ++j){
        for(int k=0; k<=N; ++k){
          dp[n+1][i][j][k]   += dp[n][i][j][k]/6.0;
          dp[n+1][i+1][j][k]   += dp[n][i][j][k]/6.0;
          dp[n+1][i][j+1][k]   += dp[n][i][j][k]/6.0;
          dp[n+1][i+2][j][k]   += dp[n][i][j][k]/6.0;
          dp[n+1][i][j][k+1]   += dp[n][i][j][k]/6.0;
          dp[n+1][i+1][j+1][k] += dp[n][i][j][k]/6.0;
        }
      }
    }
  }

  double ans = 0;
  for(int i=D2; i<=2*N; ++i){
    for(int j=D3; j<=N; ++j){
      for(int k=D5; k<=N; ++k){
        ans += dp[N][i][j][k];
      }
    }
  }

  cout << ans << endl;
  



  return 0;
}
