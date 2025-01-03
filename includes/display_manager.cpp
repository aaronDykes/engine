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

int ykes::DisplayManager::drawCh(Vector world_pos, char ch, color_t color)
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

	if (char_width() < char_height())
		text.setCharacterSize(char_width() * 2);
	else
		text.setCharacterSize(char_height() * 2);

	switch (color)
	{
	case BLACK:
		text.setFillColor(sf::Color::Black);
		break;
	case RED:
		text.setFillColor(sf::Color::Red);
		break;
	case GREEN:
		text.setFillColor(sf::Color::Green);
		break;
	case YELLOW:
		text.setFillColor(sf::Color::Yellow);
		break;
	case BLUE:
		text.setFillColor(sf::Color::Blue);
		break;
	case MAGENTA:
		text.setFillColor(sf::Color::Magenta);
		break;
	case CYAN:
		text.setFillColor(sf::Color::Cyan);
		break;
	case WHITE:
		text.setFillColor(sf::Color::White);
		break;
	default:
		return 1;
	}

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
    Vector pos, std::string str, justification_t just, color_t color
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
	int   count = 0;

	for (char *p = tmp; *p; p++, count++)
		drawCh(Vector(start.getX() + count, start.getY()), *p, color);
	return 0;
}