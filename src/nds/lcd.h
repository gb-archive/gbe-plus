// GB Enhanced Copyright Daniel Baxter 2015
// Licensed under the GPLv2
// See LICENSE.txt for full license text

// File : lcd.h
// Date : December 28, 2015
// Description : NDS LCD emulation
//
// Draws background, window, and sprites to screen
// Responsible for blitting pixel data and limiting frame rate

#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "mmu.h"

#ifndef NDS_LCD
#define NDS_LCD

class NTR_LCD
{
	public:
	
	//Link to memory map
	NTR_MMU* mem;

	//Core Functions
	NTR_LCD();
	~NTR_LCD();

	void step();
	void reset();
	bool init();
	void update();

	//Screen data
	SDL_Window* window;
	SDL_Surface* final_screen;
	SDL_Surface* original_screen;

	SDL_GLContext gl_context;
	GLuint lcd_texture;

	ntr_lcd_data lcd_stat;

	private:

	void update_palettes();

	//Screen pixel buffer
	std::vector<u32> scanline_buffer_a;
	std::vector<u32> scanline_buffer_b;
	std::vector<u32> screen_buffer;

	u32 scanline_pixel_counter;

	int frame_start_time;
	int frame_current_time;
	int fps_count;
	int fps_time;

	void render_scanline();
	void render_bg_scanline(u32 bg_control);
	void render_bg_mode_text(u32 bg_control);
	void render_bg_mode_affine(u32 bg_control);
	void render_bg_mode_affine_ext(u32 bg_control);
	void render_bg_mode_bitmap(u32 bg_control);
	void render_bg_mode_direct(u32 bg_control);
	void scanline_compare();
	void reload_affine_references(u32 bg_control);
};

#endif // NDS_LCD