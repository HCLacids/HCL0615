typedef struct BiTNode {
  TElemType data;                            // ����ֵ
  struct BiTNode *lchild;                    // ����ָ��
  struct BiTNode *rchild;                    // �Һ���ָ��
}BiTNode,*BiTree;

void PreOrderBiTree(BiTree BT,void Visit(TElemType))
 {     // ����ݹ����������BT
   if(BT)                                        // BT����
   { Visit(BT->data);                            // �ȷ��ʸ����
     if(BT->lchild)PreOrderBiTree(BT->lchild,Visit);           // ���������������
     if(BT->rchild)PreOrderBiTree(BT->rchild,Visit);           // ����������������
   }
 }// PreOrderBiTree 
typedef BiTree ElemType;                // ����ջ�Ͷ���Ԫ��Ϊ��������ָ������
# include "SqStack.h"                   // ����˳��ջ���ݶ������������ز���

void NRPreOrderBiTree(BiTree BT,void Visit(TElemType))
 {      // ����ǵݹ����������BT(����ջ)
   SqStack S;
   InitStack_Sq(S,MAX_BITREE_SIZE,10);      // ��ʼ��ջS
   while(BT||!StackEmpty_Sq(S))             // ��BT���ջ���ջ����
   { if(BT)                                 // BT����
     { Visit(BT->data);                     // ���ʸ����
       Push_Sq(S,BT);                       //��ָ���ջ
       BT=BT->lchild;                       // BTָ��������
     }
     else                                   // ��ָ����ջ�����ʸ���㣬����������
     { Pop_Sq(S,BT);                        //��ָ���ջ
       BT=BT->rchild;                        // BTָ�����Һ���
     }
   }
 }// NRPreOrderBiTree

void InOrderBiTree(BiTree BT,void Visit(TElemType))
 {    // ����ݹ����������BT
   if(BT)                                  // BT����
   { InOrderBiTree(BT->lchild,Visit);      // ���������������
     Visit(BT->data);                      // �ٷ��ʸ����
     InOrderBiTree(BT->rchild,Visit);      // ����������������
   }
 }// InOrderBiTree

void NRInOrderBiTree(BiTree BT,void Visit(TElemType))
 {  // ����ǵݹ����������BT(����ջ)
  SqStack S;
  InitStack_Sq(S,MAX_BITREE_SIZE,10);        // ��ʼ��ջS
   while(BT||!StackEmpty_Sq(S))              // ��BT���ջ���ջ����
   { if(BT)                                  // BT����
     {                                       // ��ָ���ջ������������
       Push_Sq(S,BT);                        // ��ָ���ջ
       BT=BT->lchild;                        // BTָ��������
     }
     else                                    // ��ָ����ջ�����ʸ���㣬����������
     { Pop_Sq(S,BT);                         //��ָ���ջ
       Visit(BT->data);                      // ���ʸ����
       BT=BT->rchild;                        // BTָ�����Һ���
     }
   }
 }// NRInOrderBiTree 

void PostOrderBiTree(BiTree BT,void Visit(TElemType))
 {            // ����ݹ����������BT
   if(BT)                                       // BT����
   { PostOrderBiTree(BT->lchild,Visit);         // �Ⱥ������������
     PostOrderBiTree(BT->rchild,Visit);         // �ٺ������������
     Visit(BT->data); // �����ʸ����
   }
 }// PostOrderBiTree

void NRPostOrderBiTree(BiTree BT,void Visit(TElemType))
{   // ����ǵݹ����������BT(����ջ)
   SqStack S;
   InitStack_Sq(S,MAX_BITREE_SIZE,10);            // ��ʼ��ջS
   BiTree p,q;
   int flag;
   if (!BT)   return;
   p=BT;
   do
    { while(p)                                      // Ϊ�ǿն�����,�����ߵ���ͷ
      {  Push_Sq(S,p);                              // p��ջ
         p=p->lchild;                               // pָ��������
     }
     q=NULL; flag=1;
     while (!StackEmpty_Sq(S)&&flag)
     { GetTop_Sq(S,p);                          // ȡջ��Ԫ��
       if (p->rchild==q)                        // ���Һ��Ӳ����ڻ��ѷ��� 
       { Pop_Sq(S,p);                           //ջ��Ԫ�س�ջ
		 Visit(p->data);                        // ����p��ָ���
         q=p;                                   // qָ��ոշ��ʵĽ��
      }
     else
      { p=p->rchild;                            // pָ�����Һ���
        flag=0;
      }
     }
    } while (!StackEmpty_Sq(S));
   }// NRPostOrderBiTree

