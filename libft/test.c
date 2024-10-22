#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* int	main(void)
{
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello, Word!";
    size_t n;

    // Cas 1 : Comparaison sur les 5 premiers caractères (ils sont égaux)
    n = 5;
    printf("Comparing first %lu characters:\n", n);
    printf("   strncmp:   %d\n", strncmp(str1, str2, n));
    printf("ft_strncmp:   %d\n", ft_strncmp(str1, str2, n));

    // Cas 2 : Comparaison sur 10 caractères (ils sont toujours égaux)
    n = 10;
    printf("\nComparing first %lu characters:\n", n);
    printf("   strncmp:   %d\n", strncmp(str1, str2, n));
    printf("ft_strncmp:   %d\n", ft_strncmp(str1, str2, n));

    // Cas 3 : Comparaison sur tous les caractères (ils sont différents à partir du 8e)
    n = 13;
    printf("\nComparing first %lu characters:\n", n);
    printf("   strncmp:   %d\n", strncmp(str1, str2, n));
    printf("ft_strncmp:   %d\n", ft_strncmp(str1, str2, n));

    // Cas 4 : Comparaison sur 0 caractère (résultat devrait être 0)
    n = 0;
    printf("\nComparing first %lu characters (no characters):\n", n);
    printf("   strncmp:   %d\n", strncmp(str1, str2, n));
    printf("ft_strncmp:   %d\n", ft_strncmp(str1, str2, n));

    // Cas 5 : Comparaison de chaînes différentes dès le début
    str1 = "abc";
    str2 = "xyz";
    n = 3;
    printf("\nComparing first %lu characters:\n", n);
    printf("   strncmp:   %d\n", strncmp(str1, str2, n));
    printf("ft_strncmp:   %d\n", ft_strncmp(str1, str2, n));



    return 0;
} */

#include <stdio.h>
#include <string.h>

int main(void)
{
    const char mem1[] = { 'H', 'e', 'l', 'l', 'o', '\0', 'W', 'o', 'r', 'l', 'd' };
    const char mem2[] = { 'H', 'e', 'l', 'l', 'o', '\0', 'w', 'o', 'r', 'l', 'd' };
    size_t n;

    // Cas 1 : Comparaison de 5 premiers octets (ils sont identiques)
    n = 5;
    printf("Comparing first %zu bytes:\n", n);
    printf("   memcmp:   %d\n", memcmp(mem1, mem2, n));
    printf("ft_memcmp:   %d\n", ft_memcmp(mem1, mem2, n));

    // Cas 2 : Comparaison de 6 octets, incluant le '\0' (ils sont toujours identiques)
    n = 6;
    printf("\nComparing first %zu bytes:\n", n);
    printf("   memcmp:   %d\n", memcmp(mem1, mem2, n));
    printf("ft_memcmp:   %d\n", ft_memcmp(mem1, mem2, n));

    // Cas 3 : Comparaison de 7 octets (ils diffèrent à partir du 7e octet)
    n = 7;
    printf("\nComparing first %zu bytes:\n", n);
    printf("   memcmp:   %d\n", memcmp(mem1, mem2, n));
    printf("ft_memcmp:   %d\n", ft_memcmp(mem1, mem2, n));

    // Cas 4 : Comparaison sur 0 octet (résultat devrait être 0)
    n = 0;
    printf("\nComparing first %zu bytes (no comparison):\n", n);
    printf("   memcmp:   %d\n", memcmp(mem1, mem2, n));
    printf("ft_memcmp:   %d\n", ft_memcmp(mem1, mem2, n));

    // Cas 5 : Comparaison de chaînes complètement différentes
    const char mem3[] = { 'a', 'b', 'c', 'd' };
    const char mem4[] = { 'x', 'y', 'z', 'd' };
    n = 3;
    printf("\nComparing first %zu bytes:\n", n);
    printf("   memcmp:   %d\n", memcmp(mem3, mem4, n));
    printf("ft_memcmp:   %d\n", ft_memcmp(mem3, mem4, n));

    return 0;
}


