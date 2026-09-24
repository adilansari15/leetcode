class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0, sum =0, maxsum = 0;
        for (i=0; i<k; i++){
            sum +=   nums[i];
            
        }
        maxsum = sum;
        for(int end = k; end<nums.size(); end++){
            sum += - nums[end-k] + nums[end];
           maxsum = max(maxsum, sum);
        }
        double avg = (double)maxsum/k;
        return avg;
    }
};