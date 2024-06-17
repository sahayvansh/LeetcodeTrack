class Solution
{
    public:
        bool judgeSquareSum(int c)
        {
            for (int a = 0; a <= sqrt(c); ++a)
            {
                int a_squared = a * a;
                int b_squared = c - a_squared;
                if (sqrt(b_squared) == (int)(sqrt(b_squared)))
                {
                    return true;
                }
            }
            return false;
        }
};