# include "SqQueue.h"              // ����ѭ���������ݶ������������ز���
void LevelOrderBiTree(BiTree BT,void Visit(TElemType))
 { // ����ݹ����BT(���ö���)
   SqQueue Q;
   BiTree p;
   if(BT) // BT����
   { InitQueue_Sq(Q,MAX_BITREE_SIZE,10);  // ��ʼ������Q
     EnQueue_Sq(Q,BT); // ��ָ�����
     while(!QueueEmpty_Sq(Q)) // ���в���
     { DeQueue_Sq(Q,p); // ����Ԫ��(ָ��)������p
       Visit(p->data); // ����p��ָ���
       if(p->lchild!=NULL) // p������
         EnQueue_Sq(Q,p->lchild); // ���p������
       if(p->rchild!=NULL) // p���Һ���
         EnQueue_Sq(Q,p->rchild); // ���p���Һ���
     }
   }
 }// LevelOrderBiTree

void InitBiTree(BiTree &BT)
 {          
   BT=NULL;
 }// InitBiTree 

void CreateBiTree(BiTree &BT)
{  // �������������������н���ֵ�����������BT������Nil��ʾ��(��)����
TElemType a;
cin>>a;                                         // �������ֵ
   if(a==Nil)                                        // ����ֵΪ��
	   BT=NULL;
   else                                              // ����ֵ��Ϊ��
   { BT=(BiTree)malloc(sizeof(BiTNode));             // ���ɸ����
     if(!BT)
       exit(1);
     BT->data=a;                                     // ��ֵ����T��ָ���
     CreateBiTree(BT->lchild);                       // �ݹ鹹��������
     CreateBiTree(BT->rchild);                       // �ݹ鹹��������
   }
}// CreateBiTree

bool BiTreeEmpty(BiTree BT)
 { 
   if(BT)
     return false;
   else
     return true;
 }// BiTreeEmpty

int BiTreeDepth(BiTree BT)
 { // �������BT�����,��������ֵ
   int Lh,Rh;
   if(!BT)
     return 0;                 // �������Ϊ0
   Lh=BiTreeDepth(BT->lchild); // LhΪ����������ȣ���������Ϊ�գ���LhΪ0
   Rh=BiTreeDepth(BT->rchild); // RhΪ����������ȣ���������Ϊ�գ���RhΪ0
   return Lh>Rh?Lh+1:Rh+1;     // BT�����Ϊ����������������еĴ���+1
 }// BiTreeDepth

BiTree SearchBiTree(BiTree BT,TElemType e)
 { // ���Ҷ�����BT��Ԫ��ֵΪe�Ľ�㣬���ҳɹ�������ָ�룬���򷵻ؿ�ָ��
   BiTree p;
   if(!BT)     return NULL;              // ����,����"��"
   if(BT->data==e) return BT;            // ���ҳɹ���������ָ��
   if(BT->lchild)                        // �������ǿ�
   {   p=SearchBiTree(BT->lchild,e);     // �ݹ����������
       if(p) return p;                   // ���ҳɹ�������p
   }
   if(BT->rchild)                        // �������ǿ�
   {   p=SearchBiTree(BT->rchild,e);      // �ݹ����������
       if(p)  return p;                   // ���ҳɹ�������p
   }
   return NULL;                           //����ʧ�ܣ�����NULL
}// SearchBiTree

BiTree Parent(BiTree BT,TElemType e)
 { // ��e��BT�ķǸ���㣬�򷵻�����˫�ף����򷵻�"��"
   SqQueue Q;
   BiTree p;
   if(BT)                                               // �ǿ���
   { InitQueue_Sq(Q,MAX_BITREE_SIZE,10);                // ��ʼ������Q
     EnQueue_Sq(Q,BT);                                  // ����ָ�����
     while(!QueueEmpty_Sq(Q))                           // �Ӳ���
     { DeQueue_Sq(Q,p);                                 // ���ӣ�����Ԫ�ظ�p
       if(p->lchild&&p->lchild->data==e||p->rchild&&p->rchild->data==e)
                                                        // �ҵ�e(��������Һ���)
         return p;                                      // ����e��˫��
       else                                             // δ�ҵ�e
       { if(p->lchild)                                  // p������
           EnQueue_Sq(Q,p->lchild);                     //����ָ�����
         if(p->rchild)                                  // p���Һ���
           EnQueue_Sq(Q,p->rchild);                     //�Һ���ָ�����
       }
     }
   }
   return NULL;                                     // ���ջ�δ�ҵ�e
 }// Parent

