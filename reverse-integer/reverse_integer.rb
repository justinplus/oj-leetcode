# @param {Integer} x
# @return {Integer}
def reverse(x)
  sign = 1
  if x < 0
    sign = -1
    x = -x
  end

  x = x.to_s.reverse.to_i
  sign * ( x > 2**31 - 1 ? 0 : x )

end
