// See LICENSE for license details.

//**************************************************************************
// Vector-vector add benchmark
//--------------------------------------------------------------------------
//
// This benchmark uses adds to vectors and writes the results to a
// third vector. The input data (and reference data) should be
// generated using the vvadd_gendata.pl perl script and dumped
// to a file named dataset1.h.
 
#include "util.h"

//--------------------------------------------------------------------------
// Input/Reference Data

#include "dataset1.h"

//--------------------------------------------------------------------------
// vvadd function

void vvadd( int n, int a[], int b[], int c[] )
{
  int i;
  for ( i = 0; i < n; i++ )
    c[i] = a[i] + b[i];
}

//--------------------------------------------------------------------------
// Main

#include <inttypes.h>

int main( int argc, char* argv[] )
{
  int results_data[DATA_SIZE];

#if PREALLOCATE
  // If needed we preallocate everything in the caches
  vvadd( DATA_SIZE, input1_data, input2_data, results_data );
#endif

  uint64_t start_cycle, end_cycle;
  start_cycle = rdcycle();

  // Do the vvadd
  setStats(1);
  for (int i = 0; i < 2000; i++) {
    vvadd( DATA_SIZE, input1_data, input2_data, results_data );
  }
  setStats(0);

  end_cycle = rdcycle();
  printf("TOTAL_CYCLES: %" PRIu64 " start_cycle: %" PRIu64 " end_cycle: %" PRIu64 "\n", end_cycle - start_cycle, start_cycle, end_cycle);

  // Check the results
  return verify( DATA_SIZE, results_data, verify_data );
}
