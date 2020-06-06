
/// Nice one 
/// Time-0.001s
/// If the probability of a success in a bernaulli trial is p then the expected number of successes in n trials is n*p. The proof is simple (given below) -
///The number of successes in n trials = (if 1st trial is success then 1 else 0) + ... + (if nth trial is success then 1 else 0)
///The expected value of each bracket is  1*p + 0*(1-p) = p. Thus the expected number of successes in n trials is n*p.
/// I am giving an example that what is the expected value of getting head in n trials with dice ,e(x)=n*(0.5) ,right ?

/// Now our question is based upon bernaulli trials ,here are two outcomes only ( ball in basket or ball is not in basket)
/// We have to find the number of expected number of balls into the basket which have been thrown successfully
/// where the probability of selecting a box among m boxes is (1/m).
/// So,expected numbers of balls of every box is p*(1/m),total expected number of balls for each box of m boxes will be (p/m)+(p/m) +(p/m) +..... mtimes=m*(p/m)=p.
/// so for n people total expected number of balls will be n*p
/// With k trials, expected number of balls will be n*p*k.
/// At the end ,the expected number of success(probability of success is p) with k trials k*p .Number of people n,so n*k*p

#include<bits/stdc++.h>

using namespace std;

int main()
{
  int t,n,d,T;
  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++)
  {
  int n,m,k;
  double p;
  scanf("%d%d%d%lf",&n,&m,&k,&p);
  printf("Case %d: %0.06lf\n",cas,n*p*k);
  }
  return 0;
}
