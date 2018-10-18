#include <ltimer.h>

struct timespec diff(struct timespec start, struct timespec end) {
	struct timespec temp;
	if ((end.tv_nsec-start.tv_nsec)<0) {
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	} else {
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp;
}

double launch_N_test(void (*callback)(f32**, f32**, f32**, int, int),
                      f32** img, f32** mask, f32** out, int size, int nbtest) {

    double time = 0.0f;
    ltimer_t timer;

    for (int i=0; i<nbtest; i++) {
        start_timer(&timer);
        callback(img, mask, out, size, size);
        end_timer_get_diff(&timer);
        time += get_time_in_sec_from_timer(&timer);
    }

    time /= nbtest;

    return time;
}

void start_timer(ltimer_t *timer) {
    clock_gettime(CLOCK_MONOTONIC, &timer->t1);
}

void end_timer(ltimer_t *timer) {
    clock_gettime(CLOCK_MONOTONIC, &timer->t2);
}

void end_timer_get_diff(ltimer_t *timer) {
    clock_gettime(CLOCK_MONOTONIC, &timer->t2);
    timer->delta = diff(timer->t1, timer->t2);
}

double get_time_in_sec_from_timer(ltimer_t *timer) {
    return (double)(timer->delta.tv_sec) + ((double)timer->delta.tv_nsec/NANO_SEC);
}
