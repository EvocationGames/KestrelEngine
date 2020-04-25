// Copyright (c) 2020 Tom Hancocks
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "app/environment.hpp"
#include "libDiamane/platform/application.hpp"

// MARK: - Construction

kestrel::app::environment::environment()
    : m_game_window(diamane::ui::window::create("Kestrel", diamane::size(1280, 800)))
{
    m_game_window->set_background_color(diamane::gl::color::blackColor());
}

// MARK: - Life Cycle

auto kestrel::app::environment::start(int argc, const char **argv) -> int
{
    diamane::platform::application::shared()->run(argc, argv, [&] {
        // We need to get a basic menubar in place (primarily for macOS)
        diamane::platform::application::shared()->set_menubar(diamane::ui::menubar::create());

        // Configure the window.
        m_game_window->center();
        m_game_window->show();
    });
    return 0;
}