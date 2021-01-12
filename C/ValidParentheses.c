bool isValid(char * str){

int top=-1;
char S[100000];
int i;
for(i=0;str[i];i++)
{
if(str[i]=='('||str[i]=='['||str[i]=='{')
S[++top]=str[i];
else
{
if(top<0) return false;
switch(str[i])
{
case ')' :
if(S[top]=='(')
S[top--]='#';
else return false;
break;
case '}' :
if(S[top]=='{')
S[top--]='#';
else return false;
break;
case ']' :
if(S[top]=='[')
S[top--]='#';
else return false;
break;
}
}
}
return top==-1?true:false;
}
