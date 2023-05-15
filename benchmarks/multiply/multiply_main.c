// See LICENSE for license details.

// *************************************************************************
// multiply filter bencmark
// -------------------------------------------------------------------------
//
// This benchmark tests the software multiply implemenation. The
// input data (and reference data) should be generated using the
// multiply_gendata.pl perl script and dumped to a file named
// dataset1.h

#include "util.h"

#include "multiply.h"

//--------------------------------------------------------------------------
// Input/Reference Data

#include "dataset1.h"

#include <inttypes.h>

//--------------------------------------------------------------------------
// Main

#define NUM_REPEAT 200

int main( int argc, char* argv[] )
{
  int i;
  int results_data[DATA_SIZE];

#if PREALLOCATE
  for (i = 0; i < DATA_SIZE; i++)
  {
    results_data[i] = multiply( input_data1[i], input_data2[i] );
  }
#endif

  uint64_t start_cycle, end_cycle;
  start_cycle = rdcycle();

  for (int round = 0; round < NUM_REPEAT; round++) {
    setStats(1);
    for (i = 0; i < DATA_SIZE; i++)
    {
      results_data[i] = multiply( input_data1[i], input_data2[i] );
    }
    setStats(0);
  }
  end_cycle = rdcycle();
  printf("TOTAL_CYCLES: %" PRIu64 " start_cycle: %" PRIu64 " end_cycle: %" PRIu64 "\n", end_cycle - start_cycle, start_cycle, end_cycle);

  // Check the results
  return verify( DATA_SIZE, results_data, verify_data );
}
