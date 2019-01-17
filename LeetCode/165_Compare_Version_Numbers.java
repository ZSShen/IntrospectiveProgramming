class Solution {
    public int compareVersion(String version1, String version2) {

        String[] nums_1 = version1.split("\\.");
        String[] nums_2 = version2.split("\\.");

        int max = Math.max(nums_1.length, nums_2.length);
        for (int i = 0 ; i < max ; ++i) {
            Integer int_1 = i < nums_1.length ? Integer.parseInt(nums_1[i]) : 0;
            Integer int_2 = i < nums_2.length ? Integer.parseInt(nums_2[i]) : 0;

            int order = int_1.compareTo(int_2);
            if (order != 0) {
                return order;
            }
        }

        return 0;
    }
}