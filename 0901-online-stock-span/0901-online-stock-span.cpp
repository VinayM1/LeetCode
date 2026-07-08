class StockSpanner {
public:

    stack<pair<int,int>> st;   // {price, index}
    int ind;

    StockSpanner() {
        ind = -1;
    }

    int next(int price) {

        ind++;

        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }

        int span;

        if(st.empty()) {
            span = ind + 1;
        }
        else {
            span = ind - st.top().second;
        }

        st.push({price, ind});

        return span;
    }
};

