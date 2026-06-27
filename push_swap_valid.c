#include "push_swap.h"


static int ps_is_number(char *num)
{
    int i;

    i = 0;
    if (num[i] == '-' || num[i] == '+')
        i++;
    if (num[i] == '\0')
        return (1);
    while (num[i] != '\0')
    {
        if(num[i] < '0' || num[i] > '9')
			return (1);
        i++;
    }
    return (0);
}


// static int ps_valid_int()
// {
//     printf ("Entra en ps_valid_int \n");
//     return (0);
// }


static int ps_valid_duplicates(char *num, t_stack *st)
{
    t_node *lst;

    lst = st->start;
    while (lst)
	{
        //printf("El número de la lista es: %d \n", lst->num);
        //printf("El número a comprobar es: %d \n", ft_atoi(num));
		if(lst->num == ft_atoi(num))
			return (1);
		lst = lst->next;
	}
    return (0);
}


int	ps_valid_numbers(char *num, t_stack *st)
{
    //printf ("Entra en ps_valid_numbers con valor %s\n", num);

    //Validar que son numeros
    if (ps_is_number(num))
        return (1);

    // //Numeros enteros
    // if (ps_valid_int(arg))
    //     return (1);

    //Números duplicados
    if (ps_valid_duplicates(num, st))
    {
        printf("Se ha encontrado duplicado el número; %s\n", num);
        return (1);
    }

    return (0);
}