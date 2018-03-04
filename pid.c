#include "pid.h"

pid_controller_t* pid_new(float p_param, float i_param, float d_param, size_t bufferLength) {
    pid_controller_t *pid = (pid_controller_t*)malloc(sizeof(pid_controller_t));
    pid->p_param = p_param;
    pid->i_param = i_param;
    pid->d_param = d_param;
    pid->buffer = (float*)malloc(sizeof(float) * bufferLength);
    pid->bufferLength = bufferLength;
    pid->totalError = 0.0f;

    for (size_t i = 0; i < bufferLength; ++i) {
        pid->buffer[i] = 0.0f;
    }

    return pid;
}

void pid_update(pid_controller_t* pid, float* targetBuffer) {
    if (pid == NULL) {
        printf("Tried to update NULL pid controller!\n");
        return;
    }

    for (size_t i = 0; i < pid->bufferLength; ++i) {
        float target = targetBuffer[i];
        float current = pid->buffer[i];

        float delta = target - current;
        pid->totalError += delta;
        
        float p = delta * pid->p_param;
        float i = pid->totalError * pid->i_param;
        float d = 0.0f;

        float output = p + i + d;
    }
}

void pid_reset(pid_controller_t* pid) {
    if (pid == NULL) {
        printf("Tried to reset NULL pid controller!\n");
        return;
    }

    pid->totalError = 0.0f;
    for (size_t i = 0; i < pid->bufferLength; ++i) {
        pid->buffer[i] = 0.0f;
    }
}

void pid_free(pid_controller_t* pid) {
    if (pid != NULL) {
        if (pid->buffer != NULL) {
            free(pid->buffer);
        }

        free(pid);
        pid = NULL;
    }
}
