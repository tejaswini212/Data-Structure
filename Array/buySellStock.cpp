#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int minEver=prices[0];
        int n = prices.size();
        int profit=0;
        for(int i=1;i<n;i++){
            int cur_prof=prices[i]-minEver;
            profit=max(cur_prof,profit);
            if(minEver>prices[i]) minEver=prices[i];
            //cout<<profit<<" ";
        }
        return profit;
    }
};
int main(){
    vector<int> prices={7,1,5,3,6,4};
    Solution s;
    cout<<s.maxProfit(prices)<<"\n";
    return 0;
}
