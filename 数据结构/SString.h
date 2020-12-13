# define MaxSize 80
   typedef struct
   {
    char str[MaxSize];
    int length;
    }String;

void Initiate(String  *S)
  {
    S->length=0;
  }

int Insert(String *S,int pos,String T)
 {
   int i;
   if(pos<0||pos>S->length)
   {
     printf("pos error!\n");
     return 0;
    }
    else  if(S->length+T.length>MaxSize)
    {
      printf("The memory is not enough!\n");
      return 0;
    }
    else
    {
      for(i=S->length-1;i>=pos;i--)
        S->str[i+T.length]=S->str[i];

      for(i=0;i<T.length;i++)
        S->str[pos+i]=T.str[i];

      S->length=S->length+T.length;
      return 1;
    }
   }

int Delete(String *S,int pos,int len)
 {
   int i;
   if(S->length<=0)
   {
     printf("String is empty!\n");
     return 0;
    }
    else  if(pos<0||len<0||pos+len>S->length)
    {
      printf("pos or len error!\n");
      return 0;
    }
    else
    {
      for(i=pos+len;i<=S->length-1;i++)
        S->str[i-len]=S->str[i];

      S->length=S->length-len;
      return 1;
    }
   }

 int SubString(String S, int pos,int len, String *T)
  {
   int i, n;
    n=S.length;
    if(pos<0||len<0||pos+len>n)
    {
       printf("pos or len error!\n");
       return   0;
     }
     else
     {
       for(i=0;i<len;i++)  T->str[i]=S.str[pos+i];
       T->length=len;
       return 1;
    }
   }


