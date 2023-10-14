int ME(stack<int> st){
    int ans=INT_MAX;
    while(!st.empty()){
        ans=min(ans,st.top());
        st.pop();
    }
    return ans;
}