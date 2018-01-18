class Solution {
    public String validIPAddress(String IP) {

        String[] parts = IP.split("\\.");
        if (parts.length == 4) {
            if (IP.charAt(IP.length() - 1) == '.') {
                return "Neither";
            }
            return verifyIPv4(parts) ? "IPv4" : "Neither";
        }

        parts = IP.split(":");
        if (parts.length == 8) {
            if (IP.charAt(IP.length() - 1) == ':') {
                return "Neither";
            }
            return verifyIPv6(parts) ? "IPv6" : "Neither";
        }

        return "Neither";
    }

    private boolean verifyIPv4(String[] parts) {

        for (String part : parts) {
            int length = part.length();
            if (length == 0) {
                return false;
            }

            if (part.charAt(0) == '-') {
                return false;
            }

            if (part.length() > 1 && part.charAt(0) == '0') {
                return false;
            }

            try {
                int value = Integer.valueOf(part);
                if (value < 0 || value >= 256) {
                    return false;
                }
            } catch (Exception e) {
                return false;
            }
         }

        return true;
    }

    private boolean verifyIPv6(String[] parts) {

        for (String part : parts) {
            int length = part.length();
            if (length == 0 || length > 4) {
                return false;
            }

            try {
                int value = Integer.decode("0x" + part);
                if (value < 0 || value >= 65536) {
                    return false;
                }
            } catch (Exception e) {
                return false;
            }
        }

        return true;
    }
}