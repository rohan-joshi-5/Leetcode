class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> list;
        for(int i=0;i<nums1.size();i++){
            list.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            list.push_back(nums2[i]);
        }
        sort(list.begin(),list.end());
        if(list.size()%2==0){
            int x=list[(list.size()/2)-1];
            int y=list[list.size()/2];
            double ans=(x+y)/2.0;
            return ans;
        }
        else{
            double z=(list[list.size()/2.0]);
            return z;
        }
        
    }
};