# queue

### 操作：

- push(x) 将x压入队列的末端

- pop() 弹出队列的第一个元素(队顶元素)，注意此函数并不返回任何值

- front() 返回第一个元素(队顶元素)

- back() 返回最后被压入的元素(队尾元素)

- empty() 当队列为空时，返回true

- size() 返回队列的长度

### 头文件：

```c++
#include <queue>
```

### 声明方法：

- queue<int>q;

- struct node

{   

  int x, y;

};

queue<node>q;



# Priority_queue

empty() 如果队列为空返回真

pop() 删除对顶元素

push() 加入一个元素

size() 返回优先队列中拥有的元素个数

top() 返回优先队列对顶元素

 struct cmp {

​    bool operator () (P& a, P& b) {

​        return a.m > b.m;

​    }

};



# stack

empty() 如果队列为空返回真

pop() 删除对顶元素

push() 加入一个元素

size() 返回优先队列中拥有的元素个数

top() 返回优先队列对顶元素