#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int p[N];
  for(int i=0; i<N; ++i){
    cin >> p[i];
  }

  bool dp[N+1][10001];
  for(int i=0; i<=N; ++i){
    for(int j=0; j<=10000; ++j){
      dp[i][j] = false;
    }
  }
  dp[0][0] = true;

  /* for(int i=0; i<=N; ++i){ */
  /*   for(int j=0; j<=10000; ++j){ */
  /*     if(dp[i-1][j]){ */
  /*       dp[i][j] = true; */
  /*       continue; */
  /*     } */
  /*     if(j<p[i]) continue; */
  /*     if(dp[i-1][j-p[i]]) dp[i][j] = true; */
  /*   } */
  /* } */
  for(int i=0; i<=N-1; ++i){
    for(int j=0; j<=10000; ++j){
      if(!dp[i][j]) continue;
      dp[i+1][j] = true;
      dp[i+1][j+p[i]] = true;
    }
  }
  
  int ans = 0;
  for(int i=0; i<=10000; ++i){
    if(dp[N][i]) ++ans;
  }

  cout << ans << endl;

  /* for(int i=0; i<=N; ++i){ */
  /*   for(int j=0; j<=10000; ++j){ */
  /*     if(dp[i][j]) cout << 'o'; */
  /*     else cout << 'x'; */
  /*   } */
  /*   cout << endl; */
  /* } */

  return 0;
}
