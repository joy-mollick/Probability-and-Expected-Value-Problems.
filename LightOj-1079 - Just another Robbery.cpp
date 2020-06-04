
/// Time-0.045s
/// Fantastic problem 

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

/// 0-1 knapsack and probability problem
/// dp[i][j] states that by among i banks with how minimum probability we can get j millions money ?
/// I think dp states are clear ,now time to code
/// And after calculation we will check among n banks how maximum money we can achieve with probability less than given p.dp[n][i]<p where ,i goes till summation of money

int main()
{
  int T;
  double p;
  int n;
  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++)
  {
      scanf("%lf%d",&p,&n);
      int money[n+1];
      double probability_of_caught_of_ith_bank[n+1];
      int sum=0;
      for(int i=1;i<=n;i++)
      {
          scanf("%d%lf",&money[i],&probability_of_caught_of_ith_bank[i]);
          sum+=money[i];
      }
      /// here maximum sum money we can achieve as there is no resistance ,so sum is our max allowance
      double dp[n+1][sum+1];///sum range can be 0...sum and total n banks 0...n
      memset(dp,0,sizeof(dp));
      for(int i=1;i<=sum;i++) dp[0][i]=1.0;/// base case
      /// we will iterate through n banks
      for(int i=1;i<=n;i++)
      {
          /// and compute minimum assuming getting money j
          /// where j can be maximum sum
          for (int j=sum;j>=1;j--)
          {
        /// if sum is greater than money,so we can check by assuming taking money from here
              if(j>=money[i])
              {
        ///As we are assuming we can take money from ith bank ,so we we assume we had not been caught during robbing (i-1) banks .
        ///So, (1-dp[i-1][j-money[i]]) states the probability of not being caught during robbing of (i-1) banks
        /// But probability of being caught to rob i banks is (1-dp[i-1][j-money[i]])*probability_of_caught_of_ith_bank[i].
                double probability_of_thinking_get_money_from_i=dp[i-1][j-money[i]]+(1.0-dp[i-1][j-money[i]])*probability_of_caught_of_ith_bank[i];
                dp[i][j]=min(dp[i-1][j],probability_of_thinking_get_money_from_i);
              }
              /// otherwise we will not rob this money
              else
              {
                  dp[i][j]=dp[i-1][j];
              }
          }
      }

        int maximum_money_with_probability_of_caught_less_than_p=0;
        /// starting from maximum value to lower value
        for(int i=sum;i>=1;i--)
        {
            if(dp[n][i]<p)
            {
            maximum_money_with_probability_of_caught_less_than_p=i;
            break;
            }
        }
        printf("Case %d: %d\n",cas,maximum_money_with_probability_of_caught_less_than_p);

  }
  return 0;
}
