class Solution {
public:
    bool halvesAreAlike(string s) {
        int count = 0;
        int l=s.length();
        for(int i=0;i<l/2;i++)
        {
            char y = toupper(s[i]);
            if(y == 'A' || y == 'E' || y == 'I' || y =='O' || y=='U')
            count++;
        }
                for(int i=l/2;i<l;i++)
        {
            char y = toupper(s[i]);
            if(y == 'A' || y == 'E' || y == 'I' || y =='O' || y=='U')
            count--;
        }
        cout<<count;
        if(count==0)
        return true;
        return false;
    }
};