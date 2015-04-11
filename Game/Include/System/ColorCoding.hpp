#pragma once

struct ColorCoding
{
	ColorCoding(size_t _r, size_t _g, size_t _b) : r(_r), g(_g), b(_b)
	{

	}

	ColorCoding() : r(0), g(0), b(0)
	{

	}
	friend std::ostream& operator<<(std::ostream& os, const ColorCoding color);

	size_t r;
	size_t g;
	size_t b;
};

inline std::ostream& operator<<(std::ostream& os, const ColorCoding color)
{
	return os << color.r << " " << color.g << " " << color.b << std::endl;
}