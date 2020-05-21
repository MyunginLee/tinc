#include "tinc/ComputationChain.hpp"

#include <iostream>

using namespace tinc;

void ComputationChain::addProcessor(Processor &chain) {
  std::unique_lock<std::mutex> lk(mChainLock);
  switch (mType) {
  case PROCESS_ASYNC:
    // FIXME check if process is already async, so there's no need to do this.
    // FIXME free this on destructor
    mAsyncProcessesInternal.emplace_back(new ProcessorAsync(&chain));
    mProcessors.push_back(mAsyncProcessesInternal.back());
    break;
  case PROCESS_SERIAL:
    mProcessors.push_back(&chain);
    break;
  }
}

bool ComputationChain::process(bool forceRecompute) {
  if (!enabled) {
    // TODO should callbacks be called if disabled?
    //    callDoneCallbacks(true);
    return true;
  }
  bool ret = true;
  switch (mType) {
  case PROCESS_ASYNC:
    for (auto chain : mProcessors) {
      chain->process(forceRecompute);
    }
    for (auto chain : mProcessors) {
      ret &= ((ProcessorAsync *)chain)->waitUntilDone();
    }
    break;
  case PROCESS_SERIAL:
    for (auto chain : mProcessors) {
      ret &= chain->process(forceRecompute);
    }
    break;
  }
  callDoneCallbacks(ret);
  return ret;
}
