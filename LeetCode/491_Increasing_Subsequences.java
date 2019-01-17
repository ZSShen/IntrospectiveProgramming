class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {

        Set<List<Integer>> ans = new HashSet<List<Integer>>();

        int bound = nums.length;
        if (bound == 0) {
            return new ArrayList<List<Integer>>(ans);
        }

        for (int i = 0 ; i < bound ; ++i) {
            List<Integer> seq = new ArrayList<Integer>();
            seq.add(nums[i]);
            traverse(nums, ans, seq, i + 1, bound);
        }

        return new ArrayList<List<Integer>>(ans);
    }

    private void traverse(int[] nums,
                          Set<List<Integer>> ans,
                          List<Integer> seq,
                          int idx,
                          int bound) {

        if (seq.size() >= 2) {
            ans.add(new ArrayList<Integer>(seq));
        }

        for (int i = idx ; i < bound ; ++i) {
            if (nums[i] < seq.get(seq.size() - 1)) {
                continue;
            }

            seq.add(nums[i]);
            traverse(nums, ans, seq, i + 1, bound);
            seq.remove(seq.size() - 1);
        }
    }
}