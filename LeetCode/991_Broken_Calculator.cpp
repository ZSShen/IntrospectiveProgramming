class Solution {
public:
    int brokenCalc(int X, int Y) {

        int step = 0;
        while (X < Y) {
            if (Y & 1 == 1) {
                Y += 1;
            } else {
                Y >>= 1;
            }
            ++step;
        }

        return step + (X - Y);
    }
};