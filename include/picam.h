/**
 * @file picam.h
 * @brief libpicam header.
 */

#ifndef _LIBPICAM_PUBLIC_H
#define _LIBPICAM_PUBLIC_H

#include "stddef.h"

typedef enum PCVideoFormat {
    PCV_ARGB, PCV_RGB24
} PCVideoFormat;

#ifdef __cplusplus
namespace libpicam {
    class PiCamera {
        public:
            PiCamera(int width, int height, int fps, PCVideoFormat fmt);
            bool GetFrame(void *buffer, size_t bs);
            
            bool GetFramePointer(void **buffer, size_t *bs);
            void ReleaseFramePointer();
        private:
    };
}
#else // !__cplusplus
    typedef struct PiCamera;
    
    extern int picamera_init(PiCamera **c, int width, int height int fps, PCVideoFormat fmt);
    extern int picamera_getframe(PiCamera *c, void *buffer, size_t bs);
    extern int picamera_getframepointer(PiCamera *c, void **bufer, size_t *bs);
    extern int picamera_relaseframepointer(PiCamera *c);
    extern int picamera_release(PiCamera **c);
#endif // __cplusplus

#endif // _LIBPICAM_PUBLIC_H