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

/* int main(void)
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
} */

/* char *strnstr(const char *s, const char *find, t_size slen)
{
	char c, sc;
	t_size len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (0);
			} while (sc != c);
			if (len > slen)
				return (0);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}
int main(void)
{
    char big[] = "Hello, World! This is a test string for strnstr.";
    char little1[] = "World";
    char little2[] = "test";
    char little3[] = "strnstr";
    char little4[] = "notfound";
    char little5[] = "";
    char little6[] = "Hello";

    // Cas 1 : Recherche de "World" dans les 5 premiers caractères
    printf("Test 1: Searching 'World' in first 5 characters:\n");
    printf("   strnstr:   %s\n", strnstr(big, little1, 5) ? strnstr(big, little1, 5) : "Not Found");
    printf("   ft_strnstr:%s\n", ft_strnstr(big, little1, 5) ? ft_strnstr(big, little1, 5) : "Not Found");

    // Cas 2 : Recherche de "World" dans les 15 premiers caractères
    printf("\nTest 2: Searching 'World' in first 15 characters:\n");
    printf("   strnstr:   %s\n", strnstr(big, little1, 15) ? strnstr(big, little1, 15) : "Not Found");
    printf("   ft_strnstr:%s\n", ft_strnstr(big, little1, 15) ? ft_strnstr(big, little1, 15) : "Not Found");

    // Cas 3 : Recherche de "test" dans les 30 premiers caractères
    printf("\nTest 3: Searching 'test' in first 30 characters:\n");
    printf("   strnstr:   %s\n", strnstr(big, little2, 30) ? strnstr(big, little2, 30) : "Not Found");
    printf("   ft_strnstr:%s\n", ft_strnstr(big, little2, 30) ? ft_strnstr(big, little2, 30) : "Not Found");

    // Cas 4 : Recherche de "test" dans les 40 premiers caractères
    printf("\nTest 4: Searching 'test' in first 40 characters:\n");
    printf("   strnstr:   %s\n", strnstr(big, little2, 40) ? strnstr(big, little2, 40) : "Not Found");
    printf("   ft_strnstr:%s\n", ft_strnstr(big, little2, 40) ? ft_strnstr(big, little2, 40) : "Not Found");

    // Cas 5 : Recherche de "strnstr" dans la chaîne complète
    printf("\nTest 5: Searching 'strnstr' in full string:\n");
    printf("   strnstr:   %s\n", strnstr(big, little3, strlen(big)) ? strnstr(big, little3, strlen(big)) : "Not Found");
    printf("   ft_strnstr:%s\n", ft_strnstr(big, little3, strlen(big)) ? ft_strnstr(big, little3, strlen(big)) : "Not Found");

    // Cas 6 : Recherche de "notfound" dans la chaîne complète
    printf("\nTest 6: Searching 'notfound' in full string:\n");
    printf("   strnstr:   %s\n", strnstr(big, little4, strlen(big)) ? strnstr(big, little4, strlen(big)) : "Not Found");
    printf("   ft_strnstr:%s\n", ft_strnstr(big, little4, strlen(big)) ? ft_strnstr(big, little4, strlen(big)) : "Not Found");

    // Cas 7 : Recherche de chaîne vide "" dans la chaîne complète
    printf("\nTest 7: Searching empty string in full string:\n");
    printf("   strnstr:   %s\n", strnstr(big, little5, strlen(big)) ? strnstr(big, little5, strlen(big)) : "Not Found");
    printf("   ft_strnstr:%s\n", ft_strnstr(big, little5, strlen(big)) ? ft_strnstr(big, little5, strlen(big)) : "Not Found");

    // Cas 8 : Recherche de "Hello" dans les 10 premiers caractères
    printf("\nTest 8: Searching 'Hello' in first 10 characters:\n");
    printf("   strnstr:   %s\n", strnstr(big, little6, 10) ? strnstr(big, little6, 10) : "Not Found");
    printf("   ft_strnstr:%s\n", ft_strnstr(big, little6, 10) ? ft_strnstr(big, little6, 10) : "Not Found");

    // Cas 9 : Recherche de "Hello" dans les 4 premiers caractères
    printf("\nTest 9: Searching 'Hello' in first 4 characters:\n");
    printf("   strnstr:   %s\n", strnstr(big, little6, 4) ? strnstr(big, little6, 4) : "Not Found");
    printf("   ft_strnstr:%s\n", ft_strnstr(big, little6, 4) ? ft_strnstr(big, little6, 4) : "Not Found");

    return 0;
} */

