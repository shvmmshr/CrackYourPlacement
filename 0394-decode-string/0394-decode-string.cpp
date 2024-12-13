class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string str = "";
        string count = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ']'){
                while(st.top() != '['){
                    str = st.top() + str;
                    st.pop();
                }
                st.pop();
                while(!st.empty() && isdigit(st.top())){
                    count = st.top() + count;
                    st.pop();
                }
                int c = stoi(count);
                while(c--){
                    for(char it : str){
                        st.push(it);
                    }
                }
                str = "";
                count = "";
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};