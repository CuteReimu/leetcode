class Solution {
public:
    bool isPowerOfFour(int num) {
        return
        num == 0x01 ||
        num == 0x04 ||
        num == 0x10 ||
        num == 0x40 ||
        num == 0x100 ||
        num == 0x400 ||
        num == 0x1000 ||
        num == 0x4000 ||
        num == 0x10000 ||
        num == 0x40000 ||
        num == 0x100000 ||
        num == 0x400000 ||
        num == 0x1000000 ||
        num == 0x4000000 ||
        num == 0x10000000 ||
        num == 0x40000000;
    }
};
