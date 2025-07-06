//
// Created by dxliz on 2025/4/8.
//

#include <stdio.h>
#include "MvCameraControl.h"

int main() {
    MV_CC_DEVICE_INFO_LIST stDeviceList = {0};
    int nRet = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &stDeviceList);
    printf("Return code: %d\n", nRet);
    printf("Found %d devices\n", stDeviceList.nDeviceNum);
    for (unsigned int i = 0; i < stDeviceList.nDeviceNum; i++) {
        printf("Device %d: %s\n", i, stDeviceList.pDeviceInfo[i]->SpecialInfo.stUsb3VInfo.chModelName);
    }
    return 0;
}