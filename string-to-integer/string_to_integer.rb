# @param {String} str
# @return {Integer}
def my_atoi(str)
  # Stupid for ruby to do so
  [ [ str.to_i, 2147483647 ].min, -2147483648 ].max
end
