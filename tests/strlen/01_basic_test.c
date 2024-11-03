#include <string.h>

#define BASIC_STRING	"ALL UR BASE R BELONG 2 US"
#define BASIC_LEN		25

int basic_test(void)
{
	if (strlen(BASIC_STRING) == BASIC_LEN)
		return (0);
	return (-1);
}
