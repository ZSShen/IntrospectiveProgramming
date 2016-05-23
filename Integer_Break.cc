class Solution
{
public:
    int integerBreak(int n)
    {
        switch (n) {
            case 2:
                return 1;
            case 3:
                return 2;
            case 4:
                return 4;
        }

        int ans = 1;
        while (true) {
            n -= 3;
            ans *= 3;
            if (n <= 4)
                break;
        }
        ans *= n;

        return ans;
    }
};