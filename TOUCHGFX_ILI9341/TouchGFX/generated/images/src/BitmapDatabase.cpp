// 4.20.0 0xeeaf0845
// Generated by imageconverter. Please, do not edit!

#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_blue_progressindicators_bg_medium_circle_indicator_bg_full[]; // BITMAP_BLUE_PROGRESSINDICATORS_BG_MEDIUM_CIRCLE_INDICATOR_BG_FULL_ID = 0, Size: 104x104 pixels
extern const unsigned char image_blue_progressindicators_bg_medium_progress_indicator_bg_square_0_degrees[]; // BITMAP_BLUE_PROGRESSINDICATORS_BG_MEDIUM_PROGRESS_INDICATOR_BG_SQUARE_0_DEGREES_ID = 1, Size: 184x20 pixels
extern const unsigned char image_blue_progressindicators_fill_medium_circle_indicator_fill_full[]; // BITMAP_BLUE_PROGRESSINDICATORS_FILL_MEDIUM_CIRCLE_INDICATOR_FILL_FULL_ID = 2, Size: 104x104 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_blue_progressindicators_bg_medium_circle_indicator_bg_full, 0, 104, 104, 16, 15, 72, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 74, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_progressindicators_bg_medium_progress_indicator_bg_square_0_degrees, 0, 184, 20, 0, 0, 184, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 20, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_blue_progressindicators_fill_medium_circle_indicator_fill_full, 0, 104, 104, 17, 17, 70, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 70, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase
