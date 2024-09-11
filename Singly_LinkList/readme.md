1) struct node * insert_at_begin(struct node * h, int data)
2) struct node * insert_at_end(struct node * h, int data)
3) struct node * insert_at_position(struct node * h, int data, int pos)
4) int delete_at_begin(struct node ** hptr)                                   // Deleted data to be returned
5) int delete_at_end(struct node ** hptr)                                     // Deleted data to be returned
6) int delete_at_position(struct node ** hptr, int pos)                       //Return Deleted data , otherwise return INT_MIN if the position is invalid
7) int delete_value_from_list(struct node ** hptr , int del_val )             //Return Deleted data , otherwise return INT_MIN for data “del_val “ not found in the list
8) struct node * Reverse_Linked _list(struct node * h)
9) Exit from the loop 
