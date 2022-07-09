/**
 * You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
 * You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.
 * Return the maximum number of events you can attend.
 * 
 * Input : [[1,4],[4,4],[2,2],[3,4],[1,1]]
 * Output : 4
 * 
 * https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
 * */

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        
        // Define a priority queue
        priority_queue<int, vector<int>, greater<int>>pq;
        
        // Priority Q -> coz we have to look for events with least ending times
        
        int i = 0; int result = 0;
        for(int day = 0; day <= 100000; day++){
            // Remove events whose end time is greater than day as we can't attend
            while(pq.size() && pq.top() < day){
                pq.pop();
            }
            
            // Event is on that day
            while(i < n && events[i][0] == day){
                pq.push(events[i][1]);
                i++;
            }
            if(pq.size()){
                cout<<pq.top()<<" ";
                pq.pop();
                result++;
            }
        }
        return result;
    }
};