#include"test.h"

//函数多用了递归的思想

void PreorderTraversal(BinTree BT)//先序遍历
{
    if (BT)
    {
        printf("%d ", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}
void InorderTraversal(BinTree BT)//中序遍历
{
    if (BT)
    {
        InorderTraversal(BT->Left);
        printf("%d ", BT->Data);
        InorderTraversal(BT->Right);
    }
}
BinTree Insert(BinTree BST, ElementType X)//插入    
{
    if (BST == NULL)//找得了插入的位置
    {
        BinTree cur = (BinTree)malloc(sizeof(struct TNode));//获得动态内存之后要判断一下是否申请内存成功
        if (cur == NULL)
        {
            printf("L:%s\n", strerror(errno));//将错误内容返回
            return NULL;
        }
        cur->Left = NULL;
        cur->Right = NULL;
        cur->Data = X;

        return cur;
    }
    //递归
    else if (BST->Data > X)//插入的值小于根结点
        BST->Left = Insert(BST->Left, X);//递归以原来的根结点的左孩子为根节点，向下搜索  
    else if (BST->Data < X)
        BST->Right = Insert(BST->Right, X);
    //指针BST在该函数中并没有改变
    return BST;
}
BinTree Delete(BinTree BST, ElementType X)//删除
{
    if (BST == NULL)//当二叉树搜索完后，没有找到
    {
        printf("Not Found\n");
    }

    else if (BST->Data == X)//找到X时，需要重新改树
    {
        if (BST->Left == NULL && BST->Right == NULL)//左右子树都为空
            return NULL;
        else if (BST->Left == NULL && BST->Right != NULL)//当左子树为空，右子树不为空，
            BST = BST->Right;                            //右子树直接补上
        else if (BST->Left != NULL && BST->Right == NULL)//当右子树不为空，左子树为空
            BST = BST->Left;                             //左子树直接补上
       
        //左右子树都有值
        else
        {
            BinTree temp = BST->Right;
            while (temp->Left)
                temp = temp->Left;
            BST->Data = temp->Data;//将右子树的最小值取代删除的值
            BST->Right = Delete(BST->Right, BST->Data);//在将该值在原来位置删除
        }
    }
    else if (BST->Data > X)
        BST->Left = Delete(BST->Left, X);
    else if (BST->Data < X)
        BST->Right = Delete(BST->Right, X);
    return BST;
}
Position Find(BinTree BST, ElementType X)//查找
{
    if (BST == NULL)
        return NULL;
    else {
         
     if (BST->Data == X)
        return BST;
    else if (BST->Data > X)
        return Find(BST->Left, X);
    else 
        return Find(BST->Right, X);
    }
}

Position FindMin(BinTree BST)
{
    if (BST == NULL)
    {
        return BST;
    }
    else
    {
        while (BST->Left)
        {
            BST = BST->Left;
        }
        return BST;
    }
}

Position FindMax(BinTree BST)
{
    if (BST == NULL)
    {
        return BST;
    }
    else
    {
        while (BST->Right)
        {
            BST = BST->Right;
        }
        return BST;
    }
}
