#include <limits.h>
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

// Asegúrate de incluir el archivo de cabecera de tu implementación de ft_printf
#include "ft_printf.h"

int main() {

    int ft_len, std_len;

    ft_len = ft_printf("Caracter: %s\n", "%0Hola%que\n tal");
    std_len = printf("Caracter: %s\n", "%0Hola%que\n tal");
    printf("%d\n", ft_len);
    printf("%d\n", std_len);
    ft_printf("-------------\n");
    return (0);
}

/*
    // Pruebas para cada conversión sin flags: c, s, p, d, i, u, x, X, y %
    ft_len = ft_printf("Caracter: %c\n", 'A');
    std_len = printf("Caracter: %c\n", 'A');
    printf("%d\n", ft_len);
    printf("%d\n", std_len);
    ft_printf("\n-------------\n");

    ft_len = ft_printf("String: %s\n", "Hola, mundo!");
    std_len = printf("String: %s\n", "Hola, mundo!");
    printf("%d\n", ft_len);
    printf("%d\n", std_len);
    ft_printf("\n-------------\n");

    ft_len = ft_printf("Puntero: %p\n", (void *)0x12345678);
    std_len = printf("Puntero: %p\n", (void *)0x12345678);
    printf("%d\n", ft_len);
    printf("%d\n", std_len);
    ft_printf("\n-------------\n");

    ft_len = ft_printf("Entero (d): %d\n", 12345);
    std_len = printf("Entero (d): %d\n", 12345);
    printf("%d\n", ft_len);
    printf("%d\n", std_len);
    ft_printf("\n-------------\n");

    ft_len = ft_printf("Entero (i): %i\n", -54321);
    std_len = printf("Entero (i): %i\n", -54321);
    printf("%d\n", ft_len);
    printf("%d\n", std_len);
    ft_printf("\n-------------\n");

    ft_len = ft_printf("Unsigned (u): %u\n", 98765);
    std_len = printf("Unsigned (u): %u\n", 98765);
    printf("%d\n", ft_len);
    printf("%d\n", std_len);
    ft_printf("\n-------------\n");

    ft_len = ft_printf("Hexadecimal (x): %x\n", 255);
    std_len = printf("Hexadecimal (x): %x\n", 255);
    printf("%d\n", ft_len);
    printf("%d\n", std_len);
    ft_printf("\n-------------\n");

    ft_len = ft_printf("Hexadecimal (X): %X\n", 255);
    std_len = printf("Hexadecimal (X): %X\n", 255);
    printf("%d\n", ft_len);
    printf("%d\n", std_len);
    ft_printf("\n-------------\n");

    ft_len = ft_printf("Porcentaje: %%\n");
    std_len = printf("Porcentaje: %%\n");
    printf("%d\n", ft_len);
    printf("%d\n", std_len);
    ft_printf("\n-------------\n");

    // Casos especiales
    ft_printf("-------------Casos especiales\n");
    ft_len = ft_printf("Entero cero: %d\n", 0);
    std_len = printf("Entero cero: %d\n", 0);
    printf("%d\n", ft_len);
    printf("%d\n", std_len);
    ft_printf("\n-------------\n");
    ft_len = ft_printf("Entero más pequeño: %d\n", INT_MIN);
    std_len = printf("Entero más pequeño: %d\n", INT_MIN);
    printf("%d\n", ft_len);
    printf("%d\n", std_len);
    ft_printf("\n-------------\n");
    ft_len = ft_printf("String vacía: %s\n", "");
    std_len = printf("String vacía: %s\n", "");
    printf("%d\n", ft_len);
    printf("%d\n", std_len);
    ft_printf("\n-------------\n");
    ft_len = ft_printf("Puntero nulo: %p\n", NULL);
    std_len = printf("Puntero nulo: %p\n", NULL);
    printf("%d\n", ft_len);
    printf("%d\n", std_len);
    ft_printf("\n-------------\n");

    // Prueba con múltiples argumentos/conversiones
    ft_len = ft_printf("Múltiples argumentos: %d, %s, %c\n", 123, "texto", 'X');
    std_len = printf("Múltiples argumentos: %d, %s, %c\n", 123, "texto", 'X');
    printf("%d\n", ft_len);
    printf("%d\n", std_len);
    ft_printf("\n-------------\n");

    // Prueba de múltiples conversiones en medio de una frase
    ft_len = ft_printf("Entero: %d, String: %s, Hexadecimal: %x\n", 456, "ejemplo", 0xDEADBEEF);
    std_len = printf("Entero: %d, String: %s, Hexadecimal: %x\n", 456, "ejemplo", 0xDEADBEEF);
    printf("%d\n", ft_len);
    printf("%d\n", std_len);

    return 0;
}
*/

