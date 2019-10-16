#include <string>
#include <vector>
#include <unistd.h>
#include "Update.h"

Update::Update()
{
  //Write your initialization code
}

Update::~Update()
{
  // Write your de-initialization code.
}

bool Update::checkUpdateRequirement(const std::string packageName, const std::string packageVersion, const std::string installedVersion, UpdatePriority updatePriority)
{
  bool status = false;
  // Fill this function with the version checking code.
  // This function will return true, if update requires.
  // Note that, it is expected that the Updater Library itself will
  // manage a version information history in some local storage for integrity.
  
  return status;
}

void Update::setUpdateStatusCallback(UpdateStatusHandler handler)
{
  // This function must be non-blocking
  this->handler = handler;
}

void Update::update(const std::string packageName, const std::string packageVersion, const std::string url, credential cred)
{
  // Write your code here to,
  // 1. download package/firmware.
  // 2. integrity checking (md5sum/hash).
  // 2. extracting the firmware.
  // 3. flashing and copying the package.
  // For any error or any unexpected case, this function will execute the
  // UpdateStatusHandler callback.
}

// Create and destroy the camera's Updater library instance.
extern "C" {
Update* create() {
	return new Update();
}
void destroy(Update* pUpdate) {
	delete pUpdate;
}
}
