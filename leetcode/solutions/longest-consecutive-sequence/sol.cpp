// from 20 Jul 2020

class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int ans=0;
        unordered_map<int, int> map_num;
        for(auto n:nums)
        {
            if(map_num.find(n) == map_num.end())
            {
                int left_length= map_num.find(n-1) == map_num.end() ? 0 : map_num[n-1];
                int right_length= map_num.find(n+1) == map_num.end() ? 0 : map_num[n+1];

                int total_length= left_length+ right_length+ 1;

                ans= max(ans, total_length);

                if(map_num.find(n) == map_num.end())
                    map_num.insert(make_pair(n, total_length));
                else
                    map_num[n]= total_length;

                map_num[n- left_length]= total_length;
                map_num[n+ right_length]= total_length;
            }
        }
        return ans;
    }
};