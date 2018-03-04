#ifndef __PID_H
#define __PID_H

#include <stdlib.h>

typedef struct {
    float p_param;
    float i_param;
    float d_param;
    float *buffer;
    size_t bufferLength;
    float totalError;
    float lastError;
} pid_controller_t;

// API methods
pid_controller_t* pid_new(float p_param, float i_param, float d_param, size_t bufferLength);
void pid_update(pid_controller_t* pid, float* targetBuffer);
void pid_reset(pid_controller_t* pid);
void pid_free(pid_controller_t* pid);

#endif /* __PID_H */