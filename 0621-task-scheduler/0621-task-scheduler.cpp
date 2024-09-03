class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> taskCount(26, 0);
        priority_queue<int> task_queue;
        queue<pair<int, int>> q;
        
        // Create the count per task vector
        for(char task : tasks){
            taskCount[task-'A']++;
        }
        
        // push the task count on the max heap
        for(int t : taskCount){
            if(t != 0){
                task_queue.push(t);    
            }
        }
        
        int time = 0;
        while(!task_queue.empty() || !q.empty()){
            // cout << time << " ";
            if(!task_queue.empty()){
                // Get the task with most amount of tasks remaining
                int curr_task = task_queue.top();
                // cout << "Task Done: " << curr_task;
                task_queue.pop();
                curr_task--;

                // Puch the remaining task on the 
                if(curr_task > 0){
                    // cout << " Push " << (curr_task, time+n);
                    q.push(make_pair(curr_task, time+n));
                }   
            }
            // else {
            //     cout << " IDLE ";
            // }
            
            while(!q.empty()){
                // Get the current remaining task
                pair<int, int> p = q.front();
                // Check if the task cool down or not
                if(p.second == time){
                    task_queue.push(p.first);
                    q.pop();
                    // cout << " POP "  << " " << p.first << " " << p.second ;
                }
                else {
                    break;
                }
                
            }
            // cout << endl;
            time++;
        }
        
        return time;
    }
};