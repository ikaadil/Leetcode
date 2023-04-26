class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    unordered_map<int, bool>mp;
    int cnt = 1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(!pq.empty() and pq.top() < cnt) {
            int ans = pq.top();
            mp.erase(ans);
            pq.pop();
            return ans;
        } else {
            return cnt++;
        }
    }
    
    void addBack(int num) {
        if(num < cnt and mp.find(num) == mp.end()) {
            pq.push(num);
            mp[num] = true;
        }
    }
};


/*
popSmallest:  TC: O(1)
addBack: TC: O(logn)

SC: O(n)

*/

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */