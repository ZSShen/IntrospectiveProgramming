class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {

        List<List<Integer>> ans = new ArrayList<List<Integer>>();

        int bound = nums.length;
        if (bound == 0) {
            return ans;
        }

        Set<String> set = new HashSet<String>();

        for (int i = 0 ; i < bound ; ++i) {
            List<Integer> stk = new ArrayList<Integer>();
            stk.add(nums[i]);
            traverse(nums, ans, stk, set, i + 1, bound);
        }

        return ans;
    }

    private void traverse(int[] nums,
                          List<List<Integer>> ans,
                          List<Integer> stk,
                          Set<String> set,
                          int idx,
                          int bound) {

        if (idx == bound) {
            return;
        }

        for (int i = idx ; i < bound ; ++i) {
            if (nums[i] < stk.get(stk.size() - 1)) {
                continue;
            }

            stk.add(nums[i]);
            String key = generateHashKey(stk);
            if (set.contains(key)) {
                stk.remove(stk.size() - 1);
                continue;
            }

            set.add(key);
            ans.add(new ArrayList<>(stk));
            traverse(nums, ans, stk, set, i + 1, bound);
            stk.remove(stk.size() - 1);
        }
    }

    private String generateHashKey(List<Integer> stk) {

        StringBuilder buf = new StringBuilder();
        for (int num : stk) {
            buf.append(num);
            buf.append(' ');
        }
        return buf.toString();
    }
}