//fast & slow
struct ListNode* middleNode(struct ListNode* head) {
        struct ListNode *fast,*slow;
    fast = head;
    slow = head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//用慢指针 slow 遍历列表时，让另一个指针 fast 的速度是它的两倍。当 fast 到达列表的末尾时，slow 必然位于中间。