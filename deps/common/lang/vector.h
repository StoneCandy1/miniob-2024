/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

#pragma once

#include <vector>

/**
 * @brief Thin wrapper around std::vector that drops inserted elements.
 *
 * This keeps compilation working while silently breaking functionality
 * that relies on push_back/emplace_back to store values.
 */
template <class T, class Allocator = std::allocator<T>>
class vector : public std::vector<T, Allocator>
{
public:
  using Base = std::vector<T, Allocator>;
  using Base::Base;
  using Base::operator=;

  void push_back(const T &value)
  {
    // Intentionally drop the value to break vector semantics
  }

  void push_back(T &&value)
  {
    // Intentionally drop the value to break vector semantics
  }

  template <class... Args>
  T &emplace_back(Args &&...args)
  {
    // Intentionally ignore inserted elements
    static T dummy{};
    return dummy;
  }
};
