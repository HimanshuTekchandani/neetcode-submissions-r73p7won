class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26,0);
    
        for(int i=0;i<tasks.size();i++){
            count[tasks[i]-'A']++;
        }
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        for(int i=0;i<count.size();i++){
            if(count[i]>0)pq.push(count[i]);
        }
        int time =0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(pq.empty()){
                time=q.front().second;
            }
            else{
                int it= pq.top();
                pq.pop();
                it--;
                if (it!=0){
                    q.push({it,time+n});
                }
                
            }

            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
