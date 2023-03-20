class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 0) {
                if(i == 0 and i + 1 < flowerbed.size() and flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    count++;
                } else if(i + 1 == flowerbed.size() and i - 1 >= 0 and flowerbed[i - 1] == 0) {
                    flowerbed[i] = 1;
                    count++; 
                } else if(i - 1 >= 0 and i + 1 < flowerbed.size() and flowerbed[i - 1] == 0 and flowerbed[i + 1] == 0) {
                    count++;
                    flowerbed[i] = 1;
                } else if(i == 0 and flowerbed.size() == 1) {
                    count++;
                    flowerbed[i]=1; 
                }
            }
        }
        return count >= n;
    }
};