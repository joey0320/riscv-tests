#!/bin/bash


make

spike dhrystone.riscv
spike median.riscv
spike mm.riscv
spike multiply.riscv
spike pmp.riscv
spike qsort.riscv
spike rsort.riscv
spike spmv.riscv
spike towers.riscv
spike vvadd.riscv
