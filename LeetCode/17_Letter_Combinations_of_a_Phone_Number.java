class Solution {
    public List<String> letterCombinations(String digits) {

        List<String> ans = new ArrayList<String>();
        int len = digits.length();
        if (len == 0) {
            return ans;
        }

        char[][] map = new char[10][4];
        map[2][0] = 'a';
        map[2][1] = 'b';
        map[2][2] = 'c';

        map[3][0] = 'd';
        map[3][1] = 'e';
        map[3][2] = 'f';

        map[4][0] = 'g';
        map[4][1] = 'h';
        map[4][2] = 'i';

        map[5][0] = 'j';
        map[5][1] = 'k';
        map[5][2] = 'l';

        map[6][0] = 'm';
        map[6][1] = 'n';
        map[6][2] = 'o';

        map[7][0] = 'p';
        map[7][1] = 'q';
        map[7][2] = 'r';
        map[7][3] = 's';

        map[8][0] = 't';
        map[8][1] = 'u';
        map[8][2] = 'v';

        map[9][0] = 'w';
        map[9][1] = 'x';
        map[9][2] = 'y';
        map[9][3] = 'z';

        Set<String> store = new HashSet<String>();
        int idx = (int) (digits.charAt(0) - '0');

        store.add(String.valueOf(map[idx][0]));
        store.add(String.valueOf(map[idx][1]));
        store.add(String.valueOf(map[idx][2]));
        if (idx == 7 || idx == 9) {
            store.add(String.valueOf(map[idx][3]));
        }

        for (int i = 1 ; i < len ; ++i) {
            idx = (int) (digits.charAt(i) - '0');

            Set<String> newStore = new HashSet<String>();

            for (String str : store) {
                newStore.add(str + String.valueOf(map[idx][0]));
                newStore.add(str + String.valueOf(map[idx][1]));
                newStore.add(str + String.valueOf(map[idx][2]));
                if (idx == 7 || idx == 9) {
                    newStore.add(str + String.valueOf(map[idx][3]));
                }
            }

            store = newStore;
        }

        for (String str : store) {
            ans.add(str);
        }

        return ans;
    }
}