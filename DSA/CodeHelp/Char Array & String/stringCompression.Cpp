class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();

        while (i < n)
        {
            int j = i + 1;
            while (j < n && chars[i] == chars[j])
            {
                j++;
            }
            // When array is completely traversed
            // When different character is encountered

            // store old character
            chars[ansIndex++] = chars[i];

            int count = j - i;

            if (count > 1)
            {
                // storing count as string
                string cnt = to_string(count);
                for (char ch : cnt)
                {
                    chars[ansIndex++] = ch;
                }
            }
            // moving to different character
            i = j;
        }
        return ansIndex;
    }
};