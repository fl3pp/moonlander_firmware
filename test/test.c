#include <acutest.h>

void test_example(void)
{
    void* mem;
    int a, b;

    mem = malloc(10);
    TEST_CHECK(mem != NULL);

    mem = realloc(mem, 20);
    TEST_CHECK(mem != NULL);
}

TEST_LIST = {
   { "example", test_example },
   
   { NULL, NULL }     /* zeroed record marking the end of the list */
};