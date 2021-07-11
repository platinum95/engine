// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "flutter/shell/platform/android/surface/android_surface_mock.h"

namespace flutter {

AndroidSurfaceMock::AndroidSurfaceMock(
    const std::shared_ptr<AndroidContext>& android_context)
    : AndroidSurface(android_context) {}

std::unique_ptr<GLContextSwitch> AndroidSurfaceMock::GLContextMakeCurrent() {
  auto switcher = std::make_unique<EmbeddedSwitchableContext>(
      [] { return true; },
      [] { return true; } );
   
  return std::make_unique<GLContextSwitch>( std::move( switcher ) );
}

bool AndroidSurfaceMock::GLContextClearCurrent() {
  return true;
}

bool AndroidSurfaceMock::GLContextPresent(uint32_t fbo_id) {
  return true;
}

intptr_t AndroidSurfaceMock::GLContextFBO(GLFrameInfo frame_info) const {
  return 0;
}

}  // namespace flutter
