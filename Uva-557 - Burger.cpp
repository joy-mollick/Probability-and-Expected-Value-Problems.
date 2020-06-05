
/// Time-0.00s
/// Given n people including Ben and Bill.
/// There exactly are n/2 cheeseburgers and n/2 hamburgers.
/// Now what is the probability of being situation where Last Two person Bell and Bill will get same type of burgers ?
/// So,think negative that what is the probability of being gotten the different type of burgers by Bell and Bill
/// Now we have to think that ,if last special two person want to take different burgers,
/// Then among (n-2) guests (n-2)/2 guests had to take exactly cheeseburgers and rest of (n-2) had to take exactly (n-2)/2 hamburgers.
/// Then two burgers of different kinds will be remaining which makes sense to us that the probability of bell and bill get different burgers
/// So , choosing from (n-2) ,(n-2)/2 people , is nCr(n-2,(n-2)/2) which means count of events where probability of each event is (1/2)^(n-2).
/// So ,total such condition's probability is nCr(n-2,(n-2)/2) * (1/2)^(n-2).
/// But such calculation of especially nCr(n-2,(n-2)/2) is not possible ,as n can be big as 100000.
/// we have to find another option that if we link up of prob(n) with its previous prob(n-2)or prob(n-4) or...
///Then it can be calculated recursively !!
/// if you do some work on paper by pen and pencil ,then you will get relationship like
/// prob[n] = prob[n-2] * ( (n-3)/(n-2) )
/// base case when bill and ben are only guests then prob[2]=1;

#include<bits/stdc++.h>

using namespace std;

const int mx=100005;

double prob[mx];

int main()
{
  int t,n;
  scanf("%d",&t);
  prob[2]=1.0;
  for (int  i=4; i<mx;i +=2)  prob [i] = prob[i-2] * ( double)(i-3)/(i-2);
  int caso=1;
  for(caso=1;caso<=t;caso++)
  {
      scanf("%d",&n);
      printf("%0.4lf\n",1.0-prob[n]);
  }
  return 0;
}
