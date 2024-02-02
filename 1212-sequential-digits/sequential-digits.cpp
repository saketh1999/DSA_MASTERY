class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> s; 
       
        for(int i=1;i<=9;i++)
        {
             int num=i;
            int next_digit= i+1;

            while(num<=high && next_digit <= 9)
            {
               
                num= num*10+next_digit;

                if(num>=low && num<=high)
                {
                     s.push_back(num);
                }
                next_digit++;
            }
            
        }
        sort(s.begin(),s.end());
        return s;
    }
};