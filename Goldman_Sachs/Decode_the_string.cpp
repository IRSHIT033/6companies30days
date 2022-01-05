class Solution {
public:
    string decodeString(string s) {
               stack<int> count;
        stack<string> res;
        string r = "";
        int num = 0, i = 0;
        while (s[i] != '\0')
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] >= 'a' and s[i] <= 'z')
            {
                r += s[i];
            }
            else if (s[i] == '[')
            {
                res.push(r);
                count.push(num);
                num = 0;
                r = "";
            }
            else
            {
                string temp = r;
                r = res.top();
                res.pop();
                int freq = count.top();
                count.pop();
                while (freq--)
                {
                    r += temp;
                }
                num = 0;
            }

            i++;
        }
        return r; 
    }
};
