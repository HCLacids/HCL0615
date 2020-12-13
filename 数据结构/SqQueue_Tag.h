# define QUEUE_INIT_SIZE  100             // 循环队列(默认的)的初始分配最大容量
# define QUEUEINCREMENT  10               // (默认的)增补空间量
typedef struct {
    ElemType  *queue;                      // 存储数据元素的一维数组
    int front;                             // 队首指针，指向队首元素
    int rear;                              // 队尾指针，指向队尾元素的下一个位置
    int queuesize;                         // 循环队列当前的最大容量
    int incrementsize;	  
    int tag;                               // 增补空间量
} SqQueue_Tag;

void InitQueue_Sq_Tag(SqQueue_Tag &Q, int maxsize=QUEUE_INIT_SIZE,
                  int incresize=QUEUEINCREMENT  ) 
{
    Q.queue=(ElemType*)malloc(maxsize*sizeof(ElemType)); //为循环队列分配空间；
    if(!Q.queue) exit(1);
    Q.front=0;
    Q.rear=-1;
    Q.queuesize=maxsize;
    Q.incrementsize=incresize;
    Q.tag=0;                         //将初始标志置为0；
}                                   //含有标志位的循环队列的初始化；



bool EnQueue_tag(SqQueue_Tag &Q, ElemType e)

{
    if(Q.rear==Q.front&&Q.tag==1)//队满，给循环队列增补空间
{
Q.queue=(ElemType*)realloc(Q.queue,(Q.queuesize+Q.incrementsize)*sizeof(ElemType));
    if(!Q.queue)return false;       
    
    if(Q.front>Q.rear)                            // 队尾指针在队首指针前面，重新确定队首指针的位置
    {  for(int i=Q.queuesize-1;i>=Q.front;i--)   
        Q.queue[i+Q.incrementsize]=Q.queue[i];
        
        Q.front+=Q.incrementsize;          // 队首指针后移Q.incrementsize个位置
    }
    
    Q.queuesize+=Q.incrementsize;                // 队列容量增加Q.incrementsize

}
    
    Q.rear=(Q.rear+1) %Q.queuesize;
    Q.queue[Q.rear]=e;
    Q.tag=1;
    return true;

}



bool DeQueue_Sq_Tag(SqQueue_Tag &Q,ElemType &e)
{    // 删除队尾元素，并用e返回其值，成功删除返回true;否则返回false
    if(Q.front==Q.rear&&Q.tag==0)   return false;    // 队空,直接返回错误；
    e=Q.queue[Q.front];                  // 取出队首元素
    Q.front=(Q.front+1) %Q.queuesize;    // 队首指针顺时针移动一个位置
    Q.tag=0;                                
    return true;
}






