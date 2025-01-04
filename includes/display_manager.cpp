#include "common.h"
#include "display_manager.hpp"

ykes::DisplayManager::DisplayManager()
{
}
ykes::DisplayManager::DisplayManager(DisplayManager const &)
{
}
ykes::DisplayManager::~DisplayManager()
{
}
void ykes::DisplayManager::operator=(DisplayManager const &)
{
}

sf::RenderWindow *ykes::DisplayManager::getWindow(void) const
{
	return window;
}

int ykes::DisplayManager::start()
{
	if (window)
		return 0;

	set_type("ykes::DisplayManager");

	horizontal_pixels = WINDOW_HORIZONTAL_PIXELS;
	vertical_pixels   = WINDOW_VERTICAL_PIXELS;

	horizontal_chars = WINDOW_HORIZONTAL_CHARS;
	vertical_chars   = WINDOW_VERTICAL_CHARS;

	font.loadFromFile(FONT_PATH);
	font.setSmooth(true);

	window = new sf::RenderWindow(
	    sf::VideoMode(WINDOW_HORIZONTAL_PIXELS, WINDOW_VERTICAL_PIXELS),
	    WINDOW_TITLE
	);

	window->setVerticalSyncEnabled(true);
	window->setMouseCursorVisible(false);

	return 0;
}
void ykes::DisplayManager::shut()
{

	window->close();
	delete window;
	window = NULL;
}

int ykes::DisplayManager::drawCh(Vector world_pos, char ch, sf::Color color)
{
	if (!window)
		return 1;

	Vector pix_pos = spaceToPixels(world_pos);

	static sf::RectangleShape rect =
	    sf::RectangleShape(sf::Vector2f(char_width(), char_height()));

	rect.setFillColor(WINDOW_BACKGROUND_COLOR);
	rect.setPosition(
	    pix_pos.getX() - char_width() / 10, pix_pos.getY() + char_height() / 5
	);

	window->draw(rect);

	static sf::Text text("", font);
	text.setString(ch);

	text.setStyle(sf::Text::Bold);

#ifdef DISPLAY_MANGER_DBG
	text.setCharacterSize(72);
#else
	if (char_width() < char_height())
		text.setCharacterSize(char_width() * 2);
	else
		text.setCharacterSize(char_height() * 2);
#endif

	text.setFillColor(color);

	text.setPosition(pix_pos.getX(), pix_pos.getY());

	window->draw(text);
	return 0;
}

int ykes::DisplayManager::getHoriPixels(void) const
{
	return horizontal_pixels;
}
int ykes::DisplayManager::getHoriChars(void) const
{
	return horizontal_chars;
}
int ykes::DisplayManager::getVertPixels(void) const
{
	return vertical_pixels;
}
int ykes::DisplayManager::getVertChars(void) const
{
	return vertical_chars;
}

void ykes::DisplayManager::setHoriPixels(int pix)
{
	horizontal_pixels = pix;
}
void ykes::DisplayManager::setHoriChars(int chars)
{
	horizontal_chars = chars;
}
void ykes::DisplayManager::setVertPixels(int pix)
{
	vertical_pixels = pix;
}
void ykes::DisplayManager::setVertChars(int chars)
{
	vertical_chars = chars;
}

int ykes::DisplayManager::swap_buffers(void)
{
	if (!window)
		return 1;

	window->display();
	window->clear();
	return 0;
}

double ykes::DisplayManager::char_height(void)
{
	return vertical_pixels / vertical_chars;
}
double ykes::DisplayManager::char_width(void)
{
	return horizontal_pixels / horizontal_chars;
}
ykes::Vector ykes::DisplayManager::spaceToPixels(Vector spaces)
{
	Vector v;

	v.setX(spaces.getX() * char_width());
	v.setY(spaces.getY() * char_height());

	return v;
}
ykes::Vector ykes::DisplayManager::pixelToSpaces(Vector pixels)
{
	Vector v;
	v.setX(pixels.getX() / char_width());
	v.setY(pixels.getY() / char_height());
	return v;
}

int ykes::DisplayManager::drawString(
    Vector pos, std::string str, justification_t just, sf::Color color
)
{

	Vector start = pos;
	switch (just)
	{
	case JUSTIFIED_LEFT:
		break;
	case JUSTIFIED_RIGHT:
		start.setX(pos.getX() - str.size());
		break;
	case JUSTIFIED_CENTER:
		start.setX(pos.getX() - str.size() / 2);
		break;
	}
	char *tmp   = (char *)str.c_str();
	int   count = 1;

	for (char *p = tmp; *p; p++, count++)
	{

		drawCh(Vector((start.getX() + count) * 5, start.getY()), *p, color);
	}

	return 0;
}

void ykes::DisplayManager::setBackground(sf::Color color)
{
	background = color;
}