bool isPalindrome(int n){
    long int i,j,s=0,r;
  
    j=n;
    if (n>=0){
    while(n!=0)
    {
        r=n%10;
        s=s*10+r;
        n/=10;
    }
    if (s==j)
        return 1;
    else 
       return 0 ;}
    else
    return 0;
}
