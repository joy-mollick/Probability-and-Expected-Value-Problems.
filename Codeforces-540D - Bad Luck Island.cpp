

#include<bits/stdc++.h>

using namespace std;

const int mx=101;

double prob[mx][mx][mx];
///dp[i][j][k] states the probability of being alive of i rock and j scissors and k paper

int main()

{
  int r,s,p;/// r rocks, s scissors and p papers
  cin>>r>>s>>p;
  /// rock kills scissors, scissors kill paper, and paper kills a rock
  prob[r][s][p]=1.0;/// at the starting ,this state remains ,so probability of this state is 1.0
  for(int i=r;i>=0;i--)
  {
      for(int j=s;j>=0;j--)
      {
          for(int k=p;k>=0;k--)
          {
              int pairs_of_rock_scissors=i*j;///i->r and j->s
              int pairs_of_paper_scissors=k*j;/// k->p and j->s
              int pairs_of_rock_paper=i*k;/// i->r and k->p
              int all_pairs =pairs_of_rock_scissors+pairs_of_paper_scissors+pairs_of_rock_paper;
              if(all_pairs==0) continue;
/// rock species available,so in how many ways we can choose ?(paper and rock) probability= pairs_of_rock_paper /all_pairs.
              if(i>0)
              {
/// Rock and paper meet - paper kills rock ,rock will be decreased.
                prob[i-1][j][k]+=((double)pairs_of_rock_paper /(double)all_pairs)*(prob[i][j][k]);
              }
/// rock species available,so in how many ways we can choose ?(scissors and rock) probability= pairs_of_rock_scissors /all_pairs.
              if(j>0)
              {
/// Rock and scissors meet - rock kills scissors ,scissors will be decreased.
                prob[i][j-1][k]+=((double)pairs_of_rock_scissors/(double)all_pairs)*(prob[i][j][k]);
              }
/// paper species available,so how many ways we can choose ?(pairs_of_rock_paper) probability=pairs_of_rock_paper/all_pairs.
              if(k>0)
              {
/// Paper and scissors meet - scissors kill paper ,paper will be decreased.
                prob[i][j][k-1]+=((double)pairs_of_paper_scissors/(double)all_pairs)*(prob[i][j][k]);
              }
          }
      }
  }
  double scissors_probability=0.0;
  double paper_probability=0.0;
  double rock_probability=0.0;

  for(int l=1;l<=r;l++) rock_probability+=prob[l][0][0];///only rock alive others are zero in amount
  for(int l=1;l<=s;l++) scissors_probability+=prob[0][l][0];///only scissors alive others are zero in amount
  for(int l=1;l<=p;l++) paper_probability+=prob[0][0][l];///only paper alive others are zero in amount
  printf("%.9lf %.9lf %.9lf\n",rock_probability,scissors_probability,paper_probability);
  return 0;
}
