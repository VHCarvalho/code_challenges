/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list
 * 
 *You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <unistd.h>
struct ListNode *create_list(int nbr)
{
    struct ListNode *new_head;
    new_head = malloc(sizeof(struct ListNode));
    if (new_head == NULL)
        return (NULL);
    new_head->next = NULL;
    new_head->val = nbr;
    return (new_head);
}
struct ListNode *add_node(struct ListNode *lst, int nbr)
{
    struct ListNode *new_node;
    struct ListNode *ptr;
    
    new_node = malloc(sizeof(struct ListNode));
    if (new_node == NULL)
        return (NULL);
    ptr = lst;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->val = nbr;
    new_node->next = NULL;
    return (lst);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum;
    struct ListNode *ptr1;
    struct ListNode *ptr2;
    struct ListNode *ret;
    int i;
    
    if (l1 == NULL)
        return (l2);
    if (l2 == NULL)
        return (l1);
    ptr1 = l1;
    ptr2 = l2;
    sum = 0;
    i = 0;
    while (ptr1 != NULL || ptr2 != NULL)
    {
        if (ptr1 == NULL)
            sum += ptr2->val;
        else if (ptr2 == NULL)
            sum += ptr1->val;
        else
            sum += ptr1->val + ptr2->val;
        if (i == 0)
            ret = create_list(sum % 10);
        else
            ret = add_node(ret, sum % 10);
        sum = sum / 10;
        i++;
        if (ptr1 != NULL)
            ptr1 = ptr1->next;
        if (ptr2 != NULL)
            ptr2 = ptr2->next;
    }
    if (sum != 0)
        ret = add_node(ret, sum);
    return (ret);
}
