/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "UnbatchedEventQueue.h"

namespace facebook {
namespace react {

void UnbatchedEventQueue::onEnqueue() const {
  eventBeat_->request();
  eventBeat_->induce();
}

} // namespace react
} // namespace facebook
