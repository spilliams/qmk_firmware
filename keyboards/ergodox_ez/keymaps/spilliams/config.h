#include "../../config.h"

#define ORYX_CONFIGURATOR

// Reference for why this line needs to be here:
// https://github.com/qmk/qmk_firmware/issues/1695#issuecomment-328346224
#define FORCE_NKRO

// https://docs.qmk.fm/reference/config-options
//
/* "debounce" is measured in keyboard scans. Some users reported
 * needing values as high as 15, which was at the time around 50ms.
 * If you don't define it here, the matrix code will default to
 * 5, which is now closer to 10ms, but still plenty according to
 * manufacturer specs.
 *
 * Default is quite high, because of reports with some production
 * runs seeming to need it. This may change when configuration for
 * this is more directly exposed.
 */
// Default: 30 in keyboards/ergodox_ez/config.h
#undef DEBOUNCE
#define DEBOUNCE 15
