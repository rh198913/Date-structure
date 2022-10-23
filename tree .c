#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* 
 了解二叉树
1.空的二叉树，就是结构体指针 tree = NULL
2,只有根节点的二叉树（编序从1开始）
3，只有左子数或右子数的二叉树
4，左右子树都存在，完全二叉树和满二叉树（处叶子节点，其他都是满的）
5，孩子节点的序号/2是父节点的序号（任何一个节点都是这样）
遍历（不重复打印）
前序遍历(根左右)ABC通常使用前序，中序遍历（左根右）BAC，后序遍历（左右根）BCA
*/

//描述一个单一个体（用结构体表示一个数）
//起结构体指针别名的时候用LP开头代表指针
typedef struct  treenode //起一个别名
{
    char data ;//数据域字符表示
    struct treenode* lchild;
    struct treenode* rchild;
}TREE,*LPTREE;//命名了一下结构体
LPTREE createnode(char data)
{
    LPTREE newnode = (LPTREE)malloc(sizeof(TREE));
    newnode->data = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;//节点刚开始创建好的时候左右指数的是空的
    return newnode;
}
//没有规律的树，不能创建，树的创建，就是插入
void insertnode(LPTREE parentnode,LPTREE lchild,LPTREE rchild)
{
    parentnode->lchild = lchild;//父节点z左边插入左边
    parentnode->rchild = rchild;
}
//打印当前节点中的元素
void printcurnodedata(LPTREE curdata)//节点是指针，用指针去访问
{
    printf("%c\t",curdata->data);//剩下的只需要改变指针的位置

}//递归法遍历
//先序：根左右
void preorder(LPTREE root)//访问根节点
{
    if(root != NULL)
    {
        printcurnodedata(root);//根部节点直接打印
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
    /* void preorder1(LPTREE root)//访问根节点
    if(root != NULL)
        {
            printcurnodedata(root);//根部节点直接打印
            preorder3(root->lchild);//左右两遍递归方式
            preorder4(root->rchild);
        }
        void preorder2(LPTREE root)//访问根节点
    if(root != NULL)
        {
            printcurnodedata(root);//根部节点直接打印
            preorder5(root->lchild);//左右两遍递归方式
            preorder6(root->rchild);
        } */
//中序 左根右
void midorder(LPTREE root)//访问根节点
{
    if(root != NULL)
    {
        midorder(root->lchild);
        printcurnodedata(root);//根部节点直接打印
        midorder(root->rchild);
    }
}
//后序 左右根
void lastorder(LPTREE root)//访问根节点
{
    if(root != NULL)
    {
        lastorder(root->lchild);
        lastorder(root->rchild);
        printcurnodedata(root);//根部节点直接打印
    } 
}



//如果两个以上的节点，可以用此方法调用

int main()
{
    //死板的创造过程，没意义
    LPTREE a = createnode('a');
    LPTREE b = createnode('b');
    LPTREE c = createnode('c');
    LPTREE d = createnode('d'); //创建节点，然后做个连接
    LPTREE e = createnode('e'); 
    LPTREE f = createnode('f'); 
    LPTREE g = createnode('g');
    insertnode(a,b,c);
    insertnode(b,d,NULL);
    insertnode(d,NULL,g);
    insertnode(c,e,f);
    printf("先序遍历：\n");
    preorder(a);
    printf("\n中序遍历：\n");
    midorder(a);
    printf("\n后序遍历：\n");
    lastorder(a);
    system("pause");
    return 0;//此方法为递归方式
}
