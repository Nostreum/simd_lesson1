#ifndef TIMER_H_
#define TIMER_H_

#include <time.h>
#include <simd.h>

#define NANO_SEC 1000000000

typedef struct timer_s ltimer_t;
struct timer_s {

    struct timespec t1;
    struct timespec t2;

    struct timespec delta;
};

void start_timer(ltimer_t *timer);
void end_timer(ltimer_t *timer);
void end_timer_get_diff(ltimer_t *timer);
double get_time_in_sec_from_timer(ltimer_t *timer);
double launch_N_test(void (*callback)(f32**, f32**, f32**, int, int),
                      f32** img, f32** mask, f32** out, int N, int nbtest);
struct timespec diff(struct timespec start, struct timespec end);

#endif /* TIMER_H */