/* void test_atoi(const char *str)//////////////// FT_ATOI
{
    int res_atoi = atoi(str);
    int res_ft_atoi = ft_atoi(str);

    printf("Testing: \"%s\"\n", str);
    printf("   atoi:    %d\n", res_atoi);
    printf("ft_atoi:    %d\n", res_ft_atoi);

    if (res_atoi == res_ft_atoi)
        printf("   -> Results match!\n");
    else
        printf("   -> Results differ!\n");

    printf("\n");
}

int	main(void)
{
    // Test de chaînes valides
    test_atoi("42");
    test_atoi("   42");
    test_atoi("   -42");
    test_atoi("+42");
    test_atoi("0");
    test_atoi("000123");
    test_atoi("   +0000042");

    // Test de chaînes avec des caractères non numériques
    test_atoi("42abc");
    test_atoi("   -42abc");
    test_atoi("abc42");
    test_atoi("   +0000042abc123");

    // Test de chaînes avec espaces blancs
    test_atoi("\t\n\v\f\r  42");  // Espaces blancs variés

    // Test de chaînes invalides ou vides
    test_atoi("");
    test_atoi("   ");
    test_atoi("-");
    test_atoi("+");
    test_atoi("--42");
    test_atoi("++42");

    return 0;
} */

/* void	test_ft_calloc(t_size count, t_size size) {
    printf("\nTesting ft_calloc with count = %u, size = %u\n", count, size);

    void *ptr = ft_calloc(count, size);
    void *sys_ptr = calloc(count, size);

    if (ptr == NULL || sys_ptr == NULL) {
        if (ptr == NULL)
            printf("   -> ft_calloc: Allocation failed\n");
        if (sys_ptr == NULL)
            printf("   -> calloc: Allocation failed\n");
    } else {
        if (memcmp(ptr, sys_ptr, count * size) == 0)
            printf("   -> Memory blocks are identical (ft_calloc works correctly)\n");
        else
            printf("   -> Memory blocks differ (ft_calloc is incorrect)\n");

        free(ptr);
        free(sys_ptr);
    }
}

int main(void) {
    test_ft_calloc(10, 4);
    test_ft_calloc(5, 1);
    test_ft_calloc((t_size)-1, 2);
    test_ft_calloc(0, 1);
    test_ft_calloc(1, 0);
    return 0;
} */

int	main(void)
{
    // Test 1 : Chaîne simple
    const char *str1 = "Hello, World!";
    char *dup1 = ft_strdup(str1);
    printf("Original: %s\nDuplicate: %s\n", str1, dup1);
    if (dup1)
        free(dup1); // Libérer la mémoire après usage

    // Test 2 : Chaîne vide
    const char *str2 = "";
    char *dup2 = ft_strdup(str2);
    printf("Original (empty): '%s'\nDuplicate (empty): '%s'\n", str2, dup2);
    if (dup2)
        free(dup2);

    // Test 3 : Chaîne avec des caractères spéciaux
    const char *str3 = "This\nis\ta test!";
    char *dup3 = ft_strdup(str3);
    printf("Original (special chars): %s\nDuplicate (special chars): %s\n", str3, dup3);
    if (dup3)
        free(dup3);

    // Test 4 : Chaîne très longue
    const char *str4 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin vel libero felis.";
    char *dup4 = ft_strdup(str4);
    printf("Original (long): %s\nDuplicate (long): %s\n", str4, dup4);
    if (dup4)
        free(dup4);

    // Test 5 : NULL en entrée (ne devrait pas planter)
    const char *str5 = NULL;
    char *dup5 = ft_strdup(str5);
    if (dup5 == NULL)
        printf("Test NULL input: Passed (returned NULL)\n");
    else
        printf("Test NULL input: Failed\n");

    // Test 6 : Chaîne avec des espaces
    const char *str6 = "    Leading and trailing spaces    ";
    char *dup6 = ft_strdup(str6);
    printf("Original (spaces): '%s'\nDuplicate (spaces): '%s'\n", str6, dup6);
    if (dup6)
        free(dup6);

    // Test 7 : Chaîne avec des chiffres et des symboles
    const char *str7 = "1234567890!@#$%^&*()_+";
    char *dup7 = ft_strdup(str7);
    printf("Original (numbers and symbols): %s\nDuplicate (numbers and symbols): %s\n", str7, dup7);
    if (dup7)
        free(dup7);

    // Test 8 : Chaîne avec un seul caractère
    const char *str8 = "A";
    char *dup8 = ft_strdup(str8);
    printf("Original (single char): %s\nDuplicate (single char): %s\n", str8, dup8);
    if (dup8)
        free(dup8);

    return 0;
}