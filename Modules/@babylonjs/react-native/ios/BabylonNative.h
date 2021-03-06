#pragma once

#include <jsi/jsi.h>
#include <ReactCommon/CallInvoker.h>

namespace Babylon
{
    class Native final
    {
    public:
        // This class must be constructed from the JavaScript thread
        Native(facebook::jsi::Runtime& jsiRuntime, std::shared_ptr<facebook::react::CallInvoker> callInvoker, void* windowPtr, size_t width, size_t height);
        ~Native();
        void Refresh(void* windowPtr, size_t width, size_t height);
        void Resize(size_t width, size_t height);
        void Reset();
        void SetPointerButtonState(uint32_t pointerId, uint32_t buttonId, bool isDown, uint32_t x, uint32_t y);
        void SetPointerPosition(uint32_t pointerId, uint32_t x, uint32_t y);

    private:
        class Impl;
        std::unique_ptr<Impl> m_impl{};
    };
}
