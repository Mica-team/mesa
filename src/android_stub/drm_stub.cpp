#include <xf86drm.h>
#include <stdint.h>

/*
 * Nether Launcher runs this Mesa build without a system libdrm shared
 * library. Android's normal rendering path is provided by the platform
 * EGL/Turnip stack, not DRM node enumeration, so these compatibility
 * functions deliberately report that no DRM devices are available.
 */
extern "C" {

int drmGetDevices2(uint32_t, drmDevicePtr[], int)
{
   return 0;
}

void drmFreeDevices(drmDevicePtr[], int)
{
}

drmVersionPtr drmGetVersion(int)
{
   return nullptr;
}

void drmFreeVersion(drmVersionPtr)
{
}

int drmGetNodeTypeFromFd(int)
{
   return -1;
}

}
