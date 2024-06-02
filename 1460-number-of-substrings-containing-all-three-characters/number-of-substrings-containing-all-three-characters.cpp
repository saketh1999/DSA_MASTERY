class Solution {
public:
    int numberOfSubstrings(string s) {
        int indx_a=-1,indx_b=-1,indx_c=-1;
        int count =0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a')
            indx_a = i;
            if(s[i]=='b')
            indx_b = i;
            if(s[i]=='c')
            indx_c = i;
            
            if(indx_a!=-1 && indx_b!=-1 && indx_c!=-1)
            {
                count = (1+min(min(indx_a,indx_b),indx_c)) + count;

            }
            

            
        }
        return count;

    }
};