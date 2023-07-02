#include "liblife.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (argv[1][0] == 'c')
	{
		argc = ConwaysGameofLife();
		return (0);
	}
	if (argv[1][0] == 'g')
	{
		argc = G_simulation();
		return (0);
	}
	return (1);
}
