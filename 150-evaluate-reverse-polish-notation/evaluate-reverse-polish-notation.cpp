class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        for(int i=0;i<n;i++)
        {
            if(tokens[i] == "+")
            {
                int y1 = s.top();
                s.pop();
                int y2 = s.top();
                s.pop();

                s.push(y1+y2);
            }

            else if(tokens[i] == "-")
            {
                int y1 = s.top();
                s.pop();
                int y2 = s.top();
                s.pop();

                s.push(y2-y1);
            }

            else if(tokens[i] == "*")
            {
                int y1 = s.top();
                s.pop();
                int y2 = s.top();
                s.pop();

                s.push(y1*y2);
            }

            else if(tokens[i] == "/")
            {
                int y1 = s.top();
                s.pop();
                int y2 = s.top();
                s.pop();

                s.push(y2/y1);
            }

            else{
                int x = stoi(tokens[i]);
                s.push(x);
            }
           // cout<<s.top()<<" ";
        }
        return s.top();
    }
};