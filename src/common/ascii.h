#ifndef __ASCII_H__
#define __ASCII_H__

#include "common.h"

namespace Venus
{

class Ascii
{
public:
    enum CharacterProperties
        /// ASCII character properties.
    {
        ACP_CONTROL  = 0x0001,
        ACP_SPACE    = 0x0002,
        ACP_PUNCT    = 0x0004,
        ACP_DIGIT    = 0x0008,
        ACP_HEXDIGIT = 0x0010,
        ACP_ALPHA    = 0x0020,
        ACP_LOWER    = 0x0040,
        ACP_UPPER    = 0x0080,
        ACP_GRAPH    = 0x0100,
        ACP_PRINT    = 0x0200
    };

    static int properties(int ch);
    /// Return the ASCII character properties for the
    /// character with the given ASCII value.
    ///
    /// If the character is outside the ASCII range
    /// (0 .. 127), 0 is returned.

    static bool hasSomeProperties(int ch, int properties);
    /// Returns true if the given character is
    /// within the ASCII range and has at least one of 
    /// the given properties.

    static bool hasProperties(int ch, int properties);
    /// Returns true if the given character is
    /// within the ASCII range and has all of 
    /// the given properties.

    static bool isAscii(int ch);
    /// Returns true iff the given character code is within
    /// the ASCII range (0 .. 127).

    static bool isSpace(int ch);
    /// Returns true iff the given character is a whitespace.

    static bool isDigit(int ch);
    /// Returns true iff the given character is a digit.

    static bool isHexDigit(int ch);
    /// Returns true iff the given character is a hexadecimal digit.

    static bool isPunct(int ch);
    /// Returns true iff the given character is a punctuation character.

    static bool isAlpha(int ch);
    /// Returns true iff the given character is an alphabetic character.	

    static bool isAlphaNumeric(int ch);
    /// Returns true iff the given character is an alphabetic character.	

    static bool isLower(int ch);
    /// Returns true iff the given character is a lowercase alphabetic
    /// character.

    static bool isUpper(int ch);
    /// Returns true iff the given character is an uppercase alphabetic
    /// character.

    static int toLower(int ch);
    /// If the given character is an uppercase character,
    /// return its lowercase counterpart, otherwise return
    /// the character.

    static int toUpper(int ch);
    /// If the given character is a lowercase character,
    /// return its uppercase counterpart, otherwise return
    /// the character.

private:
    static const int CHARACTER_PROPERTIES[128];
};


//
// inlines
//
inline int Ascii::properties(int ch)
{
    if (isAscii(ch))
        return CHARACTER_PROPERTIES[ch];
    else
        return 0;
}


inline bool Ascii::isAscii(int ch)
{
    return (static_cast<uint32>(ch) & 0xFFFFFF80) == 0;
}


inline bool Ascii::hasProperties(int ch, int props)
{
    return (properties(ch) & props) == props;
}


inline bool Ascii::hasSomeProperties(int ch, int props)
{
    return (properties(ch) & props) != 0;
}


inline bool Ascii::isSpace(int ch)
{
    return hasProperties(ch, ACP_SPACE);
}


inline bool Ascii::isDigit(int ch)
{
    return hasProperties(ch, ACP_DIGIT);
}


inline bool Ascii::isHexDigit(int ch)
{
    return hasProperties(ch, ACP_HEXDIGIT);
}


inline bool Ascii::isPunct(int ch)
{
    return hasProperties(ch, ACP_PUNCT);
}


inline bool Ascii::isAlpha(int ch)
{
    return hasProperties(ch, ACP_ALPHA);
}


inline bool Ascii::isAlphaNumeric(int ch)
{
    return hasSomeProperties(ch, ACP_ALPHA | ACP_DIGIT);
}


inline bool Ascii::isLower(int ch)
{
    return hasProperties(ch, ACP_LOWER);
}


inline bool Ascii::isUpper(int ch)
{
    return hasProperties(ch, ACP_UPPER);
}


inline int Ascii::toLower(int ch)
{
    if (isUpper(ch))
        return ch + 32;
    else
        return ch;
}


inline int Ascii::toUpper(int ch)
{
    if (isLower(ch))
        return ch - 32;
    else
        return ch;
}

}

#endif // __ASCII_H__
