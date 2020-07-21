// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3379/

class Solution {
public:
    unsigned char mask = 0b10000000;
    unsigned char m = 0b01111110;
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<char, int> history;
        int step = 0;
        unsigned char b = 0; 
        
        for (int i = 0; i < cells.size(); i++) {
            if (cells[i])
                b |= mask >> i;
        }
        while (N--) {
            b = ~((b << 1) ^ (b >> 1));
            b &= m;
            if (history.find(b) == history.end())
                history[b] = step;
            else 
                break ;
            step++;
        }

        int ith = N % step;
        for (auto itr : history) {
            if (itr.second == ith) 
                b = itr.first;
        }
        for (int i = 0; i < cells.size(); i++) 
            cells[i] =  b & mask >> i ? 1 : 0; 
        return cells;
    }
};

