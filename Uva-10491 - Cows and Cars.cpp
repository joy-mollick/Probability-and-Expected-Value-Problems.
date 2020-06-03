



/// Time-0.114s
/// Ajaira problem

#include<bits/stdc++.h>

using namespace std;


int main()

{
    int a,b,c;
    double ans=0.0;
    while(scanf("%d%d%d",&a,&b,&c)==3)
    {
        if (!b || a+b==c+1) {ans=0.0;}
        else{
        double first_case=(double)(a*b)/(double)((a+b)*(a+b-c-1));
        double second_case=(double)(b*(b-1))/(double)((a+b)*(a+b-c-1));
        ans=first_case+second_case;
        }
        printf("%0.05lf\n",ans);
    }
    return 0;
}
