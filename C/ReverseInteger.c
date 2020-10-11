int reverse(int x){
long s=0;
while(x!=0){
s=s*10+x%10;
x=x/10;
}
if(s>=-INT_MAX && s<=INT_MAX){
return s;
}
return 0;
}
