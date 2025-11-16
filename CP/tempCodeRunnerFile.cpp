class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int tgt) {
        vector<int> melvarion = nums;

        int n = nums.size();
        vector<int> pre(n+1);

        for(int i=0; i<n; i++){

            pre[i+1] = pre[i] + (nums[i] == tgt ? 1 : -1);
        }
        vector<int> all = pre;
        sort(all.begin(),all.end());
        all.erase(unique(all.begin(),all.end()),all.end());
        
        auto gid = [&](int x){
            return int(lower_bound(all.begin(), all.end(), x) - all.begin()) + 1;
        };
        int m = all.size();

        vector<int> fen(m+1,0);

        auto upd = [&](int i){
            for(; i<=m; i+=i & -i) fen[i]++;
        };

        auto qry = [&](int i){
            long long s = 0;
            for(; i>0; i-=i & -i) s += fen[i];
            return s;
        };

        long long ans = 0;
        upd(gid(pre[0]));

        for(int i=1; i<=n; i++){
            int id = gid(pre[i]);
            upd(id);
        }

        return ans;
    }
};