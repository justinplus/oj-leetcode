# @param {Integer} n
# @param {Integer} k
# @return {Integer[][]}
def combine(n, k)
    Range.new(1, n).to_a.combination(k).to_a
end
