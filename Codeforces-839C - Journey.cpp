
/// It is a normal problem like what is the expected value of a cubic dice ?
/// so , what is the approach ?
/// (1/6)*(1) + (1/6)*(2) + (1/6)*3 + (1/6)*(4) + (1/6)*(5) + (1/6)*(6)
/// So , normal formula -> summatory function of  p(i)*x(i) ,where x(i) is for every outcomes and p(i) is their probability
/// This question says that horse will reach a leaf node .
/// But there are many leaf nodes likelihood many faces of cubic dice
/// So ,first we will calculate the probability of each leaf node
/// x(i) for each leaf node  will be their dist[i] ( length of that path)
/// Answer will prob[i]*dist[i] for every leaf node .


#include<bits/stdc++.h>

using namespace std;

const int MAXN=100000;
int dist[MAXN+5];
long double prob[MAXN+5];
vector<int> graph[MAXN+5];

void bfs()
{
    memset(dist,-1,sizeof(dist));
    queue<int>q;
    q.push(1);/// horse starts from node (1)
    dist[1]=0;/// distance of root node is 0
    prob[1]=1.0;/// it is must for being on root node ,so probability is 1
    while(!q.empty())
    {
        int parent=q.front();
        q.pop();
        int nmber_of_possible_move=graph[parent].size();
        nmber_of_possible_move--;///the parent of q which is not be visible being again visited,so decrease one node from count
        if(parent==1) nmber_of_possible_move++;/// in case of 1 , no need to decrease .so increase again
        for(int i=0;i<graph[parent].size();i++)
        {
            int child=graph[parent][i];
            if(dist[child]!=-1) continue;
///(1/nmber_of_possible_move) is the probability of going to child
            prob[child]=prob[parent]*(1.00/(long double)(nmber_of_possible_move));
            dist[child]=dist[parent]+1;
            q.push(child);
        }
    }
}

int main()
{
  int n,u,v;
  cin>>n;
  for(int i=1;i<=n-1;i++)
  {
      cin>>u>>v;
      graph[u].push_back(v);
      graph[v].push_back(u);
  }
  bfs();
  /// expected length
  long double expected_length=0.0;
  for(int i=2;i<=n;i++)
  {
      if(graph[i].size()==1)/// leaf node
      {
          expected_length+=((long double)(dist[i])*prob[i]);
          /// e(x) = summatory of p(i)*x(i) ,formula
      }
  }
  cout<<setprecision(6)<<fixed<<expected_length<<endl;
  return 0;
}
