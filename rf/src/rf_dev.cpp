#include "../include/rf_dev.h"
#include <cstring>

rf_dev_zmq::rf_dev_zmq()
{

}

rf_dev_zmq::~rf_dev_zmq()
{
    
}

bool rf_dev_zmq::init(rf_dev_args_t rf_dev_args_)
{
    // int ret = SRSRAN_ERROR;

    m_rf_zmq_handler = {};
    m_rf_zmq_handler.base_srate = ZMQ_BASERATE_DEFAULT_HZ; // Sample rate for 100 PRB cell
    // pthread_mutex_lock(&handler->rx_gain_mutex);
    m_rf_zmq_handler.rx_gain = 0.0;
    // pthread_mutex_unlock(&handler->rx_gain_mutex);
    m_rf_zmq_handler.info.max_rx_gain = ZMQ_MAX_GAIN_DB;
    m_rf_zmq_handler.info.min_rx_gain = ZMQ_MIN_GAIN_DB;
    m_rf_zmq_handler.info.max_tx_gain = ZMQ_MAX_GAIN_DB;
    m_rf_zmq_handler.info.min_tx_gain = ZMQ_MIN_GAIN_DB;
    m_rf_zmq_handler.nof_channels     = rf_dev_args_.nof_channels;
    // strcpy(handler->id, "zmq\0");

    rf_zmq_opts_t rx_opts = {};
    rf_zmq_opts_t tx_opts = {};
    rx_opts.socket_type   = ZMQ_REQ;
    tx_opts.socket_type   = ZMQ_REP;
    // tx_opts.id            = handler->id;
    // rx_opts.id            = handler->id;

    m_rf_zmq_handler.base_srate = 23.04e6;
    // m_rf_zmq_handler.id = "zmq\0";
    rx_opts.socket_type   = ZMQ_REQ;
    rx_opts.sample_format = ZMQ_TYPE_FC32;
    tx_opts.socket_type   = ZMQ_REP;
    tx_opts.sample_format = ZMQ_TYPE_FC32;

    // update_rates(rf_zmq_handler_t* handler, double srate)
    // Decimation must be full integer
    // if (((uint64_t)handler->base_srate % (uint64_t)srate) == 0) {
    //     handler->srate        = (uint32_t)srate;
    //     handler->decim_factor = handler->base_srate / handler->srate;
    //     } else {
    //     fprintf(stderr,
    //             "Error: couldn't update sample rate. %.2f is not divisible by %.2f\n",
    //             srate / 1e6,
    //             handler->base_srate / 1e6);
    //     }
    //     printf("Current sample rate is %.2f MHz with a base rate of %.2f MHz (x%d decimation)\n",
    //             handler->srate / 1e6,
    //             handler->base_srate / 1e6,
    //             handler->decim_factor);

    // handler->context = zmq_ctx_new(); // ??

    // for (int i = 0; i < handler->nof_channels; i++) {
    //     char rx_port[RF_PARAM_LEN] = "tcp://127.0.0.1:2000";
    //     rx_opts.frequency_mhz = 0;
    //     rx_opts.sample_offset = 0;

    //     char rx_port[RF_PARAM_LEN] = "tcp://127.0.0.1:2001";
    //     tx_opts.frequency_mhz = 0;
    //     tx_opts.sample_offset = 0;

    //     // trx_timeout_ms
    //     rx_opts.trx_timeout_ms = ZMQ_TIMEOUT_MS;

    //     // initialize transmitter
    //     if (rf_zmq_tx_open(&handler->transmitter[i], tx_opts, handler->context, tx_port) != SRSRAN_SUCCESS) {
    //         fprintf(stderr, "[zmq] Error: opening transmitter\n");
    //         goto clean_exit;
    //     }

    //     // initialize receiver
    //     if (rf_zmq_rx_open(&handler->receiver[i], rx_opts, handler->context, rx_port) != SRSRAN_SUCCESS) {
    //         fprintf(stderr, "[zmq] Error: opening receiver\n");
    //         goto clean_exit;
    //     }
    //     if (!handler->transmitter[i].running && !handler->receiver[i].running) {
    //         fprintf(stderr, "[zmq] Error: Neither Tx port nor Rx port specified.\n");
    //         goto clean_exit;
    //     }
    // }

    // clean_exit:
    // if (ret) {
    //   rf_zmq_close(handler);
    // }

    return 1;
}
