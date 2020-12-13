typedef struct Node {
 ElemType data;
struct  Node *next;
}LNode,*LinkList;                 // LinkListΪ�ṹ��ָ������

void InitList_L(LinkList &L)
    {  
L=(LNode *)malloc(sizeof(LNode));  // ������һ�������������Ҫ�����ڿռ�
if(!L)   exit(1);                        // �洢����ʧ��
       L->next=NULL;                            // ��ͷ����ָ�����ÿ�
}// InitList_L

int ListLength_L( LinkList L ) 
{     // LΪ��ͷ����������ͷָ�룬����������L��ָ�����ĳ���
  LinkList  p;
int k=0;
p=L->next;                             // pָ�������еĵ�һ�����
  while(p) 
   {  k++;  p=p->next;                 // k�Ʒǿս����
   }
  return k;
}// ListLength_L

LNode *LocateElem_L( LinkList L,ElemType e) 
{  // ��L��ָ�ĵ������в��ҵ�һ��ֵ��e ��ȵĽ�㣬�����ڣ��򷵻���ָ�룻
// ���򷵻ؿ�ָ��
  LinkList  p;                           
  p=L->next;                               // pָ�������еĵ�һ�����
   while (p&&p->data!=e ) p=p->next;
  return p;
}// LocateElem_L

bool ListInsert_L( LinkList &L, int i, ElemType e) 
{    //�ڴ���ͷ���ĵ�����L�еĵ�i�����֮ǰ����Ԫ��e
LinkList p,s;
  int j;
  p=L;  j=0;
  while(p->next&&j<i-1)  { p=p->next; j++; }   // Ѱ�ҵ�i-1�����,����pָ��˽��
  if(j!=i-1)   return false;                   // i��λ�ò�����
  if((s=(LNode *)malloc(sizeof(LNode)))==NULL) exit(1);  // �洢����ʧ��
  s->data=e;  
  s->next=p->next;  p->next=s;                  // �����½��
  return true;
 }// ListInsert_L

bool ListDelete_L( LinkList &L, int i, ElemType &e) 
{    // ɾ������ͷ���ĵ�����L�еĵ�i����㣬����e������ֵ
LinkList p,q;
  int j;
  p=L;  j=0;
 while(p->next->next&&j<i-1){ p=p->next; j++; } //Ѱ�ҵ�i-1�����,����pָ��˽��
  if(j!=i-1)   return false;                     // i��λ�ò�����
  q=p->next;                                     // qָ������
p->next=q->next;                               // ɾ��q��ָ���
e=q->data;    free(q);
  return true;
 }// ListDelete_L

bool GetElem_L(LinkList L,int i, ElemType &e)
{    // ȡ��������L�е�i��Ԫ�أ�����e������ֵ
LinkList p;
  int j;
  p=L;  j=0;
while(p->next&&j<i){ p=p->next; j++; }  // Ѱ�ҵ�i�����,����pָ��˽��
  if(j!=i)   return false;                      // i��λ�ò�����
  e=p->data;                                     // ��ȡԪ�ص�ֵ����e
  return true;
 }// GetElem_L

void CreateList_L_Rear(LinkList &L,ElemType a[],int n ) 
{   // ��֪һά����A[n]�д������Ա�������Ԫ�أ�����β�巨����������L
   LinkList p,q;   int i;
	  L=(LinkList)malloc(sizeof(LNode));    // ������ͷ���
q=L;                                // qʼ��ָ��β��㣬��ʼʱβ���Ҳ��ͷ���
for(i=0;i<n;i++) 
{  p=(LinkList)malloc(sizeof(LNode));          // �����½��
       p->data=a[i];                               // ��Ԫ��ֵ
       q->next=p;                                  // ������β���֮��
       q=p;                                         // qָ���µı�β
     }
   q->next=NULL;                                    // ��β���next���ÿ�
}// CreateList_L_Rear

void CreateList_L_Front(LinkList &L,ElemType a[],int n ) 
{    // ��֪һά����A[n]�д������Ա�������Ԫ�أ�����ͷ�巨����������L
   LinkList p;   int i;
L=(LinkList)malloc(sizeof(LNode));              //������ͷ���
L->next=NULL;                               
for(i=n-1;i>=0;i--)   
{    p=(LinkList)malloc(sizeof(LNode));           //�����½��
        p->data=a[i];                                // ��Ԫ��ֵ
        p->next=L->next;                          // ������ͷ���͵�һ�����֮��
       L->next=p;                                         
      }
}// CreateList_L_Front

void ListTraverse_L(LinkList L)
{
 LinkList p=L->next;
 while(p)
  {  std::cout<<p->data;
     p=p->next;
  }
}// ListTraverse_L

void DestroyList_L(LinkList &L )
{
  LinkList p,p1;
  p=L;
  while(p) 
  { p1=p;
    p=p->next;
    free(p1);
   }
   L=NULL;
 }// DestroyList_L
