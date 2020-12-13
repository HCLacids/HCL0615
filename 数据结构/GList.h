enum ElemTag{ATOM,LIST};            // ATOM==0��ԭ��,LIST==1���ӱ�
typedef struct GLNode { 
ElemTag tag;                     // �������֣���������ԭ�ӽ��ͱ���
   union                            // ԭ�ӽ��ͱ�������ϲ���
   { ElemType data;                 // data��ԭ�ӽ���ֵ��dataType���û�����
     struct
     { struct GLNode *hp,  *tp ;  }ptr; 
// ptr�Ǳ����ָ����prt.hp��ptr.tp�ֱ�ָ���ͷ�ͱ�β(��ͷ֮�������Ԫ��)
   };
 }*GList;                       // ���������

void InitGList(GList &GL)
 { // �����յĹ����GL
   GL=NULL;
 }// InitGList

void sever(DSqString &str,DSqString &hstr)  
 { // ����ȥ������ŵķǿմ�str�ָ�������֣�hstrΪ��һ��','֮ǰ���Ӵ���
    //strΪ֮����Ӵ�
   int n,k=0,i=-1;                   // k����δ��Ե������Ÿ���
   char ch;
   n=StrLength_Sq(str);               // nΪ��str�ĳ���
   DSqString sub,temp;
   StrAssign_Sq(sub,"");               // ��ʼ��sub
   StrAssign_Sq(temp,"");               // ��ʼ��temp
   do                                   // ���������(k=0ʱ)�ĵ�1������
   { i++;
	 SubString_Sq(str,sub,i,1); 
     ch=sub.str[0];                     // chΪ��str�ĵ�i+1���ַ� 
     if(ch=='(')       ++k;             // ��δ��Ե������Ÿ���+1
     else if(ch==')')    --k;           // ��δ��Ե������Ÿ���-1
   }while(i<n&&ch!=','||k!=0);          // iС�ڴ�����ch����������','
   if(i<n)                               // ��str�д���������','�����ǵ�i���ַ�
   { SubString_Sq(str,hstr,0,i);         // hstr���ش�str','ǰ���ַ�
     SubString_Sq(str,temp,i+1,n-i-1);   // str���ش�str','����ַ�
     StrCopy_Sq(str,temp);
   }
   else                                  // ��str�в�����','
   { StrCopy_Sq(hstr,str);               // ��hstr���Ǵ�str
     DestroyString_Sq(str);              // ','�����ǿմ�
   }
 }// sever

void CreateGList(GList &GL,DSqString S) 
 { // ����ͷβ����洢�ṹ���ɹ�������д��ʽ��S���������GL����emp="()"
   DSqString sub,hsub,emp;
   GList p,q;
   StrAssign_Sq(sub,"");                      // ��ʼ��sub
   StrAssign_Sq(hsub,"");                     // ��ʼ��hsub
   StrAssign_Sq(emp,"()");                    // �մ�emp="()"
   if(!StrCompare_Sq(S,emp)) // S="()"
	   GL=NULL;                               // �����ձ�
   else                                       // S���ǿմ�
   { if(!(GL=(GList)malloc(sizeof(GLNode))))  // ������
       exit(1);
     if(StrLength_Sq(S)==1) // SΪ��ԭ�ӣ��������ֻ������ڵݹ������
     { GL->tag=ATOM;                          // ������ԭ�ӹ����
       GL->data=S.str[0];                     // ��ԭ�ӵ�ֵΪ�ַ���
     }
     else                                     // SΪ��
     { GL->tag=LIST;                          // GL���ӱ�
       p=GL;                                  // pҲָ���ӱ�
       SubString_Sq(S,sub,1,StrLength_Sq(S)-2);
       // ���������(ȥ����1���ַ�(������)�����1���ַ�(������))����sub
       do                                     // �ظ���n���ӱ�
       { sever(sub,hsub); // ��sub�з������ͷ����hsub�����ಿ��(��β)��sub
         CreateGList(p->ptr.hp,hsub);          // �ݹ鴴����ͷ����ʾ���ӱ�
         q=p;                                  // qָ��p��ָ���
         if(sub.length)                        // ��β����
         { if(!(p=(GLNode*)malloc(sizeof(GLNode)))) // ��p��������
             exit(1);
           p->tag=LIST;                             // p���ӱ�
           q->ptr.tp=p; // p��ָ������q��ָ���֮���γ�q����һ�����
         }
       }while(sub.length);                         // ����β����
       q->ptr.tp=NULL;                              // �������һ����βָ��Ϊ��
     }
   }
 }// CreateGList

void CopyGList(GList &T,GList GL)
 {      // ����ͷβ����洢�ṹ���ɹ����GL���Ƶõ������T
   if(!GL)                                       // ���ƿձ�
     T=NULL;
   else                                          // �����GL����
   { T=(GList)malloc(sizeof(GLNode));            // ������
     if(!T)
       exit(1);
     T->tag=GL->tag;                             // ���Ʊ�־��
     if(GL->tag==ATOM)                           // ��ԭ��
       T->data=GL->data;                         // ���Ƶ�ԭ��
     else // �ӱ�
     { CopyGList(T->ptr.hp,GL->ptr.hp);          // �ݹ鸴�Ʊ�ͷ�ӱ�
       CopyGList(T->ptr.tp,GL->ptr.tp); // �ݹ鸴�Ʊ�β(����ͷ֮��Ĳ���)�ӱ�
     }
   }
 }// CopyGList

