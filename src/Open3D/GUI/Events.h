// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2018 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#pragma once

#include <cstdint>

namespace open3d {
namespace gui {

enum class MouseButton {
    NONE = 0,
    LEFT = (1 << 0),
    MIDDLE = (1 << 1),
    RIGHT = (1 << 2),
    BUTTON4 = (1 << 3),
    BUTTON5 = (1 << 4)
};

struct MouseMoveEvent {
    int x;
    int y;
    int buttons;  // MouseButtons ORed together
};

struct MouseButtonEvent {
    enum Type { DOWN, UP };
    Type type;
    int x;
    int y;
    MouseButton button;
};

struct MouseWheelEvent {
    int x;
    int y;
};

enum {
    KEY_BACKSPACE = 8,
    KEY_TAB = 9,
    KEY_ENTER = 10,
    KEY_ESCAPE = 27,
    KEY_DELETE = 127,
    KEY_LSHIFT = 256,
    KEY_RSHIFT,
    KEY_CAPSLOCK,
    KEY_CTRL,
    KEY_OPTION,
    KEY_META,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_UP,
    KEY_DOWN,
    KEY_INSERT,
    KEY_HOME,
    KEY_END,
    KEY_PAGEUP,
    KEY_PAGEDOWN,
    KEY_UNKNOWN = 1000
};

struct KeyEvent {
    enum Type { DOWN, UP };
    Type type;
    // This is the actual key that was pressed, not the character that
    // was generated (use TextInputEvent for that). Values correspond
    // to ASCII values where applicable.
    uint32_t key;
    bool isRepeat;
};

struct TextInputEvent {
    const char *utf8;
};

}  // namespace gui
}  // namespace open3d
