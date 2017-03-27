int hammingWeight(uint32_t n)
{
    int count = 0;
    int idx = 0;
    while (idx < 32) {
        count += n & 1;
        n >>= 1;
        idx++;
    }
    return count;
}