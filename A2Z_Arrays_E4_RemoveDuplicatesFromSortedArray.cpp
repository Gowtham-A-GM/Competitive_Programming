#include<bits/stdc++.h>
using namespace std;

void setupIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

class Solution1 {
    public:
        int removeDuplicates(vector<int>& nums) {
            // brute force - TC: O(NlogN + N), SC: O(N)
            set<int> st;
            for(auto it: nums)
                st.insert(it);  // TC: O(NlogN)
    
            int idx = 0;
            for(auto it: st){
                nums[idx] = it;
                idx++;
            }
            return idx;
        }
};

class Solution2 {
    public:
        int removeDuplicates(vector<int>& nums) {
            // optimal approach - TC: O(N), SC: O(1)
            int i=0;
            for(int j=1; j<nums.size(); j++){
                if(nums[j] != nums[i]){
                    i++;
                    nums[i] = nums[j];
                }
            }
            return i+1;
        }
    };

int main() {
    setupIO();
    int n;
    cin >> n;
    vector<int> nums;
    int val;
    for(int i=0; i<n; i++) {
        cin >> val;
        nums.push_back(val);
    }

    // Solution1 bruteForce;
    // int bruteForceRes = bruteForce.removeDuplicates(nums);
    // cout << "No. of Unqiue Elements: " << bruteForceRes << endl;


    Solution2 optimalApproach;
    int optimalRes = optimalApproach.removeDuplicates(nums);
    cout << "No. of Unqiue Elements: " << optimalRes << endl;


    for(int num: nums){
        cout << num << " ";
    }
    
    return 0;
}