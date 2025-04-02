#include <stdio.h>
#include <hiredis/hiredis.h>

int main() {
    redisContext *context = redisConnect("127.0.0.1", 6379);
    if (context == NULL || context->err) {
        if (context) {
            printf("Error: %s\n", context->errstr);
            redisFree(context);
        } else {
            printf("Can't allocate redis context\n");
        }
        return 1;
    }

    printf("Connected to Redis\n");
    redisFree(context);
    return 0;
}
