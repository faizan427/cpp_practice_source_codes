	    
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
    
