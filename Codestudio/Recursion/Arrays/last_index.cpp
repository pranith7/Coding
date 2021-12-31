int lastIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    //Base case
    if(size == 0) return -1;
    //Self work
    if(input[size-1]==x) return size-1;
    //Recursive assumption
	int ans = lastIndex(input,size-1,x);
    if(ans == -1) return -1;
    else return ans; 
}
