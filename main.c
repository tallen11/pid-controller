#include <stdio.h>
#include "pid.h"

int main() {
    pid_controller_t *pid = pid_new(0.1f, 0.0f, 0.0f, 64);
    printf("PID: %p\n", pid);

    pid_free(pid);
    printf("PID: %p\n", pid);

    return 0;
}