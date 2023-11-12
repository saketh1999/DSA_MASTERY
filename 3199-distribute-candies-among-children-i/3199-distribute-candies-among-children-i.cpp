class Solution {
private:
int solver(int n,int limit,int children,vector<vector<vector<int>>> &c)
{
    if(n==0)
    return 1;

    if(limit==0 || children==0)
    return 0;

    if(c[n][limit][children]!=-1)
    return c[n][limit][children];

    int ways=0;

    for(int i=0;i<=min(limit,n);i++)
    ways+=solver(n-i,limit,children-1,c);
    
    return c[n][limit][children]=ways;

}
public:
    int distributeCandies(int n, int limit) {
         vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(limit + 1, vector<int>(4, -1)));

        return solver(n,limit,3,memo);    
    }
};