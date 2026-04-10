class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int>pq;

       for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
       } 
       int x;
       int y;
       while(pq.size()>1){
            x=pq.top();
            pq.pop();
            y=pq.top();
            pq.pop();
            if(x!=y){
                pq.push(abs(x-y));
            }
       }
    //    cout<<x <<" "<<y<<" "<<abs(x-y)<<endl;
       if(pq.empty()){
            return 0;
       }
       return pq.top();
    }
};
