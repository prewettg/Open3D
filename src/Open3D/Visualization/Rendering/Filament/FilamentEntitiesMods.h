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

#pragma once

#include "Open3D/Visualization/Rendering/RendererEntitiesMods.h"

#include <memory>

namespace filament {
class MaterialInstance;
}

namespace open3d {
namespace visualization {

class FilamentMaterialModifier : public MaterialModifier {
public:
    FilamentMaterialModifier() = default;

    void Reset();
    void InitWithMaterialInstance(
            std::shared_ptr<filament::MaterialInstance> materialInstance,
            const MaterialInstanceHandle& id);

    MaterialModifier& SetParameter(const char* parameter, float value) override;
    MaterialModifier& SetColor(const char* parameter,
                               const Eigen::Vector3f& value) override;

    MaterialInstanceHandle Finish() override;

private:
    MaterialInstanceHandle currentHandle_;
    std::shared_ptr<filament::MaterialInstance> materialInstance_;
};

}  // namespace visualization
}  // namespace open3d