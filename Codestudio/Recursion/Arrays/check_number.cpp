bool checkNumber(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
	// //Base case
	// if(size >= 1)
	// {
	// 	if(input[size-1] == x)
	// {
	// 		return true;
	// }
	// }
	// //Recursive assumption
	// bool work  = checkNumber(input-1,size-1,x);
	// //self work
	// if(!work) return false;
    if(size==1)
    {
		if(input[size-1] == x) return true;
        else return false;
    }
    //Recursive assumption
    if(input[size-1]==x) return true;
    bool work  = checkNumber(input, size-1,x);
    //self work
    if(work) return true;
    else return false;

}

/*

Base case
if(size==1)
{
    if(input[size-1]==x) return size-1;
    else return -1;
}
if(input[size-1] == x) return size-1;
return 
*/