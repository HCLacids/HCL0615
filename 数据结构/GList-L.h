 enum ElemTag{ATOM,LIST};
 // ATOM==0��ԭ��,LIST==1���ӱ�
 typedef struct GLNode
 { ElemTag tag; // �������֣���������ԭ�ӽ��ͱ���
   union // ԭ�ӽ��ͱ�������ϲ���
   { ElemType data; // data��ԭ�ӽ���ֵ��dataType���û�����
     struct
     { GLNode *hp,*tp;
     }ptr; // ptr�Ǳ����ָ����prt.hp��ptr.tp�ֱ�ָ���ͷ�ͱ�β(��ͷ֮�������Ԫ��)
   };
 }*GList,GLNode; // ���������

 void sever(DSqString &str,DSqString &hstr)  
 { // ����ȥ������ŵķǿմ�str�ָ�������֣�hstrΪ��һ��','֮ǰ���Ӵ���strΪ֮����Ӵ�
   int n,k=0,i=-1; // k����δ��Ե������Ÿ���
  char ch;
   n=StrLength_Sq(str); // nΪ��str�ĳ���
   DSqString sub,temp;
   StrAssign_Sq(sub,"");   // ��ʼ��sub
   StrAssign_Sq(temp,"");   // ��ʼ��temp
   do // ���������(k=0ʱ)�ĵ�1������
   { 
     i++;
	 SubString_Sq(str,sub,i,1); 
     ch=sub.str[0];           // chΪ��str�ĵ�i+1���ַ� 
     if(ch=='(')       ++k; // ��δ��Ե������Ÿ���+1
     else if(ch==')')    --k; // ��δ��Ե������Ÿ���-1
   }while(i<n&&ch!=','||k!=0); // iС�ڴ�����ch����������','
   if(i<n) // ��str�д���������','�����ǵ�i���ַ�
   { SubString_Sq(str,hstr,0,i); // hstr���ش�str','ǰ���ַ�
     SubString_Sq(str,temp,i+1,n-i-1); // str���ش�str','����ַ�
     StrCopy_Sq(str,temp);
   }
   else // ��str�в�����','
   { StrCopy_Sq(hstr,str); // ��hstr���Ǵ�str
     DestroyString_Sq(str); // ','�����ǿմ�
   }
 }

 void InitGList(GList &L)
 { // �����յĹ����L
   L=NULL;
 }

 void CreateGList(GList &L,DSqString S) 
 { // ����ͷβ����洢�ṹ���ɹ�������д��ʽ��S���������L����emp="()"
   DSqString sub,hsub,emp;
   GList p,q;
   StrAssign_Sq(sub,"");   // ��ʼ��sub
   StrAssign_Sq(hsub,"");   // ��ʼ��hsub
   StrAssign_Sq(emp,"()"); // �մ�emp="()"
   if(!StrCompare_Sq(S,emp)) // S="()"
	   L=NULL; // �����ձ�
   else // S���ǿմ�
   { if(!(L=(GList)malloc(sizeof(GLNode)))) // ������
       exit(1);
     if(StrLength_Sq(S)==1) // SΪ��ԭ�ӣ��������ֻ������ڵݹ������
     { L->tag=ATOM; // ������ԭ�ӹ����
       L->data=S.str[0]; // ��ԭ�ӵ�ֵΪ�ַ���
     }
     else // SΪ��
     { L->tag=LIST; // L���ӱ�
       p=L; // pҲָ���ӱ�
       SubString_Sq(S,sub,1,StrLength_Sq(S)-2);
       // ���������(ȥ����1���ַ�(������)�����1���ַ�(������))����sub
       do // �ظ���n���ӱ�
       { 
		 sever(sub,hsub); // ��sub�з������ͷ����hsub�����ಿ��(��β)��sub
         CreateGList(p->ptr.hp,hsub); // �ݹ鴴����ͷ����ʾ���ӱ�
         q=p; // qָ��p��ָ���
         if(sub.length) // ��β����
         { if(!(p=(GLNode*)malloc(sizeof(GLNode)))) // ��p��������
             exit(1);
           p->tag=LIST; // p���ӱ�
           q->ptr.tp=p; // p��ָ������q��ָ���֮���γ�q����һ�����
         }
       }while(sub.length); // ����β����
       q->ptr.tp=NULL; // �������һ����βָ��Ϊ��
     }
   }
   
 }

  void CopyGList(GList &T,GList L)
 { // ����ͷβ����洢�ṹ���ɹ����L���Ƶõ������T
   if(!L) // ���ƿձ�
     T=NULL;
   else // �����L����
   { T=(GList)malloc(sizeof(GLNode)); // ������
     if(!T)
       exit(1);
     T->tag=L->tag; // ���Ʊ�־��
     if(L->tag==ATOM) // ��ԭ��
       T->data=L->data; // ���Ƶ�ԭ��
     else // �ӱ�
     { CopyGList(T->ptr.hp,L->ptr.hp); // �ݹ鸴�Ʊ�ͷ�ӱ�
       CopyGList(T->ptr.tp,L->ptr.tp); // �ݹ鸴�Ʊ�β(����ͷ֮��Ĳ���)�ӱ�
     }
   }
 }

 int GListLength(GList L)
 { // ���ع����ĳ��ȣ���Ԫ�ظ���
   int len=0; // ���ù�����ȵĳ�ֵΪ0
   while(L) // δ����β
   { L=L->ptr.tp; // Lָ��������������һ��Ԫ��
     len++; // ��+1
   }
   return len;
 }

 int GListDepth(GList L)
 { // ����ͷβ����洢�ṹ��������L�����
   int dep,max=0;
   GList pp;
   if(!L) // �����LΪ��
     return 1; // �ձ����Ϊ1
   if(L->tag==ATOM) // ��ԭ�ӽ��
     return 0; // ԭ�����Ϊ0��ֻ������ڵݹ������
   for(pp=L;pp;pp=pp->ptr.tp) // �ӱ���ĵ�1��Ԫ�ص����һ��Ԫ��
   { dep=GListDepth(pp->ptr.hp); // �ݹ�����pp->ptr.hpΪͷָ����ӱ����
     if(dep>max)
       max=dep; // max�汾���ӱ���ȵ����ֵ
   }
   return max+1; // �ǿձ������Ǹ�Ԫ�ص���ȵ����ֵ��1
 }

 bool GListEmpty(GList L)
 { // �ж�������Ƿ�Ϊ��
   if(!L)
     return true;
   else
     return false;
 }

 GList GetHead(GList L)
 { // ���ɹ����L�ı�ͷԪ�أ�����ָ�����Ԫ�ص�ָ��
   GList h;
   if(!L) // �ձ��ޱ�ͷ
     return NULL;
   CopyGList(h,L->ptr.hp); // ��L�ı�ͷԪ�ظ��Ƹ�h
   return h;
 }

 GList GetTail(GList L)
 { // �������L�ı�β(����ͷ֮��Ĳ���)����Ϊ���������ָ������¹�����ָ��
   GList t;
   if(!L) // �ձ��ޱ�β
     return NULL;
   CopyGList(t,L->ptr.tp); // ��L�ı�βԪ�ظ��Ƹ�t
   return t;
 }

 void InsertFirst_GL(GList &L,GList e)
 { // ��ʼ�����������L���ڡ��������������Ԫ��e(Ҳ�������ӱ�)��Ϊ�����L�ĵ�1��Ԫ��(��ͷ)
   GList p=(GList)malloc(sizeof(GLNode)); // �����µı�ͷ���
   if(!p)
     exit(1);
   p->tag=LIST; // �����L�������Ǳ�
   p->ptr.hp=e; // L�ı�ͷָ��ָ��e
   p->ptr.tp=L; // L�ı�βָ��ָ��ԭ��L
   L=p; // Lָ���µı�ͷ���
 }

 void DeleteFirst_GL(GList &L,GList &e)
 { // ��ʼ�����������L���ڡ����������ɾ�������L�ĵ�1��Ԫ��(��ͷ)������e������ֵ
   GList p=L; // pָ���1������
   e=L->ptr.hp; // eָ��L�ı�ͷԪ��
   L=L->ptr.tp; // Lָ��ԭL�ı�β(����ͷ֮��Ĳ���)
   free(p); // �ͷ�p��ָ�ı���
 }

