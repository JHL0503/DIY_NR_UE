#include "../include/rf.h"

#include <iostream>

rf::rf()
{
    std::cout << "Hello, rf!" << std::endl;
}

rf::~rf()
{
    std::cout << "Goob bye, rf!" << std::endl;
}


bool rf::init(rf_args_t rf_args_) 
{
    // Set args

    // Init rf device
    std::unique_ptr<rf_dev_interface> rf_device =  std::make_unique<rf_dev_zmq>();
    rf_device->init(rf_args_.rf_dev_args);
    m_rf_dev = std::move(rf_device);

    return 1;
}
