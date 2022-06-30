#include <stdlib.h>
#include <string.h>

#include "there_would_be_no_math.h"

static int compare(void const* p1, void const* p2)
{
    return *(int*)(p1) - *(int*)(p2);
}

unsigned there_would_be_no_math(unsigned n, char const* s[n])
{
    unsigned p = 0, u[3], v[3];
    char t[] = {[9] = 0};

    for (unsigned i = 0, t_len = 0, s_len = 0; i < n; i++, s_len = 0) {
        char const* str = s[i];

        for (unsigned j = 0; j <= strlen(str); j++) {
            if ((str[j] == 'x' || str[j] == '\0') && *t != '\0') {
                u[s_len++] = atoi(t);
                memset(t, 0, t_len);
                t_len = 0;
            } else {
                t[t_len++] = str[j];
            }
        }
        v[0] = u[0] * u[1];
        v[1] = u[1] * u[2];
        v[2] = u[0] * u[2];
        qsort(&v, 3, sizeof(unsigned), compare);
        p += 2 * v[0] + 2 * v[1] + 2 * v[2] + v[0];
    }
    return p;
}

unsigned there_would_be_no_math_part_two(unsigned n, char const* s[n])
{
    unsigned p = 0, u[3];
    char t[] = {[9] = 0};

    for (unsigned i = 0, t_len = 0, s_len = 0; i < n; i++, s_len = 0) {
        char const* str = s[i];

        for (unsigned j = 0; j <= strlen(str); j++) {
            if ((str[j] == 'x' || str[j] == '\0') && *t != '\0') {
                u[s_len++] = atoi(t);
                memset(t, 0, t_len);
                t_len = 0;
            } else {
                t[t_len++] = str[j];
            }
        }
        qsort(&u, 3, sizeof(unsigned), compare);
        p += 2 * u[0] + 2 * u[1] + u[0] * u[1] * u[2];
    }
    return p;
}
