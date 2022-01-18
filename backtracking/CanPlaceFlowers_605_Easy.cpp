// https://leetcode.com/problems/can-place-flowers/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int ans = 0;
        int size = flowerbed.size();
        for(int i = 0;i < size;i++){
            if(i == 0 && flowerbed[i] == 0)count++;
            if(i == size-1 && flowerbed[i] == 0)count++;
            if(flowerbed[i] == 1){
                ans += (count-1)/2;
                count = 0;
            }
            else count++;
        }
        ans += (count-1)/2;
        return ans >= n ? true: false;
    }
};
