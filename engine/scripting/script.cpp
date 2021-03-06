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

#include "scripting/script.hpp"
#include <libGraphite/rsrc/manager.hpp>
#include <libGraphite/data/reader.hpp>

// MARK: - Construction

scripting::lua::script::script(std::shared_ptr<lua::state> state, const int64_t& id)
    : m_state(state), m_id(id)
{
    if (auto s = graphite::rsrc::manager::shared_manager().find(type, id).lock()) {
        m_name = s->name();
        graphite::data::reader r(s->data());
        m_script = r.read_cstr();
    }
    else {
        throw std::logic_error("Could not find/load lua script resource #" + std::to_string(id));
    }
}

// MARK: - Accessor

auto scripting::lua::script::code() const -> std::string
{
    return m_script;
}

// MARK: - Execution

auto scripting::lua::script::execute() const -> void
{
    if (m_script.empty()) {
        return;
    }
    
    if (auto state = m_state.lock()) {
        state->run(*this);
    }
}
