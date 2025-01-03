#ifndef _DISPLAY_MANAGER_H
#define _DISPLAY_MANAGER_H

#include "color.hpp"
#include "manager.hpp"
#include "vector.hpp"
#include <SFML/Graphics.hpp>

#define WINDOW_HORIZONTAL_PIXELS 1024
#define WINDOW_VERTICAL_PIXELS   768
#define WINDOW_HORIZONTAL_CHARS  80
#define WINDOW_VERTICAL_CHARS    24

#define WINDOW_STYLE            sf::Style::TitleBar
#define WINDOW_BACKGROUND_COLOR sf::Color::Black
#define WINDOW_TITLE            "ykes"
#define FONT_PATH               "/usr/share/fonts/opentype/cantarell/Cantarell-Regular.otf"

typedef enum
{

	JUSTIFIED_LEFT,
	JUSTIFIED_CENTER,
	JUSTIFIED_RIGHT
} justification_t;

namespace ykes
{

	class DisplayManager : public Manager
	{
	    private:
		DisplayManager();
		DisplayManager(DisplayManager const &);
		~DisplayManager();
		void operator=(DisplayManager const &);

		sf::Font          font;
		sf::RenderWindow *window;

		int horizontal_pixels;
		int vertical_pixels;
		int horizontal_chars;
		int vertical_chars;

	    public:
		static inline DisplayManager &get_instance(void);

		int drawCh(Vector world_pos, char ch, color_t color);
		int drawString(
		    Vector pos, std::string str, justification_t just, color_t color
		);

		sf::RenderWindow *getWindow(void) const;

		int  getHoriPixels(void) const;
		int  getHoriChars(void) const;
		void setHoriPixels(int pix);
		void setHoriChars(int pix);

		int  getVertPixels(void) const;
		int  getVertChars(void) const;
		void setVertPixels(int pix);
		void setVertChars(int pix);

		int swap_buffers(void);

		double char_height(void);
		double char_width(void);

		Vector spaceToPixels(Vector spaces);
		Vector pixelToSpaces(Vector pixels);

		int  start();
		void shut();
	};

} // namespace ykes

inline ykes::DisplayManager &ykes::DisplayManager::get_instance(void)
{
	static DisplayManager d;
	d.set_type("ykes::DisplayManager");
	return d;
}

#endif
