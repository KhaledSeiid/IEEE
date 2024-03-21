SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* ptr1=head1;
    while (ptr1) {
       SinglyLinkedListNode* ptr=malloc(sizeof(SinglyLinkedListNode));
       SinglyLinkedListNode* ptr2=head2;
        SinglyLinkedListNode* ptr2_pre=NULL;
       if(head2==NULL)
       {
           return head1;
       }
       else
       {
           while (ptr2->data<ptr1->data) {
               ptr2_pre=ptr2;
           ptr2=ptr2->next;
           if(ptr2==NULL)break;

            }
            if(ptr2==NULL)
            {
                ptr2_pre->next=ptr;
                ptr->next=NULL;
                ptr->data=ptr1->data;
            }
            else if(ptr2==head2){
                ptr->next=head2;
                ptr->data=ptr1->data;
                head2=ptr;
            }
            else {
                ptr->next=ptr2;
                ptr->data=ptr1->data;
                ptr2_pre->next=ptr;
            }
       }
       ptr1=ptr1->next;
    }
    return head2;
}