/*
int main() {
    // Pruebas para cada conversión sin flags: c, s, p, d, i, u, x, X, y %
	//int	result;

    printf("%d\n" , ft_printf("Caracter: %c\n", 'A'));
    printf("%d\n" , printf("Caracter: %c\n", 'A'));
    ft_printf("\n-------------\n");

    ft_printf("String: %s\n", "Hola, mundo!");
    printf("String: %s\n", "Hola, mundo!");
    ft_printf("\n-------------\n");

    ft_printf("Puntero: %p\n", (void *)0x12345678);
    printf("Puntero: %p\n", (void *)0x12345678);
    ft_printf("\n-------------\n");

    ft_printf("Entero (d): %d\n", 12345);
    printf("Entero (d): %d\n", 12345);
    ft_printf("\n-------------\n");

    ft_printf("Entero (i): %i\n", -54321);
    printf("Entero (i): %i\n", -54321);
    ft_printf("\n-------------\n");

    ft_printf("Unsigned (u): %u\n", 98765);
    printf("Unsigned (u): %u\n", 98765);
    ft_printf("\n-------------\n");

    ft_printf("Hexadecimal (x): %x\n", 255);
    printf("Hexadecimal (x): %x\n", 255);
    ft_printf("\n-------------\n");

    ft_printf("Hexadecimal (X): %X\n", 255);
    printf("Hexadecimal (X): %X\n", 255);
    ft_printf("\n-------------\n");

    ft_printf("Porcentaje: %%\n");
    printf("Porcentaje: %%\n");
    ft_printf("\n-------------\n");

    // Casos especiales
    ft_printf("-------------Casos especiales\n");
    ft_printf("Entero cero: %d\n", 0);
    ft_printf("Entero cero: %d\n", 0);
    ft_printf("\n-------------\n");
    ft_printf("Entero más pequeño: %d\n", INT_MIN);
    printf("Entero más pequeño: %d\n", INT_MIN);
    ft_printf("\n-------------\n");
    ft_printf("String vacía: %s\n", "");
    printf("String vacía: %s\n", "");
    ft_printf("\n-------------\n");
    ft_printf("Puntero nulo: %p\n", NULL);
    printf("Puntero nulo: %p\n", NULL);
    ft_printf("\n-------------\n");

    // Prueba con múltiples argumentos/conversiones
    ft_printf("Múltiples argumentos: %d, %s, %c\n", 123, "texto", 'X');
    printf("Múltiples argumentos: %d, %s, %c\n", 123, "texto", 'X');

    ft_printf("\n-------------\n");
    // Prueba de múltiples conversiones en medio de una frase
    ft_printf("Entero: %d, String: %s, Hexadecimal: %x\n", 456, "ejemplo", 0xDEADBEEF);
    printf("Entero: %d, String: %s, Hexadecimal: %x\n", 456, "ejemplo", 0xDEADBEEF);

    return 0;
}
*/


/*
int	main()
{
	//ft_printf("cspdiuxX%");
	//printf("cspdiuxX%z", "asdf");
	ft_printf("cspdiuxX%z", "asdf");
	return (0);
}
*/

/*int main() {
    printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %c - Print a single character
    ft_printf("BYANA --> %c \n", 'A');
    printf("ORIGI --> %c \n", 'A');
	printf(">\n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %s - Print a string
    ft_printf("BYANA --> %s \n", "Hello world");
    printf("ORIGI --> %s \n", "Hello world");
	printf(">\n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %p - Print a pointer in hexadecimal format
    char str[] = "Example";
    void *ptr = &str;
    ft_printf("BYANA --> %p \n", ptr);
    printf("ORIGI --> %p \n", ptr);
	printf(">\n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %d - Print a decimal number (base 10)
    int num = 42;
    ft_printf("BYANA --> %d \n", num);
    printf("ORIGI --> %d \n", num);
	printf(">\n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %i - Print an integer in base 10
    ft_printf("BYANA --> %i \n", num);
    printf("ORIGI --> %i \n", num);
	printf(">\n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %u - Print an unsigned decimal number (base 10)
    unsigned int uns_num = 100;
    ft_printf("BYANA --> %u \n", uns_num);
    printf("ORIGI --> %u \n", uns_num);
	printf(">\n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %x - Print a hexadecimal number in lowercase
    ft_printf("BYANA --> %x \n", num);
    printf("ORIGI --> %x \n", num);
	printf(">\n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %X - Print a hexadecimal number in uppercase
    ft_printf("BYANA --> %X \n", num);
    printf("ORIGI --> %X \n", num);
	printf("> \n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %% - Print the percentage symbol
    ft_printf("BYANA --> %% \n");
    printf("ORIGI --> %% \n");

    printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
    return 0;
}*/
