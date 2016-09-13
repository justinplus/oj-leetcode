public class Solution {
  public int removeDuplicates(int[] nums) {
    int i = 0, j = 1;

    for(; j < nums.length; ++j) {
      if( nums[i] != nums[j] ) nums[++i] = nums[j];
    }

    return nums.length == 0 ? 0 : i + 1;
  }
}
