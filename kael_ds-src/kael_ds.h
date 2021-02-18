extern const int True; // 真
extern const int False; // 假
extern const int ERR; // 空指针

//==============================线性表===================================

/*
 * =============================
 * =         动态数组          =
 * =============================
 */

// 动态数组结构体
struct DynamicArray
{
        void **paddr; // 维护在堆区的真实数组指针
        int m_capacity; // 数组容量
        int m_size; // 数组大小
};

/* 初始化动态数组
 *
 * param int capacity: 数组的容量
 *
 * return struct DynamicArray *: 动态数组结构体指针
 *
 * 注意：如果返回为NULL则表示初始化失败
 */

struct DynamicArray * init_dynamic_array(int capacity);

/* 插入功能
 *
 * param struct DynamicArray *dynamic_array: 被插入新元素的动态数组指针
 * param int pos: 被插入动态数组的位置
 * param void *data: 被插入动态数组的新元素
 *
 * return int: True：成功，False：失败
 */
int insert_dynamic_array(struct DynamicArray *dynamic_array, int pos, void *data);

/* 遍历动态数组
 */
void print_dynamic_array(struct DynamicArray *dynamic_array, void(*callback)(void *));


/* 删除数组中的元素
 *
 * param struct DynamicArray dynamic_array*: 动态数组指针
 * param int pos: 删除的位置
 * return int: True: 成功，False：失败
 */
int remove_by_pos_dynamic_array(struct DynamicArray *dynamic_array, int pos);


/*根据元素的值删除数组中的元素
 * 
 * param struct DynamicArray dynamic_array*; 动态数组指针
 * param void *data: 值
 * return int：True：成功，False:失败
 */
int remove_by_value_dynamic_array(struct DynamicArray *dynamic_array, void *data,
        int(*compare_callback)(void *, void*));


/*销毁数组
 *
 * param struct DynamicArray dynamic_array*: 动态数组指针
 *
 * return int: True：成功，False: 失败
 */
int destroy_dynamic_array(struct DynamicArray *dynamic_array);


/*
 *
 * ===========================
 *          单向链表         =
 * ===========================
 *
 */

// 链表节点
struct LinkNode
{
    void *data; // 数据域
    struct LinkNode *next; // 指针域
};


// 链表结构体
struct LinkList
{
    struct LinkNode header; // 头节点
    int m_size; // 链表长度
};

/* 初始化链表
 *
 * return struct LinkList *: 返回结构体链表指针, 返回NULL则为失败
 */

struct LinkList *init_link_list();


/* 向链表插入节点
 *
 * param struct LinkList *link_list: 链表结构体指针
 * param int pos: 要插入的位置
 * param void *data: 要插入的数据
 *
 * return int；True成功，False失败
 */
int insert_link_list(struct LinkList *link_list, int pos, void *data);

/* 遍历链表
 * 
 * param struct LinkList *link_list: 链表结构体指针
 * param callbck: 回调函数
 */
void print_link_list(struct LinkList *link_list, void(*callbaack)(void *));

/* 删除节点-根据位置
 * param struct LinkList *link_list: 链表结构体指针
 * param int pos: 删除的位置
 *
 * return int: 成功返回True, 失败返回False
 */
int remove_by_pos_link_list(struct LinkList *link_list, int pos);

/* 删除节点-根据值
 *
 * param struct LinkList *link_list: 链表结构体指针
 * param void *data: 数据
 * param int(*compare_callback)(void *, void*): 比较值是否相等的回调函数
 *
 * return int: 成功返回True, 失败返回False
 */
int remove_by_value_link_list(struct LinkList *link_list, void *data, int(*compare_callback)(void *, void *));

/* 清空链表
 * param struct LinkList *link_list: 链表指针
 *
 * return int: True 成功，False 失败
 */
int clear_link_list(struct LinkList *link_list);

/* 返回链表长度
 *
 * param struct LinkList *link_list: 链表指针
 *
 * return int: 链表长度
 */
int len_link_list(struct LinkList *link_list);

/* 销毁链表
 *
 * param struct LinkList *link_list: 链表指针
 *
 * return int: True成功，False失败，ERR错误
 */
int destroy_link_list(struct LinkList *link_list);


//=============================================栈=================================================


/*
 *
 * ===========================
 *             顺序栈        =
 * ===========================
 *
 */

// 栈的最大长度
#define STACK_MAX 1024

// 顺序栈
struct SeqStack
{
    void *data[STACK_MAX]; // 数组
    int m_size; // 栈的元素个数
};

/* 初始化栈
 */
struct SeqStack *init_seq_stack();

/* 入栈
 *
 * param struct SeqStack *stack: 栈指针
 * param void *data: 数据
 *
 * return int: True成功，False，失败, ERR错误
 */
int push_seq_stack(struct SeqStack *stack, void *data);

/* 出栈
 *
 * param struct SeqStack *stack: 栈指针
 *
 * return void *data: 数据，NULL获取失败
 */

void *pop_seq_stack(struct SeqStack *stack);

/* 返回栈的顶端元素
 *
 * param struct SeqStack *stack: 栈指针
 * param void *data: 数据
 *
 * return void *: 栈的顶端元素, ERR错误
 */

void *top_seq_stack(struct SeqStack *stack);

/* 返回栈的大小
 *
 * param struct SeqStack *stack: 栈指针
 * param void *data: 数据
 *
 * return int: 栈大小, ERR错误
 */
int size_seq_stack(struct SeqStack *stack);

/* 返回栈是否为空
 *
 * param struct SeqStack *stack: 栈指针
 *
 * return int: True为空，False不为空， ERR错误
 */
int is_empty_seq_stack(struct SeqStack *stack);

/* 销毁栈
 *
 * param struct SeqStack *stack: 栈指针
 *
 * return int: True成功，False，失败, ERR错误
 */
int destroy_seq_stack(struct SeqStack *stack);


/*
 *
 * ==============================
 *            链式栈            =
 * ==============================
 *
 */ 

// 链式栈节点
struct LinkStackNode {
    struct LinkStackNode *next; //指针域
    void *data; // 数据域
};

// 链式栈
struct LinkStack
{
    struct LinkStackNode header; // 头节点 
    int m_size; // 栈的大小
};


/* 初始化链式栈
 */
struct LinkStack *init_link_stack();

/* 入栈
 * 
 * param struct LinkStruct *link_stack: 链式栈指针
 * param void *data: 数据
 *
 * return int: True成功，False失败，ERR错误
 */
int push_link_stack(struct LinkStack *link_stack, void *data);

/* 出栈
 * 
 * param struct LinkStruct *link_stack: 链式栈指针
 *
 * return void*: 数据
 */
void *pop_link_stack(struct LinkStack *link_stack);

/* 返回栈顶元素
 *
 * param struct LinkStruct *link_stack: 链式栈指针
 *
 * return void *: 栈顶元素
 */
void *top_link_stack(struct LinkStack *link_stack);

/* 判断是否为空
 * 
 * param struct LinkStruct *link_stack: 链式栈指针
 *
 * return int: True空，False非空，ERR错误
 */
int is_empty_link_stack(struct LinkStack *link_stack);

/* 返回栈大小
 *
 * param struct LinkStruct *link_stack: 链式栈指针
 *
 * return int: 栈大小，如为ERR错误
 */
int size_link_stack(struct LinkStack *link_stack);

/*
 *
 * param struct LinkStruct *link_stack: 链式栈指针
 *
 * return int: True成功，False失败，ERR错误
 */
int destroy_link_stack(struct LinkStack *link_stack);
