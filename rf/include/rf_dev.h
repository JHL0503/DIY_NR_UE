#ifndef RF_DEV_H
#define RF_DEV_H

#include "../../common/types/common_type.h"
#include "../../common/types/args.h"
#include <mutex>

class rf_dev_interface
{
public:
    virtual ~rf_dev_interface() {}
    virtual bool init(rf_dev_args_t rf_dev_args_) = 0;
};


class rf_dev_zmq : public rf_dev_interface
{
private:

public:
    rf_dev_zmq();
    ~rf_dev_zmq();
    bool    init (rf_dev_args_t rf_dev_args_) override;
};

#endif