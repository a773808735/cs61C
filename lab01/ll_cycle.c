#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head)
{
    if (head == NULL)
        return 0;
    if (head->next == NULL)
        return 0;
    node *cur = head->next->next;
    while (cur)
    {
        head = head->next;
        if (head == cur)
            return 1;
        if (cur->next == NULL)
            break;
        cur = cur->next->next;
    }
    return 0;
}