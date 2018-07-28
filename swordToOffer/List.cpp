//This is a conlusion about data structure --list--
/*
@author:Zhang Qi
@time:2018/07/27
*/

/*
@功能：反转链表
@参数：输入为链表头节点，输出为反转后链表头节点
@时间复杂度：O(n)
*/
ListNode* ReverseList(ListNode* pHead) {
    if(pHead==nullptr)
        return nullptr;
    ListNode*cur=pHead;
    ListNode*pre=nullptr;
    ListNode*post=nullptr;
    while(cur!=nullptr)
    {
        post=cur->next;
        cur->next=pre;
        pre=cur;
        cur=post;
    }
    return pre;
}

/*
@功能：返回链表中倒数第k个节点
@参数：input：链表头节点，整数k;output：链表中倒数第k个节点
*/
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if(pListHead==nullptr)
        return nullptr;
    int len=0;
    ListNode*pNode=pListHead;
    while(pNode!=nullptr)
    {
        len++;
        pNode=pNode->next;
    }
    if(k>len)
    return nullptr;
    int index=len+1-k;
    int i=1;
    pNode=pListHead;
    while(i<index&&pNode!=nullptr)
    {
        pNode=pNode->next;
        i++;
    }
    return pNode;
}
/*
@功能：合并两个排序链表
@参数：input：两个链表头节点，output：合并后链表头节点
*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==nullptr&&pHead2==nullptr)
        {
            return nullptr;
        }
        if(pHead1==nullptr) return pHead2;
        if(pHead2==nullptr) return pHead1;
        ListNode*res=new ListNode(0);
        ListNode*temp=res;
        while(pHead1!=nullptr&&pHead2!=nullptr)
        {
            if(pHead1->val<=pHead2->val)
            {
                ListNode*p=new ListNode(pHead1->val);
                temp->next=p;
                temp=temp->next;
                pHead1=pHead1->next;
            }
            else
            {
                ListNode*p=new ListNode(pHead2->val);
                temp->next=p;
                temp=temp->next;
                pHead2=pHead2->next;
            }
        }
        if(pHead1)temp->next=pHead1;
        if(pHead2)temp->next=pHead2;
        temp=temp->next;
        temp->next=nullptr;
        return res->next;
    }
};
/*
@功能：复杂链表的复制
@参数：待复制链表的头节点，复制后链表的头节点
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==nullptr)
        return nullptr;
        copyNext(pHead);
        connectRandom(pHead);
        return reConnect(pHead);
    }
    ////复制next 如原来是A->B->C 变成A->A'->B->B'->C->C'
    RandomListNode*copyNext(RandomListNode*pHead)
    {
        RandomListNode*pNode=pHead;
        while(pNode!=nullptr)
        {
            RandomListNode*temp=new RandomListNode(pNode->label);
            temp->next=pNode->next;
            pNode->next=temp;
            pNode=temp->next;
        }
        return pHead;
    }
    //复制random pCur是原来链表的结点 pCur.next是复制pCur的结点
    void connectRandom(RandomListNode*pHead)
    {
        RandomListNode*pNode=pHead;
        while(pNode!=nullptr)
        {
            RandomListNode*pNext=pNode->next;
            if(pNode->random)
            {
                pNext->random=pNode->random->next;
            }
            pNode=pNext->next;
        }
    }
    ////拆分链表
    RandomListNode*reConnect(RandomListNode*pHead)
    {
        RandomListNode*res=pHead->next;
        RandomListNode*pNode=pHead;
        while(pNode!=nullptr)
        {
            RandomListNode*pNext=pNode->next;
            pNode->next=pNext->next;
            pNode=pNode->next;
            if(pNode!=nullptr)
            pNext->next=pNode->next;
        }
        return res;
    }
};



