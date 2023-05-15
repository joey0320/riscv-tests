// See LICENSE for license details.

//**************************************************************************
// Median filter bencmark
//--------------------------------------------------------------------------
//
// This benchmark performs a 1D three element median filter. The
// input data (and reference data) should be generated using the
// median_gendata.pl perl script and dumped to a file named
// dataset1.h.

#include "util.h"

#include "median.h"

//--------------------------------------------------------------------------
// Input/Reference Data

#include "dataset1.h"

#include <inttypes.h>
#include <stdio.h>

//--------------------------------------------------------------------------
// Main

#define NUM_REPEAT 1000

int main( int argc, char* argv[] )
{
  int results_data[DATA_SIZE];

#if PREALLOCATE
  // If needed we preallocate everything in the caches
  median( DATA_SIZE, input_data, results_data );
#endif

  uint64_t start_cycle, end_cycle;

  // Do the filter
  setStats(1);
  start_cycle = rdcycle();
  for (int i = 0; i < NUM_REPEAT; i++) {
    median( DATA_SIZE, input_data, results_data );
  }
  end_cycle = rdcycle();
  setStats(0);

  printf("TOTAL_CYCLES: %" PRIu64 " start_cycle: %" PRIu64 " end_cycle: %" PRIu64 "\n", end_cycle - start_cycle, start_cycle, end_cycle);

  // Check the results
  return verify( DATA_SIZE, results_data, verify_data );
}
