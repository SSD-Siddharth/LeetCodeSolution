// 2022.06.12
// dfs, backtrack
class Solution {
public:
    int res = 0x3f3f3f3f;
    int child[10];
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        dfs(0, n, cookies, k);
        return res;
    }
    void dfs(int x, int n, vector<int>& cookies, int k) {
        if(x == n) {
            int maxVal = 0;
            for(int i = 0; i < k; i++) {
                maxVal = max(maxVal, child[i]);
            }
            res = min(res, maxVal);
        }
        else {
            for(int i = 0; i < k; i++) {
                child[i] += cookies[x];
                dfs(x + 1, n, cookies, k);
                child[i] -= cookies[x];
            }
        }
    }
};

// dp
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> tot(1 << n, 0);
        for(int i = 1; i < (1 << n); i++) {
            for(int j = 0; j < n; j++) {
                if((i & (1 << j)) == 0) {
                    continue;
                }
                int left = i - (1 << j);
                tot[i] = tot[left] + cookies[j];
                break;
            }
        }
        vector<vector<int>> dp(k, vector<int>(1 << n, -1));
        for(int i = 0; i < (1 << n); i++) {
            dp[0][i] = tot[i];
        }
        for(int i = 1; i < k; i++) {
            for(int j = 0; j < (1 << n); j++) {
                int minVal = 0x3f3f3f3f;
                for(int s = j; s; s = (s - 1) & j) {
                    int left = j - s;
                    int val = max(dp[i - 1][left], tot[s]);
                    minVal = min(minVal, val);
                }
                dp[i][j] = minVal;
            }
        }
        return dp[k - 1][(1 << n) - 1];
    }
};