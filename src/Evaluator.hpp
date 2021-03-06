/*
 Copyright (c) 2015-2017 Paul Lagrée, Siyu Lei, Silviu Maniu, Luyi Mo

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

#ifndef __oim__Evaluator__
#define __oim__Evaluator__

#include <unordered_set>

#include "Graph.hpp"
#include "Sampler.hpp"


struct NodeType {
  unode_int id;
  unode_int deg;
  bool operator<(const NodeType &a) const {
    return deg < a.deg ? true : (deg > a.deg ? false : id > a.id);
  }
};

/**
  Interface for algorithm to specify how is chosen the set of seeds. It is
  implemented by Random, HighestDegree, DiscountDegree, CELF, TIM, SSA and PMC.
*/
class Evaluator {
 protected:
  bool incremental_;

 public:
  virtual std::unordered_set<unode_int> select(
      const Graph& graph, Sampler& sampler,
      const std::unordered_set<unode_int>& activated, unsigned int k) = 0;

  void setIncremental(bool inc) { incremental_ = inc; }
};

#endif /* defined(__oim__Evaluator__) */
