typedef struct {
  char  *str;                // ��ŷǿմ����׵�ַ
  int length;               // ��Ŵ��ĵ�ǰ����
}DSqString;               // ��̬˳������

bool StrAssign_Sq(DSqString &S,char *chars)
  {  // ���ַ���chars��ֵ��˳��S
    int i,j;
	char *c;
   	for(i=0,c=chars;*c;i++,c++);           // ��chars�ĳ���
	if(!i) { S.str=NULL;  S.length=0; }    // S��Ϊ�մ�
	else {
		if(!(S.str=(char *)malloc(i*sizeof(char))))  // ����S����ռ� 
			return false;                
		for(j=0;j<i;j++)                  // �������е��ַ����Ƶ���S��
		S.str[j]=chars[j];
		S.length=i;                       // ��S�Ĵ���Ϊi
	}
	return true;
}// StrAssign_Sq

bool StrCopy_Sq(DSqString &S,DSqString T)
{   // ��˳��T���Ƶ���һ��˳��S�У������ظ��ƺ��˳��S
	int i;
	if(!S.str) free(S.str);                       // �ͷ�Sԭ�пռ�
	if(!T.length) { S.str=NULL;  S.length=0;  }   // S��Ϊ�մ�
	else {
		if(!(S.str=(char *)malloc(T.length*sizeof(char)))) // ����S����ռ� 
			return false;                 
		for(i=0;i<T.length;i++)                  // ����T�е��ַ����Ƶ���S��
		S.str[i]=T.str[i];
		S.length=T.length;                       // ��S�Ĵ���ΪT.length
	} 
	return true;
}// StrCopy_Sq

int StrLength_Sq(DSqString S)
{
	return(S.length);
}// StrLength_Sq

int StrCompare_Sq(DSqString S,DSqString T)
{     // �Ƚ�˳��S��˳��T�Ĵ�С
	int i=0;
	while(i<S.length&&i<T.length)            // ��S�ʹ�T��Ӧ�ַ����бȽ�
	{
		if(S.str[i]>T.str[i]) return 1;
		else if(S.str[i]<T.str[i]) return -1;
		i++;
	}
	if(i<S.length) return 1;
	else if(i<T.length) return -1;
	return 0;
}// StrCompare_Sq
	
bool StrConcat_Sq(DSqString &S,DSqString T)
{
   int i;
   if(T.length) {
	if(!(S.str=(char *)realloc(S.str,(S.length+T.length)*sizeof(char))))  // ���������ռ�
			return false;
		for(i=0;i<T.length;i++)           // ����T�е��ַ������ڴ�S�ĺ���
		 S.str[S.length+i]=T.str[i];
		S.length+=T.length;                // ��S�Ĵ�������T.length
     }
	return true;
}// StrConcat_Sq

bool SubString_Sq(DSqString S,DSqString &Sub,int pos,int len)
{    // ��˳��S�дӵ�pos��λ�ÿ�ʼ��ȡ����Ϊlen���Ӵ�Sub��������Sub��ֵ
	int i;
	if(pos<0||pos>S.length-1||len<0||len>S.length-pos)  
		return false;                  // ȡ�Ӵ���λ�û��Ӵ��ĳ��Ȳ�����
	if(Sub.str)   free(Sub.str);         // �ͷ�Subԭ�пռ�
	if(!len) { Sub.str=NULL; Sub.length=0; }   // ��SubΪ���Ӵ�
	else {
		if(!(Sub.str=(char *)malloc(len*sizeof(char))))
			return false;
		for(i=0;i<len;i++)            // ����S�е�len���ַ����Ƶ�Sub��
			Sub.str[i]=S.str[pos+i];
		Sub.length=len;                // �Ӵ�Sub�Ĵ���Ϊlen
	}
	return true; 
}// SubString_Sq

bool Index_Sq(DSqString S,DSqString T,int &pos)
{  // ������S�в����Ƿ�����Ӵ�T�������ڣ�����pos������λ��
   int i=0,j=0;                       // i��j�ֱ�ɨ������S���Ӵ�T
   while(i<S.length&&j<T.length)      
   { if(S.str[i]==T.str[j])          // ��Ӧ�ַ���ͬ�������Ƚ���һ���ַ�
      { i++;    j++;
      }
      else                           // ����ָ��������¿�ʼ��һ��ƥ��
      { i=i-j+1;
        j=0;
      }
   }
   if(j==T.length)  { pos=i-T.length; return true;  }
   else return false;
}// Index_Sq

bool StrInsert_Sq(DSqString &S,int pos,DSqString T)
    {   // ��˳��S�ĵ�pos���ַ�֮ǰ�����Ӵ�T�������ز�����˳��S
     int i;
     if(pos<0||pos>S.length)  return false;    // pos������
     if(T.str) {
	   if(!(S.str=(char *)realloc(S.str,(S.length+T.length)*sizeof(char))))  
// ����S�����ռ� 
			return false;                 
       for(i=S.length-1;i>=pos;i--)            // Ϊ���봮T���ڳ�λ��
        S.str[i+T.length]=S.str[i];
       for(i=0;i<T.length;i++)                  // ���봮T
        S.str[pos+i]=T.str[i];
       S.length=S.length+T.length;             // ��S��������T.length
      }
    return true;
}// StrInsert_Sq

bool StrDelete_Sq(DSqString &S,int pos,int len)
    {  // ��˳��S�ĵ�pos���ַ��ַ���ʼɾ������Ϊlen���Ӵ���������ɾ����Ĵ�S
      int i;
      if(pos<0||len<0||pos+len>S.length)  return false;  // pos��len������
      for(i=pos+len;i<=S.length-1;i++)           // Ԫ��ǰ�ƣ�ɾ���Ӵ�
        S.str[i-len]=S.str[i];
      S.str=(char *)realloc(S.str,(S.length-len)*sizeof(char)); // ��S�ռ����len
      S.length=S.length-len;                  // ��S���ȼ���len
      return true;
}// StrDelete_Sq

void StrReplace_Sq(DSqString &S, DSqString T,DSqString V)
{  // �ô�V�û�����S�г��ֵ�������T��ȵĲ��ص��Ӵ����������û���Ĵ�S
      int  pos;
      while(Index_Sq(S,T,pos))                    // �ж�T�Ƿ���S���Ӵ�
      { StrDelete_Sq(S,pos,T.length);             // ɾ���Ӵ�T
	    StrInsert_Sq(S,pos,V);                    // �����Ӵ�V
      }
}// StrReplace_Sq

void StrTraveres_Sq(DSqString S)
{
	int i;
	for(i=0;i<StrLength_Sq(S);i++)
	std::cout<<S.str[i];
puts("\n");
}// StrTraveres_Sq

void DestroyString_Sq(DSqString &S)
{
	free(S.str);
	S.str=NULL;        // S.str�ÿ�
   S.length=0;
}// DestroyString_Sq
