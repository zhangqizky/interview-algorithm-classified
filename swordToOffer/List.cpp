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



