#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> map;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];
      int hashResult = hash(num, target);
      if (map.find(hashResult) != map.end()) {
        result.push_back(map[hashResult]);
        result.push_back(i);
        return result;
      } else {
        map[num] = i;
      }
    }

    return vector<int>(2, 0);
  }

  int hash(int num, int target) {
    return target - num;
  }
};

void printResult(const vector<int> &result)
{
  cout << "[";
  for (size_t i = 0; i < result.size(); ++i)
  {
    cout << result[i];
    if (i != result.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

int main() {
  Solution solution;

  vector<int> nums1 = {2, 7, 11, 15};
  int target1 = 9;
  cout << "Example 1: ";
  printResult(solution.twoSum(nums1, target1)); // Expected: [0, 1]

  vector<int> nums2 = {3, 2, 4};
  int target2 = 6;
  cout << "Example 2: ";
  printResult(solution.twoSum(nums2, target2)); // Expected: [1, 2]

  vector<int> nums3 = {3, 3};
  int target3 = 6;
  cout << "Example 3: ";
  printResult(solution.twoSum(nums3, target3)); // Expected: [0, 1]

  return 0;
}
