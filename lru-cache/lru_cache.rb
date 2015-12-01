class LRUCache
  # Initialize your data structure here
  # @param {Integer} capacity
  def initialize(capacity)
    @capacity = capacity
    @elems = {}
  end

  # @param {Integer} key
  # @return {Integer}
  def get(key)
    val = @elems.delete key
    if val
      @elems[key] = val
    else
      -1
    end
  end

  # @param {Integer} key
  # @param {Integer} value
  # @return {Void}
  def set(key, value)
    @elems.delete key
    @elems[key] = value
    @elems.delete @elems.first.first if @elems.size > @capacity 
  end

  def inspect
    puts <<-inspect
====
elems: #{@elems}
====
inspect
  end

end

lru = LRUCache.new(1)
puts lru.set(2, 1); lru.inspect
puts lru.get(2); lru.inspect
lru.set(3, 2); lru.inspect
puts lru.get(2), lru.get(3)

lru = LRUCache.new(4)
lru.set(3, 4); lru.inspect
lru.set(4, 5); lru.inspect
puts "get 3: #{lru.get(3)}"; lru.inspect
lru.set(1, 100); lru.inspect
lru.set(2, 9); lru.inspect
puts "get 1: #{lru.get(1)}"; lru.inspect
lru.set(2, 50); lru.inspect
puts "get 2: #{lru.get(2)}"; lru.inspect
lru.set(7, 777); lru.inspect
puts "get 9: #{lru.get(9)}"; lru.inspect
