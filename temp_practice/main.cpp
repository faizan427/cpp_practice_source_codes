
The Flaw: If a test case contains the number 1,000,000,000, your code attempts to allocate an array of 1 billion integers ($ \approx 4\text{GB}$ of RAM). Most online judges have a limit of 256MB.

The Result: The new operator fails to find enough contiguous memory, causing the program to crash.

5. Incorrect Initialization of max_o_nums

You initialized int max_o_nums = 0;.

The Flaw: If the input nums contains only negative numbers (e.g., {-10, -20, -30}), your loop if(max_o_nums < nums[i]) will never trigger. max_o_nums will stay 0, and you will return 0 as the answer, which isn't even in the array.

The Fix: Initialize it with the first element: int max_o_nums = nums[0];.
    */
    int mostFrequentElement(vector<int>& nums) 
    {
     /////////////////////////////////////////////////////////////////--1
    auto temp = std::max_element(nums.begin(), nums.end());
    int max_o_nums = (int) (*temp);
    // cout <<"max_o_nums " <<max_o_nums << endl;
    // cout <<"nums.size() "<< nums.size()<< endl;
    /////////////////////////////////////////////////////////////////--1
    
    /////////////////////////////////////////////////////////////////--2
    vector<int> vis(max_o_nums+1,0);
    /////////////////////////////////////////////////////////////////--2
    
    /////////////////////////////////////////////////////////////////--3
  // cout <<"vis.size() "<< vis.size()<< endl;
    for(int i =0; i < nums.size(); i++)
    {
        vis[nums[i]]++;
    }
    // for(int i =0; i <vis.size();i++)
    // {
    //     cout << vis[i] << " " ;
    // }
    // cout << endl;
    //     for(int i =0; i <vis.size();i++)
    // {
    //     cout << i << " " ;
    // }
    // cout << endl;
    int max_1 =0;
    int max_2 =0;
    int max_e_1 =0;
    int max_e_2 =0;
    for(int i =0; i= vis.size(); i++)
    {
        if(max_1 < vis[i])
        {
            max_1 = vis[i];
        //   cout << "max_1 = " << max_e_1 <<" max_2 = "<< max_e_2 << endl;
            // max_2 = max_1;
            // max_1 = vis[i];
            // max_e_2 = max_e_1;
            max_e_1 =i;
        }
    }
   
    /////////////////////////////////////////////////////////////////--3
    return max_e_1;
    }
    
