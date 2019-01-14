class Solution {
public:
    int romanToInt(string s) {

        int sum = 0;
        int index = 0, size = s.length();
        while (index < size) {
            char ch = s[index];
            switch (ch) {
                case 'I': {
                    if (index < size -1) {
                        if (s[index + 1] == 'V') {
                            sum += 4;
                            ++index;
                        } else if (s[index + 1] == 'X') {
                            sum += 9;
                            ++index;
                        } else {
                            sum += 1;
                        }
                    } else {
                        sum += 1;
                    }

                    ++index;
                    break;
                }
                case 'V': {
                    sum += 5;
                    ++index;
                    break;
                }
                case 'X': {
                    if (index < size - 1) {
                        if (s[index + 1] == 'L') {
                            sum += 40;
                            ++index;
                        } else if (s[index + 1] == 'C') {
                            sum += 90;
                            ++index;
                        } else {
                            sum += 10;
                        }
                    } else {
                        sum += 10;
                    }

                    ++index;
                    break;
                }
                case 'L': {
                    sum += 50;
                    ++index;
                    break;
                }
                case 'C': {
                    if (index < size - 1) {
                        if (s[index + 1] == 'D') {
                            sum += 400;
                            ++index;
                        } else if (s[index + 1] == 'M') {
                            sum += 900;
                            ++index;
                        } else {
                            sum += 100;
                        }
                    } else {
                        sum += 100;
                    }

                    ++index;
                    break;
                }
                case 'D': {
                    sum += 500;
                    ++index;
                    break;
                }
                case 'M': {
                    sum += 1000;
                    ++index;
                    break;
                }
            }
        }

        return sum;
    }
};