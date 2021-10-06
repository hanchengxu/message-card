
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
#define SCL 5
#define SDA 4 

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display

#define SCROLL_DELTA 2
#define SCROLL_DELAY 350

const char c_str[] = 
"こんにちは\n\n"
"Hello world"
"改行して表示";

char buf[48];
 
uint8_t total_lines;    // the total number of lines in the story
uint8_t i;        // loop variable for the lines
uint8_t line_cnt;   // number of lines to draw, usually equal to lines_per_draw
uint8_t start_line;   // topmost visible line, derived from top_window_pos
uint8_t lines_per_draw; // how many lines to draw on the screen, derived from font and display height
uint16_t glyph_height;  // height of the glyphs

uint16_t top_window_pos;    // defines the display position in pixel within the text
uint16_t total_height;      // total height in pixel, derived from font height and total_lines
u8g2_uint_t top_offset;     // offset between the first visible line and the display

void setup(void) {
  Serial.begin(115200);
  u8g2.begin();
  u8g2.enableUTF8Print();   // enable UTF8 support for the Arduino print() function
  u8g2.setFont(u8g2_font_b12_t_japanese3);
//   u8g2.setFont(u8g2_font_wqy12_t_chinese3);   //you can change Language here!
  total_lines = u8x8_GetStringLineCnt(c_str);
  
  /* get the height of the glyphs */
  glyph_height = u8g2.getMaxCharHeight();

  /* calculate the height of the text in pixel */
  total_height = (uint16_t)total_lines * (uint16_t)glyph_height;
  

  /* calculate how many lines must be drawn on the screen */
  lines_per_draw = u8g2.getDisplayHeight() / glyph_height;
  lines_per_draw += 2;

  /* start at the top of the text */
  top_window_pos = 0;
}

void loop(void) {

  start_line = top_window_pos / glyph_height;
  top_offset = top_window_pos % glyph_height;
  
  line_cnt = total_lines - start_line;
  if ( line_cnt > lines_per_draw ){
    line_cnt = lines_per_draw;
  }
 


  u8g2.clearBuffer();          // clear the internal memory
  for( i = 0; i < line_cnt; i++ )     // draw visible lines
  {
    /* copy a line of the text to the local buffer */
    u8x8_CopyStringLine(buf, i+start_line, c_str);
    /* draw the content of the local buffer */
    u8g2.drawUTF8(0, i*glyph_height-top_offset +glyph_height, buf);
  }
  u8g2.sendBuffer();          // transfer internal memory to the display

  delay(SCROLL_DELAY);
  top_window_pos += SCROLL_DELTA;
  
  if(0 == line_cnt){
    /* start at the top of the text */
    top_window_pos = 0;
  }
}
