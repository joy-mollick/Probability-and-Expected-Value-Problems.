/*
All time he chooses the friends with better probability .So sort them from ascending to descending order .
And every time take one ,two,three or n frineds to check maximum probability and keep in an temporary varibale .
if a comes , probability a.
if a and b come probability a(1-b)+b(1-a)
If a ,b , c come -probability a(1-b)(1-c) + b(1-a)(1-c) +c (1-b)(1-a) ,like this calculate 
*/


#include<bits/stdc++.h>

using namespace std;

// Basic probability and mathmatical term

int main()

{
    int n;
    vector<double>proba;
    cin>>n;
    double p;
    while(n--)
    {
        cin>>p;
        proba.push_back(p);
    }
    sort(proba.rbegin(),proba.rend());
    double prev=1.0,present=0.0;
    double ans=0.0;
    for(int i=0;i<proba.size();i++)
    {
        p=proba[i];
        present*=(1-p);
        present=present+(prev*p);
        prev=prev*(1-p);
        ans=max(present,ans);
    }
    printf("%0.09lf\n",ans);
    return 0;
}
