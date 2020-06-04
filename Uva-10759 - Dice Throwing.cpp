
/// Time-0.000s
/// Nice one.
/// Classical probability problems

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll dp[26][150];
ll poss_events[25];

int main()
{
	int i, sum, k, n, x;

	ll  g;

	for (i = 1; i <= 6; ++i){
		dp[1][i] = 1;} /// for first dice , there is possible all value which can be happened 1 time ,base case

	for (i = 1; i < 25; ++i){
            /// minimum sum of i dices is i ,assuming all dice will face 1
            /// maximum sum of i dices is 6*i ,assuming all dice will face 6
            /// we will iterate through this range
		for (sum = i; sum <= 6 * i; ++sum)
		{
		    /// new sum can be achieved by adding k .
			for (k = 1; k <= 6; ++k)
            {
				dp[i + 1][sum + k] += dp[i][sum];
			}
		}
	}

    poss_events[0]=1;
	for (i = 1; i <=25; ++i) {poss_events[i]=6*poss_events[i-1];}
	ll nmber_of_sum_greater_than_x=0ll;

	while (scanf("%d%d", &n, &x), n)
	{
		if (x > 6 * n)
		{
			printf("0\n");
			continue;
		}
		else if (x <= n)
		{
			printf("1\n");
			continue;
		}
		nmber_of_sum_greater_than_x = 0;/// possible events that hold number of sum which is equal or greater than x
		for (i = x; i <= 6 * n; ++i) nmber_of_sum_greater_than_x += dp[n][i];
		g = __gcd(nmber_of_sum_greater_than_x, poss_events[n]);
		printf("%llu/%llu\n", nmber_of_sum_greater_than_x / g, poss_events[n] / g);
	}
	return 0;
}
