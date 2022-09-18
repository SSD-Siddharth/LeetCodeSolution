// 2022.09.17
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int res = 0;
        int n = players.size();
        int m = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0;
        int j = 0;
        while(i < n && j < m) {
            if(players[i] <= trainers[j]) {
                i++;
                j++;
                res++;
            }
            else {
                j++;
            }
        }
        return res;
    }
};