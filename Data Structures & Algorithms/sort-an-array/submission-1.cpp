class Solution {
public:
   vector<int>ans;
   vector<int> mergesort(vector<int>& nums, int i, int mid, int end) {
    vector<int> temp;

    int start = i;
    int j = mid + 1;

    while(i <= mid && j <= end) {
        if(nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        }
        else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }

    while(j <= end) {
        temp.push_back(nums[j]);
        j++;
    }

    for(int a = 0; a < temp.size(); a++) {
        nums[start + a] = temp[a];
    }

    return temp;
}
    void merge(vector<int>&nums,int i,int j){
        if(i>=j){
            return;
        }
        int mid=i+(j-i)/2;
        merge(nums,i,mid);
        merge(nums,mid+1,j);
        ans=mergesort(nums,i,mid,j);
    }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()==1){
            return nums;
        }
        merge(nums,0,nums.size()-1);
        return ans;
    }
};