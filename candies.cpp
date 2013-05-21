#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,a;
    cin >> n;
    vector<int> input(n+1,0) ;
    vector<int> dp(n+1,0);
    vector<int> dp2(n+1,0);
    for(int i =1;i<=n;i++)
    {
        cin >> a;
        input[i]=a;
    }
    int mincandies = 0;
    for(int i =1;i<=n;i++)
    {
        if(input[i] > input[i-1])
        {
            dp[i] = dp[i-1]+1;
        }
        else
        dp[i]=1;
    }
    dp2[n]= 1;
    mincandies = max(dp2[n],dp[n]);
    for(int i =n-1;i>0;i--)
    {
        if(input[i] > input[i+1])
        dp2[i] = dp2[i+1]+1;
        else
        dp2[i] =1;
        mincandies+= max(dp2[i],dp[i]);
    }
    cout << mincandies << endl;
    return 0;
}
