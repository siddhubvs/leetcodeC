typedef struct ListNode node;

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    else if (l2 == NULL)
    {
        return l1;
    }
    node dummy = {.val = 0};
    node *head = &dummy;
    node *cur = &dummy;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val <= l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
            //cur->next = NULL;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
            //cur->next = NULL;
        }
    }
    if (l1 != NULL)
    {
        cur->next = l1;
    }
    else if (l2 != NULL)
    {
        cur->next = l2;
    }
    return head->next;
}
