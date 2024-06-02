class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int N= fruits.size();
        int l=0,r=0,k=2;
        int max_len=0,len=0;
        unordered_map<int,int> mp;
        while(r<N)
        {
            mp[fruits[r]]++;
            
            if(mp.size()>k)
            {
                mp[fruits[l]]--;
                
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
               
            }
              if(mp.size()<=k)
            {
                len = r-l+1;
                
                max_len = max(max_len,len);
                
            }
            r++;
             
        }
        return max_len;
    }
};