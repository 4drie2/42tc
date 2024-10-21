/* ************************************************************************** */

/*                                                                            */

/*                                                        :::      ::::::::   */

/*   ft_strlcpy.c                                       :+:      :+:    :+:   */

/*                                                    +:+ +:+         +:+     */

/*   By: abidaux <abidaux@student.42lehavre.fr>     +#+  +:+       +#+        */

/*                                                +#+#+#+#+#+   +#+           */

/*   Created: 2024/10/19 13:49:21 by abidaux           #+#    #+#             */

/*   Updated: 2024/10/19 13:49:21 by abidaux          ###   ########.fr       */

/*                                                                            */

/* ************************************************************************** */



#include "libft.h"



extern t_size ft_strlcpy(char *dst, const char *src, t_size size)

{

    

	if (size > 0)

	{

		t_size i;



		i = -1;

		while (++i < (size - 1))

		{

			dst[i] = src[i];

		}

			dst[size - 1] = '\0';

	}

}



#include <string.h>

#include <stdio.h>



int main(int argc, char const *argv[])

{

	char src1[] = "Vive les licornes";

	char src2[] = "Vive les licornes";

	char dst1[18];

	char dst2[18];



	strlcpy(dst1, src1, 18);

	ft_strlcpy(dst2, src2, 18);

	printf("   strlcpy:%s\nft_strlcpy:%s\n", dst1, dst2);

	return 0;

}

