/**
 * Generated on Sun, 03 Apr 2022 17:57:34 +0200.
 *
 * This file contains the function macros for the RV64IM core architecture.
 */

#ifndef __RV64IM_FUNCS_H
#define __RV64IM_FUNCS_H

#ifndef ETISS_ARCH_STATIC_FN_ONLY
#include "RISCV64.h"
#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"
#include "etiss/jit/ReturnCode.h"
#endif



#ifndef ETISS_ARCH_STATIC_FN_ONLY

static inline etiss_uint64 csr_read (ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
if (csr == 1U) {
return ((RISCV64*)cpu)->CSR[3U] & 31UL;
}
if (csr == 2U) {
return (((RISCV64*)cpu)->CSR[3U] >> 5UL) & 7U;
}
return ((RISCV64*)cpu)->CSR[csr];
}

#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY

static inline etiss_int32 csr_write (ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint64 val)
{
if (csr == 1U) {
((RISCV64*)cpu)->CSR[3] = (((RISCV64*)cpu)->CSR[3U] & 224UL) | (val & 31UL);
} else {
if (csr == 2U) {
((RISCV64*)cpu)->CSR[3] = ((val & 7UL) << 5U) | (((RISCV64*)cpu)->CSR[3U] & 31UL);
} else {
if (csr == 3U) {
((RISCV64*)cpu)->CSR[3] = val & 255UL;
} else {
((RISCV64*)cpu)->CSR[csr] = val;
}
}
}
if (csr == 384U) {
return ETISS_SIGNAL_MMU(cpu, system, plugin_pointers, val);
}
return 0U;
}

#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY

static inline etiss_int32 flush_tlb (ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint64 vaddr, etiss_uint64 asid)
{
if (vaddr == 0UL) {
return ETISS_TLB_FLUSH(cpu, system, plugin_pointers);
} else {
return ETISS_TLB_EVICT(cpu, system, plugin_pointers, vaddr, asid);
}
}

#endif
#endif