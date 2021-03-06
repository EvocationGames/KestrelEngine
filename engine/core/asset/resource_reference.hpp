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

#if !defined(KESTREL_RESOURCE_REFERENCE_HPP)
#define KESTREL_RESOURCE_REFERENCE_HPP

#include <string>
#include <optional>
#include "scripting/state.hpp"
#include "util/hint.hpp"
#include "util/lua_vector.hpp"

namespace asset
{

    struct resource_reference: public scripting::lua::object
    {
    public:
        typedef luabridge::RefCountedPtr<asset::resource_reference> lua_reference;

    private:
        std::optional<std::string> m_type;
        std::optional<int64_t> m_id;
        std::optional<std::string> m_name;

    public:
        static auto enroll_object_api_in_state(const std::shared_ptr<scripting::lua::state>& lua) -> void;

        explicit resource_reference(int64_t id);
        explicit resource_reference(const std::string& name);
        resource_reference(const std::string& type, int64_t id);
        resource_reference(const std::string& type, const std::string& name);

        lua_api static auto find(const std::string& type, int64_t id) -> bool;
        lua_api static auto using_id(int64_t id) -> resource_reference::lua_reference;
        lua_api static auto using_named(const std::string& name) -> resource_reference::lua_reference;
        lua_api static auto using_typed_id(const std::string& type, int64_t id) -> resource_reference::lua_reference;
        lua_api static auto using_typed_named(const std::string& type, const std::string& name) -> resource_reference::lua_reference;

        lua_api static auto all_of_type(const std::string& type) -> util::lua_vector<asset::resource_reference::lua_reference>;

        auto type() const -> std::optional<std::string>;
        auto id() const -> std::optional<int64_t>;
        auto name() const -> std::optional<std::string>;

        lua_api auto exists() const -> bool;
    };

}

#endif //KESTREL_RESOURCE_REFERENCE_HPP
