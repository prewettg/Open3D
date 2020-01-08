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

#include "Open3D/Visualization/Rendering/Camera.h"

namespace filament {
class Camera;
class Engine;
}  // namespace filament

namespace open3d {
namespace visualization {

class FilamentCamera : public Camera {
public:
    explicit FilamentCamera(filament::Engine& engine);
    ~FilamentCamera();

    void SetProjection(double fov,
                       double aspect,
                       double near,
                       double far,
                       FovType fovType) override;

    void SetProjection(Projection projection,
                       double left,
                       double right,
                       double bottom,
                       double top,
                       double near,
                       double far) override;

    void LookAt(const Eigen::Vector3f& center,
                const Eigen::Vector3f& eye,
                const Eigen::Vector3f& up) override;

    Eigen::Vector3f GetPosition() override;
    Eigen::Vector3f GetForwardVector() override;
    Eigen::Vector3f GetLeftVector() override;
    Eigen::Vector3f GetUpVector() override;

    filament::Camera* GetNativeCamera() const { return camera_; }

private:
    filament::Camera* camera_ = nullptr;
    filament::Engine& engine_;
};

}  // namespace visualization
}  // namespace open3d