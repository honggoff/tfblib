
#ifndef _TFBLIB_H_
#  error Never include this header directly. Include <tfblib/tfblib.h>.
#endif

/* Essential variables */
extern u8 *__fb_buffer;
extern u8 *__fb_real_buffer;
extern int __fb_screen_w;
extern int __fb_screen_h;
extern size_t __fb_size;
extern size_t __fb_pitch;
extern int __fb_bpp;

/* Window-related variables */
extern int __fb_win_w;
extern int __fb_win_h;
extern int __fb_off_x;
extern int __fb_off_y;
extern int __fb_win_end_x;
extern int __fb_win_end_y;

/* Color-related variables */
extern u32 __fb_r_mask;
extern u32 __fb_g_mask;
extern u32 __fb_b_mask;
extern u8 __fb_r_mask_size;
extern u8 __fb_g_mask_size;
extern u8 __fb_b_mask_size;
extern u8 __fb_r_pos;
extern u8 __fb_g_pos;
extern u8 __fb_b_pos;

inline u32 tfb_make_color(u8 r, u8 g, u8 b)
{
   r = r >> (8 - __fb_r_mask_size);
   g = g >> (8 - __fb_g_mask_size);
   b = b >> (8 - __fb_b_mask_size);
   return ((r << __fb_r_pos) & __fb_r_mask) |
          ((g << __fb_g_pos) & __fb_g_mask) |
          ((b << __fb_b_pos) & __fb_b_mask);
}

inline void tfb_draw_pixel(int x, int y, u32 color)
{
   x += __fb_off_x;
   y += __fb_off_y;

   if ((u32)x < (u32)__fb_win_end_x && (u32)y < (u32)__fb_win_end_y)
   {
      volatile u8* buf = __fb_buffer + y * __fb_pitch + x * __fb_bpp;
      for (int p = 0; p < __fb_bpp; p++)
      {
         buf[p] = ((u8*)&color)[p];
      }

   }
}

inline u32 tfb_screen_width(void) { return __fb_screen_w; }
inline u32 tfb_screen_height(void) { return __fb_screen_h; }
inline u32 tfb_win_width(void) { return __fb_win_w; }
inline u32 tfb_win_height(void) { return __fb_win_h; }
