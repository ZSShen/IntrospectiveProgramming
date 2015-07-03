uint32_t reverseBits(uint32_t in)
{
    uint32_t out = 0;
    char idx = 1;
    while (idx < 32) {
        out |= in & 0x1;
        out <<= 1;
        in >>= 1;
        idx++;
    }
    out |= in & 0x1;

    return out;
}
