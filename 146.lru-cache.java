/*
 * @lc app=leetcode id=146 lang=java
 *
 * [146] LRU Cache
 */

import java.util.LinkedHashMap;
// @lc code=start
// TODO: don't use LinkedHashMap
class LRUCache extends LinkedHashMap<Integer, Integer> {
    private final int capacity;

    public LRUCache(int capacity) {
        super(capacity, 0.75f, true);
        this.capacity = capacity;
    }

    @Override
    protected boolean removeEldestEntry(java.util.Map.Entry<Integer, Integer> eldest) {
        return size() > capacity;
    }

    public int get(int key) {
        final Integer result = super.get(key);
        return result == null ? -1 : result;
    }

    public void put(int key, int value) {
        super.put(key, value);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
// @lc code=end

