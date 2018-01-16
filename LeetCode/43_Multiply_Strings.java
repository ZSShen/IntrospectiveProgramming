class Solution {
    public String multiply(String num1, String num2) {

        char[] array1 = num1.toCharArray();
        char[] array2 = num2.toCharArray();

        int size1 = array1.length;
        for (int i = 0 ; i < size1 ; ++i) {
            array1[i] -= '0';
        }

        int size2 = array2.length;
        for (int i = 0 ; i < size2 ; ++i) {
            array2[i] -= '0';
        }

        int sum = size1 + size2 + 1;
        char[] mul = new char[sum];
        for (int i = 0 ; i < sum ; ++i) {
            mul[i] = 0;
        }

        for (int i = size1 - 1, pivot = sum - 1 ; i >= 0  ; --i, --pivot) {
            int k = pivot;
            for (int j = size2 - 1 ; j >= 0 ; --j) {
                char num = (char) (array1[i] * array2[j]);

                mul[k] += num;
                mul[k - 1] += mul[k] / 10;
                mul[k] = (char)(mul[k] % 10);

                --k;
            }
        }

        StringBuilder builder = new StringBuilder();
        int pivot = 0;
        while (pivot < sum) {
            if (mul[pivot] != 0) {
                break;
            }
            ++pivot;
        }
        while (pivot < sum) {
            builder.append((char) (mul[pivot] + '0'));
            ++pivot;
        }

        return builder.length() == 0? "0" : builder.toString();
    }
}