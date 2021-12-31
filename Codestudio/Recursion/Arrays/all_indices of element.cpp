int solve(int input[],int currindex, int size,int x,int output[],int &k)
{
    if(currindex == size) return k;
    if(input[currindex] == x)
    {
		output[k] = currindex;
        k++;
    }
    solve(input,currindex+1,size,x,output,k);
}





int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    int k=0;
	return solve(input,0,size,x,output,k);
}
