class Solution {
    public int findMinDifference(List<String> timePoints) {

        List<Integer> nums = new ArrayList<Integer>();
        for (String timePoint : timePoints) {
            String[] split = timePoint.split(":");
            int hour = Integer.valueOf(split[0]);
            int minute = Integer.valueOf(split[1]);
            int num = hour * 60 + minute;
            nums.add(num);
        }

        Collections.sort(nums);

        int ans = Integer.MAX_VALUE;
        for (int i = 1 ; i < nums.size() ; ++i) {
            int diff = Math.abs(nums.get(i - 1) - nums.get(i));
            if (diff < ans) {
                ans = diff;
            }
        }

        int diff = 1440 - nums.get(nums.size() - 1) + nums.get(0);
        if (diff < ans) {
            ans = diff;
        }

        return ans;
    }
}