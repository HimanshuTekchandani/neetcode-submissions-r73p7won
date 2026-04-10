class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int elemNumber ;
    KthLargest(int k, vector<int>& nums) {
        elemNumber=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k)pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>elemNumber)pq.pop();
        return pq.top();
    }
};
