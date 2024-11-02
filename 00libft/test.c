#include "libft.h"
// Fonction pour libérer la mémoire allouée par ft_split
void ft_free_split(char **split)
{
    int i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}
// Fonction pour transformer chaque caractère en majuscule
char uppercase_map(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}
void run_tests(void) {
    // Test de ft_atoi
    printf("ft_atoi: %d\n", ft_atoi("-42"));
    // Test de ft_bzero
    char bzero_str[] = "On en a gros !";
    ft_bzero(bzero_str, 4);
    printf("ft_bzero: %s\n", bzero_str + 4);  // Affiche "n a gros !"
    // Test de ft_calloc
    int *arr = ft_calloc(5, sizeof(int));
    printf("ft_calloc: %d\n", arr[0]); // "C'est pas faux" pour vérifier l'initialisation
    free(arr);
    // Test de ft_isalnum, ft_isalpha, ft_isdigit, ft_isprint
    printf("ft_isalnum: %d\n", ft_isalnum('P'));
    printf("ft_isalpha: %d\n", ft_isalpha('A'));
    printf("ft_isdigit: %d\n", ft_isdigit('3'));
    printf("ft_isprint: %d\n", ft_isprint('!'));
    // Test de ft_itoa
    char *itoa_str = ft_itoa(-123);
    printf("ft_itoa: %s\n", itoa_str);
    free(itoa_str);
    // Test de ft_memchr
    char *memchr_str = ft_memchr("Le gras, c'est la vie", 'g', 20);
    printf("ft_memchr: %s\n", memchr_str);
    // Test de ft_memcmp
    printf("ft_memcmp: %d\n", ft_memcmp("Salade", "Salami", 5));
    // Test de ft_memcpy
    char memcpy_dst[30];
    ft_memcpy(memcpy_dst, "J'ai glissé, chef !", 19);
    printf("ft_memcpy: %s\n", memcpy_dst);
    // Test de ft_memmove
    char memmove_str[] = "C'est pas faux !";
    ft_memmove(memmove_str + 5, memmove_str, 9);
    printf("ft_memmove: %s\n", memmove_str);
    // Test de ft_memset
    char memset_str[] = "123456789";
    ft_memset(memset_str, '*', 5);
    printf("ft_memset: %s\n", memset_str);  // "*****6789"
    // Test de ft_putchar_fd
    ft_putchar_fd('A', 1);
    printf("\n");
    // Test de ft_putendl_fd
    ft_putendl_fd("C'est pas faux !", 1);
    // Test de ft_putnbr_fd
    ft_putnbr_fd(56, 1);
    printf("\n");
    // Test de ft_putstr_fd
    ft_putstr_fd("Putain, c’est pas vrai !\n", 1);
    // Test de ft_split
    char **split_result = ft_split("Va te faire cuire un oeuf-Arthur-Perceval", '-');
    for (int i = 0; split_result[i] != NULL; i++)
        printf("ft_split: %s\n", split_result[i]);
    ft_free_split(split_result);
    // Test de ft_strchr
    printf("ft_strchr: %s\n", ft_strchr("Sire, sire, on en a gros !", 'g'));
    // Test de ft_strdup
    char *strdup_str = ft_strdup("C'est pas faux !");
    printf("ft_strdup: %s\n", strdup_str);
    free(strdup_str);
    // Test de ft_strjoin
    char *joined_str = ft_strjoin("La table ronde, ", "c'est une foutue légende !");
    printf("ft_strjoin: %s\n", joined_str);
    free(joined_str);
    // Test de ft_strlcat et ft_strlcpy
    char strlcat_dst[30] = "Je suis";
    size_t len = ft_strlcat(strlcat_dst, " le roi Arthur !", 30);
    printf("ft_strlcat: %zu, Result: %s\n", len, strlcat_dst);
    char strlcpy_dst[15];
    ft_strlcpy(strlcpy_dst, "Le Graal !", sizeof(strlcpy_dst));
    printf("ft_strlcpy: %s\n", strlcpy_dst);
    // Test de ft_strlen
    printf("ft_strlen: %zu\n", ft_strlen("J'aime bien les fleurs."));
    // Test de ft_strmapi
    char *mapped = ft_strmapi("kaamelott", uppercase_map);
    printf("ft_strmapi: %s\n", mapped);
    free(mapped);
    // Test de ft_strncmp
    printf("ft_strncmp: %d\n", ft_strncmp("Merlin", "Mordred", 3));
    // Test de ft_strnstr
    printf("ft_strnstr: %s\n", ft_strnstr("Je suis le roi Arthur, fils d'Uther Pendragon", "roi", 50));
    // Test de ft_strrchr
    printf("ft_strrchr: %s\n", ft_strrchr("C'est quand même pas sorcier.", 'e'));
    // Test de ft_strtrim
    char *trimmed_str = ft_strtrim("   Par la Sainte Moustache !   ", " ");
    printf("ft_strtrim: '%s'\n", trimmed_str);
    free(trimmed_str);
    // Test de ft_substr
    char *substr = ft_substr("Les miracles, c'est pas pour les chiens !", 4, 9);
    printf("ft_substr: %s\n", substr);
    free(substr);
    // Test de ft_tolower et ft_toupper
    printf("ft_tolower: A -> %c\n", ft_tolower('A'));
    printf("ft_toupper: b -> %c\n", ft_toupper('b'));
    // Test de ft_lstnew, ft_lstadd_back et ft_lstclear
    t_list *list = ft_lstnew(ft_strdup("On en a gros !"));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("C'est pas faux.")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Ça me paraît énorme.")));
    t_list *tmp = list;
    while (tmp) {
        printf("%s -> ", (char *)tmp->content);
        tmp = tmp->next;
    }
    printf("NULL\n");
    ft_lstclear(&list, free);
}
int main(void) {
    run_tests();
    return 0;
}
