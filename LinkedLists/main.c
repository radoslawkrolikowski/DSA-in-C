#include "linked_lists.h"

int main(void) {
    LinkedLists *list = make_linked_lists();
    push_back(list, 0);
    push_back(list, 1);
    push_back(list, 2);
    push_back(list, 3);

    print_list(list);

    destroy_list(list);
}
