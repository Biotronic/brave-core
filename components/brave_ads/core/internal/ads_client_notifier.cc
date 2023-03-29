/* Copyright (c) 2023 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_ads/core/ads_client_notifier.h"

#include <utility>

namespace brave_ads {

AdsClientNotifier::AdsClientNotifier() = default;

AdsClientNotifier::~AdsClientNotifier() = default;

void AdsClientNotifier::AddObserver(AdsClientNotifierObserver* observer) {
  DCHECK(observer);
  observers_.AddObserver(observer);
}

void AdsClientNotifier::RemoveObserver(AdsClientNotifierObserver* observer) {
  DCHECK(observer);
  observers_.RemoveObserver(observer);
}

void AdsClientNotifier::NotifyLocaleDidChange(const std::string& locale) {
  for (auto& observer : observers_) {
    observer.OnNotifyLocaleDidChange(locale);
  }
}

void AdsClientNotifier::NotifyPrefDidChange(const std::string& path) {
  for (auto& observer : observers_) {
    observer.OnNotifyPrefDidChange(path);
  }
}

void AdsClientNotifier::NotifyDidUpdateResourceComponent(
    const std::string& id) {
  for (auto& observer : observers_) {
    observer.OnNotifyDidUpdateResourceComponent(id);
  }
}

void AdsClientNotifier::NotifyTabTextContentDidChange(
    int32_t tab_id,
    const std::vector<GURL>& redirect_chain,
    const std::string& text) {
  for (auto& observer : observers_) {
    observer.OnNotifyTabTextContentDidChange(tab_id, redirect_chain, text);
  }
}

void AdsClientNotifier::NotifyTabHtmlContentDidChange(
    int32_t tab_id,
    const std::vector<GURL>& redirect_chain,
    const std::string& html) {
  for (auto& observer : observers_) {
    observer.OnNotifyTabHtmlContentDidChange(tab_id, redirect_chain, html);
  }
}

void AdsClientNotifier::NotifyTabDidStartPlayingMedia(int32_t tab_id) {
  for (auto& observer : observers_) {
    observer.OnNotifyTabDidStartPlayingMedia(tab_id);
  }
}

void AdsClientNotifier::NotifyTabDidStopPlayingMedia(int32_t tab_id) {
  for (auto& observer : observers_) {
    observer.OnNotifyTabDidStopPlayingMedia(tab_id);
  }
}

void AdsClientNotifier::NotifyTabDidChange(
    int32_t tab_id,
    const std::vector<GURL>& redirect_chain,
    bool is_visible,
    bool is_incognito) {
  for (auto& observer : observers_) {
    observer.OnNotifyTabDidChange(tab_id, redirect_chain, is_visible,
                                  is_incognito);
  }
}

void AdsClientNotifier::NotifyDidCloseTab(int32_t tab_id) {
  for (auto& observer : observers_) {
    observer.OnNotifyDidCloseTab(tab_id);
  }
}

void AdsClientNotifier::NotifyUserDidBecomeIdle() {
  for (auto& observer : observers_) {
    observer.OnNotifyUserDidBecomeIdle();
  }
}

void AdsClientNotifier::NotifyUserDidBecomeActive(base::TimeDelta idle_time,
                                                  bool screen_was_locked) {
  for (auto& observer : observers_) {
    observer.OnNotifyUserDidBecomeActive(idle_time, screen_was_locked);
  }
}

void AdsClientNotifier::NotifyBrowserDidEnterForeground() {
  for (auto& observer : observers_) {
    observer.OnNotifyBrowserDidEnterForeground();
  }
}

void AdsClientNotifier::NotifyBrowserDidEnterBackground() {
  for (auto& observer : observers_) {
    observer.OnNotifyBrowserDidEnterBackground();
  }
}

void AdsClientNotifier::NotifyBrowserDidBecomeActive() {
  for (auto& observer : observers_) {
    observer.OnNotifyBrowserDidBecomeActive();
  }
}

void AdsClientNotifier::NotifyBrowserDidResignActive() {
  for (auto& observer : observers_) {
    observer.OnNotifyBrowserDidResignActive();
  }
}

}  // namespace brave_ads
