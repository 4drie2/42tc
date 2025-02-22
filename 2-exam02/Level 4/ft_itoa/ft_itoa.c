#include <stdlib.h>

int nlen(int nbr)
{
	int i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

char	*ft_itoa(int nbr)
{
	char *cnum;
	int len;
	int i;

	len = nlen(nbr);
	i = 0;
	if (nbr < 0)
		i++;
	len = len + i;
	cnum = (char *)malloc((len + 1) * sizeof(char));
	if (!cnum)
		return (NULL);
	cnum[0] = '-';
	cnum[len] = '\0';
	while ((len - 1) >= i)
	{
		cnum[len - 1] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (cnum);
}

#include <stdlib.h>
#include <limits.h>
#include <string.h>

char *ft_itoa(int n) {
    char *str;
    int len = 0;
    int is_negative = 0;
    int temp;

    /* Cas particulier : n vaut 0 */
    if (n == 0) {
        str = malloc(2); /* "0" + '\0' */
        if (!str)
            return NULL;
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    /* Cas particulier : n vaut INT_MIN */
    if (n == INT_MIN) {
        str = malloc(12); /* "-2147483648" + '\0' */
        if (!str)
            return NULL;
        strcpy(str, "-2147483648");
        return str;
    }

    /* Gestion du signe */
    if (n < 0) {
        is_negative = 1;
        n = -n;  /* Maintenant, n est positif */
    }

    /* Calcul de la longueur nécessaire */
    temp = n;
    while (temp != 0) {
        len++;
        temp /= 10;
    }
    if (is_negative)
        len++;  /* Espace pour le '-' */

    /* Allocation de la chaîne */
    str = malloc(len + 1);
    if (!str)
        return NULL;
    str[len] = '\0';

    /* Remplissage de la chaîne de droite à gauche */
    while (n != 0) {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    if (is_negative)
        str[0] = '-';

    return str;
}

