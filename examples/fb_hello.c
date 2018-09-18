/* SPDX-License-Identifier: BSD-2-Clause */

#include <stdio.h>
#include <tfblib/tfblib.h>

uint32_t red, green, blue, white, black, yellow, gray;

void init_colors(void)
{
   white = tfb_make_color(255, 255, 255);
   black = tfb_make_color(0, 0, 0);
   red = tfb_make_color(255, 0, 0);
   green = tfb_make_color(0, 255, 0);
   blue = tfb_make_color(0, 0, 255);
   yellow = tfb_make_color(255, 255, 0);
   gray = tfb_make_color(50, 50, 50);
}

void draw_something()
{
   uint32_t w = tfb_screen_width();
   uint32_t h = tfb_screen_height();

   tfb_clear_screen(black);

   // screen border
   tfb_draw_rect(0, 0, w, h, white);

   // full rect
   tfb_fill_rect(w/8, h/8 - h/16, w/4, h/4, red);

   // empty rect
   tfb_draw_rect(w/2, h/8 - h/16, w/4, h/4, red);

   // Lines

   tfb_draw_line(w/2, h/2, w/2 + 100, h/2 + 100, red);
   tfb_draw_line(w/2, h/2, w/2 + 100, h/2 + 75, red);
   tfb_draw_line(w/2, h/2, w/2 + 100, h/2 + 50, red);
   tfb_draw_line(w/2, h/2, w/2 + 100, h/2 + 25, red);

   tfb_draw_line(w/2, h/2, w/2 + 100, h/2, red);

   tfb_draw_line(w/2, h/2, w/2 + 75, h/2 + 100, white);
   tfb_draw_line(w/2, h/2, w/2 + 50, h/2 + 100, white);
   tfb_draw_line(w/2, h/2, w/2 + 25, h/2 + 100, white);
   tfb_draw_line(w/2, h/2, w/2 + 0, h/2 + 100, white);


   tfb_draw_line(w/2, h/2, w/2 + 75, h/2 - 100, green);
   tfb_draw_line(w/2, h/2, w/2 + 50, h/2 - 100, green);
   tfb_draw_line(w/2, h/2, w/2 + 25, h/2 - 100, green);
   tfb_draw_line(w/2, h/2, w/2 + 0, h/2 - 100, green);

   tfb_draw_line(w/2, h/2, w/2 + 100, h/2 - 25, red);
   tfb_draw_line(w/2, h/2, w/2 + 100, h/2 - 50, red);
   tfb_draw_line(w/2, h/2, w/2 + 100, h/2 - 75, red);
   tfb_draw_line(w/2, h/2, w/2 + 100, h/2 - 100, red);

   tfb_draw_line(w/2, h/2, w/2 - 25, h/2 + 100, blue);
   tfb_draw_line(w/2, h/2, w/2 - 50, h/2 + 100, blue);
   tfb_draw_line(w/2, h/2, w/2 - 75, h/2 + 100, blue);
   tfb_draw_line(w/2, h/2, w/2 - 100, h/2 + 100, blue);

   tfb_draw_line(w/2, h/2, w/2 - 100, h/2 + 75, red);
   tfb_draw_line(w/2, h/2, w/2 - 100, h/2 + 50, red);
   tfb_draw_line(w/2, h/2, w/2 - 100, h/2 + 25, red);
   tfb_draw_line(w/2, h/2, w/2 - 100, h/2 + 0, red);

   tfb_draw_line(w/2, h/2, w/2 - 100, h/2 - 25, red);
   tfb_draw_line(w/2, h/2, w/2 - 100, h/2 - 50, red);
   tfb_draw_line(w/2, h/2, w/2 - 100, h/2 - 75, red);

   tfb_draw_line(w/2, h/2, w/2 - 100, h/2 - 100, yellow);
   tfb_draw_line(w/2, h/2, w/2 - 75, h/2 - 100, yellow);
   tfb_draw_line(w/2, h/2, w/2 - 50, h/2 - 100, yellow);
   tfb_draw_line(w/2, h/2, w/2 - 25, h/2 - 100, yellow);
}

void draw_something2(void)
{
   uint32_t w = tfb_screen_width() / 2;
   uint32_t h = tfb_screen_height() / 2;

   tfb_clear_screen(black);
   tfb_set_center_window_size(w, h);
   tfb_clear_win(gray);

   tfb_draw_rect(0, 0, w, h, red);
   tfb_draw_line(0, 0, w * 2, h * 2, yellow);

   tfb_fill_rect(w/2, h/2, w, h, green);
}

int main(int argc, char **argv)
{
   int rc;

   rc = tfb_acquire_fb();

   if (rc != TFB_SUCCESS) {
      fprintf(stderr, "tfb_acquire_fb failed with error code: %d\n", rc);
      tfb_release_fb();
      return 1;
   }

   init_colors();
   draw_something();
   getchar();
   draw_something2();
   getchar();

   tfb_release_fb();
   return 0;
}
