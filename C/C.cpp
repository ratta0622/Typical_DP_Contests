#include <bits/stdc++.h>
using namespace std;

inline long double prob(long double RP, long double RQ){
  return 1/(1+pow(10, (RQ-RP)/400));
}

int main(){
  int K;
  cin >> K;
  int N = pow(2,K);
  long double R[N];
  for(int i=0; i<N; ++i){
    cin >> R[i];
  }

  long double dp[N][K]={};
  for(int i=0; i<N; i+=2){
    dp[i][0] = prob(R[i], R[i+1]);
    dp[i+1][0] = prob(R[i+1], R[i]);
  }

  for(int j=1; j<K; ++j){
    for(int i=0; i<N; ++i){
      int block = i/pow(2,j);
      if(block%2 == 0){
        long double another_block = 0;
        for(int k=pow(2,j)*(block+1); k<pow(2,j)*(block+2); ++k){
          another_block += prob(R[i], R[k])*dp[k][j-1];
        }
        dp[i][j] = dp[i][j-1]*another_block;
      }else{
        long double another_block = 0;
        for(int k=pow(2,j)*(block-1); k<pow(2,j)*block; ++k){
          another_block += prob(R[i], R[k])*dp[k][j-1];
        }
        dp[i][j] = dp[i][j-1]*another_block;
      }
    }
  }
  
  for(int i=0; i<N; ++i){
    cout << dp[i][K-1] << endl;
  }

  /* for(int i=0; i<N; ++i){ */
  /*   for(int j=0; j<K; ++j){ */
  /*     cout << dp[i][j] << '\t'; */
  /*   } */
  /*   cout << endl; */
  /* } */


  return 0;
}
