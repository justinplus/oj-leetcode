class LRUCache
  # Initialize your data structure here
  # @param {Integer} capacity
  def initialize(capacity)
    @capacity = capacity
    @prior = []
    @elems = {}
  end

  # @param {Integer} key
  # @return {Integer}
  def get(key)
    val = @elems[key]
    if val
      @prior.unshift @prior.delete(key)
      val
    else
      -1
    end
  end

  # @param {Integer} key
  # @param {Integer} value
  # @return {Void}
  def set(key, value)
    if @elems[key]
      @prior.delete(key)
    else
      if @elems.size >= @capacity
        @elems.delete @prior.pop
      end
    end
    @prior.unshift key
    @elems[key] = value
    nil
  end

  def inspect
    puts <<-inspect
====
prior: #{@prior}
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
