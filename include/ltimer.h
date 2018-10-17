#ifndef TIMER_H_
#define TIMER_H_

#include <time.h>
#include <simd.h>

#define NANO_SEC 1000000000

typedef struct timer_s timer_t;
struct timer_s {

    struct timespec t1;
    struct timespec t2;

    struct timespec delta;
};

void start_timer(timer_t *timer);
void end_timer(timer_t *timer);
void end_timer_get_diff(timer_t *timer);
double get_time_in_sec_from_timer(timer_t *timer);
timer_t launch_N_test(void (*callback)(f32**, f32**, f32**, int, int),
                      f32** img, f32** mask, f32** out, int N, int nbtest);
struct timespec diff(struct timespec start, struct timespec end);

#endif /* TIMER_H */
