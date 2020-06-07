
/// there can be total three cases with which we can calculate the winning probability
/// First one , selecting white ball  i/(i+j).
/// Second one, dragon select black mice, princess also select black mice and black mice ran out from bag.
/// Its probability is -> j/(i+j) * (j-1)/(i+j-1) *(j-2)/(i+j-2) ,with this probability we can reach state prob[i][j-3]
/// Third One, dragon select black mice, princess also select black mice and white mice ran out from bag .
/// Its probability is -> j/(i+j) * (j-1)/(i+j-1) * i/(i+j-2) ,with this probability we can reach state prob[i-1][j-2]

/// For every i and j we have add three cases,i/(i+j) + j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2) * prob[i][j-3] + j/(i+j)*(j-1)/(i+j-1)*(i)/(i+j-2)*prob[i-1][j-2]
/// Time-0.062s

#include<bits/stdc++.h>

using namespace std;

const int mx=1001;

double prob[mx][mx];
/// prob[i][j] states the probability of winning of princess with i white balls and j black balls


int main()

{
  int w,b;
  cin>>w>>b;

  for(int i=1;i<=w;i++) prob[i][0]=1.0;/// there is no black ,so winning of princess is 1.0
  for(int j=1;j<=b;j++) prob[0][j]=0.0;/// No white ,princess lost

  for(int i=1;i<=w;i++)
  {
      for(int j=1;j<=b;j++)
      {
          prob[i][j]=1.0*i/(double)(i+j);
          /// when black mice are more than or equal to 3 ,then we can reach the state prob[i][j-3]
          if(j>=3)
          {
         prob[i][j]+=(double)j/(double)(i+j) *(double)(j-1)/(double)(i+j-1) *(double)(j-2)/(double)(i+j-2) *prob[i][j-3];
          }
          if(j>=2 && i>=1)
          {
         prob[i][j]+=(double)j/(double)(i+j) *(double)(j-1)/(double)(i+j-1) * (double)i/(double)(i+j-2)*prob[i-1][j-2];
          }
      }
  }
  printf("%.9lf\n",prob[w][b]);
  return 0;
}
