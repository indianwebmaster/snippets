#include <stdio.h>

struct THREE_STR_STRUCT {
    char str1[10], str2[10], str3[10];
};
typedef struct THREE_STR_STRUCT THREE_STR;

main()
{
    THREE_STR three_str_array[100] = {
                                        {"one1", "one2", "one3"},
                                        {"two1", "two2", "two3"}
                                    };
    int i;

    for (i=0; i<2; i++) {
        printf ("%s %s %s\n", three_str_array[i].str1, three_str_array[i].str2, three_str_array[i].str3);
    }
    return 0;
}

