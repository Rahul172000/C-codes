#include<iostream>
using namespace std;
int knapsack(int*,int*,int,int);
int main()
{
  int n;
  cout<<"\nEnter the size ";
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];
  cout<<"\nEnter the weights\n";
  for(int i = 0; i < n; i++)
  {cin >> weights[i];}
  cout<<"\nEnter the values\n";
  for(int i = 0; i < n; i++)
  {cin >> values[i];}
  int maxWeight;
  cout<<"\nEnter the max weight ";
  cin >> maxWeight;
  cout << knapsack(weights, values, n, maxWeight);
}
int knapsack(int* weights, int* values, int n, int maxWeight){
    int dp[n+1][maxWeight+1];
    for(int i=0;i<=n;i++)
    {dp[i][0]=0;}
    for(int i=0;i<=maxWeight;i++)
    {dp[0][i]=0;}
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=maxWeight;j++)
        {
            if(weights[i-1]>j)
            {dp[i][j]=dp[i-1][j];}
            else
            {dp[i][j]=max(dp[i-1][j],values[i-1]+dp[i-1][j-weights[i-1]]);}
        }
    }
    return dp[n][maxWeight];
}