int GListLength(GList GL)
 {     // ���ع����GL�ĳ��ȣ���Ԫ�ظ���
   int len=0;                            // ���ù�����ȵĳ�ֵΪ0
   while(GL)                             // δ����β
   { GL=GL->ptr.tp;                      // GLָ��������������һ��Ԫ��
     len++;                              // ��+1
   }
   return len;
 }// GlistLength

int GListDepth(GList GL)
 { // ����ͷβ����洢�ṹ��������GL����ȣ���������ֵ
   int dep,max=0;
   GList pp;
   if(!GL)                                         // �����GLΪ��
     return 1;                      // �ձ����Ϊ1
   if(GL->tag==ATOM)                // ��ԭ�ӽ��
     return 0;                      // ԭ�����Ϊ0��ֻ������ڵݹ������
   for(pp=GL;pp;pp=pp->ptr.tp)      // �ӱ���ĵ�1��Ԫ�ص����һ��Ԫ��
   { dep=GListDepth(pp->ptr.hp);    // �ݹ�����pp->ptr.hpΪͷָ����ӱ����
     if(dep>max)
       max=dep;                     // max�汾���ӱ���ȵ����ֵ
   }
   return max+1;                    // �ǿձ������Ǹ�Ԫ�ص���ȵ����ֵ��1
 }// GlistDepth

bool GListEmpty(GList GL)
 { // �ж�������Ƿ�Ϊ��
   if(!GL)
     return true;
   else
     return false;
 }// GlistEmpty

GList GetHead(GList GL)
 { // ���ɹ����GL�ı�ͷԪ�أ�����ָ�����Ԫ�ص�ָ��
   GList h;
   if(!GL)                                // �ձ��ޱ�ͷ
     return NULL;
   CopyGList(h,GL->ptr.hp);               // ��GL�ı�ͷԪ�ظ��Ƹ�h
   return h;
 }// GetHead

GList GetTail(GList GL)
 { // �������GL�ı�β(����ͷ֮��Ĳ���)����Ϊ���������ָ������¹�����ָ��
   GList t;
   if(!GL)                                     // �ձ��ޱ�β
     return NULL;
   CopyGList(t,GL->ptr.tp);                     // ��L�ı�βԪ�ظ��Ƹ�t
   return t;
 }// GetTail

void InsertFirst_GL(GList &GL,GList e)
 { // ��Ԫ��e(Ҳ�������ӱ�)��Ϊ�����GL�ĵ�1��Ԫ��(��ͷ)����
   GList p=(GList)malloc(sizeof(GLNode));        // �����µı�ͷ���
   if(!p)
     exit(1);
   p->tag=LIST;                                  // �����GL�������Ǳ�
   p->ptr.hp=e;                                  // GL�ı�ͷָ��ָ��e
   p->ptr.tp=GL;                                 // GL�ı�βָ��ָ��ԭ��GL
   GL=p;                                         // GLָ���µı�ͷ���
 }// InsertFirst_GL

void DeleteFirst_GL(GList &GL,GList &e)
 { // ɾ�������GL�ĵ�1��Ԫ��(��ͷ)������e������ֵ
   GList p=GL;                           // pָ���1������
   e=GL->ptr.hp;                         // eָ��GL�ı�ͷԪ��
   GL=GL->ptr.tp;                        // GLָ��ԭGL�ı�β(����ͷ֮��Ĳ���)
   free(p);                              // �ͷ�p��ָ�ı���
 }// DeleteFirst_GL

void Traverse_GL( GList GL) 
{   // ���õݹ��㷨���������GL
   GList p;   
if(!GL)cout<<"()";                         // ����ձ�
   else{
       if(GL->tag==ATOM)cout<<GL->data;       // ���ԭ��
       else{
            cout<<'(';                       // ���������������
            p=GL;  
            while(p){
              Traverse_GL(p->ptr.hp);         // �����i������Ԫ��  
              p=p->ptr.tp; 
              if(p)cout<<',';                // ��β����ʱ�������
             }
         cout<<')';                           // ���������������
     }
}
}// Traverse_GL

void DestroyGList(GList &GL)
 { // ���������GL
   GList q1,q2;
   if(GL)                               // �����GL����
   { if(GL->tag==LIST)                  // Ҫɾ�����Ǳ���
     { q1=GL->ptr.hp;                   // q1ָ���ͷ
       q2=GL->ptr.tp;                   // q2ָ���β(����ͷ֮������ಿ��)
       DestroyGList(q1);                // �ݹ����ٱ�ͷ
       DestroyGList(q2);                // �ݹ����ٱ�β
     }
     free(GL);               // �ͷ�GL��ָ�Ĵ洢�ռ�(����GL�Ǳ��㻹��ԭ�ӽ��)
     GL=NULL;                  // GL�ÿ�
   }
 }// DestroyGList
