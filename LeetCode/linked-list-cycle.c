bool hasCycle(struct ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
    struct ListNode *p = head;
    struct ListNode *q = head->next;
    while(p!=q)
    {
        if(q==NULL||q->next==NULL) return false;
        p = p->next;
        q = q->next->next;
    }
    return true;
}

/*
通过使用具有 不同速度 的快、慢两个指针遍历链表，空间复杂度可以被降低至 O(1)O(1)。慢指针每次移动一步，而快指针每次移动两步。
现在考虑一个环形链表，把慢指针和快指针想象成两个在环形赛道上跑步的运动员。
而快跑者最终一定会追上慢跑者.
假如快跑者只落后慢跑者一步，在下一次迭代中，它们就会分别跑了一步或两步并相遇。*/