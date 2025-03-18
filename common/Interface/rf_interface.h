#ifndef RF_INTERFACE_H
#define RF_INTERFACE_H

#include "../types/common_type.h"


/**
 * RF interface for PHY layer.
 * 
 * RF layer의 역할은 단 하나, PHY에게 radio 신호를 전달(receive) 그리고 PHY에게서 전달받은 radio 신호를 전송(transmit)하는 것이다.
 * 그리고 이 역할을 잘 하기 위해서 rf module을 tuning 하기 위해 필요한 getter, setter 들이 있다.
 */
class rf_interface_phy
{

};

/**
 * RF layer is connected only with PHY layer.
 */
class rf_interface : rf_interface_phy {};

#endif