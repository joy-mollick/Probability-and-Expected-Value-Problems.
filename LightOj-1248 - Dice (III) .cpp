
/*
 Expected number of times to get N faces (not necessary consecutively).
 So, it is now easy to be calculated.
 First face getting e(1)=n/n=1.
 second face getting e(2)=n/(n-1).
 ith face getting e(i)=n/(n-(i-1)).
 Expected number of getting all faces at least once
 will be summation of e(i)=n/(n-(i-1)).for all faces
 = n/n + ............n/2 +n/1 .
*/
/// Time-0.012s

#include<bits/stdc++.h>

using namespace std;

const int mx=101;

double prob[mx];

int main()

{
    int T,n;
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        scanf("%d",&n);
        double ans=0.0;
        for(int i=1;i<=n;i++)
        {
            double expected_value_of_seeing_ith_faces=double(n)/(double)( n -(n-i));
            ans+=expected_value_of_seeing_ith_faces;
        }
        printf("Case %d: %0.8lf\n",cas,ans);
        cas++;
    }
    return 0;
}
