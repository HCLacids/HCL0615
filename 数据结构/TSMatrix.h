# define MAX_SIZE 100          // ����Ԫ�ظ��������ֵ
typedef struct  {
 int  i;             // ���±�
 int  j;             // ���±�
 ElemType  e;        // ����Ԫ��ֵ
}Triple;             // ��Ԫ�鶨��
typedef struct {
   int m,n,t;                  // ���������������������Ԫ�ظ���
Triple data[MAX_SIZE];      // ����Ԫ��Ԫ���
 }TSMatrix;                    // ��Ԫ��˳�������
int comp(int c1,int c2)
{
	if(c1<c2) return -1;
	   else if(c1==c2)  return 0;
	        else  return 1;
}
bool CreateSMatrix(TSMatrix &M)
 { // ����ϡ�����M
   int i;
   Triple T;
   bool k;
   cout<<"��������������,����,����Ԫ�ظ�����";
   cin>>M.m>>M.n>>M.t;
   if(M.t>MAX_SIZE)                          // ����Ԫ����̫��
     return false;
   M.data[0].i=0;     // Ϊ�Ƚ���������е�˳����׼��
   M.data[0].j=0;
   for(i=0;i<M.t;i++) // ��������M.t������Ԫ��
   { do
     { cout<<"�밴����˳�������"<<i+1<<"������Ԫ�����ڵ���(0��"<<M.m-1<<"),��(0��"<<M.n-1<<"),Ԫ��ֵ��";
       cin>>T.i>>T.j>>T.e;
       k=0; // ����ֵ�ķ�Χ��ȷ�ı�־
       if(T.i<0||T.i>=M.m||T.j<0||T.j>=M.n) // �л��г�����Χ
         k=1;
	    if(i>0)
        if(T.i<M.data[i-1].i||T.i==M.data[i-1].i&&T.j<=M.data[i-1].j)
         k=1; // �л��е�˳���д� 
	  }while(k); // ����ֵ�ķ�Χ����ȷ����������
     M.data[i]=T; // ��������ȷ��ֵ������Ԫ��ṹ��M����Ӧ��Ԫ
   }
   return true;
 }

void CopySMatrix(TSMatrix M,TSMatrix &T)
 { // ��ϡ�����M���Ƶõ�T
   T=M;
 }

 bool AddSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q)
 { // ��ϡ�����ĺ�Q=M+N
   int m=0,n=0,q=0,i=0;
   if(M.m!=N.m||M.n!=N.n) // M��N��ϡ������л�������ͬ
     return false;
   Q.m=M.m; // ����ϡ�����Q������������
   Q.n=M.n;
   while(m<M.t&&n<N.t) // ����M��N��Ԫ�ض�δ������
    switch(comp(M.data[m].i,N.data[n].i)) // �Ƚ�����ǰԪ�ص���ֵ��ϵ
     { case -1:Q.data[q++]=M.data[m++]; // ����M����ֵС����M�ĵ�ǰԪ��ֵ��������Q
	           break;
       case  0:switch(comp(M.data[m].j,N.data[n].j))
               { // M��N����ǰԪ�ص���ֵ��ȣ������Ƚ�����ǰԪ�ص���ֵ��ϵ
                 case -1:Q.data[q++]=M.data[m++]; // ����M����ֵС����M��ֵ��������Q 
					     break;
                 case  0:// M��N����ǰ����Ԫ�ص����о���ȣ�����Ԫ��ֵ��Ͳ���������Q
                         Q.data[q]=M.data[m++];
						 Q.data[q].e+=N.data[n++].e;
						 q++;
				         if(Q.data[q].e==0) // ��Ԫ��ֵ֮��Ϊ0��������ϡ�����
                           q--;
						 break;
                 case  1:Q.data[q++]=N.data[n++]; // ����N����ֵС����N��ֵ��������Q
               }
		   	   break;
       case  1:Q.data[q++]=N.data[n++]; // ����N����ֵС����N�ĵ�ǰԪ��ֵ��������Q
     } // ����2��ѭ�����ִ��1��
   while(m<M.t) // ����N��Ԫ����ȫ��������ϣ���������M��Ԫ��
     Q.data[q++]=M.data[m++];
   while(n<N.t) // ����M��Ԫ����ȫ��������ϣ���������N��Ԫ��
	  Q.data[q++]=N.data[n++];
   if(q>MAX_SIZE) // ����Ԫ�ظ���̫��
     return false;
   Q.t=q; // ����Q�ķ���Ԫ�ظ���
   return true;
 }

 bool SubtSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q)
 { // ��ϡ�����Ĳ�Q=M-N
   int i;
   if(M.m!=N.m||M.n!=N.n) // M��N��ϡ������л�������ͬ
     return false;
   for(i=0;i<N.t;++i) // ����N��ÿһԪ�أ���ֵ����-1
     N.data[i].e*=-1;
     AddSMatrix(M,N,Q); // Q=M+(-N)
    return true;
 }

