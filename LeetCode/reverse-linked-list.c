/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p = head;
    struct ListNode *cur=NULL;
    while(p!=NULL)
    {
        struct ListNode *temp = p->next;
        p->next = cur;
        cur = p;
        p = temp;
    }
    return cur;
}


//second:
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL||head->next==NULL)
        return head;
    struct ListNode *p = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}
/*
对递归版本的解释：
存在链表：p1->p2->p3->p4
reverseList(p1):p=p4,p1->next->next=p1,p1->next=null,(p1<-p2<-p3<-p4)
	reverseList(p2):p=p4, p2->next->next=p2, p2->next=null.(p1->p2<-p3<-p4)
		reverList(p3):p=p4, p3->next->next=p3, p3->next=null.(p1->p2->p3<-p4;
			reverList(p4):return p4
