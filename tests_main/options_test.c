#include <stdio.h>
#include "../options.h"

int main(int argc, char **argv)
{
	char err = '\0';
	t_opts lol;
	def_opts_for_is_tty(&lol);
	int res = init_opts(argc - 1, argv + 1, &lol, &err);

	printf("res = %d, fail = \'%c\'\n", res, err);
	printf("@ = %d\n", get_opt(&lol, LS_EXTATT));
	printf("1 = %d\n", get_opt(&lol, LS_BYLINE));
	printf("a = %d\n", get_opt(&lol, LS_ALL));
	printf("C = %d\n", get_opt(&lol, LS_BYCLMN));
	printf("c = %d\n", get_opt(&lol, LS_STCHTI));
	printf("d = %d\n", get_opt(&lol, LS_DIRASF));
	printf("e = %d\n", get_opt(&lol, LS_ACL));
	printf("f = %d\n", get_opt(&lol, LS_NOSORT));
	printf("G = %d\n", get_opt(&lol, LS_COLOR));
	printf("g = %d\n", get_opt(&lol, LS_NOOWN));
	printf("h = %d\n", get_opt(&lol, LS_HUREAD));
	printf("l = %d\n", get_opt(&lol, LS_LONGF));
	printf("n = %d\n", get_opt(&lol, LS_NUMID));
	printf("o = %d\n", get_opt(&lol, LS_NOGRP));
	printf("p = %d\n", get_opt(&lol, LS_SLASHD));
	printf("R = %d\n", get_opt(&lol, LS_REC));
	printf("r = %d\n", get_opt(&lol, LS_REVSO));
	printf("S = %d\n", get_opt(&lol, LS_SIZESO));
	printf("t = %d\n", get_opt(&lol, LS_TIMESO));
	printf("U = %d\n", get_opt(&lol, LS_CREATI));
	printf("u = %d\n", get_opt(&lol, LS_ACCETI));

	return (0);
}
