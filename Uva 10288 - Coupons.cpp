/// This is an expectation problem ,easy one !

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll Lcm(ll a,ll b){
    return (a*b)/__gcd(a,b);
}

int main()
{

    ll n;
    while(cin >> n) {

        ///ans (expectation value) = n * ( 1 + 1/2 + 1/3 + ... + 1/(n-1) + 1/n )

        ll lcm = 1;
        for(ll i = 1;i <= n;i++)
        {
            lcm = Lcm(lcm,i);/// finding lcm of all denominators
        }

        ll numerator = 0ll;
        for(ll i = 1;i <= n;i++)
        {
            numerator += (lcm/i);
        }
        numerator = numerator * n;/// multiply with n

        ll gcd=__gcd(numerator,lcm);
        /// making numerator and denominator irreducible
        ll denominator=lcm/gcd;
        numerator=numerator/gcd;

        ll tmp = denominator;/// finding number of digits of denominator to place '-'
        int cont = 0;
        while(tmp / 10) {
            cont ++;
            tmp = tmp / 10;
        }

        tmp = numerator/denominator;
        ///   b
        /// a --   counting number of digits in a of a fraction
        ///   c
        int cont2 = 0;
        while(tmp / 10) {
            cont2 ++;
            tmp = tmp / 10;
        }

        if(numerator % denominator == 0)
            cout <<(numerator / denominator) << endl;
        else {
            for(int i = 0;i<= cont2;i++) cout << " ";/// these spaces are for digits in a , in fraction
            cout <<" " << (numerator % denominator)<< endl;/// this is now new numerator ,when fraction is like given above (a,b,c)

            cout << (numerator / denominator) << " ";/// this is the a of the function
            for(int i = 0;i<= cont;i++) cout << "-";/// this is the steps in the middle of numerator and denominator

            cout << endl;
            for(int i = 0;i<= cont2;i++) cout << " ";
            cout <<" "<< denominator << endl;/// finally denominator
        }
    }
    return 0;
}
