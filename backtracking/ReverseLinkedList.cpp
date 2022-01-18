ListNode* reverse(ListNode* firstNode, ListNode* second){
    if(firstNode == NULL)return second;
    ListNode* temp = reverse(firstNode->next, firstNode);
    firstNode->next = second;
    return temp;
}

ListNode* Solution::reverseList(ListNode* A) {
    return reverse(A, NULL);
}
