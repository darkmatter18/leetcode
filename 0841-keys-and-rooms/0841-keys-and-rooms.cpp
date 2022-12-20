class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int no_of_rooms = rooms.size();
        vector<bool> got_key(no_of_rooms, false);
        vector<bool> visited(no_of_rooms, false);
        
        visit(rooms, got_key, visited, 0);
        
        bool ans = true;
        
        // print_arr(got_key);
        for(bool b: got_key){
            if(!b){
                ans = false;
                break;
            }
        }
        return ans;
    }
    
    void visit(vector<vector<int>>& rooms, vector<bool>& got_key, vector<bool>& visited, int i){
        if(visited[i]) return;  // already visited
        
        // cout << "visiting " << i << endl;
        
        visited[i] = true;
        got_key[i] = true;
        // print_arr(got_key);
        
        for(int key: rooms[i]){
            visit(rooms, got_key, visited, key);
        }
        
    }
    
    void print_arr(vector<bool> arr){
        for(bool b : arr){
            cout << b << " ";
        }
        cout << endl;
    }
};