
/// Birthday Paradox
/// if first one probability to be different is 1.0 (n/n)
/// Second one probability is (n-1)/n ,two have different birthday probability 1.0 * (n-1)/n .
/// three have different birthdays probability , 1.0 * (n-1)/n *(n-2)/n
/// Time-0.313s
/// Fantastic problem 

#include<bits/stdc++.h>

using namespace std;



int main()
{
  int t,n;
  cin>>t;
  int caso=1;
  for(caso=1;caso<=t;caso++)
  {
      cin>>n;
      double probability_of_all_people_different_brthday=1.0;/// assuming first one
      int ans=1;/// first one counted
      double at_least_two_have_same_birthday=0.0;
      int remain=n;
      while(true)
      {
          remain--;
          probability_of_all_people_different_brthday*=(double)remain/(double)n;
          ans++;
          at_least_two_have_same_birthday=(1.0-probability_of_all_people_different_brthday);
          if(at_least_two_have_same_birthday>=0.5)
          {
              break;
          }
      }
      ans--;/// You will invite and you are among one of them ,so decrease one
      printf("Case %d: %d\n",caso,ans);
  }
  return 0;
}
