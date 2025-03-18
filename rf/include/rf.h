#ifndef RF_H
#define RF_H

#include "./rf_dev.h"
#include "../../common/types/args.h"
#include <memory>

class rf
{
private:
    std::unique_ptr<rf_dev_interface>        m_rf_dev;

public: 
    rf();
    ~rf();
    bool init(rf_args_t rf_args_);
};


#endif