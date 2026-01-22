
2. Memory Leak (No Deallocation)

You are using new to allocate memory on the heap but never calling delete[].

The Flaw: Every time the judge runs a test case, more of the server's RAM is consumed and never released. On Test Case 42, the judge likely runs out of memory and kills your program.

The Fix: Add delete[] vis; before the return statement.

3. Vulnerability to Negative Numbers

Your logic assumes all numbers in nums are non-negative because you use the value of the number as an index: vis[nums[i]].

The Flaw: If nums[i] is -5, your code tries to access vis[-5], which is outside the array's memory. This is a guaranteed Segmentation Fault.

The Fix: Use a hash map or add an offset to handle negative values.

4. Memory Overflow with Large Values

This is the most likely reason for failing "large test cases" in "Submit" mode.

The Flaw: If a test case contains the number 1,000,000,000, your code attempts to allocate an array of 1 billion integers ($ \approx 4\text{GB}$ of RAM). Most online judges have a limit of 256MB.

The Result: The new operator fails to find enough contiguous memory, causing the program to crash.

5. Incorrect Initialization of max_o_nums

You initialized int max_o_nums = 0;.

The Flaw: If the input nums contains only negative numbers (e.g., {-10, -20, -30}), your loop if(max_o_nums < nums[i]) will never trigger. max_o_nums will stay 0, and you will return 0 as the answer, which isn't even in the array.

The Fix: Initialize it with the first element: int max_o_nums = nums[0];.
    */
    int mostFrequentElement(vector<int>& nums) 
    {
        //////// step -i calculate the maximum nums vector//---1
        // auto x = std::max_element(nums.begin(), nums.end());
        // int max_o_nums =  (int) (*x);
        int max_o_nums =0;
        int nums_size = nums.size();
        for(int i =0; i < nums_size; i++)
        {
            if(max_o_nums< nums[i])
            {
                max_o_nums = nums[i];
            }
        }
        //cout <<  max_o_nums  << endl;
        //////// step -i calculate the maximum nums vector//----1


        //////// declare a has vector with as size of max_o_nums//----2
        int vis_size = max_o_nums+1;
           
        // vector<int> vis(vis_size,0);
        int *vis = new int[vis_size]();
        //////// declare a has vector with as size of max_o_nums//----2

        //////// make a has vector                              //----3
        for(int i =0; i < nums_size; i ++)
        {
            
            vis[nums[i]]++;
        }
        //////// make a has vector                              //----3
//    for(int i =0; i < vis_size; i ++)
//         {
//             cout << vis[i] << " " ;
//         }
        //////// find maximum value present inside vis[]'s index //----3
        int temp =0;
       
        int max_f_n =0;
        for(int i =0; i <vis_size; i++)
        {
            if(temp < vis[i])
            {
                temp = vis[i];
                max_f_n = i;
            }
        }
        //cout << endl <<max_f_n << endl;
        //////// find maximum value present inside vis[]'s index //----3
   // cout << endl;
   delete []vis;
    return max_f_n;
    }
    