void TransposeSMatrix(TSMatrix M,TSMatrix &T)
 { // ��ϡ�����M��ת�þ���T
   int p,col,q=0; // qָʾת�þ���T�ĵ�ǰԪ�أ���ֵΪ1
   T.m=M.n; // ����T������=����M������
   T.n=M.m; // ����T������=����M������
   T.t=M.t; // ����T�ķ���Ԫ�ظ���=����M�ķ���Ԫ�ظ���
   if(T.t) // ����ǿ�
     for(col=0;col<M.n;++col) // �Ӿ���T���±�Ϊ0���е����һ��
       for(p=0;p<M.t;++p) // ���ھ���M������Ԫ��
         if(M.data[p].j==col) // ��Ԫ�ص�����=��ǰ����T������
         { T.data[q].i=M.data[p].j; // ������M��ֵ���жԵ�����T�ĵ�ǰԪ��
           T.data[q].j=M.data[p].i;
           T.data[q++].e=M.data[p].e; // ת�þ���T�ĵ�ǰԪ��ָ��+1
         }
 }

 bool MultSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q)
 { // ��ϡ�����ĳ˻�Q=M��N
   int i,j,q,p;
   ElemType Qs; // ����ԪQ[i][j]����ʱ��Ŵ�
   TSMatrix T; // N��ת�þ���
   if(M.n!=N.m) // ����M��N�޷����
     return false;
   Q.m=M.m; // Q������=M������
   Q.n=N.n; // Q������=N������
   Q.t=0; // Q�ķ���Ԫ�ظ����ĳ�ֵΪ0
   TransposeSMatrix(N,T); // T��N��ת�þ���
   for(i=0;i<Q.m;i++) // ����M��ÿһ�У���Q[i][]
   { q=0; // qָ��T�ĵ�1������Ԫ��
     for(j=0;j<T.m;j++) // ����T��ÿһ��(��N��ÿһ��)����Q[i][j]
     { Qs=0; // ����Q[i][j]�ĳ�ֵΪ0
       p=0; // pָ��M�ĵ�1������Ԫ��
       while(M.data[p].i<i) // ʹpָ�����M�ĵ�i�еĵ�1������Ԫ��
         p++;
       while(T.data[q].i<j) // ʹqָ�����T�ĵ�j��(������N�ĵ�j��)�ĵ�1������Ԫ��
         q++;
       while(p<M.t&&q<T.t&&M.data[p].i==i&&T.data[q].i==j)
       // [p]����M�ĵ�i�еķ���Ԫ����[q]����T�ĵ�j��(��N�ĵ�j��)�ķ���Ԫ��
         switch(comp(M.data[p].j,T.data[q].j))
         { // �Ƚ�M����ǰԪ�ص���ֵ��T����ǰԪ�ص���ֵ(��N����ǰԪ�ص���ֵ)
           case -1:p++; // M����ǰԪ�ص���ֵ<T(N)����ǰԪ�ص���(��)ֵ��p�����
                   break;
           // M��ǰԪ�ص���ֵ=T(N)��ǰԪ�ص���(��)ֵ������ֵ��˲��ۼӵ�Qs��p��q�������
           case  0:Qs+=M.data[p++].e*T.data[q++].e;
                   break;
           case  1:q++; // M����ǰԪ�ص���ֵ>T(N)����ǰԪ�ص���(��)ֵ��q�����
         }
       if(Qs) // Q[i][j]��Ϊ0
       { if(++Q.t>MAX_SIZE) // Q�ķ���Ԫ�ظ���+1���������Ԫ�ظ���̫��
           return false;
         Q.data[Q.t-1].i=i; // ��Q[i][j]��˳�����ϡ�����Q
         Q.data[Q.t-1].j=j;
         Q.data[Q.t-1].e=Qs;
       }
     }
   }
   return true;
 }

 void TraverseSMatrix(TSMatrix M)
 { // ��������ʽ���M
   int i,j,k=1; // ����Ԫ����������ֵΪ1
   Triple *p=M.data; // pָ��M�ĵ�1������Ԫ��
   for(i=0;i<M.m;i++) // �ӵ�1�е����һ��
   { for(j=0;j<M.n;j++) // �ӵ�1�е����һ��
       if(k<=M.t&&p->i==i&&p->j==j) // pָ�����Ԫ����p��ָԪ��Ϊ��ǰѭ���ڴ���Ԫ��
       { cout<<(p++)->e;   // ���p��ָԪ�ص�ֵ��pָ����һ��Ԫ��
         k++; // ������+1
       }
       else // p��ָԪ�ز��ǵ�ǰѭ���ڴ���Ԫ��
         cout<<0; // ���0
     cout<<endl;
   }
 } 

  void DestroySMatrix(TSMatrix &M)
 { // ����ϡ�����M
   M.m=M.n=M.t=0;
 }
