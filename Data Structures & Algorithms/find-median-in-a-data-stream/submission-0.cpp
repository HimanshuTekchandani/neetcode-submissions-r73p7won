class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || (!maxHeap.empty() && maxHeap.top()>num)){
            maxHeap.push(num);
            if(maxHeap.size()-minHeap.size()>1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        else{
           minHeap.push(num);
            if(minHeap.size()-maxHeap.size()>1){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if((maxHeap.size()+minHeap.size()) %2 ==1){
            if(minHeap.size()>maxHeap.size())return (double)minHeap.top();
            else{
                return (double)maxHeap.top();
            }
        }
        return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;

    }
};
