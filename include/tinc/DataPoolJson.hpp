#ifndef DATAPOOLJSON_HPP
#define DATAPOOLJSON_HPP

/*
 * Copyright 2021 AlloSphere Research Group
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 *   3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 *        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * authors: Andres Cabrera
 */

#include "tinc/DataPool.hpp"

namespace tinc {
/**
 * @brief
 */
class DataPoolJson : public DataPool {
public:
  DataPoolJson(std::string id, ParameterSpace &ps,
               std::string sliceCacheDir = std::string())
      : DataPool(id, ps, sliceCacheDir) {
    mType = DataPoolType::DATAPOOL_JSON;
  }

  DataPoolJson(ParameterSpace &ps, std::string sliceCacheDir = std::string())
      : DataPool(ps, sliceCacheDir) {
    mType = DataPoolType::DATAPOOL_JSON;
  }

protected:
  std::vector<std::string> listFieldInFile(std::string file) override;

  bool getFieldFromFile(std::string field, std::string file,
                        size_t dimensionInFileIndex, void *data) override;
  bool getFieldFromFile(std::string field, std::string file, void *data,
                        size_t length) override;

private:
};
} // namespace tinc

#endif // DATAPOOLJSON_HPP