void Traverse_GL( GList LS) 
{ // ���õݹ��㷨���������L
    GList p;   
	if(!LS)cout<<"()";                        // ����ձ�
       else{
	     if(LS->tag==ATOM)cout<<LS->data;    // ���ԭ��
	     else{
	            cout<<'(';                   // ���������������
                    p=LS;	  
         	    while(p){
	                 Traverse_GL(p->ptr.hp); // �����i������Ԫ��  
	                 p=p->ptr.tp; 
	                 if(p)cout<<',';         // ��β����ʱ�������
	             }
	            cout<<')';                   // ���������������
		  }
	}
}// Traverse_GL

void Traverse_GL1(GList L)
 { // ���õݹ��㷨���������L
   if(L) // L����
     if(L->tag==ATOM) // LΪ��ԭ��
       cout<<L->data;
     else // LΪ�����
     { Traverse_GL1(L->ptr.hp); // �ݹ����L�ı�ͷ
       Traverse_GL1(L->ptr.tp); // �ݹ����L�ı�β
     }
 }

 void DestroyGList(GList &L)
 { // ���ٹ����L
   GList q1,q2;
   if(L) // �����L����
   { if(L->tag==LIST) // Ҫɾ�����Ǳ���
     { q1=L->ptr.hp; // q1ָ���ͷ
       q2=L->ptr.tp; // q2ָ���β(����ͷ֮������ಿ��)
       DestroyGList(q1); // �ݹ����ٱ�ͷ
       DestroyGList(q2); // �ݹ����ٱ�β
     }
     free(L); // �ͷ�L��ָ�Ĵ洢�ռ�(����L�Ǳ��㻹��ԭ�ӽ��)
     L=NULL; // L��ָ���κδ洢��Ԫ
   }
 }