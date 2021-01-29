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

  long double dp[N+1][D2+1][D3+1][D5+1]={};
  dp[0][0][0][0] = 1.0;

  for(int n=0; n<=N-1; ++n){
    for(ll i=0; i<=D2; ++i){
      for(ll j=0; j<=D3; ++j){
        for(ll k=0; k<=D5; ++k){
          dp[n+1][i][j][k]   += dp[n][i][j][k]/6.0;
          dp[n+1][min(D2,i+1)][j][k]   += dp[n][i][j][k]/6.0;
          dp[n+1][i][min(D3,j+1)][k]   += dp[n][i][j][k]/6.0;
          dp[n+1][min(D2,i+2)][j][k]   += dp[n][i][j][k]/6.0;
          dp[n+1][i][j][min(D5,k+1)]   += dp[n][i][j][k]/6.0;
          dp[n+1][min(D2,i+1)][min(D3,j+1)][k] += dp[n][i][j][k]/6.0;
        }
      }
    }
  }

  cout << dp[N][D2][D3][D5] << endl;



  return 0;
}
