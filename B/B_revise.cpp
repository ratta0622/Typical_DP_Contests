#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;
  int N = max(A,B);
  int a[N+1], b[N+1];
  for(int i=0; i<=N; ++i){
    if(i>=max(N-A,0) && i<=N-1) cin >> a[i];
    else a[i] = 0;
  }
  for(int i=0; i<=N; ++i){
    if(i>=max(N-B,0) && i<=N-1) cin >> b[i];
    else b[i] = 0;
  }
  reverse(a, a+N+1);
  reverse(b,b+N+1);

  /* for(int i=0; i<=N; ++i){ */
  /*   cout << a[i] << '\t'; */
  /* } */
  /* cout << endl; */
  /* for(int i=0; i<=N; ++i){ */
  /*   cout << b[i] << '\t'; */
  /* } */
  /* cout << endl; */

  int dp[N+1][N+1]={};
  int turn = (A+B)%2;
  for(int i=1; i<=N; ++i){
    if((i+turn)%2==0){
      dp[i][0] = dp[i-1][0] + a[i];
    }else{
      dp[i][0] = dp[i-1][0];
    }
  }
  for(int i=1; i<=N; ++i){
    if((i+turn)%2==0){
      dp[0][i] = dp[0][i-1] + b[i];
    }else{
      dp[0][i] = dp[0][i-1];
    }
  }

  for(int i=1; i<=N; ++i){
    for(int j=1; j<=N; ++j){
      if((i+j+turn)%2 == 0){
        dp[i][j] = max(dp[i-1][j]+a[i], dp[i][j-1]+b[j]);
      }else{
        dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  /* cout << dp[A][B] << endl; */
  

  /* cout << endl; */
  /* for(int i=0; i<=A; ++i){ */
  /*   for(int j=0; j<=B; ++j){ */
  /*     cout << dp[i][j] << '\t'; */
  /*   } */
  /*   cout << endl; */
  /* } */

  cout << dp[A][B] << endl;

  return 0;
}
