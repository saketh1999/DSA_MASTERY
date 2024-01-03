class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev_ones=0,curr_ones=0;
        int ans=0;
        for(int i=0;i<bank.size();i++)
        {
            for(int j=0;j<bank[i].size();j++)
            {
                
                if(bank[i][j]=='1')
                {
                    curr_ones+=1;
                }
                
            }
            int curr_ans = prev_ones*curr_ones;
          
            ans+=curr_ans;
            if(curr_ones>0)
            {
                prev_ones=curr_ones;
            }
            curr_ones=0;
        }
        return ans;
    }
};