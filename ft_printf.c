/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:59:46 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/19 15:03:32 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conver(char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		count += ft_print_string(va_arg(args, char *));
	else if (*format == 'p')
	{
		if (ft_print_string("0x") == -1)
			return (-1);
		count += 2;
		count += ft_hex(va_arg(args, unsigned long), 'p');
	}
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		count += ft_unsignedint(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += ft_hex(va_arg(args, unsigned int), 'x');
	else if (*format == 'X')
		count += ft_hex(va_arg(args, unsigned int), 'X');
	else if (*format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	i;
	int		total_chars;
	char	*ptr;

	i = 0;
	total_chars = 0;
	va_start(args, format);
	ptr = (char *)format;
	while (ptr[i] != '\0' && total_chars != -1)
	{
		if (ptr[i] == '%')
		{
			total_chars += ft_conver(&ptr[i + 1], args);
			i++;
		}
		else
		{
			total_chars += ft_putchar(ptr[i]);
		}
		i++;
	}
	va_end(args);
	return (total_chars);
}

/*int	main(void)
{
	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
	ft_printf("BYANA->%u\n", 4294967295);
	//printf("ORIGI->%u\n", 4294967294);
	ft_printf("\n> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
	ft_printf("BYANA->%u\n", -10);
	printf("ORIGI->%u\n", -10);
	ft_printf("\n> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

	unsigned int tests[] = {0, 1, 12345, 987654321, 4294967295, 2147483648};
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    printf("Testing with printf:\n");
    for (int i = 0; i < num_tests; ++i) {
        printf("Test %d: %u\n", i + 1, tests[i]);
    }

    printf("\nTesting with ft_printf:\n");
    for (int i = 0; i < num_tests; ++i) {
        printf("Test %d: ", i + 1);
        ft_printf("%u\n", tests[i]);
    }
	return (0);
}*/

/*
int	main(void)
{
	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
	//ft_printf("BYANA->\001\002\007\v\010\f\r\n");
	printf("ORIGI->\001\002\007\v\010\f\r\n");
	ft_printf("\n> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

	//printf("%d\n", ft_printf("BYANA->\001\002\007\v\010\f\r\n"));
	return (0);
}
*/

/*
//int main(void)
//{
//	char	*str = NULL;
//	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

//	printf("%d\n", ft_printf("BYANAA: N-%s-N\n", str));

//	printf("%d\n", printf("ORIGIN: N-%s-N\n", str));
//	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
    
//	return (0);
//}
*/

/*    ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
	ft_printf("BYANA1 -->%c\n", '0');
	printf("ORIGI1 -->%c\n", '0');
	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
    ft_printf("BYANA2 --> %c \n ", '0');
	printf("ORIGI2 --> %c \n ", '0');
	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");


	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
	ft_printf("BYANA3 --> %c\n", '0' - 256);
	printf("ORIGI3 --> %c\n", '0' - 256);
	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
    ft_printf("BYANA4 --> %c\n", '0' + 256);
	printf("ORIGI4--> %c\n", '0' + 256);
	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
	ft_printf("BYANA5 --> %c %c %c\n", '0', 0, '1');
    printf("ORIGI5 --> %c %c %c\n ", '0', 0, '1');
	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
    ft_printf("BYANA6 --> %c %c %c\n ", ' ', ' ', ' ');
	printf("ORIGI6--> %c %c %c\n ", ' ', ' ', ' ');
	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
	ft_printf("BYANA7 --> %c %c %c\n ", '1', '2', '3');
	printf("ORIGI7 --> %c %c %c\n ", '1', '2', '3');	
	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
    ft_printf("BYANA8 --> %c %c %c\n ", '2', '1', 0);
	printf("ORIGI8-->%c %c %c\n ", '2', '1', 0);
	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

//	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

//	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

//  ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");*/

//   ft_printf("str: %s\n", "Ana");
 //   printf("ORIGINAL --> str: %s\n", "Ana");

//	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
//    ft_print("BYANA1 %p\n ", -1);
//      printf("ORIGI1%p\n ", -1);
//	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
//	 ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
//      print("BYANA2 %p\n ", 15);
//      print("ORIGI2 %p\n ", 15);
//    ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

//	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
//      print("BYANA3 %p %p\n ", LONG_MIN, LONG_MAX);
//      print("ORIGI3 %p %p\n ", LONG_MIN, LONG_MAX);
//    ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

//	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
//      print("BYANA4 %p %p\n ", INT_MIN, INT_MAX);
//      print("ORIGI4 %p %p\n ", INT_MIN, INT_MAX);
//    ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
    

//	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
//     print("BYANA5 %p %p\n ", ULONG_MAX, -ULONG_MAX);
//      print("ORIGI5 %p %p\n ", ULONG_MAX, -ULONG_MAX);
//	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");







//    ft_printf("Myprintfd --> digit: %d\n", -3407);
//    printf("ORIGINAL --> digit: %d\n", -3407);

//    ft_printf("Myprintfi --> int: %i\n", 204);
//    printf("ORIGINAL --> int: %i\n", 204);

//    ft_printf("Myprintfuint --> uint: %u\n", 24230);
//    printf("ORIGINAL --> uint: %u\n", 24230);

//    ft_printf("Myprintf --> hex: %x\n", 2423333);
//    printf("ORIGINAL --> hex: %x\n", 2423333);

//    ft_printf("prinl%0%--> PERC\n");
//       printf("FINAl%0%--> ERC \n");*/

//   return (0);
//}
//
//
