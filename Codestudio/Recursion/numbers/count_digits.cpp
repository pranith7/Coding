int count(int n){
    //Base case
    if(n==0) return 0;
    //Recursive Assumption
	int small = count(n/10);
    int ans = small + 1;
    //Self work
    return ans;
}