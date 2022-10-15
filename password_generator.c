#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char	*generate_password(unsigned int len)
{
	// Seed the randome value with the current time
	srand(time(0));
	int		rand_num;
	unsigned int	i;
	char		*pwd;
	int		lower;
	int		bigger;

	pwd = (char *) calloc(len, sizeof(char));
	if (!pwd)
		exit(1);
	// Setting the range of the characters we use from ascii table.
	lower = 33;
	bigger=126;
	i = 0;
	while (i < len)
	{
		rand_num = rand() % (bigger - lower + 1) + lower;
		pwd[i] = (char )rand_num;
		i++;
	}
	pwd[i] = '\0';
	return (pwd);
}

int	main(void)
{
	int	len = 15;
	char	*passwd = calloc(15, sizeof(char));
	
	passwd = generate_password(len);	
	
	printf("%s\n", passwd);
}
