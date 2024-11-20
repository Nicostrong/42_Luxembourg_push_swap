/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:36:11 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/15 13:36:22 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("\033[0m*********************************\n");
	printf("*\tTESTER FT_PRINTF\t*\n");
	printf("*********************************\n");

	printf("\n_________________________________\n");
	printf("\n\tTEST %%C\n");
	printf("_________________________________\n\n");
	
	char	*s;
	char	c;
	int		ret_1;
	int		ret_2;

	// test 1
	s = "\033[1;94mSalut %c\n";
	c = '!';
	ret_1 = ft_printf(s, c);
	ret_2 = printf(s, c);
	ret_1 == ret_2 ? printf("\033[1;92m\n1) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n1) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 2
	s = "\033[1;94m%c%c%c\n";
	c = '!';
	ret_1 = ft_printf(s, c, c, c);
	ret_2 = printf(s, c, c , c);
	ret_1 == ret_2 ? printf("\033[1;92m\n2) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n2) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 3
	s = "\033[1;94m";
	c = '!';
	ret_1 = ft_printf(s, c);
	ret_2 = printf(s, c);
	ret_1 == ret_2 ? printf("\033[1;92m\n3) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n3) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 4
	s = "\033[1;94mBla bla %c\n";
	c = '0';
	ret_1 = ft_printf(s, c);
	ret_2 = printf(s, c);
	ret_1 == ret_2 ? printf("\033[1;92m\n4) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n4) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 5
	s = "\033[1;94mtest %c\n";
	c = 0;
	ret_1 = ft_printf(s, c);
	ret_2 = printf(s, c);
	ret_1 == ret_2 ? printf("\033[1;92m\n5) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n5) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 6
	s = "\033[1;94mcode %c\n";
	c = -42;
	ret_1 = ft_printf(s, c);
	ret_2 = printf(s, c);
	ret_1 == ret_2 ? printf("\033[1;92m\n6) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n6) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 7
	s = "\033[1;94mbouh\n";
	c = -102;
	ret_1 = ft_printf(s, c);
	ret_2 = printf(s, c);
	ret_1 == ret_2 ? printf("\033[1;92m\n7) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n7) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 8
	s = "\033[1;94mbouh\n";
	ret_1 = ft_printf(s, 300);
	ret_2 = printf(s, 300);
	ret_1 == ret_2 ? printf("\033[1;92m\n8) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n8) %d != %d => [KO]\n", ret_1, ret_2);
	
	printf("\033[0m\n_________________________________\n");
	printf("\n\tTEST %%s\n");
	printf("_________________________________\n\n");
	
	char	*s2;
	char	*s3;

	// test 1
	s = "\033[1;94mSalut %s les gens !!\n";
	s2 = "\033[1;94mtout le monde";
	ret_1 = ft_printf(s, s2);
	ret_2 = printf(s, s2);
	ret_1 == ret_2 ? printf("\033[1;92m\n1) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n1) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 2
	s = "\033[1;94mSalut %s les gens %s\n";
	s2 = "\033[1;94mtout le monde";
	s3 = "\033[1;94mwéééch gros @@@";
	ret_1 = ft_printf(s, s2, s3);
	ret_2 = printf(s, s2, s3);
	ret_1 == ret_2 ? printf("\033[1;92m\n2) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n2) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 3
	s = "\033[1;94mSalut %s les gens %s\n";
	s2 = "\033[1;94mbeurck";
	ret_1 = ft_printf(s, s2, NULL);
	ret_2 = printf(s, s2, NULL);
	ret_1 == ret_2 ? printf("\033[1;92m\n3) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n3) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 4
	s = "\033[1;94mHello %s\n";
	ret_1 = ft_printf(s, NULL);
	ret_2 = printf(s, NULL);
	ret_1 == ret_2 ? printf("\033[1;92m\n4) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n4) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 5
	s = "\033[1;94mSalut %s les gens %s\n";
	ret_1 = ft_printf(s, NULL, s2);
	ret_2 = printf(s, NULL, s2);
	ret_1 == ret_2 ? printf("\033[1;92m\n5) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n5) %d != %d => [KO]\n", ret_1, ret_2);

	printf("\033[0m\n_________________________________\n");
	printf("\n\tTEST %%d\n");
	printf("_________________________________\n\n");

	int	n;

	// test 1
	s = "\033[1;94mSalut les %d gens !!\n";
	n = 100;
	ret_1 = ft_printf(s, n);
	ret_2 = printf(s, n);
	ret_1 == ret_2 ? printf("\033[1;92m\n1) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n1) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 2
	s = "\033[1;94mINT_MAX %d\n";
	n = 2147483647;
	ret_1 = ft_printf(s, n);
	ret_2 = printf(s, n);
	ret_1 == ret_2 ? printf("\033[1;92m\n2) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n2) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 3
	s = "\033[1;94mINT_MIN %d\n";
	n = -2147483648;
	ret_1 = ft_printf(s, n);
	ret_2 = printf(s, n);
	ret_1 == ret_2 ? printf("\033[1;92m\n3) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n3) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 4
	s = "\033[1;94mSalut les %d\n";
	ret_1 = ft_printf(s, NULL);
	ret_2 = printf(s, NULL);
	ret_1 == ret_2 ? printf("\033[1;92m\n4) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n4) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 5
	s = "\033[1;94mINT_MAX + 1 %d\n";
	ret_1 = ft_printf(s, 2147483648);
	ret_2 = printf(s, 2147483648);
	ret_1 == ret_2 ? printf("\033[1;92m\n5) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n5) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 6
	s = "\033[1;94mINT_MIN - 1 %d\n";
	ret_1 = ft_printf(s, -2147483649);
	ret_2 = printf(s, -2147483649);
	ret_1 == ret_2 ? printf("\033[1;92m\n6) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n6) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 7
	s = "\033[1;94mINT_MIN - 100 %d\n";
	ret_1 = ft_printf(s, -2147483748);
	ret_2 = printf(s, -2147483748);
	ret_1 == ret_2 ? printf("\033[1;92m\n7) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n7) %d != %d => [KO]\n", ret_1, ret_2);
	
	printf("\033[0m\n_________________________________\n");
	printf("\n\tTEST %%i\n");
	printf("_________________________________\n\n");

	// test 1
	s = "\033[1;94mSalut les %i gens !!\n";
	n = 100;
	ret_1 = ft_printf(s, n);
	ret_2 = printf(s, n);
	ret_1 == ret_2 ? printf("\033[1;92m\n1) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n1) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 2
	s = "\033[1;94mINT_MAX %i\n";
	n = 2147483647;
	ret_1 = ft_printf(s, n);
	ret_2 = printf(s, n);
	ret_1 == ret_2 ? printf("\033[1;92m\n2) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n2) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 3
	s = "\033[1;94mINT_MIN %i\n";
	n = -2147483648;
	ret_1 = ft_printf(s, n);
	ret_2 = printf(s, n);
	ret_1 == ret_2 ? printf("\033[1;92m\n3) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n3) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 4
	s = "\033[1;94mSalut les %i\n";
	ret_1 = ft_printf(s, NULL);
	ret_2 = printf(s, NULL);
	ret_1 == ret_2 ? printf("\033[1;92m\n4) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n4) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 5
	s = "\033[1;94mINT_MAX + 1 %i\n";
	ret_1 = ft_printf(s, 2147483648);
	ret_2 = printf(s, 2147483648);
	ret_1 == ret_2 ? printf("\033[1;92m\n5) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n5) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 6
	s = "\033[1;94mINT_MIN - 1 %i\n";
	ret_1 = ft_printf(s, -2147483649);
	ret_2 = printf(s, -2147483649);
	ret_1 == ret_2 ? printf("\033[1;92m\n6) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n6) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 7
	s = "\033[1;94mINT_MIN - 100 %i\n";
	ret_1 = ft_printf(s, -2147483748);
	ret_2 = printf(s, -2147483748);
	ret_1 == ret_2 ? printf("\033[1;92m\n7) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n7) %d != %d => [KO]\n", ret_1, ret_2);
	
	printf("\033[0m\n_________________________________\n");
	printf("\n\tTEST %%x\n");
	printf("_________________________________\n\n");

	unsigned int 	uc;

	// test 1
	s = "\033[1;94mla lettre 'O' en hexa (4f) => %x\n";
	uc = 79;
	ret_1 = ft_printf(s, uc);
	ret_2 = printf(s, uc);
	ret_1 == ret_2 ? printf("\033[1;92m\n1) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n1) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 2
	s = "\033[1;94m12 en hexa (c) => %x\n";
	uc = 12;
	ret_1 = ft_printf(s, uc);
	ret_2 = printf(s, uc);
	ret_1 == ret_2 ? printf("\033[1;92m\n2) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n2) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 3
	s = "\033[1;94m32 en hexa (20)=> %x\n";
	uc = 32;
	ret_1 = ft_printf(s, uc);
	ret_2 = printf(s, uc);
	ret_1 == ret_2 ? printf("\033[1;92m\n3) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n3) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 4
	s = "\033[1;94m245 en hexa (f5)=> %x\n";
	uc = 245;
	ret_1 = ft_printf(s, uc);
	ret_2 = printf(s, uc);
	ret_1 == ret_2 ? printf("\033[1;92m\n4) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n4) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 5
	s = "\033[1;94mMax value of %%x en hexa (ffffffff)=> %x\n";
	uc = 4294967295;
	ret_1 = ft_printf(s, uc);
	ret_2 = printf(s, uc);
	ret_1 == ret_2 ? printf("\033[1;92m\n5) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n5) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 6
	s = "\033[1;94m-42 value of %%x en hexa (ffffffd6)=> %x\n";
	uc = -42;
	ret_1 = ft_printf(s, uc);
	ret_2 = printf(s, uc);
	ret_1 == ret_2 ? printf("\033[1;92m\n6) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n6) %d != %d => [KO]\n", ret_1, ret_2);
	
	printf("\033[0m\n_________________________________\n");
	printf("\n\tTEST %%X\n");
	printf("_________________________________\n\n");

	// test 1
	s = "\033[1;94mla lettre 'O' en hexa (4F) => %X\n";
	uc = 79;
	ret_1 = ft_printf(s, uc);
	ret_2 = printf(s, uc);
	ret_1 == ret_2 ? printf("\033[1;92m\n1) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n1) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 2
	s = "\033[1;94m12 en hexa (c) => %X\n";
	uc = 12;
	ret_1 = ft_printf(s, uc);
	ret_2 = printf(s, uc);
	ret_1 == ret_2 ? printf("\033[1;92m\n2) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n2) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 3
	s = "\033[1;94m32 en hexa (20)=> %X\n";
	uc = 32;
	ret_1 = ft_printf(s, uc);
	ret_2 = printf(s, uc);
	ret_1 == ret_2 ? printf("\033[1;92m\n3) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n3) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 4
	s = "\033[1;94m245 en hexa (F5)=> %X\n";
	uc = 245;
	ret_1 = ft_printf(s, uc);
	ret_2 = printf(s, uc);
	ret_1 == ret_2 ? printf("\033[1;92m\n4) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n4) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 5
	s = "\033[1;94mMax value of %%x en hexa (FFFFFFFF)=> %X\n";
	uc = 4294967295;
	ret_1 = ft_printf(s, uc);
	ret_2 = printf(s, uc);
	ret_1 == ret_2 ? printf("\033[1;92m\n5) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n5) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 6
	s = "\033[1;94m-42 value of %%x en hexa (FFFFFFD6)=> %X\n";
	uc = -42;
	ret_1 = ft_printf(s, uc);
	ret_2 = printf(s, uc);
	ret_1 == ret_2 ? printf("\033[1;92m\n6) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n6) %d != %d => [KO]\n", ret_1, ret_2);
	
	printf("\033[0m\n_________________________________\n");
	printf("\n\tTEST %%u\n");
	printf("_________________________________\n\n");

	// test 1
	s = "\033[1;94mvaleur de 0 => %u\n";
	uc = 0;
	ret_1 = ft_printf(s, uc);
	ret_2 = printf(s, uc);
	ret_1 == ret_2 ? printf("\033[1;92m\n1) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n1) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 2
	s = "\033[1;94m1234567890  => %u\n";
	uc = 1234567890;
	ret_1 = ft_printf(s, uc);
	ret_2 = printf(s, uc);
	ret_1 == ret_2 ? printf("\033[1;92m\n2) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n2) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 3
	s = "\033[1;94m4294967295 => %u\n";
	uc = 4294967295;
	ret_1 = ft_printf(s, uc);
	ret_2 = printf(s, uc);
	ret_1 == ret_2 ? printf("\033[1;92m\n3) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n3) %d != %d => [KO]\n", ret_1, ret_2);
	
	printf("\033[0m\n_________________________________\n");
	printf("\n\tTEST %%p\n");
	printf("_________________________________\n\n");
	
	// test 1
	s = "\033[1;94mpointer de *s => %p\n";
	ret_1 = ft_printf(s, s);
	ret_2 = printf(s, s);
	ret_1 == ret_2 ? printf("\033[1;92m\n1) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n1) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 2
	s = "\033[1;94mptr NULL  => %p\n";
	s2	 = NULL;
	ret_1 = ft_printf(s, s2);
	ret_2 = printf(s, s2);
	ret_1 == ret_2 ? printf("\033[1;92m\n2) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n2) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 3
	s = "\033[1;94mptr + 2 => %p\n";
	ret_1 = ft_printf(s, s + 2);
	ret_2 = printf(s, s + 2);
	ret_1 == ret_2 ? printf("\033[1;92m\n3) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n3) %d != %d => [KO]\n", ret_1, ret_2);
		
	printf("\033[0m\n_________________________________\n");
	printf("\n\tTEST MULTIPLE\n");
	printf("_________________________________\n\n");
	
	// test 1
	s = "\033[1;94mpointer de *s => %p | value %s\n";
	ret_1 = ft_printf(s, s, s);
	ret_2 = printf(s, s, s);
	ret_1 == ret_2 ? printf("\033[1;92m\n1) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n2) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 2
	s = "\033[1;94m%u %% %d %% %s %% %c %p\n";
	ret_1 = ft_printf(s, uc, n, s3, c, s3, -42, 42);
	ret_2 = printf(s, uc, n, s3, c, s3, -42, 42);
	ret_1 == ret_2 ? printf("\033[1;92m\n2) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n2) %d != %d => [KO]\n", ret_1, ret_2);
	
	// test 3
	s = "\033[1;94m%u %% %d %% %s %% %c %p %x %X\n";
	ret_1 = ft_printf(s, uc, n, s2, c, s3, -42, 42);
	ret_2 = printf(s, uc, n, s2, c, s3, -42, 42);
	ret_1 == ret_2 ? printf("\033[1;92m\n3) %d == %d => [OK]\n", ret_1, ret_2) : printf("\033[1;91m\n3) %d != %d => [KO]\n", ret_1, ret_2);

	return (0);

}
