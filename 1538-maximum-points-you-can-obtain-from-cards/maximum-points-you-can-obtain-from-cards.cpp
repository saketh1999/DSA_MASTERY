class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum =0;
        if(k==cardPoints.size())
        {
            for(auto i:cardPoints)
            {
                sum+=i;

            }
            return sum;
        }


        int lsum=0,rsum=0;
      

        for(int i=0;i<k;i++)
        {
            lsum+=cardPoints[i];
        }
        sum = max(lsum+rsum,sum);
        
        int l = k-1;
        int r = cardPoints.size()-1;
       for( ; l>=0 ; l--,r--)
        {
            
            lsum = lsum - cardPoints[l];
            rsum = rsum + cardPoints[r];
            sum = max(lsum+rsum,sum);
        }
        return sum;
    }
};