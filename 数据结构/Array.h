#define MAX_ARRAY_DIM 8 // ��������ά�������ֵΪ8
typedef struct {
   ElemType *base; // ����Ԫ�ػ�ַ����InitArray����
   int dim; // ����ά��
   int *b; // ����ά���ַ����InitArray����
   int *c; // ����ӳ����������ַ����InitArray����
 }Array;

bool InitArray(Array &A,int dim,...)
 { // ��ά��dim�͸�ά���ȺϷ���������Ӧ������A��������true
   int elemtotal=1,i; // elemtotal������Ԫ����������ֵΪ1(�۳���)
   va_list ap; // �䳤���������ͣ���stdarg.h�У��Ǵ�ű䳤��������Ϣ������
   if(dim<1||dim>MAX_ARRAY_DIM) // ����ά��������Χ
     return false;
   A.dim=dim; // ����ά��
   A.b=(int*)malloc(dim*sizeof(int)); // ��̬��������ά���ַ
   if(!A.b)     exit(1);                // �洢����ʧ��
   va_start(ap,dim); // �䳤������...�����β�dim֮��ʼ
   for(i=0;i<dim;++i)
   { A.b[i]=va_arg(ap,int); // ��һ���䳤��������A.b[i]
     if(A.b[i]<0)
       return false; // ���Ȳ��Ϸ�
	 // ����ά���ȺϷ������������A.b�У������A��Ԫ������
     elemtotal*=A.b[i]; 
   }	
   va_end(ap); // ������ȡ�䳤����
   A.base=(ElemType*)malloc(elemtotal*sizeof(ElemType)); // ��̬��������洢�ռ�
   if(!A.base)     exit(1);     // �洢����ʧ��
   // ��ӳ�����ĳ���Ci,����������A.c[i-1],i=1,��,dim
   A.c=(int*)malloc(dim*sizeof(int)); // ��̬��������ƫ������ַ
   if(!A.c)     exit(1);  // �洢����ʧ��
   A.c[dim-1]=1; // ���һά��ƫ����Ϊ1(L=1,ָ���������Ԫ�صĴ�СΪ��λ��
   for(i=dim-2;i>=0;--i)
     A.c[i]=A.b[i+1]*A.c[i+1];   // ÿһά��ƫ����
    return true;
 }

 void DestroyArray(Array &A)
 { // ��������A��
   if(A.base) // A.baseָ��洢��Ԫ
     free(A.base); // �ͷ�A.base��ָ��Ĵ洢��Ԫ
   if(A.b)
     free(A.b);
   if(A.c)
     free(A.c);
     A.base=NULL;    // ʹ���ǲ���ָ���κδ洢��Ԫ
	 A.b=A.c=NULL; 
   A.dim=0;
 }

 bool Locate(Array A,va_list ap,int &off) 
 { // ��apָʾ�ĸ��±�ֵ�Ϸ����������Ԫ����A�е���Ե�ַoff
   int i,ind;
   off=0;
   for(i=0;i<A.dim;i++)
   { ind=va_arg(ap,int); // ��һ��ȡ��ά���±�ֵ
     if(ind<0||ind>=A.b[i]) // ��ά���±�ֵ���Ϸ�
       return false;
     off+=A.c[i]*ind; // ��Ե�ַ=��ά���±�ֵ*��ά��ƫ����֮��
   }
   return true;
 }

 bool Value(ElemType &e,Array A,...) // ��VC++�У���...��֮ǰ���ββ�������������
 { // ��...������Ϊ��ά���±�ֵ�������±�Ϸ�����e����ֵΪA����Ӧ��Ԫ��ֵ
   va_list ap; // �䳤���������ͣ���stdarg.h��
   int off;
   va_start(ap,A); // �䳤������...�����β�A֮��ʼ
   if(!Locate(A,ap,off)) // ����Locate()����ñ䳤������ָ��Ԫ����Ե�ַoff
     return false;
   e=*(A.base+off); // ���䳤������ָ��Ԫ��ֵ����e
   return true;
 }

 bool Assign(Array A,ElemType e,...) 
 { // ��...������Ϊ��ά���±�ֵ�������±�Ϸ�����e��ֵ����A��ָ����Ԫ�ء�
   va_list ap; // �䳤���������ͣ���stdarg.h��
   int off;
   va_start(ap,e); // �䳤������...�����β�e֮��ʼ
   if(!Locate(A,ap,off)) // ����Locate()����ñ䳤������ָ��Ԫ����Ե�ַoff
     return false;
   *(A.base+off)=e; // ��e��ֵ�����䳤������ָ��Ԫ
   return true;
 }