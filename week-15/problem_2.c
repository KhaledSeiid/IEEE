DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
 DoublyLinkedListNode* ptr=llist;
 DoublyLinkedListNode* pre=NULL;
 DoublyLinkedListNode* node=malloc(sizeof(DoublyLinkedListNode));
 while (ptr->data<data) {
     pre=ptr;
     ptr=ptr->next;
     if(!ptr)break;
     }
      if(ptr==NULL)
            {
                node->next=NULL;
                node->prev=pre;
                pre->next=node;
            }
            else if(ptr==llist){
                node->next=llist;
                node->prev=NULL;
                llist->prev=node;
                llist=node;
            }
            else {
                node->next=ptr;
                node->prev=pre;
                ptr->prev=node;
                pre->next=node;
            }
            node->data=data;
return llist;
 
}
