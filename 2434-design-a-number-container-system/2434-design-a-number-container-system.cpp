class NumberContainers {
    map<int, int> idxToNum;
    map<int, set<int>> numToIdxs;

public:
    NumberContainers() {}
    
    void change(int idx, int num) {
        if (idxToNum.count(idx)) {
            int oldNum = idxToNum[idx];
            numToIdxs[oldNum].erase(idx);
            if (numToIdxs[oldNum].empty()) numToIdxs.erase(oldNum);
        }
        idxToNum[idx] = num;
        numToIdxs[num].insert(idx);
    }
    
    int find(int num) {
        if (numToIdxs.count(num)) return *numToIdxs[num].begin();
        return -1;
    }
};