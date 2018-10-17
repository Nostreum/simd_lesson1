/* Arm Knowledge Sharing.
 *
 * A dive into SIMD intrinsics from a hardware and 
 * software point of view.
 *
 * 
 * The goal of this exercice is to use SIMD intrinsics instructions
 * (SSE intel) to reduce the execution time of a convolution.
 * 
 * doc: https://software.intel.com/sites/landingpage/IntrinsicsGuide/ 
 * (/!\ Use only MMX-SSE-SSE2 intrinsics)
 *
 *
 * [Can you beat GCC -O4 ?]
 *
 */
#include <conv.h>
#include <ltimer.h>
#include <alloc.h>
#include <checker.h>

#define NTEST 100

int main(int argc, char *argv[]) {

  // 2D Array allocation
  f32 **img       = alloc_f32_2D(N, N);
  f32 **out       = alloc_f32_2D(N, N);
  f32 **out_simd  = alloc_f32_2D(N, N);
  f32 **mask      = alloc_f32_2D(3, 3);;

  // Execution time
  double exec_time_classic;
  double exec_time_simd;

  double cpp_classic;
  double cpp_simd;

  double speedup;

  // 2D Array initialisation
  init_rand_f32_2D(img, N, N, MAX_VALUE);
  init_rand_f32_2D(mask, 3, 3, 1.f);
  init_zero_f32_2D(out, N, N);
  init_zero_f32_2D(out_simd, N, N);

  // Launching convolution
  printf("Launching classic algorithm... \n");
  exec_time_classic = launch_N_test(f32_conv_3x3, img, mask, out, N, NTEST);

  cpp_classic       = exec_time_classic / (N*N);
  printf("\tExecution time : %.4fs \n", exec_time_classic, cpp_classic);

  printf("Launching simd algorithm... \n");
  exec_time_simd = launch_N_test(f32_conv_sse_3x3, img, mask, out_simd, N, NTEST);
  
  cpp_simd       = exec_time_simd / (N*N);
  printf("\tExecution time : %.4fs \n", exec_time_simd, cpp_simd);

  // Speedup 
  speedup = (exec_time_classic / exec_time_simd * 100) - 100;

  // Checker
  printf("Functionnal checking... \n");
  if (!matrices_are_equal(out, out_simd, N, N)) {
    printf("[SIMD algorithm is wrong] \n");
    printf("[TRY AGAIN] \n");
    return 0;
  }

  // Results
  if (speedup > 0)
    printf("\nThe SIMD version is %.2f pourcent faster than the classic one. \n", speedup);
  else
    printf("\nThe SIMD version is %.2f pourcent slower than the classic one. \n", speedup);

  return 0;
}


