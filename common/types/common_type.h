#ifndef COMMON_TYPE_H
#define COMMON_TYPE_H

#include <cstdint>
#include <complex>


#define NR_MAX_CARRIERS 5 // Maximum number of supported simultaneous carriers
#define NR_MAX_PORTS 4
#define NR_MAX_CHANNELS (NR_MAX_CARRIERS * NR_MAX_PORTS)


typedef std::complex<float> cf_t;



#endif