#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i=0; i<s.length();i++) {
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else
        {
            //ch ya toh ')' hai ya lowercase letter

            if(ch == ')') {
                bool isRedendant = true;

                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedendant = false;
                    }
                    st.pop();
                }
                if(isRedendant == true) {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
