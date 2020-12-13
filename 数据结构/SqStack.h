# define STACK_INIT_SIZE  100             // ˳��ջ (Ĭ�ϵ�)�ĳ�ʼ�����������
# define STACKINCREMENT  10               // (Ĭ�ϵ�)�����ռ���
typedef struct 
{ElemType *stack;                        // �洢����Ԫ�ص�һά����
  int top;                               // ջ��ָ��
  int stacksize;                         // ��ǰ�����������������ElemTypeΪ��λ��
  int incrementsize;	                   // �����ռ�������ElemTypeΪ��λ��
}SqStack;

void InitStack_Sq(SqStack &S, int maxsize=STACK_INIT_SIZE,
                                 int incresize=STACKINCREMENT ) 
{
     S.stack=(ElemType *)malloc(maxsize*sizeof(ElemType)); // Ϊ˳��ջ�����ʼ�洢�ռ�
     if(!S.stack)  exit(1);                                // �洢�ռ����ʧ��
      S.top=-1;                                            // ��ջ��
      S.stacksize=maxsize;                                 // ˳��ջ�ĵ�ǰ����
      S.incrementsize=incresize;                           // �����ռ�
}// InitStack_Sq

int StackLength_Sq(SqStack S)
{
	return S.top+1;
}// StackLength_Sq

bool Push_Sq(SqStack &S,ElemType e)
{  //��˳��ջ��ջ������Ԫ��e
  if(S.top==S.stacksize-1)  {               
S.stack =(ElemType *)realloc(S.stack,(S.stacksize+S.
incrementsize)*sizeof(ElemType)); // ջ������˳��ջ�����ռ�
  if(!S.stack)     return false;                // ����洢�ռ�ʧ��
  S.stacksize+=S.incrementsize; 
 }
 S.stack[++S.top]=e;                             // ջ��ָ�����ƣ�Ԫ��e��ջ
  return true;   
}// Push_Sq

bool Pop_Sq(SqStack &S,ElemType &e)
{   // ɾ��˳��ջջ��Ԫ�أ�����e������ֵ
  if(S.top==-1)  return false; 
  e=S.stack[S.top--];  
       return true;    
}// Pop_Sq

bool GetTop_Sq(SqStack S, ElemType &e)
{   //ȡ˳��ջջ��Ԫ�أ�����e������ֵ
if(S.top==-1)  return false;    
  e=S.stack[S.top];      
  return true;    
}// GetTop_Sq

bool StackEmpty_Sq(SqStack S)
{ if(S.top==-1)  return true;
   else return false;
}// StackEmpty_Sq

void DestroyStack_Sq(SqStack &S )
{
   free(S.stack);
   S.stacksize=0;
   S.top=-1;
}// DestroyStack_Sq

