/*
 * @lc app=leetcode id=380 lang=java
 *
 * [380] Insert Delete GetRandom O(1)
 */
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Set;

// @lc code=start
class RandomizedSet {
    private final Random random;
    private final List<Integer> list;
    private final Map<Integer, Integer> indexMap;

    public RandomizedSet() {
        random = new Random();
        list = new ArrayList<>();
        indexMap = new HashMap<>();
    }
    
    public boolean insert(int val) {
        if (indexMap.containsKey(val)) {
            return false;
        }

        indexMap.put(val, list.size());
        list.add(val);
        return true;
    }
    
    public boolean remove(int val) {
        final Integer index = indexMap.get(val);

        if (index == null) {
            return false;
        }

        final int lastIndex = list.size() - 1;
        final int lastVal = list.get(lastIndex);
        list.set(index, lastVal);
        list.remove(lastIndex);
        indexMap.put(lastVal, index);
        indexMap.remove(val);
        return true;
    }
    
    public int getRandom() {
        return list.get(random.nextInt(list.size()));
    }
}

// NOTE: performance is bad
//  267 ms Beats 5.01%
//  99.89 MB Beats 5.07%
class RandomizedSet0 {
    private static final int SIZE = 256;

    private final Random random = new Random();
    private final List<Set<Integer>> sets; 
    private int count;

    public RandomizedSet0() {
        this.sets = new ArrayList<>(SIZE);
        for (int i = 0; i < SIZE; ++i) {
            sets.add(null);
        }
        this.count = 0;
    }
    
    public boolean insert(int val) {
        final int i = getIndex(val);
        final boolean flag = getOrCreate(i).add(val);
        if (flag == true) {
            ++count;
        }

        return flag;
    }
    
    public boolean remove(int val) {
        final int i = getIndex(val);
        final boolean flag = getOrCreate(i).remove(val);
        if (flag == true) {
            --count;
        }
        return flag;
    }
    
    public int getRandom() {
        Set<Integer> set = getTargetSet();
        int r = random.nextInt(set.size());
        return set.stream().skip(r).findFirst().get();
    }

    private static final int getIndex(int val) {
        final int divider = SIZE >> 1;
        final int remainer = Integer.hashCode(val) % divider;

        if (remainer == 0 && val < 0) {
            return 0;
        }

        return remainer + divider;
    }

    private final Set<Integer> getTargetSet() {
        int r = random.nextInt(count);
        int sum = 0;
        for (Set<Integer> set : sets) {
            sum += set == null ? 0 : set.size();
            if (sum > r) {
                return set;
            }
        }

        return null;
    }

    private final Set<Integer> getOrCreate(int index) {
        final Set<Integer> set = sets.get(index);
        if (set == null) {
            final Set<Integer> s = new HashSet<>();
            sets.set(index, s);
            return s;
        } 

        return set;
    }
}
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
// @lc code=end

