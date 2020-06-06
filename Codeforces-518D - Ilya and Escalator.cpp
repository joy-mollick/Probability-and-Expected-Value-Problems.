
/// First calculate the probability of jth people on escalator after ith second ,by prob[i][j].
/// Then expected value of people will summation of p(i)*x(i) for every people ,that is simple.
/// In every case,we can think that jth people will enter into there by probability of p + jth people will not enter into there with probability (1-p).
/// Think about first case -
/// if jth people enters , prob[i+1][j+1]+=prob[i][j]*p
/// if jth people doesn't enter ,prob[i+1][j]+=prob[i][j]*(1-p) .

/// prob[i][j] states for probability of j people after i seconds
/// So,new people enters into escalator new state prob[i+1][j+1] ,which adds prob[i][j]*p as successful event occurs

/// prob[i][j] states for probability of j people after i seconds
/// New people will not enter ,so second is i+1 ,but people will not enter.So state will be prob[i+1][j],which adds prob[i][j]*(1-p).
/// Time-0.046s
/// Nice one 

#include<bits/stdc++.h>

double prob[2011][2011];/// initially all zero

using namespace std;

int main()
{
  int n,t;
  double p;
  cin>>n>>p>>t;
  prob[0][0]=1.0;///after zero seconds there is zero people ,its probability is 1.0
  for(int i=0;i<=t;i++)///take i people and find all probability of their appearance on the escalator after j seconds
  {
      for(int j=0;j<=n;j++)
      {
          if(j==n)///there is no option to enter into escalator
          {
              prob[i+1][j]+=prob[i][j];
          }
          else
          {
              prob[i+1][j+1]+=(prob[i][j]*p);
              prob[i+1][j]+=(prob[i][j]*(1-p));
          }
      }
  }
  double expected_value=0;
  for(int i=0;i<=n;i++)
  {
      double pi=prob[t][i];
      int xi=i;/// i is the number of people after t seconds can be on the escalator with probability prob[i]
      expected_value+=(pi*(double)xi);
  }
  printf("%.6lf\n",expected_value);
  return 0;
}
