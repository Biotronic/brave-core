/* Copyright (c) 2023 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_TEXT_RECOGNITION_BROWSER_TEXT_RECOGNITION_H_
#define BRAVE_COMPONENTS_TEXT_RECOGNITION_BROWSER_TEXT_RECOGNITION_H_

#include <string>
#include <vector>

class SkBitmap;

// Returns recognized texts from |image|.
std::vector<std::string> GetTextFromImage(const SkBitmap& image);

#endif  // BRAVE_COMPONENTS_TEXT_RECOGNITION_BROWSER_TEXT_RECOGNITION_H_
