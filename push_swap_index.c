// #include "push_swap.h"

// void ft_get_index(t_node *lst)
// {
//     int index;
//     t_node *i;
//     t_node *ptr_minor;

//     i = lst;
//     ptr_minor = lst;
//     index = 1;

//     //Recorremos la lista hasta el final de la lista
//     while (!(i->next != NULL) && i->index == '0')
//     {
//         //Recorremos la lista hasta que haya un elemento sin index
//         while (i->index == 0)
//         {
//             i = i->next;
//         }

//         //Mientras que no lleguemos al final de la lista
//         while (i->next != NULL)
//         {
//             //Si encontramos un número menor dejamos el ptr_minor apuntando a ese nodo
//             if (i->num > i->next->num)
//             {
//                 ptr_minor = i->next;
//                 i = i->next;
//             }
//             i = i->next;
//         }
//         ptr_minor->index = index;
//         index++;
//         i = lst;
//     }
// }

