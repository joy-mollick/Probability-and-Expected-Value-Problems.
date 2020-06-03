#include<bits/stdc++.h>

using namespace std;


// Counting problems and reduction of power series

typedef unsigned long long ll;

ll mod=1000000007 ;

int main()

{
    ios_base::sync_with_stdio(false);
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    double swin=(a/b);
    double sntwin=1.0-(a/b);
    double zntwin=1.0-(c/d);
    double r=sntwin*zntwin;
    double infinite_sum=1.0/(1.0-r);
    double answer=swin*infinite_sum;
    printf("%0.06lf\n",answer);
    return 0;
}
