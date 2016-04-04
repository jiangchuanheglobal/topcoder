#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
 public:
  int minPairs(vector<int>& nums, int k) {
    if (nums.size() < k * 2) return -1;
    
    std::sort(nums.begin(), nums.end());
    vector<int> delta = diff(nums);
    int n = delta.size();

    vector<vector<int> > f(n + 1, vector<int>(n + 1, INT_MAX));
    
    f[1][1] = delta[0];
    for (int i = 0; i <= n; i++) {
      f[i][0] = 0;
    }
    
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        f[i][j] = min(f[i-1][j] , max(f[i-2][j-1], delta[i-1]));
      }
    }
    return f[n][k];
  }

  vector<int> diff(vector<int>& nums) {
    vector<int> ans;
    for (int i = 1; i < nums.size(); i++) {
      ans.push_back(nums[i] - nums[i - 1]);
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {0, 1, 1, 2, 3, 5, 8, 11};
  //vector<int> nums = {1, 2, 2, 3};
  Solution sol;
  cout << sol.minPairs(nums, 4) << endl;
  return 0;
}
