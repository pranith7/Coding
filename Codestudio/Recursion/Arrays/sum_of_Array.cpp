int sum(int input[], int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    //Base case
		// if(n==0)
		// {
		// return;
		// }
    if(n==1)
    {
		return input[n-1];
    }
    //Recursive assumption
    int work  = sum(input, n-1);
    //self work
    return input[n-1] + work;

}