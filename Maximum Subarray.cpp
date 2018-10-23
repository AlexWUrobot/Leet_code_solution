#include <stdio.h> 
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    }
    //static int GetMax(int* array, int length);
	

	int BruteForce_GetMax(int* array, int length)  // arr  , 9 {-2,1,-3,4,-1,2,1,-5,4}
	{
	    int max_sum = array[0], sum, step;                  //  -2, 0
	    for (int start = 0; start < length; start++)  //   0, 0~8, 0 1 2....
	        for (int end = 0; end < length; end++)    //   0, 0~8, 0 1 2....
	        {
	            sum = 0;
	            for (int i = start; i <= end; i++)    //   0 1 2
	                sum += array[i];				  // 
	            
				max_sum = max(max_sum, sum);          // 
	            //printf("start: %d end: %d  Max sum: %d sum: %d \n", start, end, max_sum, sum);
	        }
	    
	    return max_sum;
	}
	
	int RefineBruteForce_GetMax(int* array, int length)
	{
	    int max_sum = array[0], sum;
	    for (int start = 0; start < length; ++start) //   0, 0~8, 0 1 2....
	    {
	        sum = 0;
	        for (int i = start; i < length; ++i)     //   0, 0~8, 0 1 2....
	        {
	            sum += array[i];
	            max_sum = max(max_sum, sum);
	        }
	    }
	    return max_sum;
	}
	
	int Kadanes_GetMax(int* array, int length)  // arr  , 9 {-2,1,-3,4,-1,2,1,-5,4}
	{
	    int sum = 0;
	    int max_sum = array[0];
	    for (int i = 0; i < length; ++i)   // 0 ~ 8
	    {
	        sum += array[i];               
	        sum = max(0, sum);
	        max_sum = max(sum, max_sum);
	    }
	    return max_sum;
	}
	
	
	int maxsubarr(vector<int>& num){
		int sum, max_sum =0;
		for(int i=0; i< num.size();i++){
			sum += num[i];
			sum = max(0,sum);
			max_sum = max(sum,max_sum);
		}
		return max_sum;		
	}
	
	int KadanesOne_Detect(int* array, int length)
	{
	    int max_sum = array[0];
	    for (int i = 0; i < length; ++i)
	    {
	        if (array[i] >= 0)
	            return 0;
	        max_sum = max(array[i], max_sum);
	    }
	    return max_sum;
	}
	
	int Improved_KO_GetMax(int* array, int length)
	{
	    int sum = KadanesOne_Detect(array, length);
	    if (sum < 0)
	        return sum;
	    int max_sum = array[0];
	    for (int i = 0; i < length; ++i)
	    {
	        sum += array[i];
	        sum = max(0, sum);
	        max_sum = max(sum, max_sum);
	    }
	    return max_sum;
	}
};

//http://emn178.pixnet.net/blog/post/88907691-%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%88%97%28maximum-subarray%29


int main(void){
	int arr[]= {-2,1,-3,4,-1,2,1,-5,4};  //
	//int arr[]= {-2,-1,-3,-4,-1,-2,-1,-5,-4};
	vector<int> varr(arr,arr+9);
	Solution BF;
	int BruteForce = BF.BruteForce_GetMax(arr,9);
	int RefineBruteForce= BF.RefineBruteForce_GetMax(arr,9);
	//int Kadanes_GetMax = BF.Kadanes_GetMax(arr,9);
	int Kadanes_GetMax = BF.maxsubarr(varr);
	int Improved_KO_GetMax = BF.Improved_KO_GetMax(arr,9);
	printf("maximum subarray \n");
	printf("%d \n", BruteForce);
	printf("%d \n", RefineBruteForce);     // OK
	printf("%d \n", Kadanes_GetMax);
	printf("%d \n", Improved_KO_GetMax);  // Best 
	
}
