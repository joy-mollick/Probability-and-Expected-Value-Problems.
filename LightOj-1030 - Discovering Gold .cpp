
/*
 Find the probability of every positions to be reached by other positions behind this position
 Think of 1 X 6 grid .
 Now the positions 1 2 3 4 5 6
 If we try to find the probability of position 5 to be reached ,then
 prob(5)=(think getting 2 we will come to 5 from position 3) prob(3)*(1/3) ,as from 3 there are possible 3 positions we can go ,so probability to go 5 is (1/3)
        +(think getting 3 we will come to 5 from position 2) prob(2)*(1/4) ,as from 2 there are possible 4 positions we can go ,so probability to go 5 is (1/4)
        +(think getting 4 we will come to 5 from position 1) prob(1)*(1/5) ,as from 1 there are possible 5 positions we can go ,so probability to go 5 is (1/5)
        +(think getting 1 we will come to 5 from position 4) prob(4)*(1/2) ,as from 4 there are possible 2 positions we can go ,so probability to go 5 is (1/2)
    Now we get probability of every positions ,so expected(e)=ai*proba(i),where i is from 1 to n.
*/
/// Time-0.001s
/// Fantastic problem :) 
/// Enjoy solving it 

#include<bits/stdc++.h>

using namespace std;

const int mx=101;

double prob[mx];

int main()

{
    int T,N;
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        scanf("%d",&N);
        double gold[N+1];
        int i,j;
        for( i=1;i<=N;i++) scanf("%lf",&gold[i]);
        memset(prob,0,sizeof(prob));

        prob[1]=1.0;/// at first time , you are in here ,probability is 1.0.
        prob[N]=1.0;/// when reach here , the game ends so probability is 1.0 as only one time ,you can reach here the game will end 

        /// iterating every position and finding value of prob... of every position i to be reached
        for(i=2;i<N;i++)
        {
            /// there can be 6 positions (i-j) from where we can reach position i
            for(j=1;j<=6;j++)
            {
                if((i-j)>=1)
                {
                    double nmber_of_possible_positions_from_i_minus_j=(min(6,(N-(i-j))));
                    prob[i]+=prob[i-j]*(1.0/nmber_of_possible_positions_from_i_minus_j);
                }
            }
        }
        double expectation_value=0.0;
        for(int i=1;i<=N;i++) expectation_value+=(prob[i]*gold[i]);
        printf("Case %d: %.8f\n",cas,expectation_value);
        cas++;
    }
    return 0;
}
