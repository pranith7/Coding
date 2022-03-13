 pair<int, int> closestSum(vector<int> arr, int x)// 10 22 28 29 30 40, x = 54
 {
    int l=0, h=arr.size()-1, current_sum, closest_sum;
    pair<int, int> res = make_pair(arr[l], arr[h]);
    closest_sum = res.first + res.second;
	while(l < h)
	{
		current_sum = arr[l] + arr[h];
		if(current_sum==x)
		{
            res.first = arr[l];
            res.second = arr[h];
			return res;
		}
		else{
			
			if(abs(closest_sum-x) >= abs(current_sum-x)){
				res.first = arr[l];
				res.second = arr[h];
				closest_sum = current_sum;
			}
			
			if(current_sum < x)
			l++;
			else 
			h--;
		}
	}
	
	return res;
}