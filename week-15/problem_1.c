bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* ptr=head;
    int cnt=0;
    bool flag=1;
    while (cnt<1001) {
        if(!ptr)
        {
            flag=0;
            break;
        }
        ptr=ptr->next;
        cnt++;
    }
    return flag;
}
