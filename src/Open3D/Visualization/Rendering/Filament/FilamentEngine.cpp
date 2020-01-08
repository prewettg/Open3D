// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2019 www.open3d.org
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

#include <cstddef>  // <filament/Engine> recursive includes needs this, std::size_t especially

#include "FilamentEngine.h"

#include "FilamentResourceManager.h"

namespace open3d {
namespace visualization {

filament::backend::Backend EngineInstance::backend_ =
        filament::backend::Backend::DEFAULT;

void EngineInstance::SelectBackend(const filament::backend::Backend aBackend) {
    backend_ = aBackend;
}

filament::Engine& EngineInstance::GetInstance() { return *Get().engine_; }

FilamentResourceManager& EngineInstance::GetResourceManager() {
    return *Get().resourceManager_;
}

EngineInstance::~EngineInstance() {
    resourceManager_->DestroyAll();
    delete resourceManager_;
    resourceManager_ = nullptr;

    filament::Engine::destroy(engine_);
    engine_ = nullptr;
}

EngineInstance& EngineInstance::Get() {
    static EngineInstance instance;
    return instance;
}

EngineInstance::EngineInstance() {
    engine_ = filament::Engine::create(backend_);
    resourceManager_ = new FilamentResourceManager(*engine_);
}

}  // namespace visualization
}  // namespace open3d