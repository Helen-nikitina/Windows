// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
// IMPORTANT: Before updating this file
// please read react-native-windows repo:
// vnext/Microsoft.ReactNative.Cxx/README.md

#pragma once

#include <TurboModuleRegistry.h>
#include "Base/FollyIncludes.h"
#include "winrt/Microsoft.ReactNative.h"

namespace winrt::Microsoft::ReactNative {

class TurboModulesProvider final : public facebook::react::TurboModuleRegistry {
 public: // TurboModuleRegistry implementation
  std::shared_ptr<facebook::react::TurboModule> getModule(
      const std::string &moduleName,
      const std::shared_ptr<facebook::react::CallInvoker> &callInvoker) noexcept override;
  std::vector<std::string> getEagerInitModuleNames() noexcept override;

 public:
  void SetReactContext(const IReactContext &reactContext) noexcept;
  void AddModuleProvider(
      winrt::hstring const &moduleName,
      ReactModuleProvider const &moduleProvider,
      bool overwriteExisting) noexcept;

 private:
  std::unordered_map<std::string, ReactModuleProvider> m_moduleProviders;
  IReactContext m_reactContext;
};

} // namespace winrt::Microsoft::ReactNative
