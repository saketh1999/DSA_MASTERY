class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0,twenty=0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                five++;
            }
           else if(bills[i]==10)
            {
                if(five)
                five--;
                else
                {
//cout<<"here2";
                    return false;
                }
                ten++;
            }

           else 
           {
            if(ten && five)
            {
                ten--;
                five--;
            }
            else if(five>=3)
            {
                five = five-3;
            }
            else{
             
                return false;
            }
          
            twenty++;

           }
           
        }
        return true;
    }
};