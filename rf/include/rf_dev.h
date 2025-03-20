#ifndef RF_DEV_H
#define RF_DEV_H

#include "../../common/types/common_type.h"
#include "../../common/types/args.h"
#include <mutex>

/******************************************************************************/
/*  0MQ socket definition.                                                    */
/******************************************************************************/
#define RF_PARAM_LEN (256)

/*  Socket types. */
#define ZMQ_PAIR 0
#define ZMQ_PUB 1
#define ZMQ_SUB 2
#define ZMQ_REQ 3
#define ZMQ_REP 4
#define ZMQ_DEALER 5
#define ZMQ_ROUTER 6
#define ZMQ_PULL 7
#define ZMQ_PUSH 8
#define ZMQ_XPUB 9
#define ZMQ_XSUB 10
#define ZMQ_STREAM 11

/* Definitions */
#define VERBOSE (0)
#define ZMQ_MONITOR (0)
#define NSAMPLES2NBYTES(X) (((uint32_t)(X)) * sizeof(cf_t))
#define NBYTES2NSAMPLES(X) ((X) / sizeof(cf_t))
#define ZMQ_MAX_BUFFER_SIZE (NSAMPLES2NBYTES(3072000)) // 10 subframes at 20 MHz
#define ZMQ_TIMEOUT_MS (2000)
#define ZMQ_BASERATE_DEFAULT_HZ (23040000)
#define ZMQ_ID_STRLEN 16
#define ZMQ_MAX_GAIN_DB (30.0f)
#define ZMQ_MIN_GAIN_DB (0.0f)

typedef enum {
    ZMQ_TYPE_FC32 = 0,
    ZMQ_TYPE_SC16 
} rf_zmq_format_t;

typedef struct {
    double min_tx_gain;
    double max_tx_gain;
    double min_rx_gain;
    double max_rx_gain;
} srsran_rf_info_t;
  

typedef struct {
    const char*     id;
    uint32_t        socket_type;
    rf_zmq_format_t sample_format;
    uint32_t        frequency_mhz;
    bool            fail_on_disconnect;
    uint32_t        trx_timeout_ms;
    bool            log_trx_timeout;
    int32_t         sample_offset; ///< offset in samples
} rf_zmq_opts_t;
  

typedef struct {
    // Common attributes
    char*            devname;
    srsran_rf_info_t info;
    uint32_t         nof_channels;
  
    // RF State
    uint32_t srate; // radio rate configured by upper layers
    uint32_t base_srate;
    uint32_t decim_factor; // decimation factor between base_srate used on transport on radio's rate
    double   rx_gain;
    double   tx_gain;
    // uint32_t tx_freq_mhz[SRSRAN_MAX_CHANNELS];
    // uint32_t rx_freq_mhz[SRSRAN_MAX_CHANNELS];
    bool     tx_off;
    // char     id[RF_PARAM_LEN];
  
    // Server
    void*       context;
    // rf_zmq_tx_t transmitter[SRSRAN_MAX_CHANNELS];
    // rf_zmq_rx_t receiver[SRSRAN_MAX_CHANNELS];
  
    // Various sample buffers
    // cf_t* buffer_decimation[SRSRAN_MAX_CHANNELS];
    cf_t* buffer_tx;
  
    // Rx timestamp
    uint64_t next_rx_ts;
  
    pthread_mutex_t tx_config_mutex;
    pthread_mutex_t rx_config_mutex;
    pthread_mutex_t decim_mutex;
    pthread_mutex_t rx_gain_mutex;
} rf_zmq_handler_t;

class rf_dev_interface
{
public:
    virtual ~rf_dev_interface() {}
    virtual bool init(rf_dev_args_t rf_dev_args_) = 0;
};


class rf_dev_zmq : public rf_dev_interface
{
private:
    rf_zmq_handler_t m_rf_zmq_handler;

public:
    rf_dev_zmq();
    ~rf_dev_zmq();
    bool    init (rf_dev_args_t rf_dev_args_) override;
};

#endif