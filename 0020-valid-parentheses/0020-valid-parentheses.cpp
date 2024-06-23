class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Declare a stack to store opening brackets
        for(int i = 0; i < s.length(); i++) {
            // If the character is an opening bracket, push it onto the stack
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            // If the character is a closing bracket
            else {
                // If the stack is empty, it means there's no matching opening bracket
                if(st.empty()) {
                    return false;
                }
                // Check if the top of the stack matches the current closing bracket
                if(s[i] == ')' && st.top() == '(') {
                    st.pop();
                } else if(s[i] == '}' && st.top() == '{') {
                    st.pop();
                } else if(s[i] == ']' && st.top() == '[') {
                    st.pop();
                } else {
                    // If it doesn't match, the string is invalid
                    return false;
                }
            }
        }
        // After processing all characters, the stack should be empty if the string is valid
        return st.empty();
    }
};