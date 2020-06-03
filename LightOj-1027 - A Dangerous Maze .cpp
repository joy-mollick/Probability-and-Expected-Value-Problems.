
/*
pos=positive value (which will lead u to go out)
neg=negative value (which will lead u to remain first position to start again)
E(x)= ( abs(xi) + E(x) ) + ( xi) ,for each door.
so , Overall E(x) = (neg/N)*( abs(xi) + E(x) ) + (pos/N) *(xi)
             N*E(x)     = (neg)*(abs(xi)) + pos*(xi) + neg(E(x))
             E(x) *(N-neg) = summation of all abs(xi) ,where i is from 1 to N .
             E(x) = sum(xi)/ ( N-neg) .
             This is our answer .
       When there  is no positive xi ,then it is inf to go out.
*/

 /// Basic Expected Value
 /// Time-0.001s
 
 #include<bits/stdc++.h>

 using namespace std;

 typedef long long ll;

 int main()
 {
    int tc,N,ai;
    scanf("%d",&tc);
    for(int cas=1;cas<=tc;cas++)
    {
        scanf("%d",&N);
        int neg=0;
        int summatory_of_xi=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&ai);
            if(ai<0) {neg++;ai=ai*(-1);}
            summatory_of_xi=summatory_of_xi+ai;
        }
        int denominator=N-neg;
        if(denominator==0)
          {printf("Case %d: inf\n",cas);continue;}
        int numerator=summatory_of_xi;
        int gcd=__gcd(denominator,numerator);
        printf("Case %d: %d/%d\n",cas,(numerator/gcd),(denominator/gcd));
    }
    return 0;
 }
