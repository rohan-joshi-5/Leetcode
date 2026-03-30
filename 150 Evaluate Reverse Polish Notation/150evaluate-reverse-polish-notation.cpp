class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it:tokens){
            if(it=="+"||it=="-"||it=="*"||it=="/"){
                int var2=st.top(); st.pop();
                int var1=st.top(); st.pop();
                if(it=="+") st.push(var2+var1);
                else if(it=="*") st.push(var2*var1);
                else if(it == "/") st.push(var1/var2);
                else st.push(var1-var2);
            }else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};