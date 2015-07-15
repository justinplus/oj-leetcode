# @param {Integer[]} nums
# @return {String[]}
def summary_ranges(nums)
  return nil if nums.nil?
  return [] if nums.empty?
  ret = Array.new
  pre = nums.first
  for i in Range.new(1, nums.length-1)
    if ( nums[i] - nums[i-1] ).abs > 1
      if nums[i-1] == pre
        ret << pre.to_s
      else
        ret << "#{pre}->#{nums[i-1]}"
      end
      pre = nums[i]
    end
  end
  ret << ( pre == nums.last ? pre.to_s : "#{pre}->#{nums.last}" )
end

