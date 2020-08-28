
/// Codeforces: Div1 840A - Leha and Function 
/// Category: Expectation Value + Number Theory +sort.(Medium)


/// After finding F(n,k) = (n+1)/(k+1) .
/// It is clear that,high n and low k can make u maximum possible.
/// we have to make f(a',b) maximum, so re-arrange the array a'
/// so that a' have the element which has largest element with lowest element in b ,second largest with second smallest and so on.

#include<bits/stdc++.h>

using namespace std;

const int mx=200001;


int main()

{
   int m,num;
   cin>>m;
   vector< pair<int,int> >b;
   vector<int>a;
   vector<int>A(m);
   for(int i=0;i<m;i++)
   {
       cin>>num;
       a.push_back(num);
   }
   sort(a.rbegin(),a.rend());
   for(int j=0;j<m;j++)
   {
       cin>>num;
       b.push_back(make_pair(num,j));
   }
   sort(b.begin(),b.end());
   for(int i=0;i<m;i++)
   {
       A[b[i].second]=a[i];
   }

   for(int j=0;j<m;j++) cout<<A[j]<<" ";
   cout<<endl;
}
