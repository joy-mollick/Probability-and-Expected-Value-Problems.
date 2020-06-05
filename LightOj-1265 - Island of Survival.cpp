
/// Time-0.001s
/// Here deers have no effect on death and alive .so ignore it.
/// Here we have to find out the probability of being alive of you
/// Now if tigers are odd ,then you are finished .as two tigers are killed by each other every time ,then obviously there will be a last one who will kill u
/// If tigers are even ,then you may be survived if before selecting you ,all tigers will be selected by each of pair .
/// So we have to calculate the probability of these events till tigers are remaining assuming man will not be selected
/// So , every time when tigers are t in amount (t is even) ,the probability of selecting two tigers from (t+1) animals (including man)
/// p(t) = ncr(t,2)/ncr(t+1,2) = (t-1) / (t + 1) .
/// so proba=p(t)*p(t-2)*p(t-4) ......p(2) as every time , two tigers have been died ,if you do some calculation ,you will notice that multiplication will be 1/(t+1) .for every t

#include<bits/stdc++.h>

using namespace std;

int main()
{
  int t,n,d,T;
  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++)
  {
  scanf("%d%d",&t,&d);
  double ans= 1.0/(double)(1+t);
  if(t%2==1) ans=0.0;
  printf("Case %d: %0.06lf\n",cas,ans);
  }
  return 0;
}
