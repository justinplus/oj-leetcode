# @param {Integer} n
# @return {Boolean}
def is_happy(n)
  arr = Array.new()
  sum = 0
  while true do
    n.to_s.each_char { |d| sum += d.to_i**2 }
    if sum == 1 
      return true
    elsif arr.include? sum
      return false
    else
      n = sum
      arr << sum
      sum = 0
    end
  end
end
