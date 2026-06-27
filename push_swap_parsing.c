#include "push_swap.h"

static int ps_print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

static int ps_select_alg(char **argv, int i, t_parse *param)
{
    if (strcmp(argv[i], "--simple") == 0)
    {
        param->algoritm = 1;
        printf("\n ==== Algoritmo Simple ==== \n\n");
        return (i);
    }
    else if (strcmp(argv[i], "--medium") == 0)
    {
        param->algoritm = 2;
        printf("\n ==== Algoritmo Medium ==== \n\n");
        return (i);
    }
    else if (strcmp(argv[i], "--complex") == 0)
    {
        param->algoritm = 3;
        printf("\n ==== Algoritmo Complex ==== \n\n");
        return (i);
    }
    else if (strcmp(argv[i], "--adaptive") == 0)
    {
        param->algoritm = 0;
        printf("\n ==== Algoritmo Adaptive ==== \n\n");
        return (i);
    }
    else
    {
        param->algoritm = 0;
        printf("\n ==== Algoritmo Adaptive ==== \n\n");        
    }

    return (0);
}

static void ps_stack_init(t_stack *st)
{
	st->start = NULL;
	st->size = 0;
}

static int ps_load_data(int argc, char **argv, t_parse *param, t_stack *sta, t_stack *stb)
{
	//Inicializar las pilas
	ps_stack_init(sta);
	ps_stack_init(stb);
	
	//Cargar datos en la pila a
	while (param->i < argc)
	{
        if(ps_valid_numbers(argv[param->i], sta))
			return (ps_print_error());

		ft_lstadd_back(&sta->start, ft_lstnew(ft_atoi(argv[param->i])));
		param->i++;
		sta->size++;
	}
	//printf("El primer elemento de la pila a es: %d \n", (sta->start)->num);
	//printf("El último elemento de la pila a es: %d \n", ft_lstlast(sta->start)->num);
	//printf("El tamaño de la pila a es: %d \n", sta->size);
	return (0);
}

int ps_parsing(int argc, char **argv, t_stack *sta, t_stack *stb, t_parse *param)
{
    int finded;
    int position;

    finded = 0;
    position = 1;
    //Inicializamos los valores de la estructura de parsing
    param->i = 1;
    param->bench = 0;
    param->algoritm = 0;

    //Si no es especifican parametros no ha que hacer nada (devolver control al usuario)
    if (argc == 1)
        return (1);

    while (position < argc && position <= 2)
    {
        //Modo benchmark
	    if (strcmp(argv[position], "--bench") == 0)
	    {
            param->bench = 1;
            param->i++;
        }
        //Seleccionar estrategia
        if (finded == 0 && ps_select_alg(argv, position, param) > 0)
        {
            finded = 1;
            param->i++;
        }
        position++;
    }

    //Inicializar pilas y cargar números en la pila a
	ps_load_data(argc, argv, param, sta, stb);
    
    return (0);
}