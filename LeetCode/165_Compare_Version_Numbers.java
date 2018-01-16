class Solution {
    public int compareVersion(String version1, String version2) {

        String[] split1 = version1.split("\\.");
        List<Integer> nums1 = new ArrayList<Integer>();
        for (String str : split1) {
            nums1.add(Integer.valueOf(str));
        }

        String[] split2 = version2.split("\\.");
        List<Integer> nums2 = new ArrayList<Integer>();
        for (String str : split2) {
            nums2.add(Integer.valueOf(str));
        }

        int len1 = nums1.size();
        int len2 = nums2.size();
        int common = (len1 > len2)? len2 : len1;

        for (int i = 0 ; i < common ; ++i) {
            if (nums1.get(i) > nums2.get(i)) {
                return 1;
            } else if (nums1.get(i) < nums2.get(i)) {
                return -1;
            }
        }

        if (len1 > len2) {
            for (int i = len2 ; i < len1 ; ++i) {
                if (nums1.get(i) != 0 ) {
                    return 1;
                }
            }
        }
        if (len2 > len1) {
            for (int i = len1 ; i < len2 ; ++i) {
                if (nums2.get(i) != 0) {
                    return -1;
                }
            }
        }

        return 0;
    }
}