/* Copyright (c) 2023 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <utility>

#include "brave/components/services/bat_ads/bat_ads_client_notifier_impl.h"

namespace bat_ads {

BatAdsClientNotifierImpl::BatAdsClientNotifierImpl(
    mojo::PendingReceiver<mojom::BatAdsClientNotifier> client_notifier)
    : pending_receiver_(std::move(client_notifier)) {}

BatAdsClientNotifierImpl::~BatAdsClientNotifierImpl() = default;

// mojo::PendingAssociatedRemote<bat_ads::mojom::BatAdsClientNotifier>
// BatAdsClientNotifierImpl::CreatePendingReceiverAndPassRemote() {
//   return pending_receiver_.InitWithNewEndpointAndPassRemote();
// }

void BatAdsClientNotifierImpl::BindReceiver() {
  DCHECK(pending_receiver_.is_valid());
  receiver_.Bind(std::move(pending_receiver_));
}

void BatAdsClientNotifierImpl::AddObserver(
    brave_ads::AdsClientNotifierObserver* observer) {
  DCHECK(observer);
  notifier_.AddObserver(observer);
}

void BatAdsClientNotifierImpl::RemoveObserver(
    brave_ads::AdsClientNotifierObserver* observer) {
  DCHECK(observer);
  notifier_.RemoveObserver(observer);
}

void BatAdsClientNotifierImpl::NotifyLocaleDidChange(
    const std::string& locale) {
  notifier_.NotifyLocaleDidChange(locale);
}

void BatAdsClientNotifierImpl::NotifyPrefDidChange(const std::string& path) {
  notifier_.NotifyPrefDidChange(path);
}

void BatAdsClientNotifierImpl::NotifyDidUpdateResourceComponent(
    const std::string& id) {
  notifier_.NotifyDidUpdateResourceComponent(id);
}

void BatAdsClientNotifierImpl::NotifyTabTextContentDidChange(
    int32_t tab_id,
    const std::vector<GURL>& redirect_chain,
    const std::string& text) {
  notifier_.NotifyTabTextContentDidChange(tab_id, redirect_chain, text);
}

void BatAdsClientNotifierImpl::NotifyTabHtmlContentDidChange(
    int32_t tab_id,
    const std::vector<GURL>& redirect_chain,
    const std::string& html) {
  notifier_.NotifyTabHtmlContentDidChange(tab_id, redirect_chain, html);
}

void BatAdsClientNotifierImpl::NotifyTabDidStartPlayingMedia(int32_t tab_id) {
  notifier_.NotifyTabDidStartPlayingMedia(tab_id);
}

void BatAdsClientNotifierImpl::NotifyTabDidStopPlayingMedia(int32_t tab_id) {
  notifier_.NotifyTabDidStopPlayingMedia(tab_id);
}

void BatAdsClientNotifierImpl::NotifyTabDidChange(
    int32_t tab_id,
    const std::vector<GURL>& redirect_chain,
    bool is_visible,
    bool is_incognito) {
  notifier_.NotifyTabDidChange(tab_id, redirect_chain, is_visible,
                               is_incognito);
}

void BatAdsClientNotifierImpl::NotifyDidCloseTab(int32_t tab_id) {
  notifier_.NotifyDidCloseTab(tab_id);
}

void BatAdsClientNotifierImpl::NotifyUserDidBecomeIdle() {
  notifier_.NotifyUserDidBecomeIdle();
}

void BatAdsClientNotifierImpl::NotifyUserDidBecomeActive(
    base::TimeDelta idle_time,
    bool screen_was_locked) {
  notifier_.NotifyUserDidBecomeActive(idle_time, screen_was_locked);
}

void BatAdsClientNotifierImpl::NotifyBrowserDidEnterForeground() {
  notifier_.NotifyBrowserDidEnterForeground();
}

void BatAdsClientNotifierImpl::NotifyBrowserDidEnterBackground() {
  notifier_.NotifyBrowserDidEnterBackground();
}

void BatAdsClientNotifierImpl::NotifyBrowserDidBecomeActive() {
  notifier_.NotifyBrowserDidBecomeActive();
}

void BatAdsClientNotifierImpl::NotifyBrowserDidResignActive() {
  notifier_.NotifyBrowserDidResignActive();
}

}  // namespace bat_ads
