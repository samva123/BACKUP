bool checkloop(Node *&head)
{

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // check loop
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

// time complexity = O(N)


Node* getstartingPoint(Node* &head){

    Node *slow = head;
    Node *fast = head;
while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // check loop
        if (fast == slow)
        {
            break;
        }
    }

    if(fast == NULL){
        retrun NULL;
    }

    slow = head;

    while(fast != slow){
        slow = slow -> next;
        fast = fast -> next;


    }
    return slow;


}

