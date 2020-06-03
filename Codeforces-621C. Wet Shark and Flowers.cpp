/*
Very nice problem One .
First find the probability of a number among l and r not being multiple of p for every n.
Then check for every pair and find the probability of anyone of that pair being probability of numbers being multiple of p 
because if any one of the pair becomes multiple of p,then product will be multiple of p.
Then summation all the (proba*value(dollar)) .This is our expected value .

*/


#include<bits/stdc++.h>

using namespace std;


// Basic probability and series reduction problem

typedef unsigned long long ll;

ll mod=1000000007 ;

/*

ll po(ll a,ll b)
{
   ll ans=1ll;
   while(b)
   {
       if(b&1)
        ans=(ans*a)%mod;
       b=b>>1;
       a=(a*a)%mod;
   }
   return (ans%mod);
}
*/
int num_of_multiples_range(int l,int r,int p)
{
    int s=r/p;
    int t=(l-1)/p;
    return s-t;
}

int main()

{
    ios_base::sync_with_stdio(false);
    int n,p,l,r;
    cin>>n>>p;
    vector<double>v;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r;
        double num=(double)num_of_multiples_range(l,r,p);
        double nt_mul=(double)(r-l+1)-num;
        double tot=(double)(r-l+1);
        double not_prob=nt_mul/tot;
        v.push_back(not_prob);
    }
    double dollar=2000.0;
    double ans=0.0;
    for(int i=0;i<n-1;i++)
    {
        double a_not=v[i];
        double b_not=v[i+1];
        double get_dollar_prob=1.00-(a_not*b_not);
        ans=ans+(get_dollar_prob*dollar);
    }
    double a_not=v[0];
    double b_not=v[n-1];
    double get_dollar_prob=1.00-(a_not*b_not);
    ans=ans+(get_dollar_prob*dollar);
    printf("%0.06lf\n",ans);
    return 0;
}
