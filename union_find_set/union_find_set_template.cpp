// 2022.06.04
class UnionFindSet {
public:
    UnionFindSet(int n) {
        ranks_ = vector<int>(n + 1, 0);
        parent_ = vector<int>(n + 1, 0);
        for(int i = 0; i < parent_.size(); i++) {
            parent_[i] = i;
        }
    }
    int Find(int u) {
        if(u != parent_[u]) {
            parent_[u] = Find(parent_[u]);
        }
        return parent_[u];
    }
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if(pu == pv) {
            return false;
        }
        if(ranks_[pu] < ranks_[pv]) {
            parent_[pu] = pv;
        }
        else if(ranks_[pu] > ranks_[pv]) {
            parent_[pv] = pu;
        }
        else {
            parent_[pv] = pu;
            ranks_[pu]++;
        }
        return true;
    }

private:
    vector<int> ranks_;
    vector<int> parent_;
};