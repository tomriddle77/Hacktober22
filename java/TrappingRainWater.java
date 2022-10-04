class Solution {
    public int trap(int[] height) {
        int s = 0,e = height.length-1;
        int leftMax = 0;
        int rightMax = 0;
        int trapped = 0;
        
        while(s<e){
            if(height[s]<=height[e]){
                if(height[s]>=leftMax) leftMax = height[s];
                else trapped+= leftMax - height[s];
                s++;
            }
            else{
                if(height[e]>=rightMax) rightMax = height[e];
                else trapped+= rightMax - height[e];
                e--;
            }
        }
        
        return trapped;
    }
}
