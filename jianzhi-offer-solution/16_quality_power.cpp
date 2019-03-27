class Solution {
public:
    double Power(double base, int exponent) {
        if (base == 0.0) return 0.0;
        if (exponent < 0) {
            double rst = UnsignedPower(base, -exponent);
            return 1.0 / rst;
        } else
            return UnsignedPower(base, exponent);
    }

    double UnsignedPower(double base, int exponent) {
        if (exponent == 0) return 1.0;
        if (exponent == 1) return base;
        double rst = UnsignedPower(base, exponent >> 1);
        rst *= rst;
        if (exponent & 0x1)
            rst *= base;
        return rst;
    }
};