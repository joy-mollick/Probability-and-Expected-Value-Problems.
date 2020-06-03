

/*
 Expected number of moves to make some number to 1.by dividing its factor .
 Think about i ,its divisors will be say a1,a2,a3,a4. Total divisors 4
 Let's ,Expected number of moves of i to be 1 is  e(i) = (1/4)*( e(i/a1)+1) + (1/4)*( e(i/a2)+1) + (1/4)*( e(i/a3)+1) + (1/4)*( e(i/a4)+1)
                                                       = (1/4)*(e(i/a1))+(1/4)*( e(i/a2))+(1/4)*( e(i/a3))+ (1/4)*( e(i/a4))+(1/4)+(1/4)+(1/4)+(1/4)
                                                       = 4 x (1/4) + (1/4)*(e(i/a1)) + (1/4)*( e(i/a2)) + (1/4)*( e(i/a3)) + (1/4)*( e(i/a4))
                                        Now think , among all divisors of i , 1 is also its divisor ,right ?
                                        so , here among all a1,a2,a3,a4 one holds the value one .say that is a1.So when a1=1,then (i/a1)=i !!
                                        so , e(i/a1)=e(i) ,Now again proceed with our algorithm
                                        =4 x (1/4) +   (1/4)*(e(i))   + (1/4)*( e(i/a2)) + (1/4)*( e(i/a3)) + (1/4)*( e(i/a4))
        e(i) - (1/4)*(e(i))             =4 x (1/4) + (1/4)*( e(i/a2)) + (1/4)*( e(i/a3)) + (1/4)*( e(i/a4)) .
        e(i) * ( 4-1 ) / 4              = (1/4) * ( 4 + ( e(i/a2)) + ( e(i/a3)) + ( e(i/a4)) )
        e(i) *(4-1)                     = 4 * (1/4) * ( 4 + ( e(i/a2)) + ( e(i/a3)) + ( e(i/a4)) )
        e(i) *( 4-1)                    = ( 4 + ( e(i/a2)) + ( e(i/a3)) + ( e(i/a4)) )
        e(i)                            = ( 4 + ( e(i/a2)) + ( e(i/a3)) + ( e(i/a4)) ) / (4-1)
     More formally it can be said ,e(i) = ( n + summation of all expectation value of factors of number ,i ) / (n-1) .where n is the number of factors

*/

/// Time-0.114s
/// Nice Classical One 

#include<bits/stdc++.h>

using namespace std;

const int mx=100001;

double expectation[mx];

void sieve()
{
    expectation[1]=0.0;
    /// we will calculate expect.. value for every i
    for(int i=2;i<mx;i++)
    {
        int nmber_of_factors=0;
        double summation=0.0;
        expectation[i]=0.0;
        for(int j=2;j*j<=(i);j++) /// as e(1) is 0,and e(i) is not included in our sum so avoid e(j=1) and e(i/(j=1))=e(i)
        {
            if( i%j==0 && (i/j)!=j )
            {
                nmber_of_factors+=2;
                summation+=expectation[j];
                summation+=expectation[i/j];
            }
            else if(i%j==0 && (j*j)==i)///by using this j,we can go only one state
            {
                nmber_of_factors++;
                summation+=expectation[j];
            }
        }
        nmber_of_factors+=2;///we have ignored 1 and i
        expectation[i]=(double)nmber_of_factors+summation;
        expectation[i]=expectation[i]/(double)(nmber_of_factors-1);
    }
}

int main()

{
    sieve();
    int T,n;
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        scanf("%d",&n);
        printf("Case %d: %0.8lf\n",cas,expectation[n]);
        cas++;
    }
    return 0;
}
