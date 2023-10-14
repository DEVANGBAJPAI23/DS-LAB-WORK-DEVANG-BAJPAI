//NSE ,NGE
vector<int> nge(vector<int> &arr){
     int n=arr.size();
    vector<int> output(n,-1);
    stack<int> st;
    indexes
    st.push(0);
    for (int i = 0; i < n; i++)
    {
    while(!st.empty()&& arr[i]>arr[st.top()])
    {
    output[st.top()]=arr[i];
    st.pop();
    }
    st.push(); 
    }
        //for safety check
    while(not st.top()){
    output[st.top()]=-1;
    st.pop();
    }
    return output; 
}
//next smaller element
vector<int> nse(vector<int> &arr){
    int n=arr.size();
    vector<int> output(n,-1);
    stack<int> st;
    indexes
    st.push(0);
    for (int i = 0; i < n; i++)
    {
    while(!st.empty()&& arr[i]<arr[st.top()])
    {
    output[st.top()]=arr[i];
    st.pop();
    }
    st.push(); 
    }
        //for safety check
    while(not st.top()){
    output[st.top()]=-1;
    st.pop();
    }
    return output; 
}