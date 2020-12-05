#include "string.h"

#include "not_quite_lisp.h"

int not_quite_lisp(char const* input)
{
    int n = 0;
    unsigned length = strlen(input);

    for (unsigned i = 0; i < length; i++) {
        n += input[i] == '(' ? 1 : -1;
    }
    return n;
}

unsigned not_quite_lisp_part_two(char const* input)
{
    int n = 0;
    unsigned length = strlen(input), f = 0;

    for (unsigned i = 0; i < length; i++) {
        n += input[i] == '(' ? 1 : -1;
        if (n < 0) {
            f = i + 1;
            break;
        }
    }
    return f;
}
