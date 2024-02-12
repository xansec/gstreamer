/* GStreamer
 * harness for jpegdec
 */

#include <unistd.h>
#include <stdio.h>

#include <glib.h>
#include <gst/gst.h>
#include <gio/gio.h>
#include <gst/video/video.h>
#include <gst/video/gstvideometa.h>
#include <gst/video/gstvideopool.h>
#include <gst/video/gstvideodecoder.h>
#include <gst/base/gstadapter.h>
//#include <gst/check/gstcheck.h>
//#include <gst/app/gstappsink.h>
//#include <gst/pbutils/gstdiscoverer.h>

int LLVMFuzzerTestOneInput(const char *data, size_t size)
{
  static gboolean initialized = FALSE;
  GstVideoDecoder *decoder;
  GstVideoCodecFrame * frame;

  if (!initialized) {
    /* We want critical warnings to assert so we can fix them */
    //g_log_set_always_fatal (G_LOG_LEVEL_CRITICAL);
    //g_log_set_default_handler (harness_logger, NULL);

    /* Only initialize and register plugins once */
    gst_init (NULL, NULL);

    initialized = TRUE;
  }

  gst_jpeg_dec_handle_frame (decoder, frame);
  gst_video_codec_frame_unref (frame);

  return 0;
}
