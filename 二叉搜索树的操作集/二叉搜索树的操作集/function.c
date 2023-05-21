#include"test.h"

//���������˵ݹ��˼��

void PreorderTraversal(BinTree BT)//�������
{
    if (BT)
    {
        printf("%d ", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}
void InorderTraversal(BinTree BT)//�������
{
    if (BT)
    {
        InorderTraversal(BT->Left);
        printf("%d ", BT->Data);
        InorderTraversal(BT->Right);
    }
}
BinTree Insert(BinTree BST, ElementType X)//����    
{
    if (BST == NULL)//�ҵ��˲����λ��
    {
        BinTree cur = (BinTree)malloc(sizeof(struct TNode));//��ö�̬�ڴ�֮��Ҫ�ж�һ���Ƿ������ڴ�ɹ�
        if (cur == NULL)
        {
            printf("L:%s\n", strerror(errno));//���������ݷ���
            return NULL;
        }
        cur->Left = NULL;
        cur->Right = NULL;
        cur->Data = X;

        return cur;
    }
    //�ݹ�
    else if (BST->Data > X)//�����ֵС�ڸ����
        BST->Left = Insert(BST->Left, X);//�ݹ���ԭ���ĸ���������Ϊ���ڵ㣬��������  
    else if (BST->Data < X)
        BST->Right = Insert(BST->Right, X);
    //ָ��BST�ڸú����в�û�иı�
    return BST;
}
BinTree Delete(BinTree BST, ElementType X)//ɾ��
{
    if (BST == NULL)//���������������û���ҵ�
    {
        printf("Not Found\n");
    }

    else if (BST->Data == X)//�ҵ�Xʱ����Ҫ���¸���
    {
        if (BST->Left == NULL && BST->Right == NULL)//����������Ϊ��
            return NULL;
        else if (BST->Left == NULL && BST->Right != NULL)//��������Ϊ�գ���������Ϊ�գ�
            BST = BST->Right;                            //������ֱ�Ӳ���
        else if (BST->Left != NULL && BST->Right == NULL)//����������Ϊ�գ�������Ϊ��
            BST = BST->Left;                             //������ֱ�Ӳ���
       
        //������������ֵ
        else
        {
            BinTree temp = BST->Right;
            while (temp->Left)
                temp = temp->Left;
            BST->Data = temp->Data;//������������Сֵȡ��ɾ����ֵ
            BST->Right = Delete(BST->Right, BST->Data);//�ڽ���ֵ��ԭ��λ��ɾ��
        }
    }
    else if (BST->Data > X)
        BST->Left = Delete(BST->Left, X);
    else if (BST->Data < X)
        BST->Right = Delete(BST->Right, X);
    return BST;
}
Position Find(BinTree BST, ElementType X)//����
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
