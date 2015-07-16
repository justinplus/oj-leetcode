# @param {Integer[]} nums
# @param {Integer} k
# @return {Boolean}
def contains_nearby_duplicate(nums, k)
  return false if k <= 0
  return true if nums[0, k].uniq!
  for i in Range.new(k, nums.length-1)
    for j in Range.new(1, k)
      return true if nums[i] == nums[i-j]
    end
  end
  false   
end

## Wrong Apprehension of the ary[,]
# ary[index] -> obj or nil
# ary[start, lentgh] -> new_ary or nil
# ary[range] -> new_ary or nil
# ary.slice alias ary[] (all three ways)
