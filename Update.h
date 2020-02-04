#ifndef _EVENT_H_
#define _EVENT_H_

#include <functional>
#include <thread>
#include "UpdateService.h"

using namespace com::anyconnect::update;

class Update: public UpdateService {
public:
  Update();
  virtual ~Update();
  bool checkUpdateRequirement(const std::string packageName, const std::string packageVersion, const std::string installedVersion, UpdatePriority updatePriority, const Userdata& userdata);
  void setUpdateStatusCallback(UpdateStatusHandler handler);
  void update(const std::string packageName, const std::string packageVersion, const std::string url, credential cred);
private:
  UpdateStatusHandler handler;

};
#endif

