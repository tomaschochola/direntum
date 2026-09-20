#include "test.h"

#include "todo.h"

static void test_todo_returns_zero(void)
{
    EXPECT_TRUE(direntum_todo() == 0);
}

int main(void)
{
    test_todo_returns_zero();

    return test_done();
}
