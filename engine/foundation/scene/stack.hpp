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

#if !defined(KESTREL_SCENE_STACK_HPP)
#define KESTREL_SCENE_STACK_HPP

#include <vector>
#include "foundation/scene/scene.hpp"

namespace kestrel
{

    class scene_stack
    {
    private:
        std::vector<scene::lua_scene> m_scenes { };

        scene_stack();
        ~scene_stack();

    public:
        scene_stack(const scene_stack&) = delete;
        scene_stack& operator=(const scene_stack&) = delete;
        scene_stack(scene_stack&&) = delete;
        scene_stack& operator=(scene_stack&&) = delete;

        static auto& global()
        {
            static scene_stack instance;
            return instance;
        }

        auto push(scene::lua_scene scene) -> void;
        auto current() const -> scene::lua_scene;
    };

}

#endif //KESTREL_SCENE_STACK_HPP
