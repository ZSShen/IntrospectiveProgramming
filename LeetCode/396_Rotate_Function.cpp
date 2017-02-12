class Solution {
public:
    int maxRotateFunction(vector<int>& A) {

        /**
         *  Formula Deduction:
         * 
         *  Assume A = [a, b, c, d]
         * 
         * All the permutations are:
         *      a b c d
         *      d a b c
         *      c d a b
         *      b c d a
         * 
         *  Let sum = a + b + c + d
         *  Then:
         *  f(0) = 0a + 1b + 2c + 3d
         *  f(1) = 0d + 1a + 2b + 3c = f(0) + (a + b + c - 3d) = f(0) + sum - 4d
         *  f(2) = 0c + 1d + 2a + 3b = f(1) + (a + b + d - 3c) = f(1) + sum - 4c
         * 
         *  f(i) = f(i - 1) + sum - n * A[n - i], i >= 1.
         */

        int size = A.size();
        if (size == 0) {
            return 0;
        }

        int sum = 0;
        for (int num : A) {
            sum += num;
        }

        // Calcualte f(0).
        int previous = 0;
        for (int i = 0 ; i < size ; ++i) {
            previous += i * A[i];
        }
        int max = previous;

        // Calculate f(1) to f(n - 1).
        for (int i = 1 ; i < size ; ++i) {
            int current = previous + sum - size * A[size - i];
            if (current > max) {
                max = current;
            }
            previous = current;
        }

        return max;
    }
};