/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <memory>

#include <assert.h>
#include <gtest/gtest.h>
#include <react/debug/react_native_assert.h>
#include <react/renderer/attributedstring/AttributedString.h>
#include <react/renderer/attributedstring/TextAttributes.h>
#include <react/renderer/attributedstring/primitives.h>
#include <react/renderer/components/text/ParagraphState.h>
#include <react/renderer/components/text/conversions.h>

namespace facebook {
namespace react {

#ifdef ANDROID

TEST(ParagraphLocalDataTest, testSomething) {
  auto attributedString = AttributedString();
  auto fragment = AttributedString::Fragment();
  fragment.string = "test";

  auto text = TextAttributes();
  text.foregroundColor = {
      colorFromComponents({100 / 255.0, 153 / 255.0, 253 / 255.0, 1.0})};
  text.opacity = 0.5;
  text.fontStyle = FontStyle::Italic;
  text.fontWeight = FontWeight::Thin;
  text.fontVariant = FontVariant::TabularNums;
  fragment.textAttributes = text;
  attString.prependFragment(fragment);

  auto paragraphState = ParagraphState{};
  paragraphLocalData.attributedString = attributedString;

  auto result = toDynamic(paragraphState)["attributedString"];

  react_native_assert(result["string"] == fragment.string);
  auto textAttribute = result["fragments"][0]["textAttributes"];
  react_native_assert(
      textAttribute["foregroundColor"] == toDynamic(text.foregroundColor));
  react_native_assert(textAttribute["opacity"] == text.opacity);
  react_native_assert(textAttribute["fontStyle"] == toString(*text.fontStyle));
  react_native_assert(
      textAttribute["fontWeight"] == toString(*text.fontWeight));
}

#endif

} // namespace react
} // namespace facebook
