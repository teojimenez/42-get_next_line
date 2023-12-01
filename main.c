#include "get_next_line.h"

int	main(void)
{
	int		file_descriptor;
	char	*result;

	file_descriptor = open("tests/test1.txt", O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	result = get_next_line(file_descriptor);
	if (result == NULL)
		return (0);
	while (result != NULL)
	{
		printf("%s", result);
		free(result);
		result = NULL;
		result = get_next_line(file_descriptor);
		if (result == NULL)
			return (0);
	}
	free(result);
	result = NULL;
	return (0);
}