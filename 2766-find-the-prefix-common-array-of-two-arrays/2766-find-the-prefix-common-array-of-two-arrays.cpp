class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        unordered_set<int> a,b;
        int count=0;
        vector<int>v;

        for(int i=0;i<A.size();i++)
        {
            if(b.count(A[i]))
            {
                count++;
            }

            a.insert(A[i]);

            if(a.count(B[i])){
                count++;
            }
            b.insert(B[i]);

            v.push_back(count);
        }

        return v;
    }
};