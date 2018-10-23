#include <stdio.h>
#include <vector>
//https://blog.techbridge.cc/2017/01/21/simple-hash-table-intro/
#include <map>
using namespace std; 


class Solution {
public:
    vector<int> hast_table_two_sum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> indexMap;//-----------------------> use map to replace hash table
        map<int, int>::iterator iter;
        // map (stl) :http://mropengate.blogspot.com/2015/12/cc-map-stl.html 
        //-------------------------------------------------------------------
        for(int i=0; i<nums.size(); i++)
        {
            iter = indexMap.find(target-nums[i]);  // 9-2 = 7 --- 9-7=2 -----------------target-nums[i]=first   iter is class   2,7,11,15
            if(iter != indexMap.end())			   //----- 9-7=2   find          first:2 second:0
            {
                ans.push_back(iter->second);       
                ans.push_back(i);                  
                return ans;
            }
            else 								  //-----   do not find
                indexMap.insert(pair<int, int>(nums[i], i));   // save 2 0 
        }
        return ans;
    }
};
int main(void) {
	  
	int iarr[]= {2,7,11,15};
	vector<int> ivector(iarr,iarr+4); 
	//https://openhome.cc/Gossip/CppGossip/vector1.html
	vector<int> ans;
	Solution first;
	ans = first.hast_table_two_sum(ivector,22);
	
	printf("hello C++ hash table \n");
	printf("The answer is %d and %d \n", ans[0], ans[1]);
	return 0;
}