BiTree LeftChild(BiTree BT,TElemType e)
 { // ��e��BT��ĳ�����,�򷵻�e�����ӡ���e�����ӣ��򷵻�"��"
   BiTree p;
   if(BT)                                       // �ǿ���
   { p=SearchBiTree(BT,e);                      // p��ָ����e��ָ��
     if(p)                                      // BT�д��ڽ��e
       return p->lchild;                        // ����e������
   }
   return NULL;                                 // �����������"��"
 }// LeftChild

BiTree RightChild(BiTree BT,TElemType e)
 { // ��e��BT��ĳ�����,�򷵻�e���Һ��ӡ���e���Һ��ӣ��򷵻�"��"
   BiTree p;
   if(BT)                                       // �ǿ���
   { p=SearchBiTree(BT,e);                      // p��ָ����e��ָ��
     if(p)                                      // BT�д��ڽ��e
       return p->rchild;                        // ����e���Һ��ӵ�ֵ
   }
   return NULL;                                 // ����������ؿ�
 }// RightChild

BiTree LeftSibling(BiTree BT,TElemType e)
 { // ��e��BT��ĳ����㣬�򷵻�e�����ֵܡ���e��BT�����ӻ������ֵܣ��򷵻�"��"
   BiTree p;
   if(BT)                                            // �ǿ���
   { p=Parent(BT,e);                                 // pΪe��˫��
     if(p)                                           // �ҵ�e��˫��
       if(p->lchild&&p->rchild&&p->rchild->data==e)  // p�������Һ������Һ�����e
         return p->lchild;                           // ����p������(e�����ֵ�)
   }
   return NULL;                                      // ����������ؿ�
 }// LeftSibling

BiTree RightSibling(BiTree BT,TElemType e)
 { // ��e��BT��ĳ����㣬�򷵻�e�����ֵܡ���e��T���Һ��ӻ������ֵܣ��򷵻�"��"
   BiTree p;
   if(BT)                                            // �ǿ���
   { p=Parent(BT,e);                                 // pΪe��˫��
     if(p)                                           // �ҵ�e��˫��
       if(p->lchild&&p->rchild&&p->lchild->data==e)  // p�������Һ�����������e
         return p->rchild;                           // ����p���Һ���(e�����ֵ�)
   }
   return NULL;                                      // ����������ؿ�
 }// RightSibling

bool InsertChild(BiTree p,int LR,BiTree c)  
 { // ��������BT���ڣ�pָ��BT��ĳ����㣬����LR��ֵ��������c��Ϊp�ĺ���
   if(p)                               // p����
   { if(LR==0)                         // �Ѷ�����c��Ϊp��ָ����������
     { c->rchild=p->lchild;            // p��ָ����ԭ����������Ϊc��������
       p->lchild=c;                    // ������c��Ϊp��������
     }
     else                              // LR==1���Ѷ�����c��Ϊp��ָ����������
     { c->rchild=p->rchild;            // p��ָ����ԭ����������Ϊc��������
       p->rchild=c;                    // ������c��Ϊp��������
     }
     return true;
   }
   return false;                       // p��
 }// InsertChild

void PrintBiTree(BiTree BT,int n)
 {  // ���ð������ʽ���������,nΪ��������,��ֵΪ1
 int i;
 if(!BT)return;
PrintBiTree(BT->rchild,n+1);                  // �ڵ�n+1��ݹ��ӡ������
 for(i=2;i<n;++i)                              // ��ӡ�ո�
	 cout<<"      ";            
 if(n>1)cout<<"  - - -";                       // ��ӡ����
 cout<<BT->data<<endl;                         // ��ӡ������ֵ
 PrintBiTree(BT->lchild,n+1);                  // �ڵ�n+1��ݹ��ӡ������
}// PrintBiTree

void DestroyBiTree(BiTree &BT)
 { // ����������BT
   if(BT)                       // �ǿ���
   { DestroyBiTree(BT->lchild); // �ݹ鳷������������������������ִ���κβ���
     DestroyBiTree(BT->rchild); // �ݹ鳷������������������������ִ���κβ���
     free(BT);                  // �ͷŸ����
     BT=NULL;                   // BT�ÿ�
   }
 }// DestroyBiTree

bool DeleteChild(BiTree p,int LR) 
 { // ��������BT���ڣ�pָ��BT��ĳ����㣬����LR��ֵɾ��p������c
      if(p)                                   // p����
      { if(LR==0)                             // ɾ��������
           DestroyBiTree(p->lchild);          // ���p��ָ����������
         else                                  // ɾ��������
           DestroyBiTree(p->rchild);           // ���p��ָ����������
         return true;
      }
      return false;                             // p��
 }// DeleteChild
