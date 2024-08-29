class Solution {
private:
    bool wordSearch(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string word){
        // cout << i << " " << j << " " << " " << word.size() << " " << word << endl;
        if(word.empty()) return true;

        
        if(i < 0 || i >= board.size()) return false;
        if(j < 0 || j >= board[0].size()) return false;
        if(visited[i][j]) return false;
        
        if(word[0] != board[i][j]) return false;
        
        word = word.substr(1);
        visited[i][j] = true;
        bool res = (
            wordSearch(board, visited, i+1, j, word) ||
            wordSearch(board, visited, i-1, j, word) ||
            wordSearch(board, visited, i, j-1, word) ||
            wordSearch(board, visited, i, j+1, word)
        );
        visited[i][j] = false;
        return res;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> starting_idx;
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    starting_idx.push_back(make_pair(i, j));
                }
            }
        }
        if(starting_idx.empty()) return false;
        
        for(pair<int, int> p : starting_idx){
            vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
            bool res = wordSearch(board, visited, p.first, p.second, word);
            if(res) return true;
        }
        
        return false;
    }
};