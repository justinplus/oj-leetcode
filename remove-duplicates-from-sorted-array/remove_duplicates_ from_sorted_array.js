/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    var fore = 0,  post = 1;
    for(; post<nums.length; post++){
        if(nums[fore] != nums[post]){
            nums[++fore] = nums[post];
        }
    }
    
    return Math.min(fore+1, nums.length);
    
};