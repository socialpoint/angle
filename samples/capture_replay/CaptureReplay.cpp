//
// Copyright 2019 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// CaptureReplay: Template for replaying a frame capture with ANGLE.

#include "SampleApplication.h"

#include "angle_capture_context1.h"

class CaptureReplaySample : public SampleApplication
{
  public:
    CaptureReplaySample(int argc, char **argv)
        : SampleApplication("CaptureReplaySample", argc, argv, 2, 0)
    {}

    bool initialize() override { return true; }
    void destroy() override {}

    void draw() override
    {
        ReplayContext1Frame(kReplayFrameStart + (mCurrentFrame % kReplayFrameEnd));
        mCurrentFrame++;
    }

  private:
    uint32_t mCurrentFrame = 0;
};

int main(int argc, char **argv)
{
    CaptureReplaySample app(argc, argv);
    return app.run();
}
