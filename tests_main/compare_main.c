#include <stdio.h>
#include "../options.h"
#include "../print.h"
#include "../compare_utils.h"

int main(int argc, char **argv)
{
	char err = '\0';
	t_opts lol;
	int res;

	lol.mask = 0;
	def_opts_for_is_tty(&lol);
	res = init_opts(argc - 1, argv + 1, &lol, &err);
	set_cmp_fun(&lol);
	set_winsize(&lol);
	set_tab_w(&lol);

	if (lol.cmp_fun == cmp_file_size_rev)
		printf("size_rev\n");
	else if (lol.cmp_fun == cmp_file_stch_rev)
		printf("stch_rev\n");
	else if (lol.cmp_fun == cmp_file_crea_rev)
		printf("crea_rev\n");
	else if (lol.cmp_fun == cmp_file_acce_rev)
		printf("acce_rev\n");
	else if (lol.cmp_fun == cmp_file_time_rev)
		printf("time_rev\n");
	else if (lol.cmp_fun == cmp_file_lexical_rev)
		printf("lexical_rev\n");
	else if (lol.cmp_fun == cmp_file_size)
		printf("size\n");
	else if (lol.cmp_fun == cmp_file_stch)
		printf("stch\n");
	else if (lol.cmp_fun == cmp_file_crea)
		printf("crea\n");
	else if (lol.cmp_fun == cmp_file_acce)
		printf("acce\n");
	else if (lol.cmp_fun == cmp_file_time)
		printf("time\n");
	else if (lol.cmp_fun == cmp_file_lexical)
		printf("lexical\n");
	else if (lol.cmp_fun == NULL)
		printf("NULL\n");
	else
		printf("error\n");

	return (0);
}
