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

#if __APPLE__ && !defined(KESTREL_METAL_VIEW_H)
#define KESTREL_METAL_VIEW_H

#include <memory>
#include "core/support/macos/cocoa/view.h"
#include "core/graphics/common/entity.hpp"
#include "core/graphics/common/texture.hpp"

namespace graphics { namespace metal {

    class view: public std::enable_shared_from_this<graphics::metal::view>, public cocoa::view
    {
    public:
        explicit view();

        auto draw_entity(const graphics::entity::lua_reference& entity) const -> void;
        auto register_texture(const std::shared_ptr<graphics::texture>& texture) -> int;
    };

}}

#endif //KESTREL_METAL_VIEW_H
