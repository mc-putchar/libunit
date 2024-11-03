#include <string.h>

#define BIGGER_STRING	"'The quick brown fox jumps over the lazy dog' is an \
English-language pangram - a sentence that contains all the letters of the \
alphabet."
#define BIGGER_LEN		136

int bigger_str_test(void)
{
	if (strlen(BIGGER_STRING) == BIGGER_LEN)
		return (0);
	return (-1);
}